#include "stdafx.h"

LRUCache::LRUCache(int capacity)
	: mMaxCapacity(capacity)
{
	front = NULL;
	end = NULL;
}


std::string LRUCache::Get(int i)
{
	if (mCurrCapacity > 0)
	{ 
		return front->value;
	}

	return "";
}

std::string LRUCache::Remove(int key)
{
	if (mContainer.find(key) != mContainer.end())
	{
		// pull the item and put it in the front of the LRU sequence.
		// remove it from the Double Linked List
		auto ret = this->RemoveItem(key);
		std::string retStr = ret->value;
		this->mContainer.erase(ret->key);
		delete ret;

		mCurrCapacity -= 1;

		return retStr;
	}

	// TODO: return empty string if key doesn't exist.
	return "";
}

DoubleLinkedListNode *LRUCache::RemoveItem(int i)
{
	DoubleLinkedListNode *old_node = mContainer[i];
	old_node->pPrevious->pNext = old_node->pNext;
	old_node->pNext->pPrevious = old_node->pPrevious;

	// Fix front and rear pointers.
	if (end == old_node)
	{
		end = old_node->pPrevious;
	}
	else if (front == old_node)
	{
		front = old_node->pNext;
	}

	return old_node;
}


void LRUCache::Put(int i, std::string value)
{
	DoubleLinkedListNode *new_node = NULL;
	
	// If item exists pull it out
	if (mContainer.find(i) != mContainer.end())
	{
		// pull the item and put it in the front of the LRU sequence.
		// remove it from the Double Linked List
		new_node = this->RemoveItem(i);
	}
	else
	{
		if (mCurrCapacity == mMaxCapacity)
		{
			// Remove last node in the Double Linked List To Make room for new Node
			auto temp = this->RemoveItem(this->end->key);
			this->mContainer.erase(temp->key);
			delete temp;
		}
		else
		{
			mCurrCapacity += 1;
		}

		new_node = new DoubleLinkedListNode();
		new_node->key = i;
		new_node->value = value;
		mContainer[i] = new_node;
	}

	if (1 == mCurrCapacity)
	{
		front =  new_node;
		end = new_node;
		new_node->pPrevious = front;
		new_node->pNext = end;
	}
	else
	{
		new_node->pNext = front;
		new_node->pPrevious = front->pPrevious;
		front->pPrevious = new_node;
		
		// Now update front
		front = new_node;

		// Update end
		end->pNext = front;
	}
}

void LRUCache::PrintLRUCache()
{
	if (mCurrCapacity == 0)
	{
		return;
	}
	DoubleLinkedListNode *curr = front;
	printf("===============================\n");
	
	printf("%s ", curr->value.c_str());
	curr = curr->pNext;
	for (int i = 1; i < mCurrCapacity; i++)
	{
		printf(" -> %s ", curr->value.c_str());
		curr = curr->pNext;
	}

	printf("\n===============================\n");
}