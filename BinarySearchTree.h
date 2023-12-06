
#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H

#include <algorithm>
#include "Customer.h"
#include "dsexceptions.h"
using namespace std;

// BinarySearchTree class
//
// CONSTRUCTION: zero parameter
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

// template <typename Customer>
class BinarySearchTree
{
public:
    BinarySearchTree() : root{nullptr}
    {
    }

    BinarySearchTree(BinarySearchTree &&rhs) : root{rhs.root}
    {
        rhs.root = nullptr;
    }

    ~BinarySearchTree()
    {
        makeEmpty();
    }

    BinarySearchTree &operator=(BinarySearchTree &&rhs)
    {
        std::swap(root, rhs.root);
        return *this;
    }

    const Customer &findMin() const
    {
        if (isEmpty())
            throw UnderflowException{};
        return findMin(root)->element;
    }

    Customer findMax() const
    {
        if (isEmpty())
            throw UnderflowException{};
        return findMax(root);
    }

    bool contains(const Customer &x) const
    {
        return contains(x, root);
    }

    bool isEmpty() const
    {
        return root == nullptr;
    }

    void makeEmpty()
    {
        makeEmpty(root);
    }

    void insert(const Customer &x)
    {
        insert(x, root);
    }

    void remove(const Customer &x)
    {
        remove(x, root);
    }

private:
    struct BinaryNode
    {
        Customer element;
        BinaryNode *left;
        BinaryNode *right;

        BinaryNode(const Customer &theElement, BinaryNode *lt, BinaryNode *rt)
            : element{theElement}, left{lt}, right{rt} {}

        BinaryNode(Customer &&theElement, BinaryNode *lt, BinaryNode *rt)
            : element{std::move(theElement)}, left{lt}, right{rt} {}
    };

    BinaryNode *root;

    void insert(const Customer& x, BinaryNode *&t)
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

    void remove(const Customer &x, BinaryNode *&t)
    {
        if (t == nullptr)
            return; // Item not found; do nothing
        if (x.getID() < t->element.getID())
            remove(x, t->left);
        else if (t->element.getID() < x.getID())
            remove(x, t->right);
        else if (t->left != nullptr && t->right != nullptr) // Two children
        {
            t->element = findMin(t->right)->element;
            remove(t->element, t->right);
        }
        else
        {
            BinaryNode *oldNode = t;
            t = (t->left != nullptr) ? t->left : t->right;
            delete oldNode;
        }
    }


    BinaryNode *findMin(BinaryNode *t) const
    {
        if (t == nullptr)
            return nullptr;
        if (t->left == nullptr)
            return t;
        return findMin(t->left);
    }

    Customer findMax(BinaryNode *t) const
    {
        if (t != nullptr)
            while (t->right != nullptr)
                t = t->right;
        return t->element;
    }

    bool contains(const Customer &x, BinaryNode *t) const
    {
        if (t == nullptr)
            return false;
        else if (x.getID() < t->element.getID())
            return contains(x, t->left);
        else if (t->element.getID() < x.getID())
            return contains(x, t->right);
        else
            return true;
    }
    void makeEmpty(BinaryNode *&t)
    {
        if (t != nullptr)
        {
            makeEmpty(t->left);
            makeEmpty(t->right);
            delete t;
        }
        t = nullptr;
    }
};

#endif
