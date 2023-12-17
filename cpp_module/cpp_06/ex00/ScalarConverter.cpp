#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter( const ScalarConverter & src ) { (void)src; }

ScalarConverter::~ScalarConverter() {}

ScalarConverter &				ScalarConverter::operator=( ScalarConverter const & rhs )
{
	(void)rhs;
	return *this;
}

static int	findConvertType(const std::string& input)
{
	size_t index;

	if (input.length() == 1 && !isdigit(input[0]))
		return (0);
	if (input == "inff" || input == "-inff" || input == "+inff" || input == "nanf")
		return (3);
	if (input == "inf" || input == "-inf" || input == "+inf" || input == "nan")
		return (4);
	index = input.std::string::find('.');
	if (index != std::string::npos)
	{
		index = input.std::string::find('f', index);
		if (index != std::string::npos)
			return (3);
		return (4);
	}
	return (2);
}

static void convertChar(char input)
{
	int intType = static_cast<int>(input);
	
	if (intType > std::numeric_limits<char>::max() || intType < std::numeric_limits<char>::min())
		std::cout << "char: impossible" << std::endl;
	else if (std::isprint(intType))
		std::cout << "char: '" << input << "'" << std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;
	
	std::cout << "int: " << intType << std::endl;
	std::cout << "float: " << static_cast<float>(input) << ".0f" << std::endl;
	std::cout << "double: " << static_cast<float>(input) << ".0" << std::endl;
}

void ScalarConverter::convert(const std::string& input)
{
	int type = findConvertType(input);

	switch(type) {
		case 0:
			convertChar(input[0]);
			break ;
		/*case 1:
			convertInt(input);
			break ;
		case 2:
			convertFloat(input);
			break ;
		case 3:
			convertDouble(input);
			break ;*/
		default:
			throw ScalarConverter::WrongType();
	}
}

const char* ScalarConverter::WrongType::what() const throw() 
{
	return "Wrong type...\n";
}