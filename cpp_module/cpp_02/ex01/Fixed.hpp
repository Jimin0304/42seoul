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
		float 	toFloat( void ) const;
		int 	toInt( void ) const;

	private:

		int fixed_point;
		static const int fraction_bit = 8;

};

std::ostream &operator<<( std::ostream & o, Fixed const & i );

#endif