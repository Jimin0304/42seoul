#include "RPN.hpp"

RPN::RPN() {}
RPN::RPN( const RPN & src ): stack(src.stack) {}
RPN::~RPN() {}
RPN &				RPN::operator=( RPN const & rhs )
{
	if ( this != &rhs )
	{
		this->stack = rhs.stack;
	}
	return *this;
}

void RPN::RPNResult(std::string input)
{
	try {
		for (size_t i = 0; i < input.length(); i++)
		{
			if (input[i] == ' ')
				continue ;
			if (std::isdigit(input[i]))
				stack.push(input[i] - '0');
			else if (input[i] == '+' || input[i] == '-' || input[i] == '*' || input[i] == '/')
			{
				int firstNum, secondNum;
				if (stack.size() > 1) {
					firstNum = stack.top();
					stack.pop();
					secondNum = stack.top();
					stack.pop();
				} else {
					throw std::logic_error("Error: invalid expression.");
				}

				if (input[i] == '+')
					stack.push(firstNum + secondNum);
				else if (input[i] == '-')
					stack.push(firstNum - secondNum);
				else if (input[i] == '*')
					stack.push(firstNum * secondNum);
				else if (input[i] == '/') {
					if (secondNum == 0)
						throw std::logic_error("Error: cannot be divided by zero.");
					stack.push(firstNum / secondNum);
				}
			}
		}
		if (stack.size() > 1)
			throw std::logic_error("Error: invalid expression.");
	} catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}	
}