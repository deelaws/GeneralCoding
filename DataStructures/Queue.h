#include <vector>

namespace DataStructs{

    class Queue
    {
    public:
        Queue();
        virtual ~Queue(){};

        void Enqueue(int i);

        int Dequeue();

        // Returns the element in the front of the queue
        int Front();
        
    private:
        std::vector<int> m_vector;


    };


}