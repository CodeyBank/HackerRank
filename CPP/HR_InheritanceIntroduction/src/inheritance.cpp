/*****************************************************************//**
 * \file   inheritance.cpp
 * \brief  Challenge on classes and inheritance. Difficulty - Easy
 * 
 * \author HP
 * \date   September 2023
 *********************************************************************/

#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;


class Triangle
{
public:
    void triangle()
    {
        cout << "I am a triangle\n";
    }
};

class Isosceles : public Triangle
{
public:
    void isosceles()
    {
        cout << "I am an isosceles triangle\n";
    }
    //Write your code here.
    void description(void)
    {
        cout << "In an isosceles triangle two sides are equal" << endl;
    }
};

int main()
{
    Isosceles isc;
    isc.isosceles();
    isc.description();
    isc.triangle();
    return 0;
}
