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

ll m[100007];
ll ty[5];
vector<ll> v;

ll gcd(ll a, ll b)
{
    while (a && b)
    {
        if (a > b)
            a%=b;
        else
            b%=a;
    }
    return a+b;
}

int main()
{
    freopen("inputb.txt", "r", stdin);
    freopen("outputb.txt", "w", stdout);
    int T;
    ll b, n, ans, lcm, temp, mi;
    bool ok;
    cin >> T;
    for (int t=1; t<=T; ++t)
    {
        v.clear();
        scanf("%I64d", &b);
        scanf("%I64d", &n);
        for (ll i=0; i<b; ++i)
            scanf("%I64d", &m[i]);
        if ((n==1) || (b==1))
        {
            printf("Case #%d: 1\n", t);
            continue;
        }
        lcm=m[0];
        ty[0]=0;
        for (int i=1; i<b; ++i)
        {
            lcm=m[i]*lcm/gcd(m[i], lcm);
            ty[i]=0;
        }
        int i;
        for (i=0; ; ++i)
        {
            mi=40;
            for (int j=0; j<b; ++j)
            {
                if (ty[j]==0)
                {
                    ty[j]+=m[j];
                    v.pb(j);
                //    cout << j << ' ';
                    break;
                }
            }
            for (int j=0; j<b; ++j)
            {
                mi=min(mi, ty[j]);
            }
            for (int j=0; j<b; ++j)
            {
                ty[j]-=mi;
            }
            bool ok=true;
            for (int j=0; j<b; ++j)
                if (ty[j]!=0)
                    ok=false;
            if (ok)
                break;
        }
        printf("Case #%d: %I64d\n", t, v[(n-1)%(i+1)]+1);
    }




    return 0;
}

