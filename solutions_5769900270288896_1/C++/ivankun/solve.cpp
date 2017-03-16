#define _USE_MATH_DEFINES
#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <algorithm>
#include <map>
#include <vector>
#include <iostream>
#include <set>
#include <cmath>
#include <cstring>
#include <bitset>
#include <deque>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<string> vs;
typedef pair<int, int> pii;
typedef vector<pii> vpii;

#define mp make_pair
#define pb push_back
#define bpc(a) __builtin_popcount(a)
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define clr(ar,val) memset(ar, val, sizeof(ar))
#define forn(i,n) for(int i=0;i<(n);++i)
#define X first
#define Y second
#define debug(x) { cerr<<#x<<" = "<<(x)<<endl; }

const int mod = 1e9 + 7;
const int inf = 1e9;

ll powm(ll a,ll p,ll m){ll r=1 % m;while(p){if(p&1)r=r*a%m;p>>=1;a=a*a%m;}return r;}

int solve1(int r, int c, int n)
{
    vvi rc(r + 1);
    forn(i, r + 1)
        rc[i].resize(c + 1);
    int ans = inf;
    forn(mask, 1 << (r * c))
    {
        int cnt = 0;
        for(int t = mask; t; t /= 2)
            cnt += t % 2;
        if(cnt != n)
            continue;
        forn(i, r * c)
            rc[i / c][i % c] = (mask & (1 << i)) != 0;
        cnt = 0;
        forn(i, r)
            forn(j, c)
                cnt += rc[i][j] * (rc[i + 1][j] + rc[i][j + 1]);
        ans = min(ans, cnt);
    }
    return ans;
}

int solve2(int r, int c, int n)
{
    vvi rc(r + 1);
    forn(i, r + 1)
        rc[i].resize(c + 1);
    if(n <= (r * c + 1) / 2)
        return 0;
    forn(i, r)
        forn(j, c)
        {
            rc[i][j] = (i + j) % 2;
            n -= (i + j) % 2;
        }
    for(int i = 0; i < r; i += r == 1 ? 1 : r - 1)
        for(int j = 0; j < c; j += c == 1 ? 1 : c - 1)
            if(rc[i][j] == 0 && n)
            {
                rc[i][j] = 1;
                --n;
            }
    for(int i = 0; i < r && n; ++i)
        if(rc[i][0] == 0)
        {
            rc[i][0] = 1;
            --n;
        }
    for(int i = 0; i < r && n; ++i)
        if(rc[i][c - 1] == 0)
        {
            rc[i][c - 1] = 1;
            --n;
        }
    for(int j = 0; j < c && n; ++j)
        if(rc[0][j] == 0)
        {
            rc[0][j] = 1;
            --n;
        }
    for(int j = 0; j < c && n; ++j)
        if(rc[r - 1][j] == 0)
        {
            rc[r - 1][j] = 1;
            --n;
        }
    for(int i = 1; i < r && n; ++i)
        for(int j = 1; j < c && n; ++j)
            if(rc[i][j] == 0)
            {
                rc[i][j] = 1;
                --n;
            }
    int ans = 0;
    forn(i, r)
        forn(j, c)
            ans += rc[i][j] * (rc[i + 1][j] + rc[i][j + 1]);
    return ans;
}

int solve3(int r, int c, int n)
{
    vvi rc(r + 1);
    forn(i, r + 1)
        rc[i].resize(c + 1);
    if(n <= (r * c + 1) / 2)
        return 0;
    forn(i, r)
        forn(j, c)
        {
            rc[i][j] = (i + j + 1) % 2;
            n -= (i + j + 1) % 2;
        }
    for(int i = 0; i < r; i += r == 1 ? 1 : r - 1)
        for(int j = 0; j < c; j += c == 1 ? 1 : c - 1)
            if(rc[i][j] == 0 && n)
            {
                rc[i][j] = 1;
                --n;
            }
    for(int i = 0; i < r && n; ++i)
        if(rc[i][0] == 0)
        {
            rc[i][0] = 1;
            --n;
        }
    for(int i = 0; i < r && n; ++i)
        if(rc[i][c - 1] == 0)
        {
            rc[i][c - 1] = 1;
            --n;
        }
    for(int j = 0; j < c && n; ++j)
        if(rc[0][j] == 0)
        {
            rc[0][j] = 1;
            --n;
        }
    for(int j = 0; j < c && n; ++j)
        if(rc[r - 1][j] == 0)
        {
            rc[r - 1][j] = 1;
            --n;
        }
    for(int i = 1; i < r && n; ++i)
        for(int j = 1; j < c && n; ++j)
            if(rc[i][j] == 0)
            {
                rc[i][j] = 1;
                --n;
            }
    int ans = 0;
    forn(i, r)
        forn(j, c)
            ans += rc[i][j] * (rc[i + 1][j] + rc[i][j + 1]);
    return ans;
}

int solve23(int r, int c, int n)
{
    return min(solve2(r, c, n), solve3(r, c, n));
}

int solve()
{
    int r, c, n;
    scanf("%d%d%d", &r, &c, &n);
    //if(solve1(r, c, n) == solve23(r, c, n))
    //printf("= %d %d %d = %d %d %d\n", r, c, n, solve1(r, c, n), solve2(r, c, n), solve3(r, c, n));
    return solve23(r, c, n);
}

int main()
{
    int t;
    scanf("%d", &t);
    forn(i, t)
        printf("Case #%d: %d\n", i + 1, solve());
    return 0;
}
