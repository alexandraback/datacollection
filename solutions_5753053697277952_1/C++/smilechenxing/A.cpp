#pragma comment(linker, "/STACK:1024000000,1024000000")
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<vector>
#include<set>
#include<map>
#include<cmath>
#include<queue>
#include<sstream>
#include<string>
#include<bitset>
#include<utility>
#include<numeric>
#include<assert.h>

using namespace std;
#define rep(i,a,n) for (int i=a;i<n;i++)
#define repn(i,a,n) for (int i=a;i<=n;i++)

typedef long long LL;
typedef unsigned long long ULL;

const LL LINF = (1LL <<60);
const int INF = 0x3f3f3f3f;

const int NS = 20010;
const int MS = 210;
const int MOD = 1000000007;
const double PI = acos(-1.0);

#define form(_i, L, R) for (int (_i) = L; (i) <= (R); ++(_i))
inline bool isdigit(char ch){return ((ch<='9')and(ch>='0'));}
inline void read(int &x){
    char ch;
    bool flag=false;
    for (ch=getchar();!isdigit(ch);ch=getchar()) if (ch=='-') flag=true;
    for (x=0;isdigit(ch);x=x*10+ch-'0',ch=getchar());
    x=flag?-x:x;
}

int n, p[MS];


int getSum()
{
    int sum = 0;
    for(int i = 0; i < n; i++)
    {
        sum += p[i];
    }
    return sum;
}

int getMax()
{
    int pos = -1, maxv = 0;
    for(int i = 0; i < n; i++)
    {
        if(p[i] > maxv)
        {
            maxv = p[i];
            pos = i;
        }
    }
    return pos;
}

int main()
{
   // ios::sync_with_stdio(false);
#ifndef ONLINE_JUDGE
    freopen("A-large.in", "r", stdin);
    freopen("A-large.out", "w", stdout);
#endif
    int nCase;
    while(~scanf("%d", &nCase))
    {
        for(int nT = 1; nT <= nCase; nT++)
        {
            scanf("%d", &n);
            for(int i = 0; i < n; i++)
            {
                scanf("%d", &p[i]);
            }
            printf("Case #%d:", nT);
            while(true)
            {
                int sum = getSum();
                if(sum <= 0) break;
                if(sum >= 1 && sum <= 2)
                {
                    printf(" ");
                    for(int i = 0; i < n; i++)
                    {
                        if(p[i] > 0)
                        {
                            p[i]--;
                            printf("%c", 'A' + i);
                        }
                        if(p[i] > 0)
                        {
                            p[i]--;
                            printf("%c", 'A' + i);
                        }
                    }
                    break;
                }

                int pos = getMax();
                if(pos >= 0)
                {
                    printf(" %c", 'A' + pos);
                    p[pos]--;
                }

                pos = getMax();
                if(sum >= 4 && pos >= 0)
                {
                    printf("%c", 'A' + pos);
                    p[pos]--;
                }
            }
            puts("");
        }
    }
    return 0;
}


//   __typeof(val.begin()) it = val.begin();
// ios::sync_with_stdio(false);
// cout<<setprecision(30);
