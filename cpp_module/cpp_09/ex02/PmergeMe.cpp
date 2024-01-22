#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}
PmergeMe::~PmergeMe() {}
PmergeMe::PmergeMe( const PmergeMe & src ) { (void)src; }
PmergeMe &				PmergeMe::operator=( PmergeMe const & rhs )
{
	if ( this == &rhs )
		return *this;
	return *this;
}

/* ---------------------------- Vector ---------------------------- */

PmergeMe::PmergeVector::PmergeVector(): _depth(1) {}
PmergeMe::PmergeVector::~PmergeVector() {}
PmergeMe::PmergeVector::PmergeVector( const PmergeVector & src ): _input(src._input), _vector(src._vector), _mainChain(src._mainChain), _leftNum(src._leftNum), _jacob(src._jacob), _depth(src._depth) {}
PmergeMe::PmergeVector &				PmergeMe::PmergeVector::operator=( PmergeVector const & rhs )
{
	if ( this != &rhs )
	{
		this->_depth = rhs._depth;
		this->_input = rhs._input;
		this->_vector = rhs._vector;
		this->_mainChain = rhs._mainChain;
		this->_leftNum = rhs._leftNum;
		this->_jacob = rhs._jacob;
	}
	return *this;
}

int PmergeMe::PmergeVector::getDepth() { return this->_depth; }
std::vector<int> PmergeMe::PmergeVector::getInput() { return this->_input; }
std::vector<int> PmergeMe::PmergeVector::getVector() { return this->_vector; }
std::vector<int> PmergeMe::PmergeVector::getMainChain() { return this->_mainChain; }

int PmergeMe::PmergeVector::ValidateInput(std::string input)
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

int PmergeMe::PmergeVector::Jacobsthal(int n)
{
    if (n == 0) return 1;
    if (n == 1) return 1;
    return Jacobsthal(n - 1) + 2 * Jacobsthal(n - 2);
}

void PmergeMe::PmergeVector::MakeJacobsthalArray(std::vector<int> input)
{
	int i, tmp, num, size = input.size();
	if (size % 2 == 0)
		num = size / 2;
	else
		num = size / 2 + 1;
	for (i = 1; (tmp = Jacobsthal(i)) <= num; i++)
	{
		_jacob.push_back(tmp);
	}
	_jacob.push_back(tmp);
}

void PmergeMe::PmergeVector::PrintContainer(std::vector<int> container)
{
	for (std::vector<int>::iterator it = container.begin(); it < container.end(); it++) {
		std::cout << *it << " ";
	}
	std::cout <<  std::endl;
}

std::vector<int> PmergeMe::PmergeVector::ParseArgv(int argc, char *argv[])
{
	if (argc <= 2)
		throw std::logic_error("invalid argument.");
	for (int i = 1; i < argc; i++) {
		std::string input(argv[i]);
		int value = ValidateInput(input);
		if(std::find(_input.begin(), _input.end(), value) != _input.end())	// 중복 검사
			throw std::logic_error("duplicate number.");
		_input.push_back(value);
	}
	return _input;
}

void PmergeMe::PmergeVector::PushBack(std::vector<int> &container, std::vector<int> &input, int index, int depth)
{
	while (depth)
	{
		container.push_back(input[index++]);
		--depth;
	}
}

void PmergeMe::PmergeVector::Merge(int depth)
{
	size_t index = 1 << depth;
	if (index < _input.size())
	{
		for (size_t i = 0; i < _input.size(); i += index)
		{
			if (i + index/2 < _input.size()) {
				if (_input[i] > _input[i + index/2]) {
					PushBack(_vector, _input, i, index/2);
					PushBack(_vector, _input, i + index/2, index/2);
				}
				else {
					PushBack(_vector, _input, i + index/2, index/2);
					PushBack(_vector, _input, i, index/2);
				}
			} 
			else {
				std::vector<int> tmp;
				PushBack(tmp, _input, i, index/2);
				_leftNum.push_back(tmp);
			}
		}
		_input.swap(_vector);
		_vector.clear();
		Merge(++_depth);
	}
	else {
		if (index > _input.size())
			--_depth;
	}
}

int PmergeMe::PmergeVector::BinarySearch(std::vector<int> mainChain, int target, int low, int high, int index)
{
	int mid;

	while (low <= high)
	{
		mid = low + (high - low) / 2;
		if (target == mainChain.at(mid * index))
			return (mid);

		if (target > mainChain.at(mid * index))
			low = mid + 1;
		else
			high = mid - 1;
	}
	if (target > mainChain.at(mid * index))
		return (mid + 1);
	else
		return (mid);
}

void PmergeMe::PmergeVector::InsertElements(std::vector<int> &mainChain, std::vector<int> &pendingElements, int index)
{
	int i, endPoint, size = pendingElements.size() / index;
	std::vector<int> tmp(mainChain);
	for(i = 0; size >= _jacob.at(i); i++)
	{
		if (_jacob[i] == 1)
		{
			for (int j = index - 1; j >= 0; j--)
				mainChain.insert(mainChain.begin(), pendingElements[j]);
		}
		else
		{
			for (int k = _jacob[i] - 1; k >= _jacob.at(i - 1); k--)
			{
				if (k * index >= static_cast<int>(tmp.size()))
					endPoint = mainChain.size() / index - 1;
				else {
					std::vector<int>::iterator it = std::find(mainChain.begin(), mainChain.end(), tmp.at(k * index));
					endPoint = std::distance(mainChain.begin(), it) / index - 1;
				}
				int pos = BinarySearch(mainChain, pendingElements.at(k * index), 0, endPoint, index);
				for (int j = ((k + 1) * index) - 1; j >= k * index; j--)
					mainChain.insert(mainChain.begin() + pos * index, pendingElements[j]);
			}
		}
	}
	// 야콥수열을 넘는 원소 처리
	for(int l = pendingElements.size() / index - 1; l >= _jacob.at(i - 1); l--)
	{
		int pos = BinarySearch(mainChain, pendingElements.at(l * index), 0, mainChain.size() / index - 1, index);
		for (int j = ((l + 1) * index) - 1; j >= l * index; j--)
			mainChain.insert(mainChain.begin() + pos * index, pendingElements[j]);
	}
}

void PmergeMe::PmergeVector::Insertion(std::vector<int> input, int depth)
{
	if (depth > 0)
	{
		size_t index = 1 << depth;
		size_t i;
		std::vector<int> mainChain, pendingElements;
		for (i = 0; i < input.size(); i += index)
		{
			if (input[i] > input[i + index/2]) {
				PushBack(mainChain, input, i, index/2);
				PushBack(pendingElements, input, i + index/2, index/2);
			}
			else {
				PushBack(mainChain, input, i + index/2, index/2);
				PushBack(pendingElements, input, i, index/2);
			}
		}
		if (!_leftNum.empty() && (_leftNum.back().size() == index/2)) {
			for (size_t i = 0; i < _leftNum.back().size(); i++) {
				pendingElements.push_back(_leftNum.back().at(i));
			}
			_leftNum.pop_back();
		}
		InsertElements(mainChain, pendingElements, index/2);
		Insertion(mainChain, --_depth);
	}
	else {
		_mainChain = input;
	}
}

/* ---------------------------- Deque ---------------------------- */

PmergeMe::PmergeDeque::PmergeDeque(): _depth(1) {}
PmergeMe::PmergeDeque::~PmergeDeque() {}
PmergeMe::PmergeDeque::PmergeDeque( const PmergeDeque & src ): _input(src._input), _deque(src._deque), _mainChain(src._mainChain), _leftNum(src._leftNum), _jacob(src._jacob), _depth(src._depth) {}
PmergeMe::PmergeDeque &				PmergeMe::PmergeDeque::operator=( PmergeDeque const & rhs )
{
	if ( this != &rhs )
	{
		this->_depth = rhs._depth;
		this->_input = rhs._input;
		this->_deque = rhs._deque;
		this->_mainChain = rhs._mainChain;
		this->_leftNum = rhs._leftNum;
		this->_jacob = rhs._jacob;
	}
	return *this;
}

int PmergeMe::PmergeDeque::getDepth() { return this->_depth; }
std::deque<int> PmergeMe::PmergeDeque::getInput() { return this->_input; }
std::deque<int> PmergeMe::PmergeDeque::getDeque() { return this->_deque; }
std::deque<int> PmergeMe::PmergeDeque::getMainChain() { return this->_mainChain; }

int PmergeMe::PmergeDeque::ValidateInput(std::string input)
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

int PmergeMe::PmergeDeque::Jacobsthal(int n)
{
    if (n == 0) return 1;
    if (n == 1) return 1;
    return Jacobsthal(n - 1) + 2 * Jacobsthal(n - 2);
}

void PmergeMe::PmergeDeque::MakeJacobsthalArray(std::deque<int> input)
{
	int i, tmp, num, size = input.size();
	if (size % 2 == 0)
		num = size / 2;
	else
		num = size / 2 + 1;
	for (i = 1; (tmp = Jacobsthal(i)) <= num; i++)
	{
		_jacob.push_back(tmp);
	}
	_jacob.push_back(tmp);
}

std::deque<int> PmergeMe::PmergeDeque::ParseArgv(int argc, char *argv[])
{
	if (argc <= 2)
		throw std::logic_error("invalid argument.");
	for (int i = 1; i < argc; i++) {
		std::string input(argv[i]);
		int value = ValidateInput(input);
		if(std::find(_input.begin(), _input.end(), value) != _input.end())	// 중복 검사
			throw std::logic_error("duplicate number.");
		_input.push_back(value);
	}
	return _input;
}

void PmergeMe::PmergeDeque::PushBack(std::deque<int> &container, std::deque<int> &input, int index, int depth)
{
	while (depth)
	{
		container.push_back(input[index++]);
		--depth;
	}
}

void PmergeMe::PmergeDeque::Merge(int depth)
{
	size_t index = 1 << depth;
	if (index < _input.size())
	{
		for (size_t i = 0; i < _input.size(); i += index)
		{
			if (i + index/2 < _input.size()) {
				if (_input[i] > _input[i + index/2]) {
					PushBack(_deque, _input, i, index/2);
					PushBack(_deque, _input, i + index/2, index/2);
				}
				else {
					PushBack(_deque, _input, i + index/2, index/2);
					PushBack(_deque, _input, i, index/2);
				}
			} 
			else {
				std::deque<int> tmp;
				PushBack(tmp, _input, i, index/2);
				_leftNum.push_back(tmp);
			}
		}
		_input.swap(_deque);
		_deque.clear();
		Merge(++_depth);
	} else {
		if (index > _input.size())
			--_depth;
	}
}

int PmergeMe::PmergeDeque::BinarySearch(std::deque<int> mainChain, int target, int low, int high, int index)
{
	int mid;

	while (low <= high)
	{
		mid = low + (high - low) / 2;
		if (target == mainChain.at(mid * index))
			return (mid);

		if (target > mainChain.at(mid * index))
			low = mid + 1;
		else
			high = mid - 1;
	}
	if (target > mainChain.at(mid * index))
		return (mid + 1);
	else
		return (mid);
}

void PmergeMe::PmergeDeque::InsertElements(std::deque<int> &mainChain, std::deque<int> &pendingElements, int index)
{
	int i, endPoint, size = pendingElements.size() / index;
	std::deque<int> tmp(mainChain);
	for(i = 0; size >= _jacob.at(i); i++)
	{
		if (_jacob[i] == 1)
		{
			for (int j = index - 1; j >= 0; j--)
				mainChain.insert(mainChain.begin(), pendingElements[j]);
		}
		else
		{
			for (int k = _jacob[i] - 1; k >= _jacob[i - 1]; k--)
			{
				if (k * index >= static_cast<int>(tmp.size()))
					endPoint = mainChain.size() / index - 1;
				else {
					std::deque<int>::iterator it = std::find(mainChain.begin(), mainChain.end(), tmp.at(k * index));
					endPoint = std::distance(mainChain.begin(), it) / index - 1;
				}
				int pos = BinarySearch(mainChain, pendingElements.at(k * index), 0, endPoint, index);
				for (int j = ((k + 1) * index) - 1; j >= k * index; j--)
					mainChain.insert(mainChain.begin() + pos * index, pendingElements[j]);
			}
		}
	}
	// 야콥수열을 넘는 원소 처리
	for(int l = pendingElements.size() / index - 1; l >= _jacob[i - 1]; l--)
	{
		int pos = BinarySearch(mainChain, pendingElements.at(l * index), 0, mainChain.size() / index - 1, index);
		for (int j = ((l + 1) * index) - 1; j >= l * index; j--)
			mainChain.insert(mainChain.begin() + pos * index, pendingElements[j]);
	}
}

void PmergeMe::PmergeDeque::Insertion(std::deque<int> input, int depth)
{
	if (depth > 0)
	{
		size_t index = 1 << depth;
		size_t i;
		std::deque<int> mainChain, pendingElements;
		for (i = 0; i < input.size(); i += index)
		{
			if (input[i] > input[i + index/2]) {
				PushBack(mainChain, input, i, index/2);
				PushBack(pendingElements, input, i + index/2, index/2);
			}
			else {
				PushBack(mainChain, input, i + index/2, index/2);
				PushBack(pendingElements, input, i, index/2);
			}
		}
		if (!_leftNum.empty() && (_leftNum.back().size() == index/2)) {
			for (size_t i = 0; i < _leftNum.back().size(); i++) {
				pendingElements.push_back(_leftNum.back().at(i));
			}
			_leftNum.pop_back();
		}
		InsertElements(mainChain, pendingElements, index/2);
		Insertion(mainChain, --_depth);
	}
	else {
		_mainChain = input;
	}
}

/* ---------------------------- sort ---------------------------- */

void PmergeMe::PrintTime(const int &size, const std::string &ct, const double &time)
{
	std::cout << std::fixed << "Time to process a range of " << size << " elements with std::" << ct << " : " << time << "s\n";
}

void PmergeMe::Sort(int argc, char *argv[])
{
	PmergeVector vec;
	PmergeDeque dq;
	clock_t start, end;

	try {
		/* ----------------------- vector ----------------------- */
		start = clock();
		
		std::vector<int> vecInput = vec.ParseArgv(argc, argv);
		
		vec.Merge(vec.getDepth());
		vec.MakeJacobsthalArray(vecInput);
		vec.Insertion(vec.getInput(), vec.getDepth());

		end = clock();

		std::cout << "Before: ";
		vec.PrintContainer(vecInput);

		std::cout << "After: ";
		vec.PrintContainer(vec.getMainChain());

		PrintTime(vec.getMainChain().size(), "vector", static_cast<double>(end - start) / CLOCKS_PER_SEC);

		/* ----------------------- deque ----------------------- */
		start = clock();
		
		std::deque<int> dqInput = dq.ParseArgv(argc, argv);
		dq.Merge(dq.getDepth());
		dq.MakeJacobsthalArray(dqInput);
		dq.Insertion(dq.getInput(), dq.getDepth());

		end = clock();
		PrintTime(dq.getMainChain().size(), "deque", static_cast<double>(end - start) / CLOCKS_PER_SEC);
	} catch(const std::exception& e) {
		std::cerr << "Error: " << e.what() << std::endl;
    }
}