//#define __test__aTest__
#ifndef __test__aTest__

#include <vector>
#include <list>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <string.h>
#include <assert.h>
#include <stdexcept>

using namespace std;

#define ll long long
#define ull size_t

void process(int index) {
    int b1[4][4], b2[4][4];
    int r1, r2;
    vector<int> v;
    cin >> r1;
    r1--;
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
            cin >> b1[i][j];
    cin >> r2;
    r2--;
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
            cin >> b2[i][j];
    for (int j = 0; j < 4; j++) {
        bool found = false;
        for (int k = 0; k < 4; k++) {
            if (b1[r1][j] == b2[r2][k]) {
                found = true;
            }
        }
        if (found) v.push_back(b1[r1][j]);
    }
    cout<<"Case #"<<index<<": ";
    if (v.size() == 0)       cout<< "Volunteer cheated!";
    else if (v.size() == 1)  cout<< v[0];
    else                     cout<< "Bad magician!";
    cout<<endl;
}


int main() {
    
    freopen("/Users/zishirs/Documents/workspace/test/test/test.txt", "r", stdin);
    freopen("/Users/zishirs/Documents/workspace/test/test/output.txt", "w", stdout);
    
    
    int T;
    cin >> T;
    for (int index = 1; index <= T; ++index) {
        process(index);
        //cout<<"Case #"<<index<<": "<<endl;
    }
    
    /*
    int F;
    cin >> F;
    int n;
    vector<int> v;
    while (cin >> n) {
        v.push_back(n);
    }
    vector<int> v1(v.begin(), v.begin() + v.size()/2), v2(v.begin() + v.size()/2, v.end());
     */
    
    return 0;
}

#endif