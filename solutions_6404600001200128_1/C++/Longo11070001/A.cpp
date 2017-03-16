#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#define pb push_back
using namespace std;
const int maxn = 1010;
int n;
int m[maxn];

int main()
{
    freopen("A-large.in","r",stdin);
    freopen("A-large.out","w",stdout);
    int T,cas,i,a1,a2,ma;
    scanf("%d",&T);
    for(cas=1; cas<=T; cas++)
    {
        scanf("%d",&n);
        for(i=0; i<n; i++)
        {
            scanf("%d",&m[i]);
        }
        a1 = a2 = 0; ma = 0;
        for(i=1; i<n; i++)
        {
            if(m[i]<m[i-1])
            {
                ma = max(m[i-1]-m[i],ma);
                a1 += m[i-1]-m[i];
            }
        }
        for(i=0; i<n-1; i++)
        {
            if(m[i] > ma) a2 += ma;
            else a2 += m[i];
        }
        printf("Case #%d: %d %d\n",cas,a1,a2);
    }
    return 0;
}
