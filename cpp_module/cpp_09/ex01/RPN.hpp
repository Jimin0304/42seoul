#ifndef RPN_HPP
# define RPN_HPP

#include <stack>
#include <cctype>
#include <iostream>

class RPN
{

	public:

		RPN();
		RPN( RPN const & src );
		~RPN();
		RPN &		operator=( RPN const & rhs );

		void RPNResult(std::string input);

	private:

		std::stack<int> stack;

};

#endif