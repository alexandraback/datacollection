#include <iostream>
#include <sstream>
#include <fstream>
#include <iomanip>
#include <string>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <ctime>
#include <climits>
#include <cassert>
#include <vector>
#include <queue>
#include <stack>
#include <deque>
#include <set>
#include <map>
#include <bitset>
#include <utility>
#include <algorithm>

#define forn(i, n) for (int i = 0; i < int(n); i++)

using namespace std;

int cnts[100];
int n;

vector<string> best, cur;


void rec()
{   
    //cout << n << " " << cnts[0] << endl;
    int sum = 0;
    forn(i, n)
        sum += cnts[i];        
    if (*max_element(cnts, cnts + n) * 2 > sum)
        return;
    /*
    cout << "=" << endl;
    forn(i, n)
        cout << " " << cnts[i];
    cout << endl;        
    */
    if (!best.empty())
        return;
    bool ok = true;
    forn(i, n)
        if (cnts[i] != 0)
            ok = false;
    if (ok)
    {
        //cout << "!" << endl;
        best = cur;
        return;
    }    

    int m1 = max_element(cnts, cnts + n) - cnts;
    
    string step = "A";
    step[0] += m1;
    cur.push_back(step);
    cnts[m1]--;
    rec();
    //cnts[m1]++;
    cur.pop_back();

    int m2 = max_element(cnts, cnts + n) - cnts;
    if (cnts[m2] > 0)
    {
        step += "A";    
        step[1] += m2;
        cur.push_back(step);
        //cnts[m1]--;
        cnts[m2]--;
        //cout << "!" << cnts[0] << " " << cnts[1] << endl;
        rec();
        cnts[m1]++;
        cnts[m2]++;
        cur.pop_back();
    }
}   

int main(int argc, char* argv[])
{
    int testCount;
    cin >> testCount;

    forn(test, testCount)
    {
        cin >> n;
        forn(i, n)
            cin >> cnts[i];
        cur.clear();
        best.clear();
        rec();
        cout << "Case #" << (test + 1) << ":";
        forn(i, best.size())
            cout << " " << best[i];
        cout << endl;
    }

    return 0;
}
