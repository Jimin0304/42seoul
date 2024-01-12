#include "RPN.hpp"

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        std::cerr << "Error: invalid argument." << std::endl;
        return 1;
    }

    RPN rpn;
    std::string str(argv[1]);
    rpn.RPNResult(str);

    return 0;
}