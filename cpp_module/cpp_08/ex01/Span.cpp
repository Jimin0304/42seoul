#include "Span.hpp"

Span::Span() {}

Span::Span( std::size_t N )
{
	_vector.reserve(N);
}

Span::Span( const Span & src ): _vector(src._vector) {}

Span::~Span() {}

Span &				Span::operator=( Span const & rhs )
{
	if ( this != &rhs )
	{
		_vector = rhs._vector;
	}
	return *this;
}

void Span::addNumber(int n)
{
	if (_vector.size() == _vector.capacity())
		throw NotEnoughCapacity();
	_vector.push_back(n);
}

std::size_t Span::shortestSpan() const
{
	if (_vector.size() <= 1)
		throw NotEnoughStoredNum();
	std::vector<int> tmp = _vector;
	std::sort(tmp.begin(), tmp.end());
	int min = tmp.at(1) - tmp.at(0);
	for (std::size_t i = 2; i < _vector.size(); i++) {
		if (tmp.at(i) - tmp.at(i - 1) < min)
			min = tmp.at(i) - tmp.at(i - 1);
	}
	return static_cast<std::size_t>(min);
}

std::size_t Span::longestSpan() const
{
	if (_vector.size() <= 1)
		throw NotEnoughStoredNum();
	int max = *max_element(_vector.begin(), _vector.end());
	int min = *min_element(_vector.begin(), _vector.end());
	return static_cast<std::size_t>(max - min);
}

const char* Span::NotEnoughCapacity::what() const throw() 
{
	return "Can't add number. Not enough capacity.\n";
}

const char* Span::NotEnoughStoredNum::what() const throw() 
{
	return "Can't show result. Not enough Stored Number.\n";
}