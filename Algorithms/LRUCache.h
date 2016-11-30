#pragma once

struct DoubleLinkedListNode
{
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

	void PrintLRUCache();

private:
	int mCurrCapacity;
	int mMaxCapacity;
	std::map<int, DoubleLinkedListNode*> mContainer;
	DoubleLinkedListNode *front;
	DoubleLinkedListNode *end;
};