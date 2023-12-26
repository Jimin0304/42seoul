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
	bool indexDF = false;
	bool indexF = false;

	if (input.std::string::length() == 1 && !isdigit(input[0]))
		return (0);		// char
	if (input == "inff" || input == "-inff" || input == "+inff")
		return (5);		// float inff
	if (input == "inf" || input == "-inf" || input == "+inf")
		return (6);		// double inf
	if (input == "nan" || input == "nanf")
		return (4);
	for (size_t i = 0; i < input.std::string::length(); i++) {
		if (input[0] == '+' || input[0] == '-')
			continue;
		if (input[i] != '.' && input[i] != 'f' && !isdigit(input[i]))
			return (4);
		if (indexDF == true && input[i] == '.')
			return (4);
		if (indexDF == false && input[i] == 'f')
			return (4);
		if (indexF == true && input[i] == 'f')
			return (4);
		if (input[i] == '.')
			indexDF = true;
		if (input[i] == 'f')
			indexF = true;
	}
	if (indexDF == true && indexF == true)
		return (2);		// float
	else if (indexDF == true && indexF == false)
		return (3);		// double
	return (1);			// int
}

static void printChar(const char* input, int index)
{
	if (index == 0)
		const char* val = input;
	else if (index == 1)
		int val = std::atoi(input);
	else if (index == 2)
		float val = std::atof(input);
	else if (index == 3) {
		char* ptr = NULL;
		double val = std::strtod(input, &ptr);
	}
	
	if (static_cast<char>(val) > std::numeric_limits<char>::max() || static_cast<char>(val) < std::numeric_limits<char>::min())	// char overflow
		std::cout << "char: impossible" << std::endl;
	else if (std::isprint(static_cast<int>(val)))
		std::cout << "char: '" << static_cast<char>(val) << "'" << std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;
}

static void printInt(const char* input, int index)
{
	if (index == 0)
		const char* val = input;
	else if (index == 1)
		int val = std::atoi(input);
	else if (index == 2)
		float val = std::atof(input);
	else if (index == 3) {
		char* ptr = NULL;
		double val = std::strtod(input, &ptr);
	}

	if (static_cast<int>(val) > std::numeric_limits<int>::max() || static_cast<int>(val) < std::numeric_limits<int>::min())	// int overflow
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << static_cast<int>(val) << std::endl;
}

static void printFloat(const char* input, int index)
{
	if (index == 0)
		const char* val = input;
	else if (index == 1)
		int val = std::atoi(input);
	else if (index == 2)
		float val = std::atof(input);
	else if (index == 3) {
		char* ptr = NULL;
		double val = std::strtod(input, &ptr);
	}

	if (static_cast<float>(val) > std::numeric_limits<float>::max() || static_cast<float>(val) < std::numeric_limits<float>::min())	// float overflow
		std::cout << "float: impossible" << std::endl;
	else {
		std::cout.precision(1);
    	std::cout << std::fixed;
		std::cout << "float: " << static_cast<float>(val) << 'f' << std::endl;
	}
}

static void printDouble(const char* input, int index)
{
	if (index == 0)
		const char* val = input;
	else if (index == 1)
		int val = std::atoi(input);
	else if (index == 2)
		float val = std::atof(input);
	else if (index == 3) {
		char* ptr = NULL;
		double val = std::strtod(input, &ptr);
	}

	if (val > std::numeric_limits<double>::max() || val < std::numeric_limits<double>::min())	// double overflow
		std::cout << "double: impossible" << std::endl;
	else {
		std::cout.precision(1);
    	std::cout << std::fixed;
		std::cout << "double: " << static_cast<double>(val) << std::endl;
	}
}

void ScalarConverter::convert(const std::string& input)
{
	int type = findConvertType(input);

	if (type == 4)
		throw ScalarConverter::NotANumber();
	else if (type == 5) {
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: " << input << std::endl;
		std::cout << "double: " << input.substr(0, input.length() - 1) << std::endl;
		return ;
	}
	else if (type == 6) {
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: " << input << "f" << std::endl;
		std::cout << "double: " << input << std::endl;
		return ;
	}

	printChar(input.c_str(), type);
	printInt(input.c_str(), type);
	printFloat(input.c_str(), type);
	printDouble(input.c_str(), type);
}

const char* ScalarConverter::NotANumber::what() const throw() 
{
	return "char: impossible\nint: impossible\nfloat: nanf\ndouble: nan\n";
}