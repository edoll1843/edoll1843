#ifndef GRAPH_H
#define GRAPH_H

#include "Vertex.h"
#include "Edge.h"
using namespace std;
#include <fstream>
#include <vector>
#include <iostream>
//using namespace std;
#define IN_FINITY 999999
#define visited true
#define unvisited false

class Graph
{
private:
	// the head pointer for the linked list of the vertics
	Vertex * m_pVHead;
	// the number of the vertics
	int m_vSize;

public:
	/// constructor
	Graph();
	/// destructor
	~Graph();
	/// <summary>
	/// add vertex with vertexNum at the end of the linked list for the vertics
	/// </summary>
	///
	/// <param name="vertexKey">
	/// the key for the vertex
	/// </param>
	Vertex*GetpVHead();
	void AddVertex(int vertexKey);
	/// <summary>
	/// add edge from the vertex which the number is startVertexKey to the vertex which the number is endVertexKey
	/// [startVertexKey] ---weight---> [endVertexKey]
	/// </summary>
	///
	/// <param name="startVertexKey">
	/// the start vertex key of the edge
	/// </param>
	/// <param name="endVertexKey">
	/// the end vertex key of the edge
	/// </param>
	/// <param name="weight">
	/// the weight of the edge
	/// </param>
	void AddEdge(int startVertexKey, int endVertexKey, int weight);
	/// <summary>
	/// get the vertex which the key is vertexNum
	/// </summary>
	///
	/// <param name="key">
	/// the key of the vertex to find
	/// </param>
	///
	/// <returns>
	/// the vertex which the key is vertexNum
	/// </returns>
	Vertex* FindVertex(int key);
	/// <summary>
	/// get the number of the vertics
	/// </summary>
	///
	/// <returns>
	/// the number of the vertics
	/// </returns>
	int Size() const;
	/// <summary>
	/// memory free for the vertics
	/// </summary>
	void SetSize(int size);
	/// memory free for the vertics
	void Clear();
	/// <summary>
	/// print out the graph as matrix form
	/// </summary>
	///
	/// <param name="fout">
	/// file stream for the result log
	/// </param>
	void Print(std::ofstream& fout);
	/// <summary>
	/// check whether the graph has negative edge or not.
	/// </summary>
	///
	/// <returns>
	/// true if the graph has negative edge.
	/// false otherwise.
	/// </returns>
	bool IsNegativeEdge();
	/// <summary>
	/// </summary>
	///
	/// <param name="startVertexKey">
	/// the start vertex key
	/// </param>
	/// <param name="endVertexKey">
	/// the end vertex key
	/// </param>
	///
	/// <returns>
	/// the key list of the vertics which are included in the path
	/// last element should be the total cost
	/// </returns>
	/// <summary>
	/// find the shortest path from startVertexKey to endVertexKey with Dijkstra using std::set
	/// </summary>
	///
	/// <param name="startVertexKey">
	/// the start vertex key
	/// </param>
	/// <param name="endVertexKey">
	/// the end vertex key
	/// </param>
	///
	/// <returns>
	/// the key list of the vertics which are included in the shortest path<para/>
	/// the last element should be the total cost<para/>
	/// for the special case, it would be others
	/// </returns>
	std::vector<int> FindShortestPathDijkstraUsingSet(int startVertexKey, int endVertexKey);
	/// <summary>
	/// find the shortest path from startVertexKey to endVertexKey with Dijkstra using MinHeap
	/// </summary>
	///
	/// <param name="startVertexKey">
	/// the start vertex key
	/// </param>
	/// <param name="endVertexKey">
	/// the end vertex key
	/// </param>
	///
	/// <returns>
	/// the key list of the vertics which are included in the shortest path<para/>
	/// the last element should be the total cost<para/>
	/// for the special case, it would be others
	/// </returns>
	std::vector<int> FindShortestPathDijkstraUsingMinHeap(int startVertexKey, int endVertexKey);
	/// <summary>
	/// find the shortest path from startVertexKey to endVertexKey with Bellman-Ford
	/// </summary>
	///
	/// <param name="startVertexKey">
	/// the start vertex key
	/// </param>
	/// <param name="endVertexKey">
	/// the end vertex key
	/// </param>
	///
	/// <returns>
	/// the key list of the vertics which are included in the shortest path
	/// last element should be the total cost
	/// </returns>
	std::vector<int> FindShortestPathBellmanFord(int startVertexKey, int endVertexKey);

	std::vector<vector<int>>FindShortestPathFloyd();

	bool checkvisittable(int arr[])
	{
		for (int i = 0; i < m_vSize; i++)
		{
			if (arr[i] == 0)
				return false;
		}
		return true;
	}

};

#endif
