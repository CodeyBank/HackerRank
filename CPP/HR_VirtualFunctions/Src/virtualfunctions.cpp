/**
 * @file virtualfunctions.cpp
 * @author Stanley Ezeh (ezeh.stanley.es@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2023-09-13
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


/// @brief 
class Person
{
private:
    /* data */
public:
    Person(){};
    ~Person(){};

    /*Menmbers*/
    int age;
    std::string name;
    

    /* virtual functions */
    virtual void getdata() =0;
    virtual void putdata() =0;
};

class Professor : public Person
{
    
public:
    static int ProfessorInst;  
    Professor(){
        ProfessorInst++;
        cur_id = ProfessorInst;
        }
    ~Professor(){}

    /*Members*/
    int publications;
    int cur_id;

    void getdata() override{
        std::cin>>Person::name>>Person::age>> publications;
    }
    void putdata() override{
        cout<<name<<" "<<Person::age<<" "<<publications<<" "<<cur_id<<endl;
    }
};

class Student : public Person
{
    
public:
    static int StudentInst;
    Student(){
        StudentInst++;
        cur_id=StudentInst;
        ;}
    ~Student(){}

    /* Array of scores */
    int scores[6] = {0};
    int cur_id {0};
    void getdata() override{
        /* First get the name and age of the student */
        cin>>Person::name>>Person::age;

        /* Then store the marks of the student in scores array*/
        for (size_t i = 0; i < 6; i++)
        {
            cin>>scores[i];
        } 
    }

    void putdata() override{
        /* get the sum of the student's scores */
        int totalScores {0};
        for (size_t i = 0; i < 6; i++)
        {
            totalScores += scores[i];
        }

        /* Print out name age sum of marks and the cur_id of student */
        cout<<Person::name<<" "<<Person::age<<" "<<totalScores<<" "<<cur_id<<endl;
        
    }
};

int Professor::ProfessorInst = 0;
int Student::StudentInst = 0;

int main(){

    int n, val;
    cin>>n; //The number of objects that is going to be created.
    Person *per[n];

    for(int i = 0;i < n;i++){

        cin>>val;
        if(val == 1){
            // If val is 1 current object is of type Professor
            per[i] = new Professor;

        }
        else per[i] = new Student; // Else the current object is of type Student

        per[i]->getdata(); // Get the data from the user.

    }

    for(int i=0;i<n;i++)
        per[i]->putdata(); // Print the required output for each object.

    return 0;

}
