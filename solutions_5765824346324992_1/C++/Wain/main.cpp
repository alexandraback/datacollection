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
    int barberCount = 0, myNumber = 0;
    int whichBarber = 0;
    
    cin >> barberCount >> myNumber;
    
    int* barberTime = new int[barberCount];
    double customerPerMin = 0;
    long long estimatedTime = 0;
    long long currentWaiting = 0;
    
    for ( int i = 0 ; i < barberCount ; i++ ) {
        cin >> barberTime[i];
        customerPerMin += 1.0/(double)barberTime[i];
    }
    estimatedTime = floor ( ((double)myNumber-(double)barberCount)/customerPerMin ) - 1;
    
    /*
     easy cases
     1) if barberCount >= waitingNumber : immediately serviced with waitingNumber;
     
     
     hard cases
     1)
     */
    
    int nextNumberChange = 1;
    if ( barberCount >= myNumber ) {
        whichBarber = myNumber-1;
    }
    else if ( barberCount == 1 ) {
        whichBarber = 0;
    }
    else {
        for ( int i = 0 ; i < barberCount ; i++ ) {
            currentWaiting += floor(estimatedTime/barberTime[i])+1;
        }

        while (1) {
            estimatedTime += nextNumberChange;
            nextNumberChange = 1;
            for ( int i = 0 ; i < barberCount ; i++ ) {
                if ( estimatedTime % barberTime[i] == 0 ) {
                    whichBarber = i;
                    currentWaiting++;
                }
                else if ( nextNumberChange > estimatedTime % barberTime[i] ) {
                    nextNumberChange = estimatedTime % barberTime[i];
                }
                    
                if ( currentWaiting == myNumber ) {
                    break;
                }
                if ( currentWaiting > myNumber ) {
//                    cout << currentWaiting << ", " << myNumber << ", " << estimatedTime ;
                    break;
                }
            }
            if ( currentWaiting >= myNumber ) {
                break;
            }
        }

//            cout << ":" << currentWaiting << ", " << myNumber ;
//        cout << currentWaiting
    }
    
    whichBarber++;
    cout << "Case #" << number << ": " << whichBarber ;


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

