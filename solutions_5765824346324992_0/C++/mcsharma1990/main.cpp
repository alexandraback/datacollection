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
int p[] = {2, 3, 5, 7, 11, 13, 17, 19, 23};
int c = 9;

int alpha, beta;
int extended_gcd(int a, int b){
    int x1=1, y1=0, x2=0, y2=1;
    while(b){
        int t=a, tx=x1, ty=y1;            /// saving eq 1
        x1=x2; y1=y2; a=b;                /// copying eq 2 into eq 1
        x2=tx-(t/b)*(long long)x2;        /// modifying eq2
        y2=ty-(t/b)*(long long)y2;        ///     ''
        b=t%b;                            ///     ''
    }
    alpha = x1;
    beta = y1;
    if (a<0) {
        a=-a;alpha=-alpha;beta=-beta;
    }
    return a;
}

int lcm(int a, int b) {
    int g = extended_gcd(a, b);
    return a*b/g;
}

int MIN(int arr[5], int B) {
    int ans = inf;
    rep(i, B) {
        ans = min(ans, arr[i]);
    }
    return ans;
}

int main () {
    freopen("/Users/mahesh/Desktop/Codejam/Codejam/test.txt", "r", stdin);
    freopen("/Users/mahesh/Desktop/Codejam/Codejam/out.txt", "w", stdout);

    int test_count = SS;
    rep(test_index, test_count) {
        int B = SS, N = SS;
        N--;
        rep(i, B) {
            a[i] = SS;
        }
        int L = a[0];
        fori(i, 1, B) {
            L = lcm(a[i], L);
        }
        int k = 0;
        rep(i, B) {
            k += L/a[i];
        }
        
        N = N % k;
        
        int bar[5] = {};
        int ans = -1;
        rep(i, N + 1) {
            int l = MIN(bar, B);
            rep(j, B) {
                bar[j] -= l;
            }
            rep(j, B) {
                if (bar[j] == 0) {
                    bar[j] = a[j];
                    ans = j+1;
                    break;
                }
            }
        }
        printf("Case #%d: %d\n", test_index+1, ans);
    }
}

