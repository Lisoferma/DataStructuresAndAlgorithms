// @author Lisoferma

#include <iostream>
#include <string>
#include <list>
#include "Graph.h"

using namespace std;
using namespace DSAGraph;


int main()
{
    Graph<char> graph;

    // Вставка вершин
    graph.InsertVertex('a');
    graph.InsertVertex('b');
    graph.InsertVertex('c');
    graph.InsertVertex('d');

    // Вставка рёбер
    graph.InsertEdge('a', 'b', 1);
    graph.InsertEdge('a', 'c', 2);
    graph.InsertEdge('b', 'c', 3);
    graph.InsertEdge('b', 'd', 4);


    // Информация о графе
    cout << "Vertexes count: " << graph.VertexesCount() << endl;
    cout << "Edges count: " << graph.EdgesCount() << endl;


    // Получить все вершины у которых есть ребро с указанной вершиной
    cout << "Neighbors for 'a': ";
    list<char> vertexNeighbors = graph.GetNeighbors('a');

    for (char item : vertexNeighbors)
        cout << item << " ";


    // Получить список вершин обходом сначала в глубину
    cout << "\nDepth first traversal from 'a': ";
    list<char> traversal = graph.DepthFirstTraversal('a');

    for (char item : traversal)
        cout << item << " ";


    // Получить список вершин обходом сначала в ширину
    cout << "\nBreadth first traversal from 'a': ";
    traversal = graph.BreadthFirstTraversal('a');

    for (char item : traversal)
        cout << item << " ";


    // Получить минимальный путь между двумя вершинами
    cout << "\nMinimum path between 'a' and 'd': " << graph.MinimumPath('a', 'd');

    
    // Удалить ребро
    graph.DeleteEdge('a', 'c');

    cout << "\nDepth first traversal from 'a' after delete edge 'ac': ";
    traversal = graph.DepthFirstTraversal('a');

    for (char item : traversal)
        cout << item << " ";


    // Прочитать граф из файла
    cout << "\nRead graph from file: " << endl;

    const string filename = "GraphData.txt";
    Graph<string> graphFromFile;

    bool result = graphFromFile.ReadFromFile(filename);
    if (result == false) cout << "Failed to open file";

    list<string> list = graphFromFile.GetVertexes();

    for (string& item : list)
        cout << item << " ";
        
}
