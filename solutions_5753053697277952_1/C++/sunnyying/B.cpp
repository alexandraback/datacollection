#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <queue>
#include <set>
#include <map>
using namespace std;
#define  ll unsigned long long
#define endl '\n'
#define INF 0x3f3f3f3f
struct node
{
    int x,i;
    bool operator < (const node &a) const {
        return x<a.x;
    }
}a[50];
int main()
{
  // freopen("Binput.txt","r",stdin);
 // freopen("Boutput.txt","w",stdout);
   int n,t,cas=1,sum;
   scanf("%d",&t);
   while(t--)
   {
       scanf("%d",&n);
       sum=0;
       priority_queue<node>q;
       for(int i=0;i<n;i++)
       {
           scanf("%d",&a[i].x),a[i].i=i;
           q.push(a[i]);
           sum+=a[i].x;
       }
       printf("Case #%d: ",cas++);
       while(sum)
       {
           node e=q.top();q.pop();
           node ee=q.top();q.pop();
         //  cout<<sum<<" "<<e.x<<" "<<ee.x<<endl;
           if(ee.x>(sum-1)/2)
           {
               if(sum==2) printf("%c%c\n",'A'+e.i,'A'+ee.i);
               else printf("%c%c ",'A'+e.i,'A'+ee.i);
               sum-=2;
               e.x--;ee.x--;
               q.push(e),q.push(ee);
            //   cout<<" **"<<endl
           }
           else
           {
               printf("%c ",'A'+e.i);
               e.x--;
               q.push(e);
               q.push(ee);
               sum--;
           }
       }
   }
   return 0;
}
