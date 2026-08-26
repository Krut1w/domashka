#include "vector.hpp"

#include <iostream>

using kp::Vector;

template<typename T>
Vector<T>::Vector() {
	arr = new T[capacity];
}

template<typename T>
Vector<T>::~Vector() {
	delete[] arr;
	arr = nullptr;
	size = 0;
	capacity = START_CAPACITY;
}

template<typename T>
std::size_t Vector<T>::get_size() const noexcept {
	return size;
}

template<typename T>
bool Vector<T>::has_item(const T& value) const noexcept {
	for (std::size_t i = 0; i < size; i++) {
		if (arr[i] == value) {
			return true;
		}
	}
	return false;
}

template<typename T>
bool Vector<T>::insert(const std::size_t position, const T& value) {
	if (position > size) {
		return false;
	}
	if (size == capacity) {
		std::size_t new_capacity = capacity*2;
		T* new_arr = new T[new_capacity];
		for (std::size_t i = 0; i < position; i++) {
			new_arr[i] = arr[i];
		}
		for (std::size_t i = position + 1; i <= size; i++) {
			new_arr[i] = arr[i - 1];
		}
		arr = new_arr;
		capacity = new_capacity;
	} else {
		for (std::size_t i = 0; i <= size; i++) {
			arr[i] = arr[i-1];
		}
	}
	arr[position] = value;
	return true;
}

template<typename T>
void Vector<T>::print() const noexcept {
	for (std::size_t i = 0; i < size; i++) {
		std::cout << arr[i];
	}
}

template<typename T>
void Vector<T>::push_back(const T& value) {
	if (size == capacity) {
		std::size_t new_capacity = capacity * 2;
		T* new_arr = new T[new_capacity];
		for (std::size_t i = 0; i < size; i++) {
			new_arr[i] = arr[i];
		}
		delete[] arr;
		arr = new_arr;
		capacity = new_capacity;
	}
	arr[size] = value;
	size++;
}

template<typename T>
bool Vector<T>::remove_first(const T& value) {
	for (std::size_t i = 0; i < size; i++) {
		if (arr[i] == value) {
			size--;
			if (size < capacity/2) {	
				std::size_t new_capacity = capacity/2;
				T* new_arr = new T[new_capacity];
				for (std::size_t j = 0; j < i; j++) {
					new_arr[i] = arr[i];
				}
				for (std::size_t j = i+1; j <= size) {
					new_arr[j - 1] = arr[j];
				}
				delete[] arr;
				arr = new_arr;
				capacity = new_capacity;
				return true;
			} else {
				for (std::size_t j = i; j <= size; j++) {
					arr[j] = arr[j + 1];
				}
				return true;
		}
	}
	return false;
    }
}

template<typename T>
void Vector<T>::expand_by_one() {
	std::size_t new_capacity = capacity * 2;
	T* new_arr = new T[new_capacity];
	for (std::size_t i = 0; i < size; i++) {
		new_arr[i] = arr[i];
	}
	delete[] arr;
	arr = new_arr;
	capacity = new_capacity;
}