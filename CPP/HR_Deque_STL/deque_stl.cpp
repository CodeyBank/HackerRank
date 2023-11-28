/**
 * @file deque_stl.cpp
 * @author Stanley Ezeh (ezeh.stanley.es@gmail.com)
 * @brief
 * @version 0.1
 * @date 2023-11-26
 *
 * @copyright Copyright (c) 2023
 *
 */

#include <iostream>
#include <deque>
#include <vector>
#include <algorithm>

using namespace std;
typedef deque<int> subarrayptr;
typedef deque<deque<int> *> subarray;

subarray * ReturnSubArray(int array[], int size, int k){
    int n = (size - k)+1;
    subarray * Subarrays = new subarray;

    for(int i{}; i<n; i++){
        subarrayptr * newSubarray = new subarrayptr;
        for(int j{i}; j<(i+k); j++){
            newSubarray->push_back(array[j]);
            // cout<<array[j]<<" ";
        }
        Subarrays->push_back(newSubarray);
        // cout<<endl;
    }

    return Subarrays;
}

void printMax(int arr[], int n, int k){
    int numOfSubarrays = (n-k)+1;
    deque<int> sub;
    for(int i=0; i<numOfSubarrays;i++){
        for(int j=i; j<(i+k); j++){
            sub.push_back(arr[j]);
        }
        cout<<*max_element(sub.begin(), sub.end())<<" ";

        // for(auto &v: sub){
        //     cout<<v<<" "<<endl;
        // }
        // cout<<*max_element(sub.begin(), sub.end());

        (void)sub.clear();
    }
    cout<<endl;
}

void print(int arr[], int n, int k){
    int numOfSubarrays = (n-k)+1;
    int oldMax =arr[0], newMax = 0;
    cout<<oldMax;
    for(int i=0; i< numOfSubarrays; i++){
        newMax = *max_element(&arr[i], &arr[i+k]);
    }
    cout<<endl;
}

void printKMax(int arr[], int n, int k){
    deque<int> subarr;
    subarr.insert(subarr.end(), arr, arr+k);
    int curr_max = *max_element(subarr.begin(),subarr.end());

    cout << curr_max;
    for(size_t i=k; i<n; ++i){
        int fr = subarr.front();
        subarr.pop_front();
        subarr.push_back(arr[i]);

        if (curr_max != fr){
            if (arr[i] > curr_max){
            curr_max = arr[i];
            }
        } else {
            curr_max = *max_element(subarr.begin(),subarr.end());
        }
        cout << " " << curr_max;
    }
    cout << endl;
}


int main(){

    int array [10] = {2,4,5,6,3,1,8,11,9,7};

    // subarray * result = ReturnSubArray(array, 10, 5);

    // for(int i=0; i<result->size(); i++){
    //     auto current = result->at(i);
    //     for(int j=0; j<current->size(); j++){
    //         cout<<current->at(j)<<" ";
    //     }
    //     cout<<endl;
    // }
    // vector<int> aa;
    // aa.push_back(7);
    // aa.push_back(20);
    // aa.push_back(23);

    // for(auto &v:aa){
    //     cout<<v<<endl;
    // }
    printMax(array, 10, 5);
    print(array, 10, 5);


    return 0;
}
