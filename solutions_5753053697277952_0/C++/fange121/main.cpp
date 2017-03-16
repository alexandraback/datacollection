#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <queue>
#include <cstdio>
using namespace std;
#define N 1001000
typedef __int64 ll;
int a[N];
struct NODE{
    int x,val;
    friend bool operator< (NODE n1,NODE n2)  //可以自动排列的方式,价格最小的放在最下,最大的放在最上//
    {
        return n1.val<n2.val;
    }
};

priority_queue<NODE>q;    //可以自动排列的队列//
int main()
{
    NODE tmp,tmp1;
    int T,n,i,i1=1;
    freopen("A-small-attempt1.in","r",stdin);
    freopen("out.txt","w",stdout);
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        for(i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
            tmp.x=i;tmp.val=a[i];
            q.push(tmp);
        }
        printf("Case #%d:",i1++);
        while(!q.empty())
        {
            tmp=q.top();
            q.pop();
            if(!q.empty())
            {
                tmp1=q.top();
                q.pop();
                if(tmp.val==1&&!q.empty())
                {
                    q.push(tmp1);
                    printf(" %c",tmp.x+'A');
                }
                else
                {
                    tmp1.val--;
                    tmp.val--;
                    printf(" %c%c",tmp.x+'A',tmp1.x+'A');
                    if(tmp.val>0)
                    {
                        q.push(tmp);
                    }
                    if(tmp1.val>0)
                    {
                        q.push(tmp1);
                    }
                }
            }
            else
            {
                tmp.val--;
                printf(" %c",tmp.x+'A');
                if(tmp.val>0)
                    q.push(tmp);
            }
        }
        printf("\n");
    }
    return 0;
}
