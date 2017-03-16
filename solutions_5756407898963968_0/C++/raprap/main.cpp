#include <cstdio>
#include <algorithm>
#include <iostream>
#include <string>
#include <fstream>
#include <unordered_map>
#include <vector>
#include <sstream>
#include <iomanip>
#include <map>

using namespace std;

ifstream in;
ofstream out;

int T;
int n1, n2;
int r1[4][4], r2[4][4];

int main ()
{
    // Create input/Output Streams
    in.open("A.in");
    out.open("A.out");
    
    //Read N
    in >> T;
    
    for (int t = 0; t < T; t++)
    {
        memset(r1, 0, sizeof(r1));
        memset(r2, 0, sizeof(r2));
        
        //Read first matrix
        in >> n1;
        --n1;
        
        for(int x = 0; x < 4; x++)
        {
            for(int y = 0; y < 4; y++)
            {
                in >> r1[x][y];
            }
        }
        
        //Read second matrix
        in >> n2;
        --n2;
        
        for(int x = 0; x < 4; x++)
        {
            for(int y = 0; y < 4; y++)
            {
                in >> r2[x][y];
            }
        }
        
        //Compare the 2 selected lines
        int matches = 0;
        int lastMatch = 0;
        
        for(int y = 0; y < 4; y++)
        {
            for(int x = 0; x < 4; x++)
            {
                if(r1[n1][x] == r2[n2][y])
                {
                    matches++;
                    lastMatch = r1[n1][x];
                }
            }
        }
        
        out << "Case #" << t+1 << ": ";
        cout << "Case #" << t+1 << ": ";
        
        if(matches == 1)
        {
            out << lastMatch;
            cout << lastMatch;
        }
        else if(matches > 1)
        {
            out << "Bad magician!";
            cout << "Bad magician!";
        }
        else if(matches == 0)
        {
            out << "Volunteer cheated!";
            cout << "Volunteer cheated!";
            
        }
        
        out << endl;
        cout << endl;

    }
    
    return 0;
}
