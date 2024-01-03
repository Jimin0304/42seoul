#include "ScalarConverter.hpp"

int main(int argc, char* argv[])
{
    if (argc != 2)
    {
        std::cout << "Wrong argument: [실행파일] [scalar 값]" << std::endl;
        return (-1);
    }
    std::string str(argv[1]);
    try {
		ScalarConverter::convert(str);
	}
	catch(const std::exception& e) {
		std::cerr << e.what();
	}
std::cout << "float의 최소값: " << std::numeric_limits<float>::min() << std::endl;
    std::cout << "float의 최대값: " << std::numeric_limits<float>::max() << std::endl;

    // double의 최소값 및 최대값
    std::cout << "double의 최소값: " << std::numeric_limits<double>::min() << std::endl;
    std::cout << "double의 최대값: " << std::numeric_limits<double>::max() << std::endl;

    return (0);
}