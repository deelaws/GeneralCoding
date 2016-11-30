#include "stdafx.h"

LRUCache::LRUCache(int capacity)
	: mMaxCapacity(capacity)
{
	front = NULL;
	end = NULL;
}


std::string LRUCache::Get(int i)
{
	return "";
}

void LRUCache::Put(int i, std::string value)
{
	// If item exists
	if (mContainer.find(i) != mContainer.end())
	{
		// pull the item and put it in the front of the LRU sequence.
		DoubleLinkedListNode *item = mContainer[i];
	}
	else
	{
		// If doesn't exist
		DoubleLinkedListNode *new_node = new DoubleLinkedListNode();
		new_node->value = value;
		new_node->pNext = front;
		new_node->pPrevious = end;
		front = new_node;
		if (end == NULL)
		{
			end = front;
			end->pPrevious = front;
		}
		if (mCurrCapacity == mMaxCapacity)
		{
			// remove last item
			auto temp = *end;
			end->pPrevious->pNext = front;
		}
		else
		{
			mCurrCapacity += 1;
		}
	}	
}

void LRUCache::PrintLRUCache()
{
	DoubleLinkedListNode *curr = front;
	while (curr != end->pNext)
	{
		printf(" -> %s ", curr->value.c_str());
		curr = curr->pNext;
	}
}