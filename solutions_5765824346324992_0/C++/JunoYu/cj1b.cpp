#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<map>
#include<vector>
#include<queue>
#include<cmath>
#include<stack>
#include<queue>
#include<bitset>
#define N 111111
#define lc(x) (x<<1)
#define rc(x) (lc(x)|1)
#define INF 0x3f3f3f3f
#define mod 1000000007
#define LL long long
#define CLR(a,b) memset(a,b,sizeof(a))
#define FOE(i,a,b) for(int i=a;i<=b;++i)
#define FOD(i,a,b) for(int i=a;i>=b;--i)
using namespace std;
int n,m,q,t,cs=0;
int dx[4]={0,0,-1,1},dy[4]={1,-1,0,0};
int sg[N<<4];
int B,M[N];
void pu(int x){
    sg[x]=sg[lc(x)]+sg[rc(x)];
}
void bt(int x,int l,int r){
    if(l==r){
        sg[x]=1;
        return;
    }
    int md=(l+r)>>1;
    bt(lc(x),l,md);
    bt(rc(x),md+1,r);
    pu(x);
}
int qry(int x,int l,int r){
    if(sg[x]<=0)return -1;
    if(l==r)return l;
    int md=(l+r)>>1;
    if(sg[lc(x)]>=1)return qry(lc(x),l,md);
    else return qry(rc(x),md+1,r);
}
void edt(int x,int l,int r,int p,int v){
    if(sg[x]<=0)return ;
    if(l==r){
        sg[x]=v;return;
    }
    int md=(l+r)>>1;
    if(p<=md)edt(lc(x),l,md,p,v);
    else edt(rc(x),md+1,r,p,v);
    pu(x);
}
struct node{
    int id,time;
    node(int x,int y){
        id=x,time=y;
    }
    bool operator<(const node &a)const{
        if(time!=a.time)return time>a.time;
        else return id>a.id;
    }
};
priority_queue<node> Q; 
int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&B,&n);
        FOE(i,1,B)scanf("%d",&M[i]);
        /*
           int gg=qry(1,1,B);
           printf("gg:%d\n",gg);
           edt(1,1,B);
           gg=qry(1,1,B);
           printf("gg:%d\n",gg);
           */
        int mx=0,mxid;
        FOE(i,1,B)if(M[i]>=mx)mx=max(M[i],mx),mxid=i;
        LL cycle=0;
        FOE(i,1,B)cycle += (mx/M[i]);
        //printf("cycle:%lld\n",cycle);
        n%=cycle;
        //printf("tg:%d\n",n);
        while(Q.size())Q.pop();
        int ans=-1;
        if(n==0)n=cycle;
        FOE(i,1,B)Q.push(node(i,0));
        //bt(1,1,B);
        for(int i=0;i<n;++i){
            node wt=Q.top();Q.pop();
            ans=wt.id;
            //printf("i:%d ans:%d\n",i,ans);
            Q.push(node(wt.id,wt.time+M[wt.id]));
        }
        printf("Case #%d: %d\n",++cs,ans);
    }
    return 0;
}
