#ifndef MURACH_HEAPARRAY_H
#define MURACH_HEAPARRAY_H

#include <iostream>

class HeapArray {
private:
	int array_size;
	int* arr = nullptr;

public:
	// constructor
	HeapArray(const int);

	// destructor
	~HeapArray();

	// subscript operator 
	int& operator[] (int i);

	// Member functions
	int size() const;
	int* begin();
	int* end();

	HeapArray(const HeapArray &toCopy);
	HeapArray& operator= (const HeapArray &toCopy);
};

#endif /* MURACH_HEAPARRAY_H */
