#include "easyfind.hpp"
#include <iostream>
#include <vector>
#include <deque>
#include <list>

int main(void)
{
	std::vector<int> v;
	std::deque<int> d;
	std::list<int> l;

	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
		d.push_back(i);
		l.push_back(i);
	}

	try
	{
		std::cout << *(easyfind(v, 5)) << " exists in the v" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		std::cout << *(easyfind(d, 0)) << " exists in the d" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		std::cout << *(easyfind(l, 10)) << " exists in the l" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	return (0);
}