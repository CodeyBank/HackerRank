#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <set>
#include <map>
#include <algorithm>
#include <string.h>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    std::map<string, int>db;
    string name;
    int score {0};

    int Q;
    cin>>Q;
    
    for (int i{0}; i<Q; i++){
        int type;
        cin>> type;
        switch (type) {
            case 1:{
                cin>>name>>score;

                auto it = db.find(name);
                if(it != db.end()){
                    it->second += score;
                }
                else{
                    db.insert(make_pair(name, score));
                }
                break;
            }

            case 2:{
                cin>>name;
                db.erase(name);
                break;
            }

            case 3:{
                cin >> name;
                // search for name in db
                std::map<string, int>::iterator it = db.find(name);
                if(it != db.end()){
                    cout<<it->second<<endl;
                }
                else{
                    cout<<0<<endl;
                }
            }
        
        }
    }
    return 0;
}



