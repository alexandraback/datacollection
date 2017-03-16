# include<cstdio>
# include<algorithm>
# include<iostream>
# include<cstring>
# include<string>
# include<cmath>
# include<queue>

# define N 1010
# define M 100010

typedef long long ll;

using namespace std;

struct state
{
    int id;
    int t;
    int rate;
    bool operator<(const state &rhs) const
    {
        if(t != rhs.t)  return t > rhs.t;
        else    return id > rhs.id;
    }
}a[N];
priority_queue<state> pque;
int n,m;

int gcd(int a,int b)
{
    if(b == 0)  return a;
    else    return gcd(b,a%b);
}
int main()
{
    freopen("C:\\Users\\DELL\\Desktop\\A\\B-small-attempt4.in","r",stdin);
    freopen("C:\\Users\\DELL\\Desktop\\A\\out.out","w",stdout);
    int test;scanf("%d",&test);
    for(int T=1;T<=test;T++)
    {
        while(pque.size())  pque.pop();
        scanf("%d%d",&n,&m);
        for(int i=0;i<n;i++)
        {
            scanf("%d",&a[i].rate);
            a[i].t=0,a[i].id=i+1;
            pque.push(a[i]);
        }
        int maxv=a[0].rate;
        for(int i=1;i<n;i++)
        {
            int minv=gcd(maxv,a[i].rate);
            maxv = (a[i].rate*maxv)/minv;
        }
        int cnt=0;
        for(int i=0;i<n;i++)
        {
            cnt+=maxv/a[i].rate;
        }
        m=(m-1)%cnt+1;
        state s;
        for(int i=0;i<m;i++)
        {
            s=pque.top();pque.pop();
            s.t+=s.rate;
            pque.push(s);
        }
        printf("Case #%d: %d\n",T,s.id);
    }
    return 0;
}

