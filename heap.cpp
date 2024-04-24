#include <algorithm> // std::swap
#include "heap.h"

using std::swap;

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
        if (x>val)
        {
            side = temp;
            size ++;
        }
        else
        {
            side = temp;
            size ++;
        }

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
}

int HeapNode::pop()
{
    // int popval = val;

    // HeapNode * finalval = nullptr;
    // HeapNode * traverse = this;

    // while (traverse!=nullptr)
    // {
    //     if (traverse->left==nullptr)
    //     {
    //         break;
    //     }

    //     if(traverse->right==nullptr)
    //     {
    //         traverse=traverse->left;
    //         continue;
    //     }
    //     else
        


        
    // }


    return 0; //popval;
}

void HeapNode::heapify()
{
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
