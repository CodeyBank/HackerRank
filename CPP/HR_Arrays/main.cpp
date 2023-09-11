//#include <cmath>
//#include <cstdio>
//#include <vector>
//#include <iostream>
//#include <algorithm>
//using namespace std;
//
//
//int main() {
//    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
//    vector<int> arrayOfInputs(3);
//    int sumOfNumbers {0};
//
//    cin>>arrayOfInputs.at(0)>>arrayOfInputs.at(1)>>arrayOfInputs.at(2);
//    //check if the constraint is met
//    for(size_t i=0; i<3;i++){
//            sumOfNumbers += arrayOfInputs.at(i);
//    }
//
//    cout<<sumOfNumbers;
//    return 0;
//}



//#include <stdio.h>
//#include <math.h>
//
//void update(int *a,int *b) {
//    // Complete this function
//    int temp = *a;
//    *a += *b;
//    *b = std::abs((temp - *b));
//}
//
//int main() {
//    int a, b;
//    int *pa = &a, *pb = &b;
//
//    scanf("%d %d", &a, &b);
//    update(pa, pb);
//    printf("%d\n%d", a, b);
//
//    return 0;
//}


//#include <cmath>
//#include <cstdio>
//#include <vector>
//#include <iostream>
//#include <algorithm>
//using namespace std;
//
//
//int main() {
//    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
//    int N;
//    scanf("%d",&N);
//
//    // define the array
//    int A[N] = { 0 };
//
//    // read the values to be stored until end
//    for (int j{0}; j<N; j++){
//        scanf("%d", &A[j]);
//    }
//
//    cout<<"Number of array elements: "<<N;
//
//    for (int i{N-1}; i >= 0; --i )
//        printf("%d ", A[i]);
//
//
//    return 0;
//}

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


void fillUpVector(vector<int> &arrays){
    int ch, i=0;
    scanf("%d", &ch);

    do{
        int val;
        scanf("%d", &val);
        arrays.push_back(val);
        i++;
    }while(i<ch);

}

int processQueries(const vector<vector<int>> &arrayOfVectors){
    int x, y;
    scanf("%d %d", &x, &y);
    return arrayOfVectors.at(x).at(y);
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */

    // receive and store the number of arrays and the query
    int n, q;
    scanf("%d %d", &n, &q);


    vector<vector<int>> arrays (n);

    // read the next n lines and parse the data
    for (int i=0; i<n; i++){
        fillUpVector(arrays.at(i));
    }

    // process the queries
    int results [q] = { 0 };
    for (int j=0; j<q; j++){
        results[j] = processQueries(arrays);
    }

    // print results
    for(int k{}; k<q; k++){
        cout<<results[k]<<endl;
    }

    return 0;
}
