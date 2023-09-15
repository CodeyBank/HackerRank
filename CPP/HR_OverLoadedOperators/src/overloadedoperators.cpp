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
#include <assert.h>
using namespace std;

typedef vector<vector<int>> vec;
class Matrix
{
public:
    Matrix(){};
    Matrix(int rows, int cols)
    {
        a = vector<vector<int>>(rows, vector<int>(cols, 0));
    }
    ~Matrix(){};
    vec a;
};

bool checkMatrixDimensionEquality(const Matrix &lhs, const Matrix &rhs)
{
    if (lhs.a.size() != rhs.a.size())
    {
        return false;
    }
    for (int i{}; i < lhs.a.size(); i++)
    {
        if (lhs.a.at(i).size() != rhs.a.at(i).size())
        {
            return false;
        }
    }
    return true;
}

Matrix operator+(const Matrix &lhs, const Matrix &rhs)
{
    //Matrix empty;
    // check if both matrices are of same dimmension
    //if (checkMatrixDimensionEquality(lhs, rhs))
    {
        // create new matrix to be returned
        int numOfRows = lhs.a.size();
        int numOfCols = lhs.a[0].size();
        Matrix ret(numOfRows, numOfCols);
        for (size_t i = 0; i < numOfRows; i++)
        {
            for (size_t j = 0; j < numOfCols; j++)
            {
                ret.a[i][j] = lhs.a[i][j] + rhs.a[i][j];
            }
        }
        return ret;
    }
    //return empty;
}


int main()
{
    int cases, k;
    cin >> cases;
    for (k = 0; k < cases; k++)
    {
        Matrix x;
        Matrix y;
        Matrix result;
        int n, m, i, j;
        cin >> n >> m;
        for (i = 0; i < n; i++)
        {
            vector<int> b;
            int num;
            for (j = 0; j < m; j++)
            {
                cin >> num;
                b.push_back(num);
            }
            x.a.push_back(b);
        }
        for (i = 0; i < n; i++)
        {
            vector<int> b;
            int num;
            for (j = 0; j < m; j++)
            {
                cin >> num;
                b.push_back(num);
            }
            y.a.push_back(b);
        }
        result = x + y;
        for (i = 0; i < n; i++)
        {
            for (j = 0; j < m; j++)
            {
                cout << result.a[i][j] << " ";
            }
            cout << endl;
        }
    }
    return 0;
}
