#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <exception>
#include <cstddef>

template <typename T>
class Array
{
private:
	T* _array;
	unsigned int _size;

public:
	Array();
	Array(unsigned int n);
	Array(Array const & src);
	~Array();

	Array& operator=(Array const & rhs);
	T& operator[](unsigned int index);
	T const & operator[](unsigned int index) const;

	unsigned int size() const;

	class OutOfBoundsException : public std::exception
	{
	public:
		virtual const char* what() const throw()
		{
			return "Index out of bounds";
		}
	};
};

template <typename T>
Array<T>::Array() : _array(NULL), _size(0)
{
}

template <typename T>
Array<T>::Array(unsigned int n) : _array(new T[n]()), _size(n)
{
}

template <typename T>
Array<T>::Array(Array const & src) : _array(NULL), _size(0)
{
	*this = src;
}

template <typename T>
Array<T>::~Array()
{
	if (_array)
		delete[] _array;
}

template <typename T>
Array<T>& Array<T>::operator=(Array const & rhs)
{
	if (this != &rhs)
	{
		if (_array)
			delete[] _array;

		_size = rhs._size;
		if (_size > 0)
		{
			_array = new T[_size];
			for (unsigned int i = 0; i < _size; i++)
				_array[i] = rhs._array[i];
		}
		else
			_array = NULL;
	}
	return *this;
}

template <typename T>
T& Array<T>::operator[](unsigned int index)
{
	if (index >= _size)
		throw OutOfBoundsException();
	return _array[index];
}

template <typename T>
T const & Array<T>::operator[](unsigned int index) const
{
	if (index >= _size)
		throw OutOfBoundsException();
	return _array[index];
}

template <typename T>
unsigned int Array<T>::size() const
{
	return _size;
}

#endif
