/* ***********************************************
Author        :Eopxt
Created Time  :Sun 08 May 2016 05:07:03 PM CST
File Name     :A.cpp
************************************************ */

#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <sstream>
#include <map>
#include <string>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <queue>
using namespace std;
#define rep(i,n) for (int i=1; i<=(n); i++)
#define REP(i,n) for (int i=0; i<(n); i++)
#define For(i,s,t) for (int i=(s); i<=(t); i++)
#define FOR(i,s,t) for (int i=(s); i>=(t); i--)
#define foreach(j,x) for(int j=adj[x]; j>=0; j=E[j].nxt)
#define Foreach(it,v) for(__typf((v).begin()) it=(v).begin(); it!=(v).end(); it++)
#define pb push_back
#define mp make_pair
#define INF 0x3f3f3f3f
#define mem(a,x) memset(a,x,sizeof(a))
#define X first
#define Y second
#define sqr(x) ((x)*(x))
#define C1(x) cout<<(x)<<endl
#define C2(x,y) cout<<(x)<<" "<<(y)<<endl
#define C3(x,y,z) cout<<(x)<<" "<<(y)<<" "<<(z)<<endl
typedef long long lld;
typedef vector<int> VI;
typedef pair<int,int> PII;
typedef vector< pair<int,int> > VPII;

int n,p[30];

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
#endif
    int cas; scanf("%d",&cas);
    rep(cs,cas) {
        scanf("%d",&n);
        int peo=0;
        rep(i,n) {
            scanf("%d",&p[i]);
            peo+=p[i];
        }
        printf("Case #%d:",cs);
        while (peo>0) {
            int m1=0,m2=0;
            rep(i,n) {
                if (p[i]>p[m1]) 
                {
                    m2=m1; m1=i;
                }
                else {
                    if (p[i]>p[m2]) m2=i;
                }
            }
            if (peo==3) {
                printf(" %c",m1+'A'-1);
                p[m1]--;
                peo--;
            }
            else {
                printf(" %c%c",m1+'A'-1,m2+'A'-1);
                p[m1]--; 
                p[m2]--; 
                peo-=2;
            }
        }
        printf("\n");
    }
    return 0;
}
