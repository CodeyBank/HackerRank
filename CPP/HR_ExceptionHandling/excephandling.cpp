/**
 * @file excephandling.cpp
 * @author Stanley Ezeh (ezeh.stanley.es@gmail.com)
 * @brief 
 * 
 * You are required to extend the existing code so that it handles std::invalid_argument 
 * exception properly. More specifically, you have to extend the implementation of process_input 
 * function. It takes integer  as an argument and has to work as follows:

It calls function largest_proper_divisor(n).
If this call returns a value without raising an exception, it should print in a single line 
result=d where  is the returned value. Otherwise, if the call raises a std::invalid_argument exception, 
it has to print in a single line the string representation of the raised exception, i.e. its message.
Finally, no matter if the exception is raised or not, it should print in a single line returning 
control flow to caller after any other previously printed output.
To keep the code quality high, you are advised to have exactly one line printing returning 
control flow to caller in the body of process_input function.

Your function will be tested against several cases by the locked template code.

Input Format

The input is read by the provided locked code template. In the only line of the input, 
there is a single integer , which is going to be the argument passed to function process_input
 * @version 0.1
 * @date 2023-09-13
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <iostream>
#include <stdexcept>

using namespace std;

int largest_proper_divisor(int n) {
    if (n == 0) {
        throw invalid_argument("largest proper divisor is not defined for n=0");
    }
    if (n == 1) {
        throw invalid_argument("largest proper divisor is not defined for n=1");
    }
    for (int i = n/2; i >= 1; --i) {
        if (n % i == 0) {
            return i;
        }
    }
    return -1; // will never happen
}

void process_input(int n) { 
    try{
    int d = largest_proper_divisor(n);
    cout << "result=" << d << endl;
    }
    catch (const std::invalid_argument &ex){
        
    }
    cout<<"returning control flow to caller"<<endl;
}


int main() {
    int n;
    cin >> n;
    process_input(n);
    return 0;
}