/*****************************************************************//**
 * \file   classenum.cpp
 * \brief  
 * 
 * \author Stanley Ezeh
 * \date   October 2023
 *********************************************************************/
#include <iostream>
#include <type_traits>
using namespace std;

enum class Fruit
{
    apple,
    orange,
    pear
};
enum class Color
{
    red,
    green,
    orange
};

template<typename T>
struct Trait
{
    static char* name(int index);
};


template <typename T>
char *Trait<T>::name(int index)
{
    char *retval = nullptr;
    if (is_same < T, Color>::value)
    {
        switch ((Color)index)
        {
        case Color::green:
            retval = "green";
            break;
        case Color::orange:
            retval = "orange";
            break;
        case Color::red:
            retval = "red";
            break;
        default:
            retval = "unknown";
            break;
        }
    }
    if (std::is_same < T, Fruit>::value)
    {
        switch (Fruit(index))
        {
        case Fruit::apple:
            retval = "apple";
            break;
        case Fruit::orange:
            retval = "orange";
            break;
        case Fruit::pear:
            retval = "pear";
            break;
        default:
            retval = "unknown";
            break;
        }
    }
    return retval;
}

int main(int argc, char **argv)
{
    cout << Trait<Color>::name(1) << " ";
    cout << Trait<Fruit>::name(1)<<endl;
    return 0;
}
