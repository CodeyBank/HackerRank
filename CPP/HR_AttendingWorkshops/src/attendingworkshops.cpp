/*****************************************************************//**
 * \file   attendingworkshops.cpp
 * \brief  Find details about challenge here
 * https://www.hackerrank.com/challenges/attending-workshops/problem?isFullScreen=true
 * 
 * \author HP
 * \date   September 2023
 *********************************************************************/
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


//Workshop

typedef struct Workshop_t
{
    int startTime;
    int duration;
    int endTime;

    Workshop_t(int startTime_p, int duration_p)
    {
        this->startTime = startTime_p;
        this->duration = duration_p;
        this->endTime = startTime_p + duration_p;
    }
} Workshop;

// Available workshops
typedef struct Available_Workshops_t
{
    int n; 
    vector<Workshop> workshops;
    Available_Workshops_t() : n(0){}
} Available_Workshops;


Available_Workshops *initialize(int start_time[], int duration[], int n)
{
    // create an Available_Workshops object
    Available_Workshops *avWorkPtr = new Available_Workshops;

    for (size_t i = 0; i < n; i++)
    {
        // temporary workshop object
        Workshop tmp{start_time[i], duration[i]};
        avWorkPtr->workshops.push_back(tmp);
        avWorkPtr->n += 1;
    }
    return avWorkPtr;
}

int CalculateMaxWorkshops(Available_Workshops *ptr)
{
    /**
     * Steps
     * 0. Create a variable to store MaxWorkshops, initialized to 0
     * 1. Go through the list of available workshops.
     * 2. Check that the end time of each workshop is less than the start time of the subsequent
     * 3. If check passes, increment MaxWorkshops, else skip
     */


    // start iterating through the array of workshops starting from the begining
    vector<int>MaxWorkshops(ptr->n,0);

    for (size_t i{}; i < ((size_t)ptr->n) - 1; i++)
    {
        MaxWorkshops[i] += 1;
        for (size_t j{i+1}; j < (size_t)ptr->n; j++)
        {   
            if (ptr->workshops[i].endTime < ptr->workshops[j].startTime)
            {
                MaxWorkshops[i] += 1;
                i=j;
            }
        }
    }
    return *(std::max_element(MaxWorkshops.begin(), MaxWorkshops.end()));
}

int main(int argc, char *argv[])
{
    int n; // number of workshops
    cin >> n;
    // create arrays of unknown size n
    int *start_time = new int[n];
    int *duration = new int[n];

    for (int i = 0; i < n; i++)
    {
        cin >> start_time[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> duration[i];
    }

    Available_Workshops *ptr;
    ptr = initialize(start_time, duration, n);
    cout << CalculateMaxWorkshops(ptr) << endl;
    return 0;
}
