#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

typedef struct data data_t;

/**
 * @brief Get the Index Of Lower Bound object.
 *
 * @param arr array to traverse through
 * @param query integer to find in the array
 * @return int returns negative index of the lower bound if value not found. If found, returns index
 */
int GetIndexOfLowerBound(const vector<int> arr, int query);

/**
 * @brief Get the Index Of Lower Bound object
 *
 * @param arr array to traverse through
 * @param query integer to find in the array
 * @return int returns negative index of the lower bound if value not found. If found, returns index
 */
int GetIndexOfLowerBound(const int arr[], int array_size, int query);

int main()
{
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    /* Receive and store elements in the arrray*/
    int N = 0; // array size
    cin >> N;
    vector<int> input; // array of inputs
    //int arrayOfInputs[N];

    for (size_t i = 0; i < N; i++)
    {
        int tmp{0};
        cin >> tmp;
        input.push_back(tmp);
    }

    /* Retrieve the store the queries */
    int Q{0};
    cin >> Q;

    vector<int> queries; // vector of queries
   
    for (size_t i = 0; i < Q; i++)
    {
        int tmp{0};
        cin >> tmp;
        queries.push_back(tmp);
    }

    // Repeatedly run query
    for (size_t i = 0; i < Q; i++)
    {
        int retval = GetIndexOfLowerBound(input, queries.at(i));
        if (retval < 0)
        {
            cout << "No " << ((retval*-1) +1) << endl;
        }
        else
        {
            cout << "Yes " << retval+1 << endl;
        }
    }
    return 0;
}

int GetIndexOfLowerBound(const vector<int> arr, int query)
{

    int indexOfLowerBound{0};
    int leastGreaterNumber{100000000};

    for (size_t i{0}; i < arr.size(); i++)
    {
        int tmp = arr.at(i);
        // first check if the ith term is greater than the query
        if (tmp > query)
        {
            if (tmp < leastGreaterNumber)
            {
                leastGreaterNumber = tmp;
                indexOfLowerBound = i;
            }
        }
        // if query is found, return index of the query
        else if (query == tmp)
        {
            return i;
        }
    }

    // return a negative index of the least value greater than the query
    return (indexOfLowerBound) * -1;
}

int GetIndexOfLowerBound(const int arr[], int array_size, int query)
{

    int indexOfLowerBound{-100000}; // initialized index to impossible value
    int leastGreaterNumber{100000}; // initialized to impossible value

    for (size_t i{0}; i < array_size; i++)
    {
        int tmp = arr[i];
        // first check if the ith term is greater than the query
        if (tmp > query)
        {
            // update the leastGreaterNumber and corresponding index
            if (tmp < leastGreaterNumber)
            {
                leastGreaterNumber = tmp;
                indexOfLowerBound = i;
            }
        }
        // if query is found, return index of the query
        else if (query == tmp)
        {
            return i;
        }
    }

    // check to se
    return (indexOfLowerBound) * -1;
}
