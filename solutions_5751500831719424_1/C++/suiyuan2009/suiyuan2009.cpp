#include <stdio.h>
#include <string>
#include <string.h>
#include <vector>
#include <algorithm>
#include <math.h>
#include <queue>
#include <map>
#include <stack>
#include <iostream>
using namespace std;
typedef long long ll;
const double eps = 1e-10;
//const double PI = acos(-1);
const int maxn = 105;
const int maxm=maxn*maxn;
const int inf = 0x3fffffff;
const int mod = 1000000007;

int n;
string a[maxn];
vector<pair<char,int> >b[maxn];

bool test()
{
    for(int i=1; i<=n; i++)
        if(b[i].size()!=b[1].size())return 0;
    int m=b[1].size();
    for(int i=0; i<m; i++)
        for(int j=1; j<=n; j++)
            if(b[j][i].first!=b[1][i].first)return 0;
    return 1;
}

int main()
{
    freopen("A-large.in","r",stdin);
    freopen("out.out","w",stdout);
    int T,ncase=0;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        for(int i=1; i<=n; i++)
        {
            cin>>a[i];
            b[i].clear();
            int m=a[i].size();
            for(int j=0; j<m; j++)
            {
                int pos=j;
                while(pos+1<m&&a[i][pos+1]==a[i][j])pos++;
                b[i].push_back(make_pair(a[i][j],pos-j+1));
                j=pos;
            }
        }
//        for(int i=1;i<=n;i++)
//        {
//            for(int j=1;j<=b[i].size();j++)
//                printf("%d ",b[i][j-1].second);
//            printf("\n");
//        }
        if(!test())
        {
            printf("Case #%d: Fegla Won\n",++ncase);
            continue;
        }
        int ret=0;
        int m=b[1].size();
        for(int i=0; i<m; i++)
        {
            int tmp=-1;
            for(int j=1; j<maxn; j++)
            {
                int tt=0;
                for(int k=1; k<=n; k++)
                    tt+=abs(b[k][i].second-j);
                if(tmp==-1||tmp>tt)tmp=tt;
            }
            ret+=tmp;
        }
        printf("Case #%d: %d\n",++ncase,ret);
    }
    return 0;
}
