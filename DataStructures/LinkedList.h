#include "SharedTypes.h"


namespace DataStructs
{
    /*
    struct LinkedListNode
    {
        int value;
        std::unique_ptr<LinkedListNode> next;
    };

    class LinkedList
    {
    public:
        void Insert(int val);
        void Delete(int val);

        // Iterates through the linked list and prints all the elements.
        void Print();

    private:
        std::unique_ptr<LinkedListNode> m_front;
        std::shared_ptr<LinkedListNode> m_rear;
    };

    */


    /*template<typename T>
    struct Node
    {
        T value;
        Node<T> *next = NULL;
    };

    template<typename T>
    class LinkedList
    {
    public:
        LinkedList();
        virtual ~LinkedList(){};
        T peek();
        void Insert(const T& item);
        bool Delete(const T& item);
        uint32_t size();

        // Prints to std::out
        void Print();

    private:
        uint32_t m_size;
        Node<T>* m_First;
    };*/
};