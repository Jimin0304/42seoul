#include "Array.hpp"
#include <iostream>

// void leaks()
// {
//     system("leaks ex02");
// }

int main() 
{
    // atexit(leaks);
    try {
        std::cout << "------------- 기본 test -------------" << std::endl;
        Array<int> test1(3);
        test1[0] = 1;
        test1[1] = 2;
        test1[2] = 3;

        std::cout << "test1 size: " << test1.size() << std::endl;
        for (unsigned int i = 0; i < test1.size(); i++)
            std::cout << "test1[" << i << "]: " << test1[i] << std::endl;
        
        std::cout << "------------- 복사생성자 -------------" << std::endl;
        Array<int> test2(test1);
        std::cout << "test2 size: " << test2.size() << std::endl;
        for (unsigned int i = 0; i < test2.size(); i++)
            std::cout << "test2[" << i << "]: " << test2[i] << std::endl;

        test2[0] = 42;
        std::cout << "test1[0]: " << test1[0] << std::endl;
        std::cout << "test2[0]: " << test2[0] << std::endl;

        std::cout << "------------- 할당연산자 -------------" << std::endl;
        Array<int> test3;
        std::cout << "test3 size: " << test3.size() << std::endl;
        test3 = test1;
        std::cout << "test3 size: " << test3.size() << std::endl;
        for (unsigned int i = 0; i < test3.size(); i++)
            std::cout << "test3[" << i << "]: " << test3[i] << std::endl;

        test3[0] = 42;
        std::cout << "test1[0]: " << test1[0] << std::endl;
        std::cout << "test3[0]: " << test3[0] << std::endl;

        std::cout << "------------- Out of bound -------------" << std::endl;
        std::cout << "test1[-1]: " << test1[-1] << std::endl;

    } catch(const std::exception& e) {
		std::cerr << e.what() << std::endl;
    }
}
