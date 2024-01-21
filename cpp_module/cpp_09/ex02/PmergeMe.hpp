#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <string>
# include <vector>
# include <sstream>
# include <algorithm>
# include <limits> 
# include <deque>
# include <ctime>

class PmergeMe
{

	public:

		PmergeMe();
		PmergeMe( PmergeMe const & src );
		~PmergeMe();
		PmergeMe &		operator=( PmergeMe const & rhs );

		void PrintTime(const int &size, const std::string &ct, const int &time);
		void Sort(int argc, char *argv[]);

		class PmergeVector
		{
			private:
				std::vector<int> _input;
				std::vector<int> _vector;
				std::vector<int> _mainChain;
				std::vector<std::vector<int> > _leftNum;
				int _depth;

			public:
				PmergeVector();
				~PmergeVector();
				int getDepth();
				std::vector<int> getInput();
				std::vector<int> getVector();
				std::vector<int> getMainChain();
				int ValidateInput(std::string input);
				int jacobsthal(int n);
				void PrintContainer(std::vector<int> container);
				void ParseArgv(int argc, char *argv[]);
				void Merge(int depth);
				void PushBack(std::vector<int> &container, std::vector<int> &input, int index, int depth);
				int BinarySearch(std::vector<int> array, int target, int low, int high, int index);
				void InsertElements(std::vector<int> &mainChain, std::vector<int> &pendingElements, int index);
				void Insertion(std::vector<int> input, int depth);
		};

		class PmergeDeque
		{
			private:
				std::deque<int> _input;
				std::deque<int> _deque;
				std::deque<int> _mainChain;
				std::deque<std::deque<int> > _leftNum;
				int _depth;

			public:
				PmergeDeque();
				~PmergeDeque();
				int getDepth();
				std::deque<int> getInput();
				std::deque<int> getDeque();
				std::deque<int> getMainChain();
				int ValidateInput(std::string input);
				int jacobsthal(int n);
				void ParseArgv(int argc, char *argv[]);
				void Merge(int depth);
				void PushBack(std::deque<int> &container, std::deque<int> &input, int index, int depth);
				int BinarySearch(std::deque<int> array, int target, int low, int high, int index);
				void InsertElements(std::deque<int> &mainChain, std::deque<int> &pendingElements, int index);
				void Insertion(std::deque<int> input, int depth);
		};

	private:

};

#endif