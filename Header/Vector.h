#pragma once
#include <iostream>

template <typename T> class Vector {
	T* data_array = nullptr;
	int capacity;
	int current_ammount;
public:
	Vector();
	~Vector();

	void push(T data);
	void pop();
	void remove(int id);

	T get(int index);
	int size();
	int getCapacity();
	int getLen();

	T* begin();
	T* end();

	void print();

	T& operator [] (int index);
};

template<typename T>
inline Vector<T>::Vector()
{
	data_array = new T[1];
	capacity = 1;
	current_ammount = 0;
}

template<typename T>
inline Vector<T>::~Vector()
{
	delete[] data_array;
	data_array = nullptr;
}

//dodawanie rzeczy na koniec vektora
template<typename T>
inline void Vector<T>::push(T data)
{
	//gdy brakuje miejsca w tablicy to zwiêkszamy jej rozmiar
	if (current_ammount == capacity) {
		T* tmp = new T[2 * capacity];
		for (int i = 0; i < capacity; i++)
			tmp[i] = data_array[i];
		delete[] data_array;
		capacity *= 2;
		data_array = tmp;
	}
	data_array[current_ammount] = data;
	current_ammount++;
}

template<typename T>
inline void Vector<T>::pop()
{
	current_ammount--;
}

template<typename T>
inline void Vector<T>::remove(int id)
{
	// usuwa element i na jego miejsce wstawia ostatni
	if (id >= current_ammount)return;
	current_ammount--;
	data_array[id] = data_array[current_ammount];
}

template<typename T>
inline T Vector<T>::get(int index)
{
	if (index < current_ammount)
		return data_array[index];
	return data_array[0];
}

template<typename T>
inline int Vector<T>::size()
{
	return current_ammount;
}

template<typename T>
inline int Vector<T>::getCapacity()
{
	return capacity;
}

template<typename T>
inline int Vector<T>::getLen()
{
	return current_ammount;
}


// begin() oraz end() s¹ potrzebne do for(T a: obj)
template<typename T>
inline T* Vector<T>::begin()
{
	return &data_array[0];
}

template<typename T>
inline T* Vector<T>::end()
{
	return &data_array[current_ammount];
}


template<typename T>
inline void Vector<T>::print()
{
	for (int i = 0; i < current_ammount; i++)
		std::cout << data_array[i];
}

template<typename T>
inline T& Vector<T>::operator[](int index)
{
	return data_array[index];
}

