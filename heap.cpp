#include <algorithm> // std::swap
#include "heap.h"
#include <iostream>

using std::swap;
using namespace std;

void HeapNode::push(int x)
{
    bool leftside = true;
     HeapNode * temp = new HeapNode(x);
     HeapNode * side = left;

    if (left!=nullptr && right==nullptr)
        {
            side = right;
            leftside = false;
        }

    //Base Case -- One of the sides is pointing to nullptr
    if (side == nullptr)
    {
        side = temp;

        if(leftside)
        {
            left= side;
        }
        else
        {
            right = side;
        }
        heapify();
        return;
    }

    //None of the nodes is pointing to nullptr
    if (left->left == nullptr)
    {

        left->push(x);
    }
    else if (right->left ==nullptr)
    {
        right->push(x);
    }
    else if (left->right == nullptr)
    {
        left->push(x);
    }
    else if (right->right == nullptr)
    {
        right->push(x);
    }
    else 
    {
        if (left->size == right->size)
        {
                left->push(x);
        }
        else if (left->size > right->size)
        {
                right->push(x);
        }
    }
    size ++;
}

int HeapNode::pop()
{
    int popval = val;
    HeapNode * finalval = nullptr;
    HeapNode * traverse = this;
    HeapNode * previous = nullptr;
    bool leftside = true;

    // if (!left && !right) {
    //     // If it's a leaf node, simply delete it
    //     delete this;
    //     return popval;
    // }

    while (true)
    {
        if (traverse->left==nullptr)
        {
            break;
        }
        if(traverse->right==nullptr)
        {
            previous=traverse;
            traverse->size= traverse->size -1;
            traverse=traverse->left;
            leftside=true;
            continue;
        }
        if (traverse->right->size==traverse->left->size)
        { 
            previous=traverse;
            traverse->size= traverse->size -1;
            traverse= traverse->right;
            leftside=false;
            continue;
        }
        if(traverse->right->size < traverse->left->size)
        {
            previous=traverse;
            traverse->size= traverse->size -1;
            traverse= traverse->left;
            leftside=true;
            continue;
        }
        if(traverse->right->size > traverse->left->size)
        {
            std::cout << "There was an error because right size is bigger than left size subtree" << std::endl;
        }
        
    }

    finalval= traverse;
    swap(val,finalval->val);

    if (previous!=nullptr)
    {
        if(leftside)
        {
            previous->left= nullptr;
        }
        else
        {
            previous->right = nullptr;
        }
    }

    delete finalval;
    heapify();    
    return popval;
}

void HeapNode::heapify()
{
    if (right==nullptr && left==nullptr)
    {
        return;
    }
    if (left!=nullptr)
    {
        if (left->val < val)
        {
            swap (left->val, val);
            left->heapify();
        }
    }
    if (right !=nullptr)
    {
        if (right->val < val) 
        {
            
            swap(right->val, val);
            right->heapify();
        }
    }

    if (right!=nullptr && left!=nullptr)
    {
        if (right->val < left->val)
        {
            swap(right->val, left->val);
            right->heapify();
            left->heapify();
        }
    }
}
