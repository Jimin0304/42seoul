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

		void ParseArgv(int argc, char *argv[]);
		int ValidateInput(std::string input);

	private:

		std::vector<int> _input;
		std::vector<std::pair<int. int>> _vectorPair;

};

#endif