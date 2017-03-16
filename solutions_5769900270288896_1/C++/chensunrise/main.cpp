//#pragma comment(linker, "/STACK:102400000,102400000")
#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
#define PI  acos(-1.0)
#define eps 1e-8
#define LL  long long
#define PB  push_back
#define MP  make_pair
#define PQ  priority_queue
#define MII map<int,int>::iterator
#define MLL map<LL,LL>::iterator
#define PII pair<int,int>
#define SI  set<int>::iterator
#define SL  set<LL>::iterator
#define MSI map<string,int>::iterator
#define IN  freopen("in.txt","r",stdin);
#define OUT freopen("out.txt","w",stdout);
#define BUG printf("bug************bug************bug\n");

#define MEM(a,b) memset(a,b,sizeof(a))
#define M_SI     multiset<int>::iterator

using namespace std;

const int maxn=10000+10;
struct node
{
    int x;
    node(int x=0):x(x){}
    bool operator<(const node& A)const
    {
        return x>A.x;
    }
};
PQ<node>q;
short s[maxn][maxn];
int dx[4]={0,0,-1,1};
int dy[4]={1,-1,0,0};


int main()
{
    IN; OUT;
    int t,cas=0,n,m,k,K;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d%d",&n,&m,&K);
        for (int i=1;i<=n;i++) for (int j=1;j<=m;j++) s[i][j]=1;
        int u=1,v=2;
        for (int i=1;i<=n;i++)
        {
            u=3-v;
            while(u<=m) {s[i][u]=0;u+=2; }
            v=3-v;
        }
        int num1=0;
        while(!q.empty()) q.pop();
        for (int i=1;i<=n;i++)
        for (int j=1;j<=m;j++)
        {
            int tp=0;
            if (!s[i][j]) {num1++;continue;}
            for (int ii=0;ii<4;ii++)
            {
                int x=i+dx[ii];
                int y=j+dy[ii];
                if (x>=1 && x<=n && y>=1 && y<=m && s[x][y]==0) tp++;
            }
            q.push(node(tp));
        }
        if (K<=num1) {printf("Case #%d: 0\n",++cas);continue;}
        k=K-num1;
        int ans1=0,ans2=0;
        while(k--)
        {
            node tp=q.top(); q.pop();
            ans1+=tp.x;
        }

        int num2=0;
        while(!q.empty()) q.pop();
        for (int i=1;i<=n;i++)
        for (int j=1;j<=m;j++)
        {
            int tp=0;
            if (s[i][j]) {num2++;continue;}
            for (int ii=0;ii<4;ii++)
            {
                int x=i+dx[ii];
                int y=j+dy[ii];
                if (x>=1 && x<=n && y>=1 && y<=m && s[x][y]==1) tp++;
            }
            q.push(node(tp));
        }
        if (K<=num2) {printf("Case #%d: 0\n",++cas);continue;}
        k=K-num2;
        while(k--)
        {
            node tp=q.top(); q.pop();
            ans2+=tp.x;
        }
        printf("Case #%d: %d\n",++cas,min(ans1,ans2));
    }
    return 0;
}
