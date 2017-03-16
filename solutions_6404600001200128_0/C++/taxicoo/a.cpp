#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <string>
#include <string.h>
#include <cstdio>
#include <cmath>
#include <stack>
#include <queue>
#include <vector>
#include <cctype>
#include <set>
#include <map>

using namespace std;

#define ll long long
#define ull unsigned long long
#define mp make_pair
#define pb push_back

int a[1007];

int main()
{
    freopen("inputa.txt", "r", stdin);
    freopen("outputa.txt", "w", stdout);
    int T, n, ans1, ans2, maxx;
    cin >> T;
    for (int t=1; t<=T; ++t)
    {
        ans1=0;
        ans2=0;
        maxx=0;
        scanf("%d", &n);
        for (int i=0; i<n; ++i)
            scanf("%d", &a[i]);
        for (int i=1; i<n; ++i)
        {
            if (a[i]<a[i-1])
                ans1+=(a[i-1]-a[i]);
            maxx=max(maxx, a[i-1]-a[i]);
        }
        for (int i=1; i<n; ++i)
            ans2+=min(a[i-1], maxx);
        printf("Case #%d: %d %d\n", t, ans1, ans2);
    }




    return 0;
}

