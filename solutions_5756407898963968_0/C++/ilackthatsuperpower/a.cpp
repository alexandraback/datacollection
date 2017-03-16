//
//  a.cpp
//
//

#include <cstdlib>
#include <stdint.h>
#include <iostream>
#include <iomanip>
#include <utility>
#include <functional>
#include <fstream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <math.h>

//#include <boost/multi_array.hpp>


// function prototypes

// utility functions

// globals

std::ifstream inFile;

// functions

void setup()
{
}


void processCase()
{

    std::vector <int> counts(17);

    for (int i=0; i<2; i++)
    {
        int row;
        
        inFile >> row;
        
        for (int r=1; r<=4; r++)
        {
            for (int c=1; c<=4; c++)
            {
                int v;
                
                inFile >> v;
                if (row==r)
                    counts[v]++;
            }
        }
    }

    std::vector <int> nums;
    
    for (int i=1; i<=16; i++)
    {
        if (counts[i]==2)
        {
            nums.push_back(i);
        }
    }
    
    
    if (nums.size()>1)
    {
        std::cout << "Bad magician!\n";
    }
    else if (nums.size()==0)
    {
        std::cout << "Volunteer cheated!\n";
    }
    else
    {
        std::cout << nums[0] << "\n";
    }
}


// main

int main(int argc, char const * argv[])
{

    int T;
    
    // make sure filename is provided
    if (argc != 2)
    {
        std::cout << "Expected one argument\n";
        std::exit(0);
    }
    
    // open input file
    inFile.open(argv[1]);
    
    inFile >> T;
    
    
    setup();
    
    std::cout << std::setprecision(9);
    
    for (int caseIndex=1; caseIndex<=T; caseIndex++)
    {
        std::cout << "Case #" << caseIndex << ": ";
        processCase();
    }
    
    return 0;
}
