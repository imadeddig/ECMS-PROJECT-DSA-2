#ifndef Avltree_H
#define Avltree_H
#include <iomanip>
#include <algorithm>
#include "Customer.h"
#include "dsexceptions.h"
using namespace std;

// AvlTree class
//
// RUCTION: zero parameter
//
// ******************PUBLIC OPERATIONS*********************
// void insert( x )       --> Insert x
// void remove( x )       --> Remove x
// bool contains( x )     --> Return true if x is present
// Customer findMin( )  --> Return smallest item
// Customer findMax( )  --> Return largest item
// boolean isEmpty( )     --> Return true if empty; else false
// void makeEmpty( )      --> Remove all items
// void printTree( )      --> Print tree in sorted order
// ******************ERRORS********************************
// Throws UnderflowException as warranted

// 5arajna hed struct + ahbet l public we added function get root

struct BinaryNode
{
    Customer element;
    BinaryNode *left;
    BinaryNode *right;

    BinaryNode(const Customer &theElement, BinaryNode *lt, BinaryNode *rt)
        : element(theElement), left(lt), right(rt) {}

    BinaryNode(Customer &&theElement, BinaryNode *lt, BinaryNode *rt)
        : element(std::move(theElement)), left(lt), right(rt) {}
};

class AvlTree
{
private:
    BinaryNode *root;

    void insert(const Customer &x, BinaryNode *&t)
    {
        if (t == nullptr)
        {
            t = new BinaryNode(x, nullptr, nullptr);
            cout << "Value inserted successfully" << endl;
        }
        else if (x.getID() < t->element.getID())
        {
            insert(x, t->left);
        }
        else if (x.getID() > t->element.getID())
        {
            insert(x, t->right);
        }
        else
        {
            cout << "No duplicate values allowed!" << endl;
            return; // No need to proceed further if the value is a duplicate
        }

        // After the recursive insertions, update balance factor and perform rotations
        int bf = getBalanceFactor(t);

        // Left Left Case
        if (bf > 1 && x.getID() < t->left->element.getID())
            t = rightRotate(t);

        // Right Right Case
        if (bf < -1 && x.getID() > t->right->element.getID())
            t = leftRotate(t);

        // Left Right Case
        if (bf > 1 && x.getID() > t->left->element.getID())
        {
            t->left = leftRotate(t->left);
            t = rightRotate(t);
        }

        // Right Left Case
        if (bf < -1 && x.getID() < t->right->element.getID())
        {
            t->right = rightRotate(t->right);
            t = leftRotate(t);
        }
       
    }

   void remov(Customer x, BinaryNode *&t)
{
    if (t == nullptr)
    {
        return;
    }
    else if (x.getID() < t->element.getID())
    {
        remov(x, t->left);
    }
    else if (x.getID() > t->element.getID())
    {
        remov(x, t->right);
    }
    else
    {
        if (t->left == nullptr)
        {
            BinaryNode *temp = t->right;
            delete t;
            t = temp;
        }
        else if (t->right == nullptr)
        {
            BinaryNode *temp = t->left;
            delete t;
            t = temp;
        }
        else
        {
            // node with two children: Get the inorder successor (smallest in the right subtree)
            BinaryNode *temp = findMin(t->right);
            // Copy the inorder successor's content to this node
            t->element = temp->element;
            // Delete the inorder successor
            remov(temp->element,t->right);
        }
    }

    int bf = getBalanceFactor(t);
    if (bf == 2 && getBalanceFactor(t->left) >= 0)
    {
        rightRotate(t);
        cout << "you rotate r";
    }
    else if (bf == 2 && getBalanceFactor(t->left) == -1)
    {
        leftRotate(t->left);
        rightRotate(t);
        cout << "you rotate lr";
    }
    else if (bf == -2 && getBalanceFactor(t->right) <= -0)
    {
        leftRotate(t);
        cout << "you rotate l";
    }
    else if (bf == -2 && getBalanceFactor(t->right) == 1)
    {
        t->right = rightRotate(t->right);
        leftRotate(t);
       
    }
}


    BinaryNode *findMin(BinaryNode *t)
    {
        if (t == nullptr)
            return nullptr;
        if (t->left == nullptr)
            return t;
        return findMin(t->left);
    }

    Customer findMax(BinaryNode *t)
    {
        if (t != nullptr)
            while (t->right != nullptr)
                t = t->right;
        return t->element;
    }

    Customer *contains(int x, BinaryNode *t)
    {
        if (t == nullptr)
            return nullptr;
        else if (x < t->element.getID())
            return contains(x, t->left);
        else if (t->element.getID() < x)
            return contains(x, t->right);
        else
            return &(t->element);
    }
    void makeEmpty(BinaryNode *t)
    {
        if (t != nullptr)
        {
            makeEmpty(t->left);
            makeEmpty(t->right);
            delete t;
        }
        t = nullptr;
    }
    int height(BinaryNode *root)
    {
        if (root == nullptr)
        {
            return -1; // Height of an empty tree is conventionally -1
        }
        else
        {
            int leftHeight = height(root->left);
            int rightHeight = height(root->right);

            // Return the maximum height of left and right subtrees, plus 1 for the current node
            return 1 + std::max(leftHeight, rightHeight);
        }
    }

    int getBalanceFactor(BinaryNode *n)
    {
        if (n == NULL)
            return -1;
        return height(n->left) - height(n->right);
    }

    BinaryNode *rightRotate(BinaryNode *y)
    {
        BinaryNode *x = y->left;
        BinaryNode *T2 = x->right;

        // Perform rotation
        x->right = y;
        y->left = T2;

        return x;
    }

    BinaryNode *leftRotate(BinaryNode *x)
    {
        BinaryNode *y = x->right;
        BinaryNode *T2 = y->left;

        // Perform rotation
        y->left = x;
        x->right = T2;

        return y;
    }

public:
    AvlTree() : root{nullptr}
    {
    }

    // get root
    BinaryNode *getroot()
    {
        return root;
    }

    AvlTree(AvlTree &rhs) : root{rhs.root}
    {
        rhs.root = nullptr;
    }

    ~AvlTree()
    {
        makeEmpty();
    }
    void print(BinaryNode *&root)
    {
        if (root == nullptr)
        {

            return;
        }
        print(root->left);
        root->element.print();
        print(root->right);
    }
    AvlTree operator=(AvlTree rhs)
    {
        std::swap(root, rhs.root);
        return *this;
    }

    Customer findMin()
    {
        if (isEmpty())
            throw UnderflowException{};
        return findMin(root)->element;
    }

    Customer findMax()
    {
        if (isEmpty())
            throw UnderflowException{};
        return findMax(root);
    }

    Customer *contain(int x)
    {
        return contains(x, root);
    }

    bool isEmpty()
    {
        return root == nullptr;
    }

    void makeEmpty()
    {
        makeEmpty(root);
    }

    void insert(Customer x)
    {
        insert(x, root);
    }

    void remove(Customer x)
    {
        remov(x, root);
    }

    void printTree2D(BinaryNode *root, int space)
    {
        const int INDENTATION = 4;

        if (root == nullptr)
            return;

        // Increase distance between levels
        space += INDENTATION;

        // Process the right child first
        printTree2D(root->right, space);

        // Print current node
        cout << setw(space) << root->element.getID() << endl;

        // Process the left child
        printTree2D(root->left, space);
    }
private:
    // Helper function to print the tree structure recursively
};

#endif


