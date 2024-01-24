#include "PmergeMe.hpp"

// // 비교 함수 정의
// bool Compare(int a, int b) {
//     return a < b;
// }

// // 정렬 함수
// void SortNumbers(std::vector<int>& numbers) {
//     // Compare 함수를 이용하여 정렬
//     std::sort(numbers.begin(), numbers.end(), Compare);
// }

int main(int argc, char *argv[])
{
    PmergeMe p;

    try {
        p.Sort(argc, argv);   
    } catch(const std::exception& e) {
		std::cerr << e.what() << std::endl;
    }

    // PmergeMe::PmergeVector vec;
    // std::vector<int> numbers = vec.ParseArgv(argc, argv);
    // SortNumbers(numbers);

    // // 정렬 후 출력
    // std::cout << "After: ";
    // for (size_t i = 0; i < numbers.size(); ++i) {
    //     std::cout << numbers[i] << " ";
    // }

    return 0;
}