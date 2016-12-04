#pragma once

/*
 * Adjacency List representation of a graph.
 */
class Graph
{
public:
	Graph();

	// Add's an edge from node "i" to node "j".
	void AddEdge(const int i, const int j);

	std::vector<int> GetEdges(const int node);

	// Remove's edge from node "i" to node "j".
	bool RemoveEdge(const int i, const int j);

private:
	std::vector<std::vector<int>> mAdjacencyLists;
};