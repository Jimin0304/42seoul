#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>
# include <string>
# include <stdexcept>

template <typename T>
class Array
{
	private:

		unsigned int size;
		T* array;

	public:

		Array() {
			size = 0;
			array = new T[0];
		}

		Array( unsigned int n ) {
			size = n;
			array = new T[n];
		}

		Array( Array const & src )
		~Array() {
			delete[] array;
		}

		Array &		operator=( Array const & rhs );
		T &	operator[]( unsigned int n );
		const T &	operator[]( unsigned int n ) const;
		
		unsigned int size() {
			return size;
		}

};

#endif