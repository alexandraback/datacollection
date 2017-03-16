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
int n, num[MAXN];
int main()
{
    freopen("A-large.in", "r", stdin);
    //freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int t;
    scanf("%d", &t);
    repd(_,1,t)
    {
        printf("Case #%d: ", _);
        scanf("%d", &n);
        rep(i,n) scanf("%d", num+i);
        int res1 = 0, res2 = 0;
        rep(i,1,n)
        {
            if (num[i] < num[i-1])
            {
                res1 += num[i-1] - num[i];
            }
        }
        int spd = 0;
        rep(i,1,n)
        {
            if (num[i] < num[i-1])
            {
                int a = num[i-1] - num[i];
                spd = max(a, spd);
            }
        }
        rep(i,n-1)
        {
            res2 += min(num[i], spd);
        }
        printf("%d %d\n", res1, res2);
    }
    return 0;
}
