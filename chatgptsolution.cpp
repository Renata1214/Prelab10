#include <algorithm> // std::swap
#include "heap.h"

using std::swap;


   void HeapNode::push(int x)
{
    if (empty()) {
        val = x;
        return;
    }

    if (!left) {
        left = new HeapNode(x);
    } else if (!right) {
        right = new HeapNode(x);
    } else {
        // Determine where to insert the new node based on the size of the subtrees
        if (left->size <= right->size) {
            left->push(x);
        } else {
            right->push(x);
        }
    }

    // Update the size of the subtree
    ++size;

    // Heapify after insertion to maintain the heap property
    heapify();
}

int HeapNode::pop()
{
    if (empty()) {
        throw "Heap is empty";
    }

    int poppedValue = val;

    if (!right && !left) {
        // If it's a leaf node, simply delete it
        delete this;
        return poppedValue;
    }

    if (!right || (left && left->size > right->size)) {
        // If there's no right child or left child has more nodes,
        // recursively pop from the left subtree
        val = left->pop();
    } else {
        // Otherwise, recursively pop from the right subtree
        val = right->pop();
    }

    // Heapify after popping to maintain the heap property
    heapify();

    return poppedValue;
}

void HeapNode::heapify()
{
    // If either child violates the heap property, swap with the child that violates it
    if (left && left->val < val) {
        swap(val, left->val);
        left->heapify();
    }
    if (right && right->val < val) {
        swap(val, right->val);
        right->heapify();
    }
}

