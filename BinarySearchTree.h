#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H

#include <algorithm>
#include "Customer.h"
#include "dsexceptions.h"
using namespace std;

// BinarySearchTree class
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

    BinaryNode(Customer &theElement, BinaryNode *lt, BinaryNode *rt)
        : element{theElement}, left{lt}, right{rt} {}

    BinaryNode(Customer &&theElement, BinaryNode *lt, BinaryNode *rt)
        : element{std::move(theElement)}, left{lt}, right{rt} {}
};

class BinarySearchTree
{
private:
    BinaryNode *root;

    void insert(Customer x, BinaryNode *&t)
    {
        if (t == nullptr)
            t = new BinaryNode{x, nullptr, nullptr};
        else if (x.getID() < t->element.getID())
            insert(x, t->left);
        else if (t->element.getID() < x.getID())
            insert(x, t->right);
        else
            ; // Duplicate; do nothing
    }
    void remov(Customer x, BinaryNode *&t)
    {
        if (t == nullptr)
            return; // Item not found; do nothing
        if (x.getID() < t->element.getID())
            remov(x, t->left);
        else if (t->element.getID() < x.getID())
            remov(x, t->right);
        else if (t->left != nullptr && t->right != nullptr) // Two children
        {
            t->element = findMin(t->right)->element;
            remov(t->element, t->right);
        }
        else
        {
            BinaryNode *oldNode = t;
            t = (t->left != nullptr) ? t->left : t->right;
            delete oldNode;
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

public:
    BinarySearchTree() : root{nullptr}
    {
    }

    // get root
    BinaryNode *getroot()
    {
        return root;
    }

    BinarySearchTree(BinarySearchTree &rhs) : root{rhs.root}
    {
        rhs.root = nullptr;
    }

    ~BinarySearchTree()
    {
        makeEmpty();
    }
    void print(BinaryNode *root)
    {
        if (root == nullptr)
        {
            return;
        }
        print(root->left);
        root->element.print();
        print(root->right);
    }
    BinarySearchTree operator=(BinarySearchTree rhs)
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
};

#endif

