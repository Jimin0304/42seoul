#include "Fixed.hpp"

Fixed::Fixed()
{
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
	*this = src;
}

Fixed::~Fixed() {}

Fixed &Fixed::operator=( Fixed const & rhs )
{
	if ( this != &rhs )
	{
		this->fixed_point = rhs.getRawBits();
	}
	return *this;
}

// 정수 -> 고정 소수점
Fixed::Fixed( const int num )
{
	this->fixed_point = num << this->fraction_bit;
}

// 실수 -> 고정 소수점
Fixed::Fixed( const float num )
{
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
	return ((float)this->fixed_point / (1 << this->fraction_bit));
}

bool Fixed::operator>( const Fixed &src ) const
{
	if (this->getRawBits() > src.getRawBits())
		return (true);
	else
		return (false);
}

bool Fixed::operator<( const Fixed &src ) const
{
	if (this->getRawBits() < src.getRawBits())
		return (true);
	else
		return (false);
}

bool Fixed::operator>=( const Fixed &src ) const
{
	if (this->getRawBits() >= src.getRawBits())
		return (true);
	else
		return (false);
}

bool Fixed::Fixed::operator<=( const Fixed &src ) const
{
	if (this->getRawBits() <= src.getRawBits())
		return (true);
	else
		return (false);
}

bool Fixed::operator==( const Fixed &src ) const
{
	if (this->getRawBits() == src.getRawBits())
		return (true);
	else
		return (false);
}

bool Fixed::operator!=( const Fixed &src ) const
{
	if (this->getRawBits() != src.getRawBits())
		return (true);
	else
		return (false);
}

Fixed Fixed::operator+( const Fixed &src ) const
{
	Fixed result(this->toFloat() + src.toFloat());
	return (result);
}

Fixed Fixed::operator-( const Fixed &src ) const
{
	Fixed result(this->toFloat() - src.toFloat());
	return (result);
}

Fixed Fixed::operator/( const Fixed &src ) const
{
	Fixed result(this->toFloat() / src.toFloat());
	return (result);
}

Fixed Fixed::operator*( const Fixed &src ) const
{
	Fixed result(this->toFloat() * src.toFloat());
	return (result);
}

Fixed &Fixed::operator++( void ) // 전위
{
	this->fixed_point++;
	return (*this);
}

Fixed &Fixed::operator--( void ) // 전위
{
	this->fixed_point--;
	return (*this);
}

const Fixed Fixed::operator++( int ) // 후위
{
	const Fixed result(*this);
	this->fixed_point++;
	return (result);
}

const Fixed Fixed::operator--( int ) // 후위
{
	const Fixed result(*this);
	this->fixed_point--;
	return (result);
}

Fixed &Fixed::min(Fixed &src1, Fixed &src2)
{
	if (src1 <= src2)
		return (src1);
	else
		return (src2);
}

const Fixed &Fixed::min(const Fixed &src1, const Fixed &src2)
{
	if (src1 <= src2)
		return (src1);
	else
		return (src2);
}

Fixed &Fixed::max(Fixed &src1, Fixed &src2)
{
	if (src1 >= src2)
		return (src1);
	else
		return (src2);	
}

const Fixed &Fixed::max(const Fixed &src1, const Fixed &src2)
{
	if (src1 >= src2)
		return (src1);
	else
		return (src2);
}

std::ostream &operator<<( std::ostream & o, Fixed const & i )
{
	o << i.toFloat();
	return o;
}