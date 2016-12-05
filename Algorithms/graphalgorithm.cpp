#include "stdafx.h"

int FindVertexWithMinDistance(std::vector<GraphVertex> &vertices)
{
	int min_dist = std::numeric_limits<int>::max();
	int ret_vertex = -1;

	for (auto &vertex : vertices)
	{
		if (vertex.visited == false && vertex.dist < min_dist)
		{
			min_dist = vertex.dist;
			ret_vertex = vertex.i;
		}
	}

	return ret_vertex;
}

std::vector<int> PathToSouceHelper(std::vector<GraphVertex>& vertices, const int & end)
{
	std::vector<int> path;
	path.push_back(end);

	int prev = vertices[end].prev;

	while (prev != -1)
	{
		path.push_back(prev);
		prev = vertices[prev].prev;
	}

	std::reverse(path.begin(), path.end());

	return path;
}

std::vector<int> DijkstraFindShortestPath(Graph& g, const int &start, const int &end)
{
	std::vector<GraphVertex> gsptSet;

	for (GraphVertex& vertex : g.GetVertices())
	{
		vertex.dist = std::numeric_limits<int>::max();
		vertex.prev = -1;
		vertex.visited = 0;
		gsptSet.push_back(vertex);
	}

	// Set the distance of the start node to 0.
	// This'll be the first vertex we visit.
	gsptSet[start].dist = 0;

	for (size_t i = 0; i <  gsptSet.size(); i++)
	{
		auto min_vertex = FindVertexWithMinDistance(gsptSet);

		// If we have reached the end vertex, return the path
		if (end == min_vertex)
		{
			return PathToSouceHelper(gsptSet, end);
		}

		gsptSet[min_vertex].visited = true;

		for (std::pair<int, int> neigbour : gsptSet[min_vertex].adjacentVertices)
		{
			// Get current vertex's distance
			int dist = gsptSet[min_vertex].dist;

			// if the neigbour edge weight plust current distance is less
			// than neighbours current distance, we found a shorter path.
			if ((dist + neigbour.second) < gsptSet[neigbour.first].dist )
			{
				gsptSet[neigbour.first].dist = dist + neigbour.second;

				// Update the neighbours previous vertex to current vertex.
				gsptSet[neigbour.first].prev = min_vertex;
			}
		}
	}

	return std::vector<int>(0);
}