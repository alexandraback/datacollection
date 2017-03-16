#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cstring>
#include <map>
#include <queue>

using namespace std;

typedef long long ll;

const int MAXN=250010;
const int MOD=1000000;

int n,x[MAXN],v[MAXN],c[110];

void init()
{
    for(int i=0;i<n;++i)
        scanf("%d%d",x+i,v+i);
}
void solve1()
{
    int ans=0;
    memset(c,0,sizeof(c));
    for(int i=0;i<n;++i)
    {
        int now=0;
        c[v[i]]++;
        for(int j=v[i]+1;j<104;++j)
            now+=c[j];
        ans=(ans+now)%MOD;
    }
    printf("%d\n",ans);
}

struct Node
{
    int a,b,ts,dx,dv;
    Node(int _a,int _b,int _ts,int _dx,int _dv):a(_a),b(_b),ts(_ts),dx(_dx),dv(_dv){}
    friend bool operator < (const Node &x,const Node &y)
    {
        if((ll)x.dx*y.dv != (ll)y.dx*x.dv) return (ll)x.dx*y.dv > (ll)y.dx*x.dv;
        return x.ts > y.ts;
    }
};
int rank[MAXN];

bool check(int i,int j)
{
    return v[i]>v[j];
}
void solve2()
{
    priority_queue<Node> Q;

    for(int i=0;i<n;++i) rank[i]=i;
    for(int i=0;i<n-1;++i)
        if(check(i,i+1))
            Q.push(Node(i,i+1,i,x[i+1]-x[i],v[i]-v[i+1]));
    int cnt=0;
    while(!Q.empty())
    {
        Node tp=Q.top();Q.pop();
        int fst=tp.a,nxt=tp.b;
        if(rank[tp.ts]==fst && rank[tp.ts+1]==nxt)
        {
            printf("%d %d\n",fst+1,nxt+1);
            if(++cnt==10000)break;
            swap(rank[tp.ts],rank[tp.ts+1]);
            if(tp.ts>0)
            {
                int a=rank[tp.ts-1],b=rank[tp.ts];
                if(check(a,b))Q.push(Node(a,b,tp.ts-1,x[b]-x[a],v[a]-v[b]));
            }
            if(tp.ts+1!=n-1)
            {
                int a=rank[tp.ts+1],b=rank[tp.ts+2];
                if(check(a,b))Q.push(Node(a,b,tp.ts+1,x[b]-x[a],v[a]-v[b]));
            }
        }
    }
}
int main()
{
//    freopen("in.txt","r",stdin);
    while(scanf("%d",&n)!=EOF)
    {
        printf("Case #%d: %d\n", T, N);
        init();
        solve1();
        solve2();
    }
    return 0;
}