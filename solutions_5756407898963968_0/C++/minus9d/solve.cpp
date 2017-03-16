#include <iostream>
#include <sstream>
#include <string>
#include <cmath>
#include <cstdio>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <algorithm>
#include <functional>
#include <numeric>

using namespace std;
typedef unsigned int uint;
typedef long long ll;
typedef unsigned long long ull;

#define REP(i,n) for(int i = 0; i < (int)(n); ++i)
#define FOR(i,a,b) for(int i = (a); i < (int)(b); ++i)
#define FOREACH(i, n) for (__typeof((n).begin()) i = (n).begin(); i != (n).end(); ++i)
#define ALL(c) (c).begin(), (c).end()
#define SIZE(v) ((int)v.size())

#define pb push_back
#define mp make_pair


void fillCell(vector< vector<int> > &cells)
{
    REP(i, 4) {
        REP(j, 4) {
            cin >> cells[i][j];
        }
    }
}

int main(void)
{
    int TEST_NUM;
    cin >> TEST_NUM;


    vector< vector<int> > cells(4);
    REP(i, 4){
        cells[i].resize(4);
    }

    REP(test, TEST_NUM){
        int n1;
        cin >> n1;
        fillCell(cells);
        set<int> possible;
        for (auto a : cells[n1-1]){
            possible.insert(a);
        }

        int n2;
        cin >> n2;
        fillCell(cells);

        int ans = 0;
        int exist_num = 0;
        
        for (auto a : cells[n2-1]){
            if (possible.count(a)){
                ans = a;
                ++exist_num;
            }
        }

        cout << "Case #" << (test+1) << ": ";
        if (exist_num == 0){
            cout << "Volunteer cheated!" << endl;
        }
        else if (exist_num > 1){
            cout << "Bad magician!" << endl;
        }
        else{
            cout << ans << endl;
        }
    }

    return 0;
}
