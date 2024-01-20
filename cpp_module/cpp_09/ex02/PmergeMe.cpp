#include "PmergeMe.hpp"

PmergeMe::PmergeMe(): _depth(1) {}
PmergeMe::PmergeMe( const PmergeMe & src ): _input(src._input), _vector(src._vector), _leftNum(src._leftNum), _depth(src._depth) {}
PmergeMe::~PmergeMe() {}
PmergeMe &				PmergeMe::operator=( PmergeMe const & rhs )
{
	if ( this != &rhs )
	{
		this->_input = rhs._input;
		this->_vector = rhs._vector;
		this->_leftNum = rhs._leftNum;
		this->_depth = rhs._depth;
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

int PmergeMe::jacobsthal(int n)
{
    if (n == 0) return 1;
    if (n == 1) return 1;
    return jacobsthal(n - 1) + 2 * jacobsthal(n - 2);
}

void PmergeMe::VectorParseArgv(int argc, char *argv[])
{
	try {
		if (argc <= 2)
			throw std::logic_error("invalid argument.");
		for (int i = 1; i < argc; i++) {
			std::string input(argv[i]);
			int value = ValidateInput(input);
			if(std::find(_input.begin(), _input.end(), value) != _input.end())	// 중복 검사
				throw std::logic_error("duplicate number.");
			_input.push_back(value);
		}
	} catch(const std::exception& e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}
}

void PmergeMe::VectorPushBack(std::vector<int> &container, int index, int depth)
{
	while (depth)
	{
		container.push_back(_input[index++]);
		--depth;
	}
}

void PmergeMe::VectorMerge(int depth)
{
	size_t index = 1 << depth;
	if (index < _input.size())
	{
		for (size_t i = 0; i < _input.size(); i += index)
		{
			if (i + index/2 < _input.size()) {
				if (_input[i] > _input[i + index/2]) {
					VectorPushBack(_vector, i, index/2);
					VectorPushBack(_vector, i + index/2, index/2);
				}
				else {
					VectorPushBack(_vector, i + index/2, index/2);
					VectorPushBack(_vector, i, index/2);
				}
			} 
			else {
				std::vector<int> tmp;
				VectorPushBack(tmp, i, index/2);
				_leftNum.push_back(tmp);
			}
		}
		_input.swap(_vector);
		_vector.clear();
		VectorMerge(++_depth);
	}
}

void Pmerge::VectorInsertElements(std::vector<int> mainChain, std::vector<int> pendingElements, int index)
{
	int pendingSize = pendingElements.size() / index;
	for(int i = 1; jacobsthal(i) < pendingSize; i++)
	{
		// TODO
	}

}

void PmergMe::VectorInsertion(int turn, int depth)
{
	size_t index = 1 << depth;
	std::vector<int> mainChain, pendingElements;
	for (size_t i = 0; i < _input.size(); i += index)
	{
		if (_input[i] < _input[i + index/2]) {
			VectorPushBack(mainChain, i, index/2);
			VectorPushBack(pendingElements, i + index/2, index/2);
		}
		else {
			VectorPushBack(mainChain, i + index/2, index/2);
			VectorPushBack(pendingElements, i, index/2);
		}
	}
	if (_leftNum.back().size() == index/2) {
		VectorPushBack(pendingElements, i, index/2);
		_leftNum.back().pop_back();
	}

}

void PmergeMe::VectorFordJohnson()
{
	VectorParseArgv(argc, argv);
	VectorMerge(_depth);
	VectorInsertion(1, _depth);
}