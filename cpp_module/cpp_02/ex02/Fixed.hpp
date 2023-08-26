#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <string>
# include <cmath>

class Fixed
{

	public:

		Fixed();
		Fixed( Fixed const & src );
		Fixed( const int num );
		Fixed( const float num );
		~Fixed();

		Fixed &operator=( Fixed const & rhs );

		int getRawBits( void ) const;
		void setRawBits( int const raw );
		float toFloat( void ) const;
		int toInt( void ) const;

		bool operator>( const Fixed &src ) const;
		bool operator<( const Fixed &src ) const;
		bool operator>=( const Fixed &src ) const;
		bool operator<=( const Fixed &src ) const;
		bool operator==( const Fixed &src ) const;
		bool operator!=( const Fixed &src ) const;

		Fixed operator+( const Fixed &src ) const;
		Fixed operator-( const Fixed &src ) const;
		Fixed operator/( const Fixed &src ) const;
		Fixed operator*( const Fixed &src ) const;

		Fixed &operator++( void );
		Fixed &operator--( void );
		const Fixed operator++( int );
		const Fixed operator--( int );

		static Fixed &min(Fixed &src1, Fixed &src2);
		static const Fixed &min(const Fixed &src1, const Fixed &src2);
		static Fixed &max(Fixed &src1, Fixed &src2);
		static const Fixed &max(const Fixed &src1, const Fixed &src2);

	private:

		int fixed_point;
		static const int fraction_bit = 8;

};

std::ostream &operator<<( std::ostream & o, Fixed const & i );

#endif