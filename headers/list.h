#pragma once
#include <exception>
#include <stdio.h>
#include <string.h>


struct immutableException : public std::exception {
	const char* what() const throw () {
		return "Exception encountered while trying to modify List size: List size is immutable (you may have set bucketSize to 0?)";
	}
};



template <class T>
class List {
	int size;
	int maxSize;
	int bucketSize;
	T* arr;

public:

	int getSize() {
		return size;
	}
	int getMaxSize() {
		return maxSize;
	}

	List(int _maxSize = 1, int _bucketSize = 10, bool suppressWarning = false) :maxSize(_maxSize), bucketSize(_bucketSize) {
		if (!suppressWarning && _bucketSize == 0) std::cout << "WARNING: List's bucket size was set to 0. The List is immutable (List object at " << this << " )" << std::endl;
		arr = new T[_maxSize];
	};

	void swap(int pos0, int pos1) {
		if (pos0 < 0) {
			throw std::invalid_argument("In List::swap : pos0 argument is negative.");
		}
		if (pos0 > size) {
			throw std::out_of_range("In List::swap : list index out of range.");
		}
		if (pos1 < 0) {
			throw std::invalid_argument("In List::swap : pos1 argument is negative.");
		}
		if (pos1 > size) {
			throw std::out_of_range("In List::swap : list index out of range.");
		}
		std::swap(arr[pos0], arr[pos1]);
	}

	void insert(T* elem, int pos = 0) {
		if (pos < 0) {
			throw std::invalid_argument("In List::insert : pos argument is negative.");
		}
		if (pos > size) {
			throw std::out_of_range("In List::insert : list index out of range.");
		}
		if (bucketSize == 0) {
			throw immutableException();
		}
		if (size >= maxSize) {
			maxSize += bucketSize;
			T* alloc = new T[maxSize];
			memcpy(alloc, arr, sizeof(T) * size);
			T* tmp = arr;
			arr = alloc;
			delete[] tmp;
		}
		arr[size++] = *elem;
	}
	
	void pop(int pos) {
		if (pos < 0) {
			throw std::invalid_argument("In List::remove : pos argument is negative.");
		}
		if (pos >= size) {
			throw std::out_of_range("In List::remove : list index out of range.");
		}
		memcpy(arr + sizeof(T) * (pos - 1), arr + sizeof(T) * (pos + 1), sizeof(T) * (size - pos - 1));
			if (size < maxSize - bucketSize) {
				maxSize -= 10;
				T* alloc = new T[maxSize];
				memcpy(alloc, arr, sizeof(T) * maxSize);
				T* tmp = arr;
				arr = alloc;
				delete[] tmp;
			}
		size--;
	}

	T& operator[](int pos) {
		if (pos < 0) {
			throw std::invalid_argument("In List::[] : pos argument is negative.");
		}
		if (pos >= size) {
			throw std::out_of_range("In List::[] : list index out of range.");
		}
		return arr[pos];
	}

	/*int& operator[] const(int pos) {
		if (pos < 0) {
			throw std::invalid_argument("In List::[] : pos argument is negative.");
		}
		if (pos >= size) {
			throw std::out_of_range("In List::[] : list index out of range.");
		}
		return arr[pos];
	}*/

	int find(T elem) {
		for (int i = 0; i < size; i++) {
			if (elem == arr[i]) {
				return i;
			}
		}
		return -1;
	}

	void push_back(T* elem) {
		insert(elem, size);
	}
	void pop_back() {
		pop(size);
	}
	void insert(T elem, int pos) {
		insert(new T(elem), pos);
	}
	void push_back(T elem) {
		insert(new T(elem), size);
	}
};
