#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}
PmergeMe::PmergeMe( const PmergeMe & src ): _vector(src._vector) {}
PmergeMe::~PmergeMe() {}
PmergeMe &				PmergeMe::operator=( PmergeMe const & rhs )
{
	if ( this != &rhs )
	{
		this->_vector = rhs._vector;
	}
	return *this;
}

int PmergeMe::ValidateInput(std::string input)
{
	// 숫자 외 다른 문자 있는지 확인 
	for (std::string::iterator it = input.begin(); it != input.end(); ++it) {
        if (!isdigit(*it)) 
			throw std::logic_error("failed to convert string to positive int.");
	}

	// overflow
	std::istringstream iss(input);
	double value;
	iss >> value;
	if (value > std::numeric_limits<int>::max())
		throw std::logic_error("too large a number.");

	return static_cast<int>(value);
}

void PmergeMe::ParseArgv(int argc, char *argv[])
{
	try {
		if (argc <= 2)
			throw std::logic_error("invalid argument.");
		for (int i = 1; i < argc; i++) {
			std::string input(argv[i]);
			int value = ValidateInput(input);
			if(std::find(_vector.begin(), _vector.end(), value) != _vector.end())	// 중복 검사
				throw std::logic_error("duplicate number.");
			_vector.push_back(value);
		}
	} catch(const std::exception& e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}
}

void PmergeMe::MISort()
{
	try {

	} catch(const std::exception& e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}
}