/*
 Petar 'PetarV' Velickovic
 Task:
*/

#include <stdio.h>
#include <math.h>
#include <string.h>
#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <algorithm>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <complex>
#include <unordered_set>
#include <unordered_map>

#define MAX_N 1001

#define DPRINTC(C) printf(#C " = %c\n", (C))
#define DPRINTS(S) printf(#S " = %s\n", (S))
#define DPRINTD(D) printf(#D " = %d\n", (D))
#define DPRINTLLD(LLD) printf(#LLD " = %lld\n", (LLD))
#define DPRINTLF(LF) printf(#LF " = %.5lf\n", (LF))

using namespace std;
typedef long long lld;
typedef unsigned long long llu;

int t;
int n;

lld arr[MAX_N];

inline lld min1(lld x, lld y)
{
    if (x < y) return x;
    return y;
}


int main()
{
    freopen("/Users/PetarV/HackerCup/A-small-attempt0.in.txt","r",stdin);
    freopen("/Users/PetarV/HackerCup/A-small-out.txt","w",stdout);
    
    scanf("%d", &t);
    for (int f=1;f<=t;f++)
    {
        scanf("%d", &n);
        for (int i=0;i<n;i++)
        {
            scanf("%lld", &arr[i]);
        }
        lld mthd_1 = 0LL, mthd_2 = 0LL;
        lld max_diff = 0;
        for (int i=1;i<n;i++)
        {
            if (arr[i] < arr[i-1]) mthd_1 += arr[i-1] - arr[i];
            if (arr[i-1] - arr[i] > max_diff) max_diff = arr[i-1] - arr[i];
        }
        
        for (int i=0;i<n-1;i++)
        {
            mthd_2 += min1(arr[i], max_diff);
        }
        
        printf("Case #%d: %lld %lld\n", f, mthd_1, mthd_2);
    }
    
    return 0;
}
