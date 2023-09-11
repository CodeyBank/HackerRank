#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


void fillUpVector(vector<int> arrays){
    int ch;
    scanf("%d", &ch);
    for (int i{0}; i<ch; i++){
        scanf("%d",&ch);
        arrays.push_back(ch);
    }
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */

    // receive and store the number of arrays and the query
    int n, q;
    scanf("%d %d", &n, &q);

    vector<vector<int>> arrays (n);

    // read the next n lines and parse the data
    // 3 4 5 4
    for (int i=0; i<n; i++){
        fillUpVector(arrays.at(i));
    }

    for (auto &val: arrays[0]){
        printf("size : %d ", val);
    }

    return 0;
}
