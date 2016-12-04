#include "stdafx.h"

Graph::Graph()
{
}

// No protection against duplicates for now.
void Graph::AddEdge(const int i, const int j)
{
	this->mAdjacencyLists[i].push_back(j);
}

std::vector<int> Graph::GetEdges(const int node)
{
	if (node < this->mAdjacencyLists.size())
	{
		return this->mAdjacencyLists[node];
	}
	
	return std::vector<int>(0);
}

bool Graph::RemoveEdge(const int i, const int j)
{
	size_t list_size = this->mAdjacencyLists[i].size();

	for (size_t start = 0; start < list_size; start++)
	{
		if (j == this->mAdjacencyLists[i][start])
		{
			this->mAdjacencyLists.erase(this->mAdjacencyLists.begin() + start);
			return true;
		}
	}

	return false;
}