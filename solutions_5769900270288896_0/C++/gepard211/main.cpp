#include <iostream>
#include <sstream>
#include <cstdio>
#include <cstdlib>
#include <iomanip>
#include <algorithm>
#include <cmath>
#include <set>
#include <map>
#include <string.h>
#include <cstring>
#include <vector>
#include <queue>
#include <deque>

#define sqr(a) ((a)*(a))
#define ABS(A) ((a)>0 ? (a) : -(a))
#define MIN(a,b) ((a)>(b) ? (b) : (a))
#define MAX(a,b) ((a)<(b) ? (b) : (a))
#define mp(a,b) make_pair(a,b)
#define pb push_back
#define f first
#define s second

typedef long long ll;
typedef long double ld;

using namespace std;

ll mn = 1000000;
bool tt[20][20];

void dfs(ll n, ll m, ll p, ll x, ll y)
{
    if(p > 0)
    {
        ll i, j;
        for(  i = x; i <= n; i++)
        {
            if(i == x) j = y;
            else
                j = 1;
            for(; j <= m; j++)
                if(tt[i][j] == 0)
                {
                    tt[i][j] = 1;
                    if(j + 1 > m) dfs(n, m, p - 1, i + 1, 1);
                        else dfs(n, m, p - 1, i, j + 1);
                    tt[i][j] = 0;
                }
        }
    }
    else if(p == 0)
    {
    ll k = 0;
        for(ll i = 1; i <= n; i++)
            for(ll j = 1; j <= m; j++)
            {
            if(tt[i][j] == 1 && tt[i][j+1] == 1) k++;
            if(tt[i][j] == 1 && tt[i+1][j] == 1) k++;
            }
            if(k < mn) mn =k;
    }
}

int main()
{
   // freopen("input.txt", "r", stdin);
   // freopen("output.txt", "w", stdout);
    ll t, i, j, s, n, m, p;
    cin>> t;
    for(i = 1; i <= t; i++)
    {
        cin>>n>>m>>p;
        mn = 100;
        memset(tt, 0, sizeof(tt));
        dfs(n, m, p, 1, 1);
        cout<<"Case #"<<i<<": "<<mn<<endl;
    }


    return 0;
}
