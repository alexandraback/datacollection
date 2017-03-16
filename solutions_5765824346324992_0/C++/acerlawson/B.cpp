#include<cstdio>
#include<cstring>
#include<cmath>
#include<string>
#include<algorithm>
#include<iostream>
#include<vector>
#include<queue>
#include<map>
#include<set>
#include<stack>

#define msn(x) (memset((x),0,sizeof((x))))
#define msx(x) (memset((x),0x7f,sizeof((x))))
#define fuck(x) cerr << #x << " <- " << x << endl
#define acer cout<<"sb"<<endl
typedef long long ll;
using namespace std;
#define inf 0x3f3f3f3f
#define eps 1e-8
#define pi acos(-1.0)


  int gcd(int x , int y)
{
    return y == 0 ? x : gcd(y , x%y);
}

struct node
{
    int t,id;
    bool operator<(const node a)const{
            if(t==a.t)return id>a.id;
            else return  t>a.t;
	}
};
int sb;
int n,m;
int p[5];
int work()
{
  //  fuck(sb);
    priority_queue<node>q;
    if(m<=n)
    {
        return m;
    }
    m-=n;
    for(int i=0;i<n;i++)
    {
        q.push((node){p[i],i});
    }
    node now;
    while(m--)
    {
        now=q.top();q.pop();
        q.push((node){now.t+p[now.id],now.id});
    }
    return now.id+1;
}
int main()
{
    int T;
   // freopen("B-small-attempt0.in","r",stdin);
   // freopen("B.out","w",stdout);
    scanf("%d",&T);
    for(int cas=1;cas<=T;cas++)
    {
        sb=1;
        scanf("%d%d",&n,&m);
        for(int i=0;i<n;i++)
        {
            scanf("%d",&p[i]);
            sb=(sb*p[i])/gcd(sb,p[i]);
        }
        int re=0;
        for(int i=0;i<n;i++)
        {
            re+=sb/p[i];
        }
        sb=re;
        m=m%sb;
        if(m==0)m=sb;
        printf("Case #%d: %d\n",cas,work());
    }
    return 0;
}
