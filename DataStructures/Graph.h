#pragma once

// Vertex absraction
struct GraphVertex
{
	// Vertex number
	int i;

	// True if visited
	bool visited;

	// Previous vertex
	int prev;

	// dist from start
	int dist;

	// Edge is represented as a tuple.
	// tuple[0] = vertex which the edge connects to.
	// tuple[1] = the weight of the edge.
	std::vector<std::pair<int, int>> adjacentVertices;
};

/*
 * Adjacency List representation of a graph.
 */
class Graph
{
public:
	Graph() {};
	virtual ~Graph() {};

	Graph(const int& num_vertices);

	// In this graph's implementation, vertices should be added
	// from 0..N, one by one.
	void AddVertex(const int& i);

	// Add's an edge from node "i" to node "j".
	void AddEdge(const int i, const int j, const int weight);

	std::vector<std::pair<int, int>> GetEdges(const int node);

	// Remove's edge from node "i" to node "j".
	bool RemoveEdge(const int i, const int j);

	// Prints the graph in stdout
	void PrintGraph();

	void ResetVisited();

	std::vector<GraphVertex> GetVertices();

private:
	std::vector<GraphVertex> mAdjacencyLists;
};