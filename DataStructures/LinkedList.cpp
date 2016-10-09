#include "stdafx.h"

using namespace DataStructs;

void FooFunction()
{
    int a = 1;
    a += 1;
}

void waleed::PleaseWork()
{
    int a = 1;
    a++;
}



/*
template<typename T>
LinkedList<T>::LinkedList()
: m_size(0)
, m_First(NULL)
{

}

template<typename T>
void LinkedList<T>::Insert(const T& item)
{

    Node<T> *newNode = new Node<T>();
    newNode->value = item;
    newNode->next = m_First->next;

    this->m_First = newNode;
}


// 1 -> 2 -> 3 -> NULL

// implement 
template<typename T>
bool LinkedList<T>::Delete(const T& item)
{
    if (NULL == m_First)
    {
        goto Exit;
    }

    Node<T>* temp = m_First;
    Node<T> *tempNext = NULL;
    // Check first Node
    if (item == m_First->value)
    {
        tempNext = m_First->next;
        ::free(m_First->value);
        ::free(m_First);
        m_First = m_First->next;
    }
    else
    {
        while (NULL != temp->next)
        {
            if (item == temp->next->value)
            {
                tempNext = temp->next->next;
                ::free(temp->next->value);
                ::free(temp->next);
                temp->next = tempNext;

                return true;
            }
        }
    }

Exit:
    return false
    }*/