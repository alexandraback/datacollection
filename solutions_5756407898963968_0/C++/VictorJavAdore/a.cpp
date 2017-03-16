#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>

using namespace std;
typedef unsigned int ui;
typedef long long ll;
typedef unsigned long long ull;

int T;
bool possible[16];
int orderA[16], orderB[16];
int rowA, rowB;
int numPossible;

int main()
{
    cin >> T;
    for(int t=1; t<=T; t++)
    {
        cin >> rowA;
        for(int i=0; i<16; i++)
            cin >> orderA[i];
        cin >> rowB;
        for(int i=0; i<16; i++)
            cin >> orderB[i];

        for(int i=0; i<16; i++)
            possible[i] = true;
        for(int i=0; i<16; i++)
        {
            if(i/4+1 != rowA)
                possible[orderA[i]-1] = false;
            if(i/4+1 != rowB)
                possible[orderB[i]-1] = false;
        }

        numPossible = 0;
        for(int i=0; i<16; i++)
            if(possible[i])
                numPossible++;

        cout << "Case #" << t << ": ";
        if(numPossible == 0)
            cout << "Volunteer cheated!" << endl;
        else if(numPossible == 1)
        {
            for(int i=0; i<16; i++)
                if(possible[i])
                    cout << i+1 << endl;
        }
        else
            cout << "Bad magician!" << endl;
    }
}
