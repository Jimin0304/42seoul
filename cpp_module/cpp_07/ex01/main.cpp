#include "iter.hpp"

int main()
{
    int a[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    const int b[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    std::cout << "---------- a ----------" << std::endl;
    iter<int>(a, 10, print<int>);
    std::cout << "---------- b ----------" << std::endl;
    iter(b, 10, print<const int>);

    std::cout << "---------- a increasement ----------" << std::endl;
    iter(a, 10, increaseData<int>);
    iter(a, 10, print<int>);

}
