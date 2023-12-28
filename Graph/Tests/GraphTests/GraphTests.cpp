// @author Lisoferma

#include <list>
#include <vector>
#include <algorithm>
#include "pch.h"
#include "../../Graph/Graph.h"

using namespace std;
using namespace DSAGraph;


/// <summary>
/// Наполненый данными граф для тестирования.
/// </summary>
class FilledGraph : public::testing::Test
{
public:
	// Количество вершин которое содержит граф
	const int VERTEXES = 6;

	// Количество рёбер которое содержит граф
	const int EDGES = 11;

	// Данные которыми инициализируется граф 
	const vector<char> INIT_DATA{ 'a', 'b', 'c', 'd', 'e', 'f' };

	// Тестируемый граф
	Graph<char> graph;


	void SetUp()
	{		
		graph.InsertVertexFromVector(INIT_DATA);

		graph.InsertEdge('a', 'b', 1);
		graph.InsertEdge('a', 'c', 2);
		graph.InsertEdge('b', 'd', 3);
		graph.InsertEdge('b', 'e', 4);
		graph.InsertEdge('c', 'd', 5);
		graph.InsertEdge('c', 'e', 6);
		graph.InsertEdge('d', 'e', 7);
		graph.InsertEdge('d', 'f', 8);
		graph.InsertEdge('e', 'f', 9);
		graph.InsertEdge('e', 'a', 10);
		graph.InsertEdge('f', 'f', 11);
	}
};


TEST(Constructor, NoParameters_GraphIsEmpty)
{
	Graph<char> graph;
	EXPECT_TRUE(graph.IsEmpty());
}


TEST(Constructor, ParameterCapacity_GraphIsEmpty)
{
	Graph<char> graph(5);
	EXPECT_TRUE(graph.IsEmpty());
}


TEST(Constructor, ParameterVector_GraphVertexesSameVectorData)
{
	vector<char> initData{ 'a', 'b', 'c', 'd'};
	Graph<char> graph(initData);

	list<char> graphResultData = graph.GetVertexes();

	EXPECT_EQ(graphResultData.size(), initData.size());

	for (auto resultItem : graphResultData)
	{
		auto result = find(begin(initData), end(initData), resultItem);
		EXPECT_FALSE(result == end(initData));
	}
}


TEST(GetNeighbors, EmptyGraph_ReturnEmptyList)
{
	Graph<char> graph;

	list<char> resultNeighbors = graph.GetNeighbors('a');

	EXPECT_TRUE(resultNeighbors.empty());
}


TEST_F(FilledGraph, GetNeighbors_GetExistingNeighbors_ReturnAllNeighbors)
{
	list<char> expectedNeighbors{ 'b', 'c' };

	list<char> resultNeighbors = graph.GetNeighbors('a');

	EXPECT_EQ(expectedNeighbors.size(), resultNeighbors.size());

	for (auto resultItem : resultNeighbors)
	{
		auto result = find(begin(expectedNeighbors), end(expectedNeighbors), resultItem);
		EXPECT_FALSE(result == end(expectedNeighbors));
	}
}


TEST(GetNeighbors, GetNonExistingNeighborsInFilledGraph_ReturnEmptyList)
{
	vector<char> initData{ 'a', 'b', 'c' };
	Graph<char> graph(initData);
	graph.InsertEdge('b', 'c', 1);

	list<char> resultNeighbors = graph.GetNeighbors('a');

	EXPECT_TRUE(resultNeighbors.empty());
}


TEST(InsertVertex, InsertSomeVertexes_AllVertexesInGraph)
{
	vector<char> insertData{ 'a', 'b', 'c', 'd', 'e'};
	Graph<char> graph;

	for (auto insertItem : insertData)
		graph.InsertVertex(insertItem);

	list<char> resultVertexes = graph.GetVertexes();

	EXPECT_EQ(resultVertexes.size(), insertData.size());

	for (auto resultItem : resultVertexes)
	{
		auto result = find(begin(insertData), end(insertData), resultItem);
		EXPECT_FALSE(result == end(insertData));
	}
}


TEST(InsertEdge, InsertSomeEdges_AllEdgeWeightCorrect)
{
	vector<char> initData{ 'a', 'b', 'c', 'd', 'e' };
	Graph<char> graph(initData);

	graph.InsertEdge('a', 'b', 1);
	graph.InsertEdge('a', 'c', 2);
	graph.InsertEdge('b', 'd', 3);
	graph.InsertEdge('b', 'e', 4);
	graph.InsertEdge('e', 'a', 10);

	EXPECT_EQ(graph.GetWeight('a', 'b'), 1);
	EXPECT_EQ(graph.GetWeight('a', 'c'), 2);
	EXPECT_EQ(graph.GetWeight('b', 'd'), 3);
	EXPECT_EQ(graph.GetWeight('b', 'e'), 4);
	EXPECT_EQ(graph.GetWeight('e', 'a'), 10);
}


TEST(InsertEdge, InsertEdgesWithNonExistingVertexes_ReturnFalse)
{
	vector<char> initData{ 'a', 'b', 'c', 'd', 'e' };
	Graph<char> graph(initData);

	EXPECT_FALSE(graph.InsertEdge('a', 'O', 1));
	EXPECT_FALSE(graph.InsertEdge('O', 'b', 2));
	EXPECT_FALSE(graph.InsertEdge('O', 'O', 3));
}


TEST(InsertEdge, InsertEdgesWithExistingVertexes_ReturnTrue)
{
	vector<char> initData{ 'a', 'b', 'c', 'd', 'e' };
	Graph<char> graph(initData);

	EXPECT_TRUE(graph.InsertEdge('a', 'b', 1));
	EXPECT_TRUE(graph.InsertEdge('b', 'c', 2));
	EXPECT_TRUE(graph.InsertEdge('a', 'a', 3));
}


TEST(InsertEdge, InsertEdgesWithZeroWeight_ReturnFalse)
{
	vector<char> initData{ 'a', 'b', 'c', 'd', 'e' };
	Graph<char> graph(initData);

	EXPECT_FALSE(graph.InsertEdge('a', 'b', 0));
	EXPECT_FALSE(graph.InsertEdge('b', 'c', 0));
	EXPECT_FALSE(graph.InsertEdge('a', 'a', 0));
}


TEST(DeleteVertex, DeleteExistingVertex_DeletedVertexesNotInGraphOtherStill)
{
	vector<char> initData{ 'a', 'b', 'c', 'd', 'e', 'f' };
	vector<char> expectedAfterDelete{ 'a', 'c', 'f' };
	Graph<char> graph(initData);

	graph.DeleteVertex('b');
	graph.DeleteVertex('d');
	graph.DeleteVertex('e');

	list<char> resultData = graph.GetVertexes();

	EXPECT_EQ(expectedAfterDelete.size(), resultData.size());

	for (auto resultItem : resultData)
	{
		auto result = find(begin(expectedAfterDelete), end(expectedAfterDelete), resultItem);
		EXPECT_FALSE(result == end(expectedAfterDelete));
	}
}


TEST(DeleteVertex, DeleteNonExistingVertexes_GraphVertexesNotChanged)
{
	vector<char> initData{ 'a', 'b', 'c', 'd', 'e', 'f' };
	Graph<char> graph(initData);

	graph.DeleteVertex('X');
	graph.DeleteVertex('Y');
	graph.DeleteVertex('Z');

	list<char> resultData = graph.GetVertexes();

	EXPECT_EQ(initData.size(), resultData.size());

	for (auto resultItem : resultData)
	{
		auto result = find(begin(initData), end(initData), resultItem);
		EXPECT_FALSE(result == end(initData));
	}
}


TEST(DeleteVertex, DeleteVertexesInEmptyGraph_GraphRemainsEmpty)
{
	Graph<char> graph;

	graph.DeleteVertex('O');

	EXPECT_TRUE(graph.IsEmpty());
}


TEST_F(FilledGraph, DeleteEdge_DeleteExistingEdges_DeletedEdgesNotInGraphOthersStill)
{
	graph.DeleteEdge('a', 'b');
	graph.DeleteEdge('b', 'd');
	graph.DeleteEdge('c', 'e');
	graph.DeleteEdge('e', 'f');
	graph.DeleteEdge('e', 'a');

	EXPECT_EQ(graph.GetWeight('a', 'b'), 0);
	EXPECT_EQ(graph.GetWeight('a', 'c'), 2);
	EXPECT_EQ(graph.GetWeight('b', 'd'), 0);
	EXPECT_EQ(graph.GetWeight('b', 'e'), 4);
	EXPECT_EQ(graph.GetWeight('c', 'd'), 5);
	EXPECT_EQ(graph.GetWeight('c', 'e'), 0);
	EXPECT_EQ(graph.GetWeight('d', 'e'), 7);
	EXPECT_EQ(graph.GetWeight('d', 'f'), 8);
	EXPECT_EQ(graph.GetWeight('e', 'f'), 0);
	EXPECT_EQ(graph.GetWeight('e', 'a'), 0);
	EXPECT_EQ(graph.GetWeight('f', 'f'), 11);
}


TEST_F(FilledGraph, DeleteEdge_DeleteExistingEdges_ReturnTrue)
{
	EXPECT_TRUE(graph.DeleteEdge('a', 'b'));
	EXPECT_TRUE(graph.DeleteEdge('f', 'f'));
}


TEST_F(FilledGraph, DeleteEdge_DeleteNonExistingEdges_ReturnFalse)
{
	EXPECT_FALSE(graph.DeleteEdge('a', 'O'));
	EXPECT_FALSE(graph.DeleteEdge('O', 'b'));
	EXPECT_FALSE(graph.DeleteEdge('O', 'O'));
}


TEST(DeleteEdge, DeleteEdgeInEmptyGraph_GraphRemainsEmpty)
{
	Graph<char> graph;

	graph.DeleteEdge('a', 'b');

	EXPECT_TRUE(graph.IsEmpty());
}


TEST_F(FilledGraph, VertexesCount_GetVertexesCount_VertexesCountIsCorrect)
{
	EXPECT_EQ(graph.VertexesCount(), VERTEXES);
}


TEST_F(FilledGraph, EdgesCount_GetEdgesCount_VertexesCountIsCorrect)
{
	EXPECT_EQ(graph.EdgesCount(), EDGES);
}


TEST(VertexesCount, GetVertexesCountInEmptyGraph_VertexesCountIsZero)
{
	Graph<char> graph;

	EXPECT_EQ(graph.VertexesCount(), 0);
}


TEST(EdgesCount, GetEdgesCountInEmptyGraph_EdgesCountIsZero)
{
	Graph<char> graph;

	EXPECT_EQ(graph.EdgesCount(), 0);
}


TEST_F(FilledGraph, DepthFirstTraversal_GetVertexesByTreversal_ResultingSequenceCorrect)
{
	vector<char> expectedData{ 'a', 'c', 'e', 'f', 'd', 'b' };

	list<char> resultData = graph.DepthFirstTraversal('a');

	EXPECT_EQ(resultData.size(), expectedData.size());

	int i = 0;
	for (auto resultItem : resultData)
	{
		EXPECT_EQ(expectedData[i], resultItem);
		++i;
	}
}


TEST_F(FilledGraph, BreadthFirstTraversal_GetVertexesByTreversal_ResultingSequenceCorrect)
{
	vector<char> expectedData{ 'a', 'b', 'c', 'd', 'e', 'f' };

	list<char> resultData = graph.BreadthFirstTraversal('a');

	EXPECT_EQ(resultData.size(), expectedData.size());

	int i = 0;
	for (auto resultItem : resultData)
	{
		EXPECT_EQ(expectedData[i], resultItem);
		++i;
	}
}


TEST_F(FilledGraph, PathCost_GetPathInFilledGraph_ResultIsCorrect)
{
	int expectedPathAF = 17;
	int expectedPathAA = 0;
	int expectedPathAO = -1;

	int resultPathAF = graph.PathCost('a', 'f');
	int resultPathAA = graph.PathCost('a', 'a');
	int resultPathAO = graph.PathCost('a', 'O');

	EXPECT_EQ(expectedPathAF, resultPathAF);	
	EXPECT_EQ(expectedPathAA, resultPathAA);
	EXPECT_EQ(expectedPathAO, resultPathAO);
}