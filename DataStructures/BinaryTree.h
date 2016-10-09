#include <memory>


namespace DataStructs{

    struct BinaryTreeNode
    {
        int value;
        std::unique_ptr<BinaryTreeNode> *leftChild;
        std::unique_ptr<BinaryTreeNode> *rightChild;
    };

    class BinaryTree
    {
    public:
        BinaryTree(int rootValue);
        virtual ~BinaryTree(){};

        virtual void Insert(int value);
        void InOrderTraverse();

        void PreOrderTraverse();

        void PostOrderTraverse();

    private:
        std::unique_ptr<BinaryTreeNode> root;
    };

}