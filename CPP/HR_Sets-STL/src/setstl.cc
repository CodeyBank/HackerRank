/**
 * @file setstl.cc
 * @author Stanley Ezeh (ezeh.stanley.es@gmail.com)
 * @brief
 * Each query is of one of the following three types:

  : Add an element  to the set.
  : Delete an element  from the set. (If the number  is not present in the set, then do nothing).
  : If the number  is present in the set, then print "Yes"(without quotes) else print "No"(without quotes).

Input Format

The first line of the input contains  where  is the number of queries. The next  lines contain  query each.
Each query consists of two integers  and  where  is the type of the query and  is an integer.

Constraints

Output Format

For queries of type  print "Yes"(without quotes) if the number  is present in the set and if the number is not present,
then print "No"(without quotes).
Each query of type  should be printed in a new line.

 * @version 0.1
 * @date 2023-09-12
 *
 * @copyright Copyright (c) 2023
 *
 */
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <set>
#include <vector>
using namespace std;


int main()
{
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    std::set<int> dataset;
    int Q{}, x{}, y{}; // number of queries
    cin >> Q;
    for (int i{}; i < Q; i++)
    {
        cin >> y >> x;
        switch (y)
        {
        case 1://Add element x to set
        {
            dataset.insert(x);
            break;
        }

        case 2://Delete element x from the set. Do nothing if not present
        {
            auto resIter = dataset.find(x);
            if (resIter != dataset.end())
            {
                dataset.erase(*resIter);
            }
            break;
        }
        case 3://Check if element is in set. Print Yes if present else No
        {
            auto resIter = dataset.find(x);
            if (resIter != dataset.end())
            {
                cout << "Yes" << endl;
            }
            else
            {
                cout << "No" << endl;
            }
            break;
        }
        default:
            break;
        }
    }

    return 0;
}
