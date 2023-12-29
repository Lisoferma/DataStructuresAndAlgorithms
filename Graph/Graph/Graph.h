// @author Lisoferma

#pragma once

#include <list>
#include <vector>
#include <stack>
#include <queue>
#include <string>  
#include <fstream>

namespace DSAGraph
{
	/// <summary>
	/// Описывает путь между двумя вершинами и его стоимость.
	/// </summary>
	/// <typeparam name="T">Тип данных вершин.</typeparam>
	template <typename T>
	struct PathInfo
	{
		// Начальная и конечная вершина пути.
		T startVertex, endVertex;

		// Стоимость пути.
		int cost;

		bool operator < (const PathInfo& pathInfo) const
		{
			return cost < pathInfo.cost;
		}
	};


	/// <summary>
	/// Ориентированный взвешенный граф. Вес ребра > 0.
	/// Вставка вершин - O(1); вставка рёбер - O(n);
	/// удаление вершин - O(n^2); удаление рёбер - O(n);
	/// обход - O(n^2).
	/// </summary>
	/// <typeparam name="T">Тип данных вершин.</typeparam>
	template <typename T>
	class Graph
	{
	public:
		Graph() = default;


		/// <summary>
		/// Задать начальную вместимость графа.
		/// </summary>
		/// <param name="initialCapacity">Вместимость графа.</param>
		Graph(size_t initialCapacity)
		{
			_edges.reserve(initialCapacity);
		}


		/// <summary>
		/// Инициализировать вершины графа данными из вектора.
		/// </summary>
		/// <param name="data">Вектор который содержит данные вершин.</param>
		Graph(const std::vector<T>& data)
		{
			InsertVertexFromVector(data);
		}


		/// <summary>
		/// Получить список вершин, у которых есть ребро с указанной вершиной.
		/// </summary>
		/// <param name="vertex">Вершина для которой нужно найти соседние вершины.</param>
		/// <returns>Список найденных вершин. Если вершин нет - пустой список.</returns>
		std::list<T>& GetNeighbors(const T& vertex) const
		{
			std::list<T>* neighborsList = new std::list<T>();

			if (IsEmpty()) return *neighborsList;

			int position = GetVertexPosition(vertex);
			if (position == -1) return *neighborsList;

			// Создать список из вершин, имеющих ребро из vertex ненулевого веса 			
			int i = 0;
			for (auto nextVertex : _vertexes)
			{
				int edge = _edges[position][i];
				
				if (edge > 0)
					neighborsList->push_back(nextVertex);

				++i;
			}

			return *neighborsList;
		}


		/// <summary>
		/// Вставить вершину в граф.
		/// </summary>
		/// <param name="vertex">Вершина которую нужно вставить.</param>
		void InsertVertex(const T& vertex)
		{
			_vertexes.push_back(vertex);

			_edges.resize(_vertexes.size());
			for (int i = 0; i < _vertexes.size(); i++)
				_edges[i].resize(_vertexes.size());
		}


		/// <summary>
		/// Вставить вершины графа с данными из вектора.
		/// </summary>
		/// <param name="vertex">Вектор который содержит данные вершин.</param>
		void InsertVertexFromVector(const std::vector<T>& data)
		{
			_edges.reserve(data.capacity());

			for (auto item : data)
				InsertVertex(item);
		}


		/// <summary>
		/// Вствить ребро в граф.
		/// </summary>
		/// <param name="vertex1">Первая вершина для которой нужно вствить ребро.</param>
		/// <param name="vertex2">Вторая вершина для которой нужно вствить ребро с первой.</param>
		/// <param name="weight">Вес ребра (>0).</param>
		/// <returns>
		/// True - если удалось вствить ребро,
		/// false - если как минимум одна из вершин не найдена или вес ребра 0.
		/// </returns>
		bool InsertEdge(const T& vertex1, const T& vertex2, int weight)
		{
			if (IsEmpty() || weight == 0) return false;

			int position1 = GetVertexPosition(vertex1);
			if (position1 == -1) return false;

			int position2 = GetVertexPosition(vertex2);
			if (position2 == -1) return false;

			_edges[position1][position2] = weight;
			return true;
		}


		/// <summary>
		/// Удалить вершину из графа.
		/// </summary>
		/// <param name="vertex">Вершина которую нужно удалить.</param>
		void DeleteVertex(const T& vertex)
		{
			if (IsEmpty()) return;

			int position = GetVertexPosition(vertex);
			if (position == -1) return;

			_vertexes.remove(vertex);

			int row, col;

			// Сдвинуть индекс столбцов влево
			for (row = 0; row < position; ++row)
			{
				for (col = position + 1; col < _vertexes.size(); ++col)
				{
					_edges[row][col - 1] = _edges[row][col];
				}	
			}

			// Сдвинуть индекс строк вверх и индекс столбцов влево
			for (row = position + 1; row < _vertexes.size(); ++row)
			{
				for (col = position + 1; col < _vertexes.size(); ++col)
				{
					_edges[row - 1][col - 1] = _edges[row][col];
				}	
			}

			// Сдвинуть индекс строк вверх
			for (row = position + 1; row < _vertexes.size(); ++row)
			{
				for (col = 0; col < position; ++col)
				{
					_edges[row - 1][col] = _edges[row][col];
				}
			}
		}


		/// <summary>
		/// Удалить ребро из графа.
		/// </summary>
		/// <param name="vertex1">Первая вершина между которой находится ребро.</param>
		/// <param name="vertex2">Вторая вершина между которой находится ребро.</param>
		/// <returns>
		/// True - если удалось удалить ребро,
		/// false - если как минимум одна из вершин не найдена.
		/// </returns>
		bool DeleteEdge(const T& vertex1, const T& vertex2)
		{
			if (IsEmpty()) return false;

			int position1 = GetVertexPosition(vertex1);
			if (position1 == -1) return false;

			int position2 = GetVertexPosition(vertex2);
			if (position2 == -1) return false;

			_edges[position1][position2] = 0;
			return true;
		}


		/// <summary>
		/// Получить количество вершин.
		/// </summary>
		size_t VertexesCount() const
		{
			return _vertexes.size();
		}


		/// <summary>
		/// Получить количество рёбер.
		/// </summary>
		int EdgesCount() const
		{
			int count = 0;

			for (int i = 0; i < _edges.size(); ++i)
				for (int j = 0; j < _edges.size(); ++j)
					if (_edges[i][j] != 0) ++count;

			return count;
		}


		/// <summary>
		/// Получить вес ребра.
		/// </summary>
		/// <param name="vertex1">Первая вершина между которой находится ребро.</param>
		/// <param name="vertex2">Вторая вершина между которой находится ребро.</param>
		/// <returns>Вес ребра. -1 если как минимум одна из вершин не найдена.</returns>
		int GetWeight(const T& vertex1, const T& vertex2) const
		{
			if (IsEmpty()) return -1;

			int position1 = GetVertexPosition(vertex1);
			if (position1 == -1) return -1;

			int position2 = GetVertexPosition(vertex2);
			if (position2 == -1) return -1;

			return _edges[position1][position2];
		}


		/// <summary>
		/// Получить список вершин.
		/// </summary>
		const std::list<T>& GetVertexes() const
		{
			return _vertexes;
		}


		/// <summary>
		/// Граф пуст.
		/// </summary>
		bool IsEmpty() const
		{
			return _vertexes.empty();
		}


		/// <summary>
		/// Получить список достижимых вершин обходом "сначала в глубину" начиная с заданной вершины.
		/// </summary>
		/// <param name="beginVertex">Вершина с которой начинать обход.</param>
		/// <returns>Список вершин после обхода.</returns>
		std::list<T>& DepthFirstTraversal(const T& beginVertex) const
		{
			// Стэк для временного хранения вершин, ожидающих обработки
			std::stack<T> stack;

			// Список пройденных вершин
			std::list<T>* traversedVertexes = new std::list<T>();

			// Список вершин смежных с текущей
			std::list<T> adjacentVertexes;

			// Извлечённая из стэка вершина
			T vertex;

			if (IsEmpty() || GetVertexPosition(beginVertex) == -1)
				return *traversedVertexes;

			stack.push(beginVertex);

			while (!stack.empty())
			{
				vertex = stack.top();
				stack.pop();

				// Если вершина посещена, переходим к следующей
				if (FindVertex(*traversedVertexes, vertex) != -1)
					continue;

				traversedVertexes->push_back(vertex);
				adjacentVertexes = GetNeighbors(vertex);
				
				// Поместить в стэк смежные вершины, которые не были посещены
				for (auto item : adjacentVertexes)
					if (FindVertex(*traversedVertexes, item) == -1)
						stack.push(item);
			}

			return *traversedVertexes;
		}


		/// <summary>
		/// Получить список достижимых вершин обходом "сначала в ширину" начиная с заданной вершины.
		/// </summary>
		/// <param name="beginVertex">Вершина с которой начинать обход.</param>
		/// <returns>Список вершин после обхода.</returns>
		std::list<T>& BreadthFirstTraversal(const T& beginVertex) const
		{
			// Очередь для временного хранения вершин, ожидающих обработки
			std::queue<T> queue;

			// Список пройденных вершин
			std::list<T>* traversedVertexes = new std::list<T>();

			// Список вершин смежных с текущей
			std::list<T> adjacentVertexes;

			// Извлечённая из очереди вершина
			T vertex;

			if (IsEmpty() || GetVertexPosition(beginVertex) == -1)
				return *traversedVertexes;

			queue.push(beginVertex);

			while (!queue.empty())
			{
				vertex = queue.front();
				queue.pop();

				// Если вершина посещена, переходим к следующей
				if (FindVertex(*traversedVertexes, vertex) != -1)
					continue;

				traversedVertexes->push_back(vertex);
				adjacentVertexes = GetNeighbors(vertex);

				// Поместить в стэк смежные вершины, которые не были посещены
				for (auto item : adjacentVertexes)
					if (FindVertex(*traversedVertexes, item) == -1)
						queue.push(item);
			}

			return *traversedVertexes;
		}


		/// <summary>
		/// Найти стоимость пути между двумя вершинами.
		/// </summary>
		/// <param name="startVertex">Вершина с которой начинается путь.</param>
		/// <param name="endVertex">Вершина где заканчивается путь.</param>
		/// <returns>Стоимость пути. -1 если пути нет.</returns>
		int PathCost(const T& startVertex, const T& endVertex) const
		{
			std::priority_queue<PathInfo<T>> queue;

			// Используется при вставке/удалении объектов PathInfo в очереди
			PathInfo<T> pathData;

			// Список всех вершин, достижимых из startVertex
			// и стоимость которых уже учтена
			std::list<T> traversedVertexes;

			// Список вершин смежных с текущей
			std::list<T> adjacentVertexes;

			// Для временного хранения данных PathInfo из очереди
			T sv{}, ev{};
			int minCost = 0;

			pathData.startVertex = startVertex;
			pathData.endVertex = startVertex;
			pathData.cost = 0;

			queue.push(pathData);

			// Обрабатывать вершины, пока не будет найден минимальный путь
			// к endVertex или пока не опустеет очередь
			while (!queue.empty())
			{
				pathData = queue.top();
				queue.pop();
				ev = pathData.endVertex;
				minCost = pathData.cost;

				// Если минимальный путь найден
				if (ev == endVertex)
					break;

				// Если текущая конечная вершина уже рассмотрена - пропустить её
				if (FindVertex(traversedVertexes, ev) != -1)
					continue;

				traversedVertexes.push_back(ev);
				sv = ev;
				adjacentVertexes = GetNeighbors(sv);

				for (auto item : adjacentVertexes)
				{
					ev = item;

					if (FindVertex(traversedVertexes, ev) != -1)
						continue;

					// Создать новый элемент приоритетной очереди
					pathData.startVertex = sv;
					pathData.endVertex = ev;
					pathData.cost = minCost + GetWeight(sv, ev);

					queue.push(pathData);
				}
			}

			if (ev == endVertex)
				return minCost;
			else
				return -1;
		}


		/// <summary>
		/// Только для графа с вершинами типа string.
		/// Добавить данные к графу из файла,
		/// анализируя текстовый файл соответствующий специальному формату разметки.
		/// </summary>
		/// <param name="filename">Имя файла, который содержит данные графа.</param>
		/// <returns>True - если удалось открыть файл, иначе false.</returns>
		bool ReadFromFile(const std::string& filename)
		{
			const std::string separators{ "^-,\n" };
			const char vertexSign = '^';
			const char edgeSign = '-';

			std::ifstream file(filename);
			std::string line;

			if (!file.is_open()) return false;

			while (std::getline(file, line))
			{
				switch (line[0])
				{
					case vertexSign:
						InsertVertexesFromString(line);
						break;

					case edgeSign:
						InsertEdgesFromString(line);
						break;
				}
			}

			file.close();
			return true;
		}


		/// <summary>
		/// Получить позицию вершины в списке.
		/// </summary>
		/// <param name="list">Список в котором нужно искать вершину.</param>
		/// <param name="vertex">Вершина которую нужно найти.</param>
		/// <returns>Позиция вершины в списке. -1 если не найдена.</returns>
		static int FindVertex(const std::list<T>& list, const T& vertex)
		{
			int position = 0;

			for (auto item : list)
				if (item == vertex) return position;
				else ++position;

			return -1;
		}


	private:
		/// <summary>
		/// Список вершин.
		/// </summary>
		std::list<T> _vertexes;

		/// <summary>
		/// Матрица смежности графа. Хранит информацию о рёбрах между вершинами и их вес.
		/// </summary>
		std::vector<std::vector<int>> _edges;


		/// <summary>
		/// Получить позицию-индекс вершины в матрице смежности.
		/// </summary>
		/// <param name="vertex">Вершина для которой нужно найти индекс.</param>
		/// <returns>Индекс вершины. -1 если такой вершины нет.</returns>
		int GetVertexPosition(const T& vertex) const
		{
			return FindVertex(_vertexes, vertex);
		}


		/// <summary>
		/// Вставить вершины в граф, анализируя строку соответствующую специальному формату разметки.
		/// </summary>
		/// <param name="str">Строка с данными о вершинах.</param>
		void InsertVertexesFromString(const std::string& str)
		{
			const std::string separators{ "^,\n" };

			// Начальный индекс первого слова
			size_t start = str.find_first_not_of(separators);

			while (start != std::string::npos)
			{
				// Конечный индекс слова
				size_t end = str.find_first_of(separators, start + 1);

				// Если не найден ни один из символов-разделителей
				if (end == std::string::npos)
					end = str.length();

				// Полученная строка - вершина
				InsertVertex(str.substr(start, end - start));

				// Начальный индекс следующего слова
				start = str.find_first_not_of(separators, end + 1);
			}
		}


		/// <summary>
		/// Вставить рёбра в граф, анализируя строку соответствующую специальному формату разметки.
		/// </summary>
		/// <param name="str">Строка с данными о рёбрах.</param>
		void InsertEdgesFromString(const std::string& str)
		{
			const std::string separators{ "-,\n" };

			// Индекс слова в строке
			int index = 0;

			// Начальная и конечная вершина ребра
			T vertexStart, vertexEnd;

			// Вес ребра
			int weight;

			// Начальный индекс первого слова
			size_t start = str.find_first_not_of(separators);

			while (start != std::string::npos)
			{
				// Конечный индекс слова
				size_t end = str.find_first_of(separators, start + 1);

				// Если не найден ни один из символов-разделителей
				if (end == std::string::npos)
					end = str.length();

				std::string dataString = str.substr(start, end - start);

				switch (index)
				{
				case 0:
					vertexStart = dataString;
					break;
				case 1:
					vertexEnd = dataString;
					break;
				case 2:
					weight = std::stoi(dataString);
					break;
				}

				// Начальный индекс следующего слова
				start = str.find_first_not_of(separators, end + 1);
				++index;
			}

			InsertEdge(vertexStart, vertexEnd, weight);
		}
	};
}