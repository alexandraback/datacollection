#include<bits/stdc++.h>
#define pb push_back
#define tr(c,i) for(typeof((c).begin() )i = (c).begin(); i != (c).end(); i++)
#define mod 1000000007
#define ii  pair<int,int>

using namespace std;
typedef long long ll;



using namespace std;
struct node
{
    int nm,tm;
}nd[2000010];

int cmp(const void *a,const void *b)
{
    node *va=(node *)a;
    node *vb=(node *)b;
    if(va->tm==vb->tm)
    return va->nm-vb->nm;
    else
    return va->tm-vb->tm;
}

int g(int a,int b)
{
    if(b==0)
    return a;
    else
    return g(b,a%b);
}
int lc(int a,int b)
{
    int lcm=(a*b)/g(a,b);
    return lcm;
}


int main()
{
  int n,m,i,j,k,ans1,ans2,mn,mx,tst,t,a[10],lcm,b;

freopen("B-small-attempt0.in", "r", stdin);
freopen("BOUT-attempt0.txt", "w", stdout);
scanf("%d",&t);
for(tst=1;tst<=t;tst++)
{
     scanf("%d%d",&b,&n);
     for(i=0;i<b;i++)
     cin>>a[i];
     mx=1;
     lcm=a[0];
     for(i=1;i<b;i++)
     lcm=lc(lcm,a[i]);
     k=0;
     for(i=0;i<b;i++)
     {
         nd[k].nm=i;
         nd[k].tm=1;
         k++;

     }
     for(i=0;i<b;i++)
     {

         j=1;
         while(j+a[i]<=lcm)
         {
             nd[k].nm=i;
             nd[k].tm=j+a[i];
             k++;
             j+=a[i];
         }
     }
     qsort(nd,k,sizeof(node),cmp);
     i=(n%k)-1;
     if(i<0)
     i+=k;
     printf("Case #%d: %d\n",tst,nd[i].nm+1);
}



    return 0;
}
