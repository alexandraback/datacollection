#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <string.h>
#include <string>
#include <vector>
#include <queue>
#include <map>
using namespace std;
#define mp make_pair
#define pb push_back
#define x first
#define y second
#define vi vector<int>
#define pii pair<int,int>
#define all(x) x.begin(),x.end()
#define ll long long
#define ull long long
#define inf 1000000007
#define mod 1000000007
#define DBG(x) cerr<<#x<<"="<<x<<"\n";
#define FOREACH(it,x) for(__typeof(x.begin())it=x.begin();it!=x.end();it++)
#define N 10005

pii a[N];int q[20];
ll dat(pii a,pii b,pii c){
    ll x1=b.x-a.x,y1=b.y-a.y;
    ll x2=c.x-a.x,y2=c.y-a.y;
    return x1*y2-x2*y1;
}
int head=0,tail=-1;
void solve(vector<pii> &b){
    sort(all(b));
    int i,n=b.size();head=0,tail=-1;q[++tail]=0;
    for(i=1;i<n;i++){
        while(head+1<=tail&&dat(b[q[tail-1]],b[q[tail]],b[i])<0)tail--;
        q[++tail]=i;
    }
    for(i=n-2;i>=0;i--){
        while(head+1<=tail&&dat(b[q[tail-1]],b[q[tail]],b[i])<0)tail--;
        q[++tail]=i;
    }
    tail--;
}
int main()
{
    freopen("input.in","r",stdin);
    freopen("out.txt","w",stdout);
    int T,i,j,k,ca=0,n,m;
    
    scanf("%d",&T);
    while(T--){
        printf("Case #%d:\n",++ca);
        scanf("%d",&n);
        for(i=0;i<n;i++)scanf("%d%d",&a[i].x,&a[i].y);
        vi v[16];
        for(i=1;i<1<<n;i++){
            for(j=0;j<n;j++)if(i>>j&1)v[j].pb(i);
        }
        for(i=0;i<n;i++){
            int ans=n-1;
            for(j=0;j<v[i].size();j++){
                int s=v[i][j];
                vector<pii> b;m=0;
                for(k=0;k<n;k++){
                    if(s>>k&1)b.pb(a[k]),m++;
                }
                solve(b);int ok=0;
                for(k=0;k<=tail;k++){
                    if(b[q[k]]==a[i]){
                        ok=1;
                    }
                }
                if(ok)ans=min(ans,n-m);
            }
            printf("%d\n",ans);
        }
    }
    return 0;
}