/* 
 * File:   main.cpp
 * Author: tlatif
 *
 * Created on May 3, 2014, 10:29 AM
 */

#include <iostream>
#include <string>
#include <algorithm>
#include <functional>
#include <utility>
#include <numeric>
#include <vector>
#include <set>
#include <map>
#include <list>
#include <queue>
#include <stack>
#include <deque>
#include <bitset>
#include <limits>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <cctype>
#include <climits>
#include <cfloat>
#include <ctime>
#include <cassert>

#define INF 999999999
#define pb push_back
typedef long long LL;

using namespace std;

bool diff(vector<int> v1, vector<int> v2) {
    int i;
    if (v1.size() != v2.size()) return true;
    for (i = 0; i < v1.size(); i++) {
        if (v1[i] != v2[i]) return true;
    }
    return false;
}

/*
 * 
 */
int main() {
    freopen("input2.in", "r", stdin);
    freopen("output.txt", "w", stdout);
    int tc = 0, t;
    cin>>t;
    while (tc++ < t) {
        int n;
        cin>>n;
        string s1, s2;
        vector<int> c1, c2;
        cin>>s1>>s2;
        int i, j, k;
        c1.pb(1);
        c2.pb(1);
        char p = s1[0];
        vector<int> cp1, cp2;
        cp1.pb(s1[0]);
        cp2.pb(s2[0]);
        for (i = 1; i < s1.size(); i++) {
            if (p == s1[i]) c1[c1.size() - 1]++;
            else {
                cp1.pb(s1[i]);
                c1.pb(1);
                p = s1[i];
            }
        }
        p = s2[0];
        for (i = 1; i < s2.size(); i++) {
            if (p == s2[i]) c2[c2.size() - 1]++;
            else {
                cp2.pb(s2[i]);
                c2.pb(1);
                p = s2[i];
            }
        }
        
        printf("Case #%d: ", tc);
        if (diff(cp2, cp1)) {
            
            cout<<"Fegla Won"<<endl;
        } else {
            int minMoves= 0;
            for (i = 0; i < c1.size(); i++) {
                int biggest = 0;
                if (c1[i] != c2[i]) {
                    if (c1[i] < c2[i]) minMoves += c2[i] - c1[i];
                    else minMoves += c1[i] - c2[i];
                }
            }
            cout<<minMoves<<endl;
        }
        
    }
    return 0;
}

