//#pragma comment (linker, "/STACK:263108864")
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <string>
#include <cstring>
#include <vector>
#include <set>
#include <list>
#include <map>
#include <queue>
#include <stack>
#include <deque>

using namespace std;

#define pb push_back
#define mp make_pair
#define fs first
#define sc second

typedef long long li;
typedef unsigned long long uli;
typedef long double ld;

const int INF = 1e9;
const li lINF = 1e18;
const int P = 1e9 + 7, Q = 1e9 + 9;
const int base = 41;
const double PI = 3.141592653589793238;
const double eps = 1e-7;

int TESTS, TEST_NOW;

int main ()
{
    freopen ("problem.in", "r", stdin);
    freopen ("problem.out", "w", stdout);
    cin >> TESTS;

    for (TEST_NOW = 1 ; TEST_NOW <= TESTS ; ++TEST_NOW)
    {
        cout << "Case #" << TEST_NOW << ": ";
        int f, s;
        pair< int, int > pos[20];
        cin >> f;
        for (int i = 0 ; i < 4 ; ++i)
            for (int j = 0 ; j < 4 ; ++j)
            {
                int t;
                cin >> t;
                pos[t].fs = i + 1;
            }
        cin >> s;
        for (int i = 0 ; i < 4 ; ++i)
            for (int j = 0 ; j < 4 ; ++j)
            {
                int t;
                cin >> t;
                pos[t].sc = i + 1;
            }
        int ans = -1;
        for (int i = 1 ; i <= 16 ; ++i)
        {
            if (pos[i] == mp (f, s))
            {
                if (ans == -1)
                    ans = i;
                else
                {
                    cout << "Bad magician!\n";
                    goto case_end;

                }
            }
        }
        if (ans < 0)
            cout << "Volunteer cheated!\n";
        else
            cout << ans << endl;
case_end:
        int k;
    }
}
