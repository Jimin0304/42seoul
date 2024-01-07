#ifndef ITER_HPP
# define ITER_HPP

#include <iostream>

template <typename T, typename F>
void iter(T *address, std::size_t length, F f)
{
    for (std::size_t i = 0; i < length; i++) {
        f(address[i]);
    }
}

template <typename T>
void print(T &input)
{
    std::cout << input << std::endl;
}

template <typename T>
void increaseData(T &input)
{
    input++;
}

#endif