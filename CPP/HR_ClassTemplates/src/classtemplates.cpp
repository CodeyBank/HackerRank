/*****************************************************************//**
 * \file   classtemplates.cpp
 * \brief  
 * 
 * You are given a main() function which takes a set of inputs. 
 * The type of input governs the kind of operation to be performed,
 *  i.e. concatenation for strings and addition for int or float.
 *  You need to write the class template AddElements which has
 *  a function add() for giving the sum of int or float elements.
 *  You also need to write a template specialization for the type 
 * string with a function concatenate() to concatenate the second 
 * string to the first string.

Input Format

The first line contains an integer . Input will consist of  lines
where  is the number given in the first line of the input followed
by  lines.

Each of the next  line contains the type of the elements provided
and depending on the type, either two strings or two integers or
two floating point numbers will be given. The type will be one of
int, float or string types only. Out of the following two elements,
you have to concatenate or add the second element to the first element.


 * \author HP
 * \date   September 2023
 *********************************************************************/

#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

/*Write the class AddElements here*/

/* Template clasee */
template<class T>
class AddElements
{
public:
    AddElements()
    {
    }
    AddElements(T arg)
    {
        element = arg;
    };

    // addition method
    T add(T &_firstArg)
    {
        return element + _firstArg  ;
    }
    ~AddElements(){};

private:
    T element;
};

/* Template specialization */
template<>
class AddElements<std::string>
{
public:
    // Default No-args constructor
    AddElements()
    {
    }
    ~AddElements()
    {
    }
    // specialised constructor
    AddElements(std::string arg) : element(arg)
    {
        //do nothing
    }
    std::string concatenate(std::string _firstArg)
    {
        return element + _firstArg;
    }

private:
    std::string element;
};

int main()
{
    int n, i;
    cin >> n;
    for (i = 0; i < n; i++)
    {
        string type;
        cin >> type;
        if (type == "float")
        {
            double element1, element2;
            cin >> element1 >> element2;
            AddElements<double> myfloat(element1);
            cout << myfloat.add(element2) << endl;
        }
        else if (type == "int")
        {
            int element1, element2;
            cin >> element1 >> element2;
            AddElements<int> myint(element1);
            cout << myint.add(element2) << endl;
        }
        else if (type == "string")
        {
            string element1, element2;
            cin >> element1 >> element2;
            AddElements<string> mystring(element1);
            cout << mystring.concatenate(element2) << endl;
        }
    }
    return 0;
}
