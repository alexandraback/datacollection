#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <queue>
#include <vector>
#include <map>
#define pb push_back
#define mp make_pair
#define eps 1e-9
#define zero(x) (fabs(x)<eps)
#define pi acos(-1.0)
#define f1 first
#define f2 second
#define ms(x,y) memset(x,y,sizeof(x))
#define fr(i,x,y) for(int i=x;i<=y;i++)
using namespace std;
typedef long long LL;
typedef pair <int, int> PII;
template<typename X> inline bool minimize(X&p,X q){if(p<=q)return 0;p=q;return 1;}
template<typename X> inline bool maximize(X&p,X q){if(p>=q)return 0;p=q;return 1;}
int a[30];
struct node{
    int v;
    char id;
    bool operator<(const node&oth)const{
        return v>oth.v;
    }
}b[30];
int n;

void output(int x,int tim)
{
    fr(tt,1,tim)
    {
        if (x%2==1)
        {
            printf(" %c",b[1].id);
            fr(i,1,x/2)
            printf(" %c%c",b[i*2].id,b[i*2+1].id);
        }
        else
        fr(i,1,x/2)
            printf(" %c%c",b[i*2-1].id,b[i*2].id);
    }
}
void doit()
{
   scanf("%d",&n);
   int tot=0;
   fr(i,1,n)
   {
       scanf("%d",&a[i]);
       tot+=a[i];
   }

   fr(i,1,n)
        {   b[i].id=i+'A'-1;
            b[i].v=a[i];
        }
   sort(b+1,b+1+n);
   b[n+1].v=-1;
   while (1)
   {   int br;
       for(int i=1;i<=n;i++)
            if (b[i].v!=b[i+1].v) {br=i;break;}
       if (br==n) break;
       int tim=b[br].v-b[br+1].v;

       output(br,tim);
       for(int i=1;i<=br;i++)
            b[i].v=b[br+1].v;
   }
   //printf("%d %d %c %c\n",b[1].v,b[2].v,b[1].id,b[2].id);
   output(n,b[1].v);
   printf("\n");
}

int main()
{
    freopen("A0.in","r",stdin);
    freopen("A0.txt","w",stdout);
    int cas,i=0;
    scanf("%d",&cas);
    while (cas--)
    {   printf("Case #%d:",++i);
        doit();
    }
}
