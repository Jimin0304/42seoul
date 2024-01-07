#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <stdexcept>

template <typename T>
class Array
{
	private:

		unsigned int len;
		T* array;

	public:

		Array( void );
		Array( unsigned int n );
		Array( Array const & src );
		Array &		operator=( Array const & rhs );
		~Array();

		class OutOfBound : public std::exception {
			public:
				virtual const char* what() const throw();
		};

		T &	operator[]( unsigned int n );
		const T &	operator[]( unsigned int n ) const;
		unsigned int size() const;

};

template <typename T>
Array<T>::Array(void): len(0), array(NULL) {}

template <typename T>
Array<T>::Array( unsigned int n ): len(n) {
	if (len == 0)
		array = NULL;
	else
		array = new T[n];
}

template <typename T>
Array<T>::Array( Array const & src ) {
	if (src.len == 0) {
		len = 0;
		array = NULL;
	}
	else {
		len = src.len;
		array = new T[len];
		for (unsigned int i = 0; i < len; i++)
			array[i] = src.array[i];
	}
}

template <typename T>
Array<T> &		Array<T>::operator=( Array const & rhs ) {
	if (this != &rhs) {
		delete[] array;
		if (rhs.len == 0) {
			len = 0;
			array = NULL;
		}
		else {
			len = rhs.len;
			array = new T[len];
			for (unsigned int i = 0; i < len; i++)
				array[i] = rhs.array[i];
		}

	}
	return *this;
}

template <typename T>
Array<T>::~Array() {
	if (len > 0)
		delete[] array;
}

template <typename T>
const char* Array<T>::OutOfBound::what() const throw() 
{
	return "Array index is out of bound";
}

template <typename T>
T &	Array<T>::operator[]( unsigned int n ) {
	if (n >= len)
		throw OutOfBound();
	return array[n];
}

template <typename T>
const T &	Array<T>::operator[]( unsigned int n ) const {
	if (n >= len)
		throw OutOfBound();
	return array[n];
}

template <typename T>		
unsigned int Array<T>::size() const {
	return len;
}

#endif