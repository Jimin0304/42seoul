#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <string>
# include <vector>
# include <sstream>
# include <algorithm>
# include <limits> 

class PmergeMe
{

	public:

		PmergeMe();
		PmergeMe( PmergeMe const & src );
		~PmergeMe();
		PmergeMe &		operator=( PmergeMe const & rhs );

		int ValidateInput(std::string input);
		int jacobsthal(int n);
		void VectorParseArgv(int argc, char *argv[]);
		void VectorFordJohnson();
		void VectorMerge(int depth);
		void VectorPushBack(std::vector<int> &container, int index, int depth);

	private:

		std::vector<int> _input;
		std::vector<int> _vector;
		std::vector<std::vector<int> > _leftNum;
		int _depth;

};

#endif