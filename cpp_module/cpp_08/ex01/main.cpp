#include "Span.hpp"
#include <iostream>

int main()
{
    try {
        std::cout << "--------------------- Subject Test ---------------------" << std::endl;
        Span sp = Span(5);
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);
        std::cout << "sp shortest span: " << sp.shortestSpan() << std::endl;
        std::cout <<"sp longest span: " <<  sp.longestSpan() << std::endl << std::endl;

        std::cout << "--------------------- Capacity Test ---------------------" << std::endl;
        sp.addNumber(42);

    } catch(const std::exception& e) {
		std::cerr << e.what() << std::endl;
    }

    try {
        std::cout << "--------------------- Not Enough Num Test - short ---------------------" << std::endl;
        Span sp1 = Span(5);
        std::cout << sp1.shortestSpan() << std::endl;

    } catch(const std::exception& e) {
		std::cerr << e.what() << std::endl;
    }

    try {
        std::cout << "--------------------- Not Enough Num Test - long ---------------------" << std::endl;
        Span sp2 = Span(5);
        sp2.addNumber(0);
        std::cout << sp2.longestSpan() << std::endl;

    } catch(const std::exception& e) {
		std::cerr << e.what() << std::endl;
    }

    try {
        std::cout << "--------------------- Add Many Num Test ---------------------" << std::endl;
        Span sp3 = Span(10000);
        std::vector<int> v;
        for (int num = 0; num < 8000; ++num) {
            v.push_back(num);
        }
        sp3.addManyNumbers(v);

        std::cout << "sp3 shortest span: " << sp3.shortestSpan() << std::endl;
        std::cout << "sp3 longest span: " << sp3.longestSpan() << std::endl << std::endl;

        std::cout << "--------------------- Add Many Num Capacity Test ---------------------" << std::endl;
        sp3.addManyNumbers(v);
                
    } catch(const std::exception& e) {
		std::cerr << e.what() << std::endl;
    }

    return 0;
}