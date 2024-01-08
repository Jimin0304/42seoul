#ifndef SPAN_HPP
# define SPAN_HPP

#include <algorithm>
#include <cstddef>
#include <vector>

class Span
{

	public:

		Span();
		Span( std::size_t N );
		Span( Span const & src );
		~Span();
		Span &		operator=( Span const & rhs );

		void addNumber(int n);
		std::size_t shortestSpan() const;
		std::size_t longestSpan() const;

		template <typename T>
		void addManyNumbers(T &container)
		{
			if (container.size() > (_vector.capacity() - _vector.size()))
				throw NotEnoughCapacity();
			
			typename T::iterator iter = container.begin();
			while (iter != container.end()) {
				_vector.push_back(*iter);
				iter++;
			}
		}

		class NotEnoughCapacity : public std::exception {
			public:
				virtual const char* what() const throw();
		};
		
		class NotEnoughStoredNum : public std::exception {
			public:
				virtual const char* what() const throw();
		};

	private:

		std::vector<int> _vector;


};

#endif