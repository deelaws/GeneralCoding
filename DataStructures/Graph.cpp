#include "stdafx.h"

Graph::Graph(const int& num_vertices)
{
	for (int i = 0; i <= num_vertices; i++)
	{
		GraphVertex vertex;
		vertex.i = i;
		vertex.visited = false;

		this->mAdjacencyLists.push_back(vertex);
	}
}

void Graph::AddVertex(const int& i)
{
}

// No protection against duplicates for now.
void Graph::AddEdge(const int i, const int j, const int weight)
{
	this->mAdjacencyLists[i].adjacentVertices.push_back({j, weight});
}

std::vector<std::pair<int, int>> Graph::GetEdges(const int node)
{
	if (node < this->mAdjacencyLists.size())
	{
		return this->mAdjacencyLists[node].adjacentVertices;
	}
	
	return std::vector<std::pair<int, int>>(0);
}

bool Graph::RemoveEdge(const int i, const int j)
{
	size_t list_size = this->mAdjacencyLists[i].adjacentVertices.size();

	for (size_t start = 0; start < list_size; start++)
	{
		if (j == this->mAdjacencyLists[i].adjacentVertices[start].first)
		{
			this->mAdjacencyLists[i].adjacentVertices.erase(
				this->mAdjacencyLists[i].adjacentVertices.begin() + start);
			return true;
		}
	}

	return false;
}

void Graph::PrintGraph()
{
	size_t num_vertices = this->mAdjacencyLists.size();

	printf("=========================================\n");
	for (size_t index = 0; index < num_vertices; index++)
	{
		printf("Node '%d --> ", index);
		size_t adjacent_v = 0;
		mAdjacencyLists[index].adjacentVertices;
		for (auto i : mAdjacencyLists[index].adjacentVertices)
		{
			printf("%d - ", i.first);
		}
		printf("\n");
	}
	printf("=========================================\n");
}

void Graph::ResetVisited()
{
	for (GraphVertex& gv : this->mAdjacencyLists)
	{
		gv.visited = false;
	}
}

std::vector<GraphVertex> Graph::GetVertices()
{
	return this->mAdjacencyLists;
}