
#include<cstdio>
#include<set>
#include<map>
#include<iostream>
#include<queue>
#include<stack>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<cstdlib>
#include<cmath>
#include<ctime>
#define read freopen("in.txt","r",stdin)
#define maxlongint 2147483647
typedef  long long LL;
typedef  unsigned long long ULL;
#define fori for(i=1;i<=n;i++)
#define forj for(j=1;j<=m;j++)
#define fork for(k=1;k<=n;k++)
#define FOR(i,n) for(i=1;i<=n;i++)
#define REP(i,a,b) for(i=a;i<=b;i++)
#define DREP(i,a,b) for(i=a;i>=b;i--)
#define DOWN(i,n) for(i=n;i>=1;i--)
#define enter cout<<endl;
#define in push_back
#define out pop_back
#define lson 2*k
#define rson 2*k+1
#define offcin ios::sync_with_stdio(false)

#define s(n) scanf("%d",&n)
#define sll(n) scanf("%lld",&n)
#define sd(x,y) scanf("%d%d",&x,&y)
#define sch(s) scanf("%s",s)
#define fillfalse(v) memset(v,false,sizeof(v))
#define filltrue(v) memset(v,true,sizeof(v))
#define Fill0(a)    memset(a,0,sizeof(a))
#define Fillplus(a)    memset(a,-1,sizeof(a))
#define lowbit(x) x&(-x)
using namespace std;
const int maxn=100005;
const double pi=2*acos(0);
int T,ii,i,j,n,m,l,sum;
int m1,m2,l1,l2;
int a[30];
int main()
{
 freopen("A-small-attempt0.in","r",stdin);
 freopen("out.txt","w",stdout);
 cin>>T;
 FOR(ii,T)
 {
  cin>>n; sum=0;
  Fill0(a);
  fori {cin>>a[i]; sum+=a[i];}
  cout<<"Case #"<<ii<<": "<<endl;
  while(sum!=0)
  {
   if (sum==1) {sum=0;
   fori if(a[i]!=0) {a[i]--;printf("%c\n",'A'+(i-1));}
   }
   else{
   sum-=2;
   m1=0;
   fori if (a[i]>m1) {m1=a[i]; l1=i;}
   a[l1]--;
   m2=0;
    fori if (i!=l1&&a[i]>m2) {m2=a[i]; l2=i;}
    a[l2]--;
   if (sum==0) {printf("%c%c\n",'A'+(l1-1),'A'+(l2-1));}
   else printf("%c%c ",'A'+(l1-1),'A'+(l2-1));
   }
  }
 }
}
