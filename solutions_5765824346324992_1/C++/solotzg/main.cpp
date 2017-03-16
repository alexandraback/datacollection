#include <cstdio>
#include <iostream>
#include <string>
#include <iterator>
#include <algorithm>
#include <vector>
#include <cstring>
#include <array>
#include <queue>
#include <set>
#include <map>
#include <list>
using namespace std;
#define _rep1(i,a,b) for(int i=(a);i<(b);++i)
#define _rep2(i,b) for(int i=0;i<(b);++i)
#define GET_ALL_ARGS(_1,_2,_3,_name,...) _name
#define rep(...) GET_ALL_ARGS(__VA_ARGS__,_rep1,_rep2)(__VA_ARGS__)
#define repd(i,a,b) for(int i=(a);i<=(b);++i)
#define LL long long
const int MAXN = 1005;
const LL  inf = 0x3f3f3f3f3f3f3f3f;
int gcd(int a, int b)
{
    return b?gcd(b,a%b):a;
}
int M[MAXN], B, N;
LL cnt[MAXN];
int solve()
{
    if (N <= B) return N;
    LL bg = 0, ed = 100000000000000ll;
    while (bg < ed)
    {
        LL mid = (bg+ed)>>1;
        LL sum = 0;
        rep(i,B)
        {
            sum += 1+(mid-1)/M[i];
        }
        if (sum >= N-1 )
        {
            ed = mid;
        }
        else
        {
            bg = mid+1;
        }
    }
    LL sum = 0;
    memset(cnt, 0, sizeof cnt);
    rep(i,B)
    {
        LL tp = 1+(bg-1)/M[i];
        sum += tp;
        cnt[i] = tp*M[i] - bg;
    }
    if (sum >= N)
    {
        rep(i,B)
        {
            cnt[i] -= M[i];
        }
        while (1)
        {
            LL mx = cnt[B-1];
            int dx = B-1;
            for (int i = B-1; i>= 0; --i)
            {
                if (cnt[i] > mx)
                    mx = cnt[i], dx = i;
            }
            if (sum == N)
                return dx+1;
            --sum;
            cnt[dx] -= M[dx];
        }

    }
    while (1)
    {
        LL mn = inf;
        int dx = -1;
        rep(i,B)
        {
            if (cnt[i] < mn)
            {
                mn = cnt[i];
                dx = i;
            }
        }
        cnt[dx] += M[dx];
        ++sum;
        if (sum == N)
            return dx+1;
    }
}
int main()
{
    freopen("B-large.in", "r", stdin);
    //freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int t;
    scanf("%d", &t);
    repd(_,1,t)
    {
        printf("Case #%d: ", _);
        scanf("%d%d", &B , &N);
        rep(i,B) scanf("%d", M+i);
        printf("%d\n", solve());
    }
    return 0;
}
