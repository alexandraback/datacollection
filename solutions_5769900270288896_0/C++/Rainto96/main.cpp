/*
*Rainto96
*Beijing University of Posts and Telecommunications School of Software Engineering
*http://blog.csdn.net/u011775691
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <cmath>
#include <vector>
#include <climits>
using namespace std;
#define pb push_back
#define ALL(x) x.begin(),x.end()
#define VINT vector<int>
#define PII pair<int,int>
#define MP(x,y) make_pair((x),(y))
#define ll long long
#define ull unsigned long long
#define MEM0(x)  memset(x,0,sizeof(x))
#define scand(x) scanf("%d",&x)
#define Max(a,b) a=max(a,b)
#define DBL(x) ((x)*(x))
const int INF=0x3f3f3f3f;
int onenum_lrt(int x)
{
    int rnt_lrt=0;
    while(x)
    {
        rnt_lrt+=(x&1);
        x>>=1;
    }
    return rnt_lrt;
}

int main()
{
    //freopen("B-small-attempt0.in","r",stdin);
    //freopen("B-small-attempt0.out","w",stdout);
    int T;

    scanf("%d",&T);
    for(int t=1; t<=T; t++)
    {
        int n,r,c;
        scanf("%d%d%d",&r,&c,&n);
        int totnum=r*c;
        int limit = 1<<totnum;
        int ans_lrt=INF;
        for(int kind_lrt=0;kind_lrt<limit;kind_lrt++)
        {
            if(onenum_lrt(kind_lrt)!=n) continue;
            int rnt_lrt=0;
            for(int i=0;i<totnum;i++)
            {
                if(kind_lrt & (1<<i))
                {
                    if((i+1)%c!=0 && (kind_lrt & (1<<(i+1))))
                        rnt_lrt++;
                    if(i+c<totnum && (kind_lrt & (1<<(i+c))))
                        rnt_lrt++;
                }
            }
            ans_lrt=min(ans_lrt,rnt_lrt);
        }
        printf("Case #%d: %d\n",t,ans_lrt);
    }
    return 0;
}
