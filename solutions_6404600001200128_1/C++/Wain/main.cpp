//
//  main.cpp
//  CodeJam2015 - Round1A

#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <cmath>

using namespace std;

void runQuestion(int number)
{
    int intervalCount = 0;
    int comp1 = 0, comp2 = 0;
    
    
    int max_diff = 0;
    int sum_diff1 = 0;
    int sum_diff2 = 0;
    
    cin >> intervalCount ;
    
    int* intervalData = new int[intervalCount];
    
    cin >> intervalData[0];
    for ( int i = 1 ; i < intervalCount ; i++ ) {
        cin >> intervalData[i];
        if ( intervalData[i] < intervalData[i-1] ) {
            if ( max_diff < intervalData[i-1] - intervalData[i] )
                max_diff = intervalData[i-1] - intervalData[i];
            sum_diff1 += intervalData[i-1] - intervalData[i];
        }
    }
    for ( int i = 0 ; i < intervalCount - 1 ; i++ ) {
        if ( intervalData[i] > max_diff ) sum_diff2 += max_diff;
        else sum_diff2 += intervalData[i];
    }
    
    comp1 = sum_diff1;
    comp2 = sum_diff2;
    
    cout << "Case #" << number << ": " << comp1 << " " << comp2 ;


    cout << endl;
}

int main(int argc, const char * argv[]) {
    
    int howManyTimes;
    
    scanf("%d", &howManyTimes);
    
    for ( int i = 0 ; i < howManyTimes ; i++ ) {
        runQuestion(i+1);
    }

    return 0;
}

