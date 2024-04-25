#include <algorithm> // std::swap
#include "heap.h"
#include <iostream>

using std::swap;
using namespace std;

HeapNode* HeapNode::Iterator::leftmost (HeapNode * node2)
{
    HeapNode * leftmost1;

    if(node2->left!=nullptr)
    {
        itstack.push(node2); //or iterator begin
        leftmost1 = node2->left;
        while(leftmost1->left!=nullptr)
        {
            itstack.push(leftmost1);
            leftmost1= leftmost1->left;
        }
        pointer=leftmost1;
    }
    return pointer;
}

HeapNode::Iterator::Iterator ()
{
    pointer=nullptr;
}

HeapNode::Iterator::Iterator(HeapNode *pointer1) {
    if (pointer1 == nullptr) {
        pointer = nullptr; // End iterator
    } else {
        pointer = leftmost(pointer1);
    }
}


HeapNode&  HeapNode::Iterator::operator*() const { return *pointer; }
HeapNode*  HeapNode::Iterator::operator->() { return pointer; }

// Prefix increment
HeapNode::Iterator& HeapNode::Iterator::operator++()
{ 
    HeapNode* run = pointer;
    //roots are still to be visited

    if(!(itstack.empty()))
    {
        if (run!=itstack.top())
        {
            run= itstack.top();
            pointer=run;
        }
        else 
        {
            HeapNode * save =itstack.top();
            itstack.pop();
            if(save->right!=nullptr)
            {
                run=leftmost(save->right);
            }
            else 
            {
                run=itstack.top();
            }
        }
        pointer=run;
    }

    else 
    {
        cout << "You have reached the end of the tree" << endl;
        pointer=nullptr;
    }

    //roots have already been visited

    return *this;
}  

// Postfix increment
// Iterator HeapNode::Iterator:operator++(int) 
// { 
//     Iterator tmp = *this; ++(*this);
//     return tmp;
// }

bool HeapNode::Iterator::operator== (const Iterator& b) { return pointer == b.pointer; };
bool HeapNode::Iterator::operator!= (const Iterator& b) { return pointer != b.pointer; };  


//ITERATOR BEGIN AND END FUNCTIONS
HeapNode::Iterator HeapNode::begin(){return Iterator(this);}

HeapNode::Iterator HeapNode::end() {
    return Iterator(nullptr); // Return an iterator with a null pointer to signify the end
}



void HeapNode::push(int x)
{
    bool leftside = true;
     HeapNode * temp = new HeapNode(x);
     HeapNode * side = left;

    //check to which side we will insert the node and set the variables of bool and side to the correct values
    if (left!=nullptr && right==nullptr)
        {
            side = right;
            leftside = false;
        }

    //Base Case -- One of the sides is pointing to nullptr
    if (side == nullptr)
    {
        //set the corresponding side node to the new node
        side = temp;

        //
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
    //check for the first node right and left if they have children
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
    //if they are balanced then decide which side to take based on the size
    else 
    {
        //if the sizes are equal go to the left size 
        if (left->size == right->size)
        {
                left->push(x);
        }
        //if the size of left is bigger than right push it right
        else if (left->size > right->size)
        {
                right->push(x);
        }
    }
    //increase the size
    size ++;
}

int HeapNode::pop()
{
    //set the val of pop to the node that is clalling it val
    int popval = val;
    HeapNode * finalval = nullptr;
    //tarverse and previous, set previous to nullptr initially
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
        //if the left node is empty that means the node is a leaf hence, break from the loop since you have found what is the last value
        if (traverse->left==nullptr)
        {
            break;
        }
        //
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
    //base condition
    if (right==nullptr && left==nullptr)
    {
        return;
    }

    //check for left
    if (left!=nullptr)
    {
        if (left->val < val)
        {
            swap (left->val, val);
            left->heapify();
        }
    }

    //check for right
    if (right !=nullptr)
    {
        if (right->val < val) 
        {
            
            swap(right->val, val);
            right->heapify();
        }
    }

    //check sideways if right and left are not equal to nullptr
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




// if(pointer->left!=nullptr)
//     {
//         pointer = pointer->left;
//         return pointer;
//     }
//     else if (!(itstack.empty()))
//     {
//         pointer = itstack.top();
//         itstack.pop();
//     }
   
//     pointer++; 
