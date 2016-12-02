#pragma once

struct DoubleLinkedListNode
{
	int key;
	std::string value;
	DoubleLinkedListNode *pPrevious;
	DoubleLinkedListNode *pNext;
};

class LRUCache
{
public:
	LRUCache(int capacity);
	std::string Get(int i);
	void Put(int i, std::string value);
	std::string Remove(int key);
	void PrintLRUCache();

private:

	DoubleLinkedListNode *RemoveItem(int i);

	int mCurrCapacity;
	int mMaxCapacity;
	std::map<int, DoubleLinkedListNode*> mContainer;
	DoubleLinkedListNode *front;
	DoubleLinkedListNode *end;
};