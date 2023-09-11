#include <sstream>
#include <vector>
#include <iostream>
using namespace std;

vector<int> parseInts(string str) {
	// Complete this function
    stringstream ss(str);
    int number {0};
    // vector<int> *vec = new vector<int>();
    vector<int> vec;
    while(ss>>number || !ss.eof()){

        // check if parse worked
        if(ss.fail()){
            ss.clear();
            ss.ignore(); // ignore the errored data
            continue;
        }
        // vec->push_back(number);
        vec.push_back(number);
    }

    return vec;
}

int main() {
    string str;
    cin >> str;
    vector<int> integers = parseInts(str);
    for(int i = 0; i < integers.size(); i++) {
        cout << integers[i] << "\n";
    }

    return 0;
}
