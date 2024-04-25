# Prelab10

1. How does heapsort work? Explain your answer and then use pseudocode to illustrate the
solution.

Heap sort is a comparison-based sorting algorithm that uses the properties of a binary heap to sort an array in ascending order. The algorithm builds a heap from the input array, then repeatedly extracts the maximum element from the heap and places it at the end of the array until the heap is empty. Finally, the sorted array is obtained by reversing the order of the elements at the end of the array.

First convert the array into heap data structure using heapify function.
Delete the root node of the Max-heap and replace it with the last node in the heap and then use the heapify function on the end of the root of the heap. 
Repeat this process until the size of heap is greater than 1.

Build a heap from the given array.
Repeat the following steps until the heap contains one element:
Swap the root element of the heap with the last element.
Remove the last element of the heap.
Heapify the remaining elements of the heap.
The sorted array is obtained by reversing the order of the elements in the input array.


2. What is a leftist heap? Show an example.
A leftist tree is a type of binary tree-based data structure used to
 implement priority queues. It maintains a property where the "leftist" subtree of any node is always 
 at least as tall as the right subtree.
 The priority of the node is determined by its key value, and the node with the smallest key value is 
 designated as the root node.

Leftist trees allow merge operation, which allows two trees to be combined while maintaining the leftist property.The 
    tree with the smaller root value is merged into the tree with the larger root value.
    Insertion and deletion operations in leftist trees involve maintaining the leftist property and possibly 
    performing merge operations to maintain balance.

An example is shown below:

![alt text](leftist_heap1.jpg)
