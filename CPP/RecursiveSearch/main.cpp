#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>


using namespace std;
struct MyStruct {
    std::vector<MyStruct> children;
    int value;
};

struct MyStruct* recursive_search(MyStruct & node, int const value) {
    struct MyStruct *emptyTag = nullptr;
    if (node.value == value) {
        emptyTag = &node;
        return emptyTag;
    }
    for (auto & child : node.children) {
        emptyTag = recursive_search(child, value);
        if (emptyTag !=nullptr) {
            return emptyTag;
        }
    }
    return emptyTag;
}


int main(){

    MyStruct s;
    for(int i{0}; i<10; i++){
       MyStruct newStruct;
       newStruct.value = i;
       s.children.push_back(newStruct);
    }

    // search for the child struct with int
    cout<<std::boolalpha;
    cout<<recursive_search(s, 8)->value<<endl;
    return 0;
}
