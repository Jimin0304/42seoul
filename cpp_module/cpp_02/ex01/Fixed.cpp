#include "Fixed.hpp"

Fixed::Fixed()
{
	std::cout << "Default constructor called" << std::endl;
	this->fixed_point = 0;
}

int Fixed::getRawBits( void ) const
{
	return (this->fixed_point);
}

void Fixed::setRawBits( int const raw )
{
	this->fixed_point = raw;
}

Fixed::Fixed( const Fixed & src )
{
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

Fixed &Fixed::operator=( Fixed const & rhs )
{
	std::cout << "Copy assignment operator called" << std::endl;
	if ( this != &rhs )
	{
		this->fixed_point = rhs.getRawBits();
	}
	return *this;
}

// 정수 -> 고정 소수점
Fixed::Fixed( const int num )
{
	std::cout << "Int constructor called" << std::endl;
	this->fixed_point = num << this->fraction_bit;
}

// 실수 -> 고정 소수점
Fixed::Fixed( const float num )
{
	std::cout << "Float constructor called" << std::endl;
	this->fixed_point = roundf( num * (1 << this->fraction_bit) );
}

// 고정 소수점 -> 정수
int Fixed::toInt( void ) const
{
	return (this->fixed_point >> this->fraction_bit);
}

// 고정 소수점 -> 부동 소수점
float Fixed::toFloat( void ) const
{
	return (static_cast<float>(this->fixed_point) / (1 << this->fraction_bit));
}

std::ostream &operator<<( std::ostream & o, Fixed const & i )
{
	o << i.toFloat();
	return o;
}