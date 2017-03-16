/*
 Petar 'PetarV' Velickovic
 Task: Haircut
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
#define LIM 1000000000000000LL

#define DPRINTC(C) printf(#C " = %c\n", (C))
#define DPRINTS(S) printf(#S " = %s\n", (S))
#define DPRINTD(D) printf(#D " = %d\n", (D))
#define DPRINTLLD(LLD) printf(#LLD " = %lld\n", (LLD))
#define DPRINTLF(LF) printf(#LF " = %.5lf\n", (LF))

using namespace std;
typedef long long lld;
typedef unsigned long long llu;

int t;
int b, n;

int arr[MAX_N];

int last_chosen = -1;

inline lld cnt(lld x)
{
    lld ret = 0LL;
    for (int i=0;i<b;i++)
    {
        ret += (x / arr[i]) + (x % arr[i] > 0 ? 1 : 0);
    }
    //cout << "cnt(" << x << ") = " << ret << endl;
    return ret;
}

inline bool check(lld x)
{
    return (cnt(x) < n);
}

inline lld bin_search(lld lo, lld hi)
{
    lld i = lo, j = hi;
    while (i < j)
    {
        lld mid = (i + j) >> 1;
        if (i == mid) mid++;
        if (check(mid)) i = mid;
        else j = mid - 1;
    }
    return i;
}

int main()
{
    freopen("/Users/PetarV/HackerCup/B-small-attempt0.in.txt","r",stdin);
    freopen("/Users/PetarV/HackerCup/B-small-out.txt","w",stdout);
    
    scanf("%d", &t);
    for (int f=1;f<=t;f++)
    {
        scanf("%d%d", &b, &n);
        
        for (int i=0;i<b;i++)
        {
            scanf("%d", &arr[i]);
        }
        
        lld T = bin_search(0LL, LIM);
        
        //cout << T << endl;
        //cout << cnt(T+1) << " " << cnt(T) << endl;
        
        int best = 0;
        lld tot = cnt(T);
        
        for (int i=0;i<b;i++)
        {
            if (T % arr[i] == 0)
            {
                best = i;
                if (++tot == n) break;
            }
        }
        
        printf("Case #%d: %d\n", f, best + 1);
    }
    
    return 0;
}
