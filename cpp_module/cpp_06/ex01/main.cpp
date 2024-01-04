#include "Serializer.hpp"

int main()
{
    Data data;
    data.str = "jimpark";

    Data *originPtr = &data;
    Data *changePtr = Serializer::deserialize(Serializer::serialize(&data));

    std::cout << "originPtr: " << originPtr->str << std::endl;
    std::cout << "changePtr: " << changePtr->str << std::endl;
}