#include "MaxHeap.h"
#include <iostream>

// Driver program to test above functions.
int main() {
	// Assuming the maximum size of the heap to be 15.
	MaxHeap h(15);

	// Asking the user to input the keys:
	int k, i, n = 6, arr[10];
	std::cout << "Entered 6 keys:- 3, 10, 12, 8, 2, 14" << ENTER;
	h.insertKey(3);
	h.insertKey(10);
	h.insertKey(12);
	h.insertKey(8);
	h.insertKey(2);
	h.insertKey(14);

	// Printing the current size
	// of the heap.
	std::cout << "The current size of the heap is " << h.curSize() << ENTER;

	// Printing the root element which is
	// actually the maximum element.
	std::cout << "The current maximum element is " << h.getMax() << ENTER;

	// Deleting key at index 2.
	h.deleteKey(2);

	// Printing the size of the heap
	// after deletion.
	std::cout << "The current size of the heap is " << h.curSize() << ENTER;

	// Inserting 2 new keys into the heap.
	h.insertKey(15);
	h.insertKey(5);
	std::cout << "The current size of the heap is " << h.curSize() << ENTER;
	std::cout << "The current maximum element is " << h.getMax() << ENTER;

	return 0;
}