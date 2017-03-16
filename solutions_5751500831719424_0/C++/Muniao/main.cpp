//
//  main.cpp
//  a
//
//  Created by qylqy on 14-5-3.
//  Copyright (c) 2014年 linqiuyan. All rights reserved.
//

#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <utility>
#include <cmath>
using namespace std;
char a[105][105];
int l[105], r[105], c[105];

int solve(int n)
{
    int sum, Min, Max, i, Minsum, Maxsum, cnt;
    memset (l, 0, sizeof(l));
    memset (r, 0, sizeof(r));
    sum = 0;
    while (1)
    {
        //memcpy(r, l, n);
        for (i=0; i<n; i++)
        {
            while (a[i][r[i]] && a[i][r[i]] == a[i][l[i]]) r[i]++;
            ///printf ("%d %d  ", r[i], l[i]);
        }
        //printf ("\n");
        for (i=1; i<n; i++)
            if (a[i][l[i]] != a[0][l[0]]) return -1;
        for (i=0; i<n; i++)
            c[i] = r[i]-l[i];
        sort(c, c+n);
        /*Min = r[0]-l[0];
        Max = r[0]-l[0];
        for (i=1; i<n; i++)
        {
            Min = min(Min, r[i]-l[i]);
            Max = max(Max, r[i]-l[i]);
        }*/
        Minsum = 0;
        //Maxsum = 0;
        Min = c[n>>1];
        for (i=0; i<n; i++)
        {
            Minsum += abs(r[i]-l[i]-Min);
            //Maxsum += abs(r[i]-l[i]-Max);
        }
        //printf ("%d %d %d %d\n", Min, Max, Minsum, Maxsum);
        sum += Minsum; //, Maxsum);
        cnt = 0;
        for (i=0; i<n; i++)
            if (!a[i][r[i]]) cnt++;
        if (cnt>0 && cnt!=n) return -1;
        if (cnt==n) break;
        //memcpy(l, r, n);
        for (i=0; i<n; i++) l[i] = r[i];
    }
    return sum;
}

int main()
{
    int T, I, n, i, j;
    scanf ("%d", &T);
    for (I=1; I<=T; I++)
    {
        scanf ("%d", &n);
        for (i=0; i<n; i++)
        {
            scanf ("%s", a[i]);
        }
        i = solve(n);
        if (i==-1)
            printf ("Case #%d: Fegla Won\n", I);
        else
            printf ("Case #%d: %d\n", I, i);
        
    }
    return 0;
}

