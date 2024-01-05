#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

# include "Data.hpp"

# include <iostream>
# include <string>
# include <stdint.h>

class Serializer
{

	public:

		static uintptr_t serialize(Data* ptr);
		static Data* deserialize(uintptr_t raw);

	private:

		Serializer();
		Serializer( Serializer const & src );
		~Serializer();

		Serializer &		operator=( Serializer const & rhs );

};

#endif