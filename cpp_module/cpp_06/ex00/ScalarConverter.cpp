// #include "ScalarConverter.hpp"

// ScalarConverter::ScalarConverter() {}

// ScalarConverter::ScalarConverter( const ScalarConverter & src ) { (void)src; }

// ScalarConverter::~ScalarConverter() {}

// ScalarConverter &				ScalarConverter::operator=( ScalarConverter const & rhs )
// {
// 	(void)rhs;
// 	return *this;
// }

// static int	findConvertType(const std::string& input)
// {
// 	bool indexDF = false;
// 	bool indexF = false;

// 	if (input.std::string::length() == 1 && !isdigit(input[0]))
// 		return (0);		// char
// 	if (input == "inff" || input == "-inff" || input == "+inff")
// 		return (5);		// float inff
// 	if (input == "inf" || input == "-inf" || input == "+inf")
// 		return (6);		// double inf
// 	if (input == "nan" || input == "nanf")
// 		return (4);
// 	for (size_t i = 0; i < input.std::string::length(); i++) {
// 		if (input[0] == '+' || input[0] == '-')
// 			continue;
// 		if (input[i] != '.' && input[i] != 'f' && !isdigit(input[i]))
// 			return (4);
// 		if (indexDF == true && input[i] == '.')
// 			return (4);
// 		if (indexDF == false && input[i] == 'f')
// 			return (4);
// 		if (indexF == true && input[i] == 'f')
// 			return (4);
// 		if (input[i] == '.')
// 			indexDF = true;
// 		if (input[i] == 'f')
// 			indexF = true;
// 	}
// 	if (indexDF == true && indexF == true)
// 		return (2);		// float
// 	else if (indexDF == true && indexF == false)
// 		return (3);		// double
// 	return (1);			// int
// }

// static void printChar(char value)
// {
// 	if (value > std::numeric_limits<char>::max() || value < std::numeric_limits<char>::min())	// char overflow
// 		std::cout << "char: impossible" << std::endl;
// 	else if (std::isprint(static_cast<int>(value)))
// 		std::cout << "char: '" << value << "'" << std::endl;
// 	else
// 		std::cout << "char: Non displayable" << std::endl;

// 	std::cout << "int: " << static_cast<int>(value) << std::endl;
// 	std::cout << "float: " << static_cast<float>(value) << std::endl;
// 	std::cout << "double: " << static_cast<double>(value) << std::endl;
// }

// static void printInt(const char* input)
// {
// 	int value = std::atoi(input);
	
// 	// char
// 	if (static_cast<char>(value) > std::numeric_limits<char>::max() || static_cast<char>(value) < std::numeric_limits<char>::min())	// char overflow
// 		std::cout << "char: impossible" << std::endl;
// 	else if (std::isprint(value))
// 		std::cout << "char: '" << static_cast<char>(value) << "'" << std::endl;
// 	else
// 		std::cout << "char: Non displayable" << std::endl;

// 	// int
// 	if (value > std::numeric_limits<int>::max() || value < std::numeric_limits<int>::min())	 // int overflow
// 		std::cout << "int: impossible" << std::endl;
// 	else
// 		std::cout << "int: " << value << std::endl;

// 	// float
// 	if (static_cast<float>(value) > std::numeric_limits<float>::max() || static_cast<float>(value) < std::numeric_limits<float>::min())	 // int overflow
// 		std::cout << "float: impossible" << std::endl;
// 	else {
// 		std::cout.precision(1);
//     	std::cout << std::fixed;
// 		std::cout << "float: " << static_cast<float>(value) << 'f' << std::endl;
// 	}

// 	// double
// 	if (static_cast<double>(value) > std::numeric_limits<double>::max() || static_cast<double>(value) < std::numeric_limits<double>::min())	 // int overflow
// 		std::cout << "double: impossible" << std::endl;
// 	else {
// 		std::cout.precision(1);
//     	std::cout << std::fixed;
// 		std::cout << "double: " << static_cast<double>(value) << std::endl;
// 	}
// }

// static void printFloat(const char* input)
// {
// 	float value = std::atof(input);

// 	// char
// 	if (static_cast<char>(value) > std::numeric_limits<char>::max() || static_cast<char>(value) < std::numeric_limits<char>::min())	// char overflow
// 		std::cout << "char: impossible" << std::endl;
// 	else if (std::isprint(value))
// 		std::cout << "char: '" << static_cast<char>(value) << "'" << std::endl;
// 	else
// 		std::cout << "char: Non displayable" << std::endl;

// 	// int
// 	if (static_cast<int>(value) > std::numeric_limits<int>::max() || static_cast<int>(value) < std::numeric_limits<int>::min())	 // int overflow
// 		std::cout << "int: impossible" << std::endl;
// 	else
// 		std::cout << "int: " << static_cast<int>(value) << std::endl;

// 	// float
// 	if (value > std::numeric_limits<float>::max() || value < std::numeric_limits<float>::min())	 // int overflow
// 		std::cout << "float: impossible" << std::endl;
// 	else {
// 		std::cout.precision(1);
//     	std::cout << std::fixed;
// 		std::cout << "float: " << value << 'f' << std::endl;
// 	}

// 	// double
// 	if (static_cast<double>(value) > std::numeric_limits<double>::max() || static_cast<double>(value) < std::numeric_limits<double>::min())	 // int overflow
// 		std::cout << "double: impossible" << std::endl;
// 	else {
// 		std::cout.precision(1);
//     	std::cout << std::fixed;
// 		std::cout << "double: " << static_cast<double>(value) << std::endl;
// 	}
// }

// static void printDouble(const char* input)
// {
// 	char* ptr = NULL;
// 	double value = std::strtod(input, &ptr);

// 	// char
// 	if (static_cast<char>(value) > std::numeric_limits<char>::max() || static_cast<char>(value) < std::numeric_limits<char>::min())	// char overflow
// 		std::cout << "char: impossible" << std::endl;
// 	else if (std::isprint(value))
// 		std::cout << "char: '" << static_cast<char>(value) << "'" << std::endl;
// 	else
// 		std::cout << "char: Non displayable" << std::endl;

// 	// int
// 	if (static_cast<int>(value) > std::numeric_limits<int>::max() || static_cast<int>(value) < std::numeric_limits<int>::min())	 // int overflow
// 		std::cout << "int: impossible" << std::endl;
// 	else
// 		std::cout << "int: " << static_cast<int>(value) << std::endl;

// 	// float
// 	if (static_cast<float>(value) > std::numeric_limits<float>::max() || static_cast<float>(value) < std::numeric_limits<float>::min())	 // int overflow
// 		std::cout << "float: impossible" << std::endl;
// 	else {
// 		std::cout.precision(1);
//     	std::cout << std::fixed;
// 		std::cout << "float: " << static_cast<float>(value) << 'f' << std::endl;
// 	}

// 	// double
// 	if (value > std::numeric_limits<double>::max() || value < std::numeric_limits<double>::min())	 // int overflow
// 		std::cout << "double: impossible" << std::endl;
// 	else {
// 		std::cout.precision(1);
//     	std::cout << std::fixed;
// 		std::cout << "double: " << value << std::endl;
// 	}
// }

// void ScalarConverter::convert(const std::string& input)
// {
// 	int type = findConvertType(input);

// 	if (type == 0)
// 		printChar(input[0]);
// 	else if (type == 1)
// 		printInt(input.c_str());
// 	else if (type == 2)
// 		printFloat(input.c_str());
// 	else if (type == 3)
// 		printDouble(input.c_str());
// 	else if (type == 4)
// 		throw ScalarConverter::NotANumber();
// 	else if (type == 5) {
// 		std::cout << "char: impossible" << std::endl;
// 		std::cout << "int: impossible" << std::endl;
// 		std::cout << "float: " << input << std::endl;
// 		std::cout << "double: " << input.substr(0, input.length() - 1) << std::endl;
// 	}
// 	else if (type == 6) {
// 		std::cout << "char: impossible" << std::endl;
// 		std::cout << "int: impossible" << std::endl;
// 		std::cout << "float: " << input << "f" << std::endl;
// 		std::cout << "double: " << input << std::endl;
// 	}
// }

// const char* ScalarConverter::NotANumber::what() const throw() 
// {
// 	return "char: impossible\nint: impossible\nfloat: nanf\ndouble: nan\n";
// }

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

static void printChar(double input)
{
	if (input > std::numeric_limits<char>::max() || input < std::numeric_limits<char>::min())
		std::cout << "char: impossible" << std::endl;
	else if (std::isprint(input))
		std::cout << "char: '" << static_cast<char>(input) << "'" << std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;
}

static void printInt(double input)
{
	if (input > std::numeric_limits<int>::max() || input < std::numeric_limits<int>::min())	// int overflow
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << static_cast<int>(input) << std::endl;
}

static void printFloat(double input)
{
	if (input > std::numeric_limits<float>::max() || input < std::numeric_limits<float>::min()) {	// float overflow
		std::cout << "float: " << input << 'f' << std::endl;
	}
	else {
		std::cout.precision(1);
    	std::cout << std::fixed;
		std::cout << "float: " << static_cast<float>(input) << 'f' << std::endl;
	}
}

static void printDouble(double input)
{
	if (input > std::numeric_limits<double>::max() || input < std::numeric_limits<double>::min())	// double overflow
		std::cout << "double: " << input << std::endl;
	else {
		std::cout.precision(1);
    	std::cout << std::fixed;
		std::cout << "double: " << input << std::endl;
	}
}

static void convertChar(char input)
{
	if (input > std::numeric_limits<char>::max() || input < std::numeric_limits<char>::min())
		std::cout << "char: impossible" << std::endl;
	else if (std::isprint(static_cast<int>(input)))
		std::cout << "char: '" << static_cast<char>(input) << "'" << std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;
	std::cout << "int: " << static_cast<int>(input) << std::endl;
	std::cout << "float: " << static_cast<float>(input) << ".0f" << std::endl;
	std::cout << "double: " << static_cast<double>(input) << ".0" << std::endl;
}

static void convertInt(const std::string& input)
{
	int	intType = std::atoi(input.c_str());
	char* ptr = NULL;
	double dvalue = std::strtod(input.c_str(), &ptr);
	std::stringstream ssDouble;
	ssDouble << input;

	if (dvalue > std::numeric_limits<int>::max() || dvalue < std::numeric_limits<int>::min()) {
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
	}
	else {
		printChar(intType);
		std::cout << "int: " << intType << std::endl;
	}
	if (dvalue != 0.0 && (dvalue > std::numeric_limits<float>::max() || dvalue < std::numeric_limits<float>::min()))
		std::cout << "float: " << dvalue << "f" << std::endl;
	else {
		if (ssDouble.str().size() > 6)
			std::cout << "float: " << static_cast<float>(dvalue) << "f" << std::endl;
		else
			std::cout << "float: " << static_cast<float>(dvalue) << ".0f" << std::endl;
	}
	/*
	float double 오버플로우 다시 보기
	*/
	if (dvalue != 0.0 && (ssDouble.str().size() > 6 || dvalue > std::numeric_limits<double>::max() || dvalue < std::numeric_limits<double>::min()))
		std::cout << "double: " << dvalue << std::endl;
	else
		std::cout << "double: " << dvalue << ".0" << std::endl;
}

static void convertFloat(const std::string& input)
{
	char* ptr = NULL;
	double dvalue = std::strtod(input.c_str(), &ptr);
	if (dvalue > std::numeric_limits<float>::max() || dvalue < std::numeric_limits<float>::min()) {	// float overflow
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: " << dvalue << std::endl;
	}
	else {
		printChar(dvalue);
		printInt(dvalue);
		printFloat(dvalue);
	}
	printDouble(dvalue);
}

static void convertDouble(const std::string& input)
{
	char* ptr = NULL;
	double dvalue = std::strtod(input.c_str(), &ptr);
	if (dvalue > std::numeric_limits<double>::max() || dvalue < std::numeric_limits<double>::min()) {	// double overflow
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: " << dvalue << std::endl;
		std::cout << "double: " << dvalue << std::endl;
	}
	else {
		printChar(dvalue);
		printInt(dvalue);
		printFloat(dvalue);
		printDouble(dvalue);
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
		case 5:
			std::cout << "char: impossible" << std::endl;
			std::cout << "int: impossible" << std::endl;
			std::cout << "float: " << input << std::endl;
			std::cout << "double: " << input.substr(0, input.length() - 1) << std::endl;
			break ;
		case 6:
			std::cout << "char: impossible" << std::endl;
			std::cout << "int: impossible" << std::endl;
			std::cout << "float: " << input << "f" << std::endl;
			std::cout << "double: " << input << std::endl;
			break ;
	}
}

const char* ScalarConverter::NotANumber::what() const throw() 
{
	return "char: impossible\nint: impossible\nfloat: nanf\ndouble: nan\n";
}
