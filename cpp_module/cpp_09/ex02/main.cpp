#include "PmergeMe.hpp"

int main(int argc, char *argv[])
{
    PmergeMe p;

    try {
        p.Sort(argc, argv);   
    } catch(const std::exception& e) {
		  std::cerr << e.what() << std::endl;
    }

    return 0;
}