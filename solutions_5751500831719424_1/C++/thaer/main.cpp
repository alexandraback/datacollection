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

bool diff(vector<char> v1, vector<char> v2) {
    int i;
    if (v1.size() != v2.size()) return true;
    for (i = 0; i < v1.size(); i++) {
        if (v1[i] != v2[i]) return true;
    }
    return false;
}

vector<char> getCommon(string s1, string s2) {
    vector<int> c1, c2;
    vector<char> emp;
    int i;
    c1.pb(1);
    c2.pb(1);
    char p = s1[0];
    vector<char> cp1, cp2;
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
    if (diff(cp1, cp2)) return emp;
    else {
        int minMoves= 0;
        for (i = 0; i < c1.size(); i++) {
            int biggest = 0;
            if (c1[i] != c2[i]) {
                if (c1[i] < c2[i]) minMoves += c2[i] - c1[i];
                else minMoves += c1[i] - c2[i];
            }
        }
        return cp1;
    }
    
}

int solve(string s1, string s2) {
    vector<int> c1, c2;
    int i;
    c1.pb(1);
    c2.pb(1);
    char p = s1[0];
    vector<char> cp1, cp2;
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
    if (diff(cp1, cp2)) return INF;
    else {
        int minMoves= 0;
        for (i = 0; i < c1.size(); i++) {
            int biggest = 0;
            if (c1[i] != c2[i]) {
                if (c1[i] < c2[i]) minMoves += c2[i] - c1[i];
                else minMoves += c1[i] - c2[i];
            }
        }
        return minMoves;
    }
    
}

/*
 * 
 */
int main() {
    freopen("input3.in", "r", stdin);
    freopen("output2.txt", "w", stdout);
    int tc = 0, t;
    cin>>t;
    while (tc++ < t) {
        int n, i, j, k;
        cin>>n;
        string s1, s2;
        vector<int> c1, c2;
        vector<string> strs;
        for (i = 0; i < n; i++) {
            string aux;
            cin>>aux;
            strs.pb(aux);
        }
        int minMoves = INF;
        bool imp = false;
        string commonStr = "";
        vector<char> aux;
        for (i = 1; i < n; i++) {
            aux = getCommon(strs[0], strs[i]);
            if (aux.size() == 0) imp = true;
        }
        if (!imp) {
            for (i = 0; i < aux.size(); i++) {
                commonStr += aux[i];
            }
        }
        strs.pb(commonStr);
        for (i = 0; i < strs.size() && !imp; i++) {
            int auxMoves = 0;
            for (j = 0; j < n; j++) {
                int val = solve(strs[i], strs[j]);
                if (val == INF) {
                    auxMoves = INF;
                    break;
                }
                auxMoves += val;
                
            }
            minMoves = min(minMoves, auxMoves);
        }
        
        
        printf("Case #%d: ", tc);
        if (minMoves == INF) {
            cout<<"Fegla Won"<<endl;
        } else {
            cout<<minMoves<<endl;
        }
        
    }
    return 0;
}

