#include "MVector.h"


template <typename T>
class MVector
{
private:
	T* m_arr = nullptr;
	int m_size;
	int m_capacity;
public:
	MVector();
	MVector(int capacity);
	MVector(std::initializer_list<T> list);
	~MVector();
	
	//delete 
	void pop_back();
	void erase(T* begin, T* end);
	void erase(T* index); 
	void erase(int indexBegin, int indexEnd);


	//iterators
	T* begin();
	T* end();
	
	//size
	int size()	   { return m_size; }
	int capacity() { return m_capacity; }
	bool is_empty() {return m_size == 0;}

	//add elements
	void push_back(T value);
	void emplace(int index, T value);
	


	T& operator[](int index);

private:
	void resize();
	int get_new_capacity();
};

template<typename T>
void MVector<T>::erase(T* begin, T* end)
{
	for (auto el = begin; el < end; el++) {
		if (this->begin() == begin) {
			*el = 0;
		}
 		for (auto element = begin; begin != end; begin++) {
			*element = 0;
		}
	}
}

template<typename T>
MVector<T>::~MVector()
{
}


template<typename T>
void MVector<T>::erase(T* index)
{
}

template<typename T>
void MVector<T>::erase(int indexBegin, int indexEnd)
{
	int delta = indexEnd - indexBegin;
	T* newArr = new T[m_size - delta];

	for (int i = indexBegin; i <= indexEnd; i++) {
		m_arr[i] = m_arr;
	}
}

template<typename T>
T* MVector<T>::begin() { return m_arr;}
template<typename T>
T* MVector<T>::end() { return m_arr + m_size-1;}

template<typename T>
void MVector<T>::pop_back()
{

}

template<typename T>
void MVector<T>::push_back(T value)
{
	if (this->m_size ==0 || this->m_size == this->m_capacity)
		resize();
	m_arr[m_size] = value;
	m_size++;
}


template<typename T>
void MVector<T>::emplace(int index, T value)
{
	if (index > size) {
		throw "out of range";
	}
	m_arr[index] = value;
}

template<typename T>
T& MVector<T>::operator[](int index)
{
	return *(m_arr + index);
}

	#pragma region realloc


template<typename T>
int MVector<T>::get_new_capacity()
{
	if (m_size == 0)
		return 1;

	return 2 * m_size;
}

template<typename T>
void MVector<T>::resize()
{
	m_capacity = get_new_capacity();
	T* newArray = new T[m_capacity];
	for (int i = 0; i < m_size; i++) {
		newArray[i] = m_arr[i];
	}
	delete m_arr;
	m_arr = newArray;
}

#pragma endregion


template<typename T>
MVector<T>::MVector(){}

template<typename T>
MVector<T>::MVector(int capacity) {
	this->m_arr[capacity] = new T();
	this->m_capacity = capacity;
}

template<typename T>
MVector<T>::MVector(std::initializer_list<T> list)
{
	this->m_arr = new T[list.size()];
	for (auto i = list.begin(); i!=list.end(); i++) {
		*m_arr = *i;
		m_arr++;
		m_size++;
	}
	m_arr -= list.size();
	this->m_capacity = list.size();
}
