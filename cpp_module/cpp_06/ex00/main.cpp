#include "ScalarConverter.hpp"

int main(int argc, char* argv[])
{
    if (argc != 2)
    {
        std::cout << "Wrong argument: [실행파일] [scalar 값]" << std::endl;
        return (-1);
    }
    std::string str(argv[1]);
    ScalarConverter::convert(str);
    return (0);
}