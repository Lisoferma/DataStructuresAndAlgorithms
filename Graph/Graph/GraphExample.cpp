// @author Lisoferma

#include <iostream>
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


    // Получить список вершин обходом в глубину
    cout << "\nDepth first traversal from 'a': ";
    list<char> traversal = graph.DepthFirstTraversal('a');

    for (char item : traversal)
        cout << item << " ";

    
    // Удалить ребро
    graph.DeleteEdge('a', 'c');

    cout << "\nDepth first traversal from 'a' after delete edge 'ac': ";
    traversal = graph.DepthFirstTraversal('a');

    for (char item : traversal)
        cout << item << " ";

}
