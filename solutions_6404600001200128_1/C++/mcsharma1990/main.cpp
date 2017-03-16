//
//  main.cpp
//  Codejam
//
//  Created by Mahesh Sharma on 4/10/15.
//  Copyright (c) 2015 Mahesh Sharma. All rights reserved.
//

/* Author: Mahesh */

/* 1. Did u interpret the qns correctly ?
 2. Is your i/o correct ?
 3. Int overflow, double precesion
 4. Array size correct ?
 5. Clearing/resetting vector, map etc.
 6. Stack ovrflow
 7. Global/local conflict
 8. Check for obvious typo(most imp)
 9. Think about edge cases
 */

#include <vector>
#include <string>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cctype>
#include <cstring>
#include <memory.h>
#include <cassert>

using namespace std;

#define ford(i, a, b, c)        for(int i=(a); i<(b); i+=(c))
#define fori(i, a, b)           ford(i,a,b,1)
#define rep(i, n)               fori(i,0,n)
#define ifor(i, a, b)           for(int i=(a); i>=(b); i--)
#define iter(i, a)              for(typeof((a).begin()) i=(a).begin(); i!=(a).end(); i++)
#define si(x)                   ((int)x.size())
#define SS                      ({int x;scanf("%d",&x);x;})
#define pb                      push_back
#define mp                      make_pair
#define all(a)                  a.begin(),a.end()
#define fill(a, v)              memset(a, v, sizeof(a))
#define inf                     (int)1e9
#define linf                    (long long)1e18
#define V                       vector
#define S                       string
#define XX                      first
#define YY                      second
#define P(v)                    rep(i, si(v)) cout<<v[i]<<" "; puts("")

typedef V<int> vi;
typedef V<S> vs;
typedef long long ll;
typedef pair<int,int> pii;

/* Program Body starts here */

int a[10000];

int main () {
    freopen("/Users/mahesh/Desktop/Codejam/Codejam/test.txt", "r", stdin);
    freopen("/Users/mahesh/Desktop/Codejam/Codejam/out.txt", "w", stdout);

    int test_count = SS;
    rep(test_index, test_count) {
        int N = SS;
        rep(i, N) {
            a[i] = SS;
        }
        
        int x = 0, y = 0;
        rep(i, N-1) {
            x += max(0, -1*(a[i+1] - a[i]));
        }
        int r = 0;
        rep(i, N-1) {
            if (a[i+1] < a[i]) {
                r = max(a[i]-a[i+1], r);
            }
        }
        rep(i, N-1) {
            y += min(a[i], r);
        }
        
        
        
        printf("Case #%d: %d %d\n", test_index+1, x, y);
    }
}

