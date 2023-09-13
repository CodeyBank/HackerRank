/*****************************************************************//**
 * \file   overloadedoperators.cpp
 * \brief  
 * You are given a main() function which takes a set of inputs to create 
 * two matrices and prints the result of their addition. You need to write
 *  the class Matrix which has a member a of type vector<vector<int> >.
 *  You also need to write a member function to overload the operator +. 
 * The function's job will be to add two objects of Matrix type and return
 *  the resultant Matrix.
 * 
 * \author HP
 * \date   September 2023
 *********************************************************************/
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

typedef vector<vector<int>> vec;
class Matrix
{
public:
    Matrix(){};
    ~Matrix(){};

    vec operator+(Matrix &rhs)
    {

    }

private:
    vec a;
};

