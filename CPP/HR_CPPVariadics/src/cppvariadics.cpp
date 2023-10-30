/*****************************************************************//**
 * \file   cppvariadics.cpp
 * \brief  
 * 
 * \author stanleyezeh
 * \date   October 2023
 *********************************************************************/

#include <iostream>
#include <string>
#include <sstream>
using namespace std;

template <bool... digits>
int reversed_binary_value()
{
    stringstream digits_str;
    std:string str;
    for (bool digit : {digits...})
    {
        digits_str<<(digit ? "1"s : "0"s);
    }
    str = digits_str.str();
    std::reverse(begin(str), end(str));
    return stoi(str);
}

template <int n, bool... digits>
struct CheckValues
{
    static void check(int x, int y)
    {
        CheckValues<n - 1, 0, digits...>::check(x, y);
        CheckValues<n - 1, 1, digits...>::check(x, y);
    }
};

template <bool... digits>
struct CheckValues<0, digits...>
{
    static void check(int x, int y)
    {
        int z = reversed_binary_value<digits...>();
        std::cout << (z + 64 * y == x);
    }
};

int main()
{
    int t;
    std::cin >> t;

    for (int i = 0; i != t; ++i)
    {
        int x, y;
        cin >> x >> y;
        CheckValues<6>::check(x, y);
        cout << "\n";
    }
}
