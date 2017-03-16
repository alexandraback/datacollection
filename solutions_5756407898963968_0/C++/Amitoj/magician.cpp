#include <algorithm>  
#include <iostream>  
#include <iomanip>  
#include <fstream>  
#include <sstream>  
#include <string>  
#include <list>  
#include <queue>  
#include <set>  
#include <map>  
#include <cstdio>  
#include <cstdlib>  
#include <cctype>  
#include <cmath>  
using namespace std;  

#define FOR(i,a,b) for(long i=(a);i<(b);++i)  
#define REP(i,n) FOR(i,0,n)  


int main(int argc, char** argv)
{
    ifstream in;
    in.open(argv[1],ios::in);
    ofstream out;
    out.open(argv[2],ios::out);
    int N = 0;
    in>>N;
    cout << " Total  " << N <<endl;
    REP(caseN,N)
    {
        cout<<"solving case "<<caseN+1<<endl;
        int answer1;
        in >> answer1;
        int row1[4], row2[4];
        
        int temp;
        for(int i = 0; i < 4; i++)
        {
            for(int j = 0; j < 4; j++)
            {
                if((i+1) == answer1)
                    in >> row1[j];
                else
                    in >> temp;
            }
        }
        
        int answer2;
        in >> answer2;
        
        for(int i = 0; i < 4; i++)
        {
            for(int j = 0; j < 4; j++)
            {
                if((i+1) == answer2)
                    in >> row2[j];
                else
                    in >> temp;
            }
        }
        
        int no_matches = 0;
        int matchedNumber = 0;
        for(int i = 0; i < 4; ++i)
        {
            for(int j = 0; j < 4; j++)
            {
                if(row1[i] == row2[j])
                {
                    ++no_matches;
                    matchedNumber = row1[i];
                }
            }
        }

        out << "Case #"<<caseN+1<<": ";
        if(no_matches == 0)
            out << "Volunteer cheated!" << endl;
        else if(no_matches == 1)
            out << matchedNumber << endl;
        else 
            out << "Bad magician!" << endl;
        
    }
        
    in.close();
    out.close();
    return 0;
}
