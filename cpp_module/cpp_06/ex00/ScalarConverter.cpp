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
	if (input == "inff" || input == "-inff" || input == "+inff" || input == "nanf")
		return (2);		// float
	if (input == "inf" || input == "-inf" || input == "+inf" || input == "nan")
		return (3);		// double
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

static void printChar(int input)
{
	if (input > std::numeric_limits<char>::max() || input < std::numeric_limits<char>::min())
		std::cout << "char: impossible" << std::endl;
	else if (std::isprint(input))
		std::cout << "char: '" << static_cast<char>(input) << "'" << std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;
}

static void printInt(int ivalue)
{
	if (ivalue > std::numeric_limits<int>::max() || ivalue < std::numeric_limits<int>::min())	// int overflow
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << ivalue << std::endl;
}

static void printFloat(const std::string& input)
{
	char* ptr = NULL;
	double dvalue = std::strtod(input.c_str(), &ptr);
	if (static_cast<float>(dvalue) > std::numeric_limits<float>::max() || static_cast<float>(dvalue) < std::numeric_limits<float>::min()) {	// float overflow
		std::cout << "float: impossible" << std::endl;
	}
	else {
		std::cout.precision(1);
    	std::cout << std::fixed;
		std::cout << "float: " << static_cast<float>(dvalue) << 'f' << std::endl;
	}
}

static void printDouble(const std::string& input)
{
	char* ptr = NULL;
	double dvalue = std::strtod(input.c_str(), &ptr);
	if (input == "inff" || input == "-inff" || input == "+inff")
	{
		std::cout << "double: " << input.substr(0, input.length() - 1) << std::endl;
	}
	else if (dvalue > std::numeric_limits<double>::max() || dvalue < std::numeric_limits<double>::min())	// double overflow
		std::cout << "double: impossible" << std::endl;
	else {
		std::cout.precision(1);
    	std::cout << std::fixed;
		std::cout << "double: " << dvalue << std::endl;
	}
}

static void convertChar(char input)
{
	int intType = static_cast<int>(input);
	
	printChar(intType);
	std::cout << "int: " << intType << std::endl;
	std::cout << "float: " << static_cast<float>(input) << ".0f" << std::endl;
	std::cout << "double: " << static_cast<double>(input) << ".0" << std::endl;
}

static void convertInt(const std::string& input)
{
	int	intType, len;
	const char* charInput = input.c_str();

	intType = std::atoi(charInput);
	printChar(intType);
	len = input.std::string::length();
	if (input[0] == '+' || input[0] == '-')
		len -= 1;
	if ((len > 10) || (len == 10 && intType < 0))	// int overflow
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << intType << std::endl;
	std::cout << "float: " << static_cast<float>(intType) << ".0f" << std::endl;
	std::cout << "double: " << static_cast<double>(intType) << ".0" << std::endl;
}

static void convertFloat(const std::string& input)
{
	if (input == "nanf")
		throw ScalarConverter::NotANumber();
	
	char* ptr = NULL;
	double dvalue = std::strtod(input.c_str(), &ptr);
	if (input == "inff" || input == "-inff" || input == "+inff")
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: " << input << std::endl;
	}
	else if (static_cast<float>(dvalue) > std::numeric_limits<float>::max() || static_cast<float>(dvalue) < std::numeric_limits<float>::min()) {	// float overflow
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: impossible" << std::endl;
	}
	else {
		printChar(static_cast<int>(dvalue));
		printInt(static_cast<int>(dvalue));
		printFloat(input);
	}
	printDouble(input);
}

static void convertDouble(const std::string& input)
{
	if (input == "nan")
		throw ScalarConverter::NotANumber();
	
	char* ptr = NULL;
	double dvalue = std::strtod(input.c_str(), &ptr);
	if (input == "inf" || input == "-inf" || input == "+inf")
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: " << input << "f" << std::endl;
		std::cout << "double: " << input << std::endl;
	}
	else if (dvalue > std::numeric_limits<double>::max() || dvalue < std::numeric_limits<double>::min()) {	// double overflow
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: impossible" << std::endl;
		std::cout << "double: impossible" << std::endl;
	}
	else {
		printChar(static_cast<int>(dvalue));
		printInt(static_cast<int>(dvalue));
		printFloat(input);
		printDouble(input);
	}
}

void ScalarConverter::convert(const std::string& input)
{
	int type = findConvertType(input);

	switch(type) {
		case 0:
			convertChar(input[0]);
			break ;
		case 1:
			convertInt(input);
			break ;
		case 2:
			convertFloat(input);
			break ;
		case 3:
			convertDouble(input);
			break ;
		case 4:
			throw ScalarConverter::NotANumber();
	}
}

const char* ScalarConverter::NotANumber::what() const throw() 
{
	return "char: impossible\nint: impossible\nfloat: nanf\ndouble: nan\n";
}