//Hello. I'm Peter.
#include<cstdio>
#include<iostream>
#include<sstream>
#include<cstring>
#include<string>
#include<cmath>
#include<cstdlib>
#include<algorithm>
#include<functional>
#include<cctype>
#include<ctime>
#include<stack>
#include<queue>
#include<vector>
#include<set>
#include<map>
using namespace std;
typedef long long ll;
typedef long double ld;
//const double pi=acos(-1.0);
//const double eps=1e-9;
#define peter cout<<"i am peter"<<endl
#define input freopen("data.txt","r",stdin)
#define randin srand((unsigned int)time(NULL))
#define INT (0x3f3f3f3f)*2
#define LL (0x3f3f3f3f3f3f3f3f)*2
#define gsize(a) (int)a.size()
#define len(a) (int)strlen(a)
#define slen(s) (int)s.length()
#define clr(a) memset(a,0,sizeof(a))
#define clr_true(a) memset(a,true,sizeof(a))
#define clr_queue(q) while(!q.empty()) q.pop()
#define clr_stack(s) while(!s.empty()) s.pop()
#define rep(i, a, b) for (int i = a; i < b; i++)
#define dep(i, a, b) for (int i = a; i > b; i--)
#define repin(i, a, b) for (int i = a; i <= b; i++)
#define depin(i, a, b) for (int i = a; i >= b; i--)
#define MAXN
#define N 1024
#define M
ll b[N];
int nb,n;
struct Data{
    int id;
    ll lasttime;
}data[N];
inline bool comp(const Data a,const Data b){
    if(a.lasttime!=b.lasttime) return a.lasttime<b.lasttime;
    else return a.id<b.id;
}
int main(){
    //freopen("B-large (1).in","r",stdin);
    //freopen("outputbig.txt","w",stdout);
    //input;
    int T;
    scanf("%d",&T);
    repin(Case,1,T){
        scanf("%d%d",&nb,&n);
        repin(i,1,nb){
            scanf("%lld",b+i);
        }
        ll l=1,r=1e15,mid;
        while(l<r){
            mid=(l+r)>>1;
            ll numt=0;
            repin(i,1,nb){
                numt+=mid/b[i];
                if(mid%b[i]) numt+=1;
            }
            if(numt>=n) r=mid;
            else l=mid+1;
        }
        repin(i,1,nb){
            ll t;
            if(l%b[i]==0) t=l-b[i];
            else t=(l/b[i])*b[i];
            data[i].id=i;
            data[i].lasttime=t;
        }
        ll served=0;
        repin(i,1,nb){
            ll t;
            t=l/b[i];
            if(l%b[i]==0) t-=1;
            served+=t;
        }
        n-=served;
        sort(data+1,data+1+nb,comp);
        int ans=data[n].id;
        printf("Case #%d: %d\n",Case,ans);
    }
    return 0;
}




















