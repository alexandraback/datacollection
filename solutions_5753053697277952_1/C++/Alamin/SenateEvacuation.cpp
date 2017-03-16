/*Author : Md. Al- Amin
           20th batch
           Dept. of CSE, SUST*/
#include<stdio.h>
#include<math.h>
#include<string.h>
#include<iostream>
#include<algorithm>
#include<stack>
#include<map>
#include<set>
#include<queue>
#include<vector>
#define pi (2*acos(0))
#define SF scanf
#define SFd1(a) scanf("%d",&a)
#define SFd2(a,b) scanf("%d%d",&a,&b)
#define SFd3(a,b,c) scanf("%d%d%d",&a,&b,&c)
#define PF printf
#define inf 99999999
#define eps 0.00000001
#define ll long long
#define ull long long unsigned
#define int_max 2147483647
#define int_min -2147483648
#define long_max 9223372036854775807
#define long_min -9223372036854775808
#define fr(i,n) for(i=0;i<n;i++)
#define ms(dp,a) memset(dp,a,sizeof(dp))
#define dist(x1,y1,x2,y2) sqrt( ((x2-x1)*(x2-x1)) + ((y2-y1)*(y2-y1)) )
#define PB push_back
#define mem(arr,val) memset(arr,val,sizeof(arr))

using namespace std;
//int rr[]={1,2,-1,-2,1,2,-1,-2};
//int cc[]={2,1,2,1,-2,-1,-2,-1};
//int rr[]={0,0,1,-1};
//int cc[]={-1,1,0,0};

struct node{
int val;
char ind;
};

node in;
priority_queue<node>pq;

bool operator<(node a,node b)
{
    return a.val<b.val;
}

int t,p,i,n;

int main()
{
    freopen("A-largec.in","r",stdin);
    freopen("SenateOutL.txt","w",stdout);

    scanf(" %d",&t);

    for(p=1;p<=t;p++)
    {
        while(!pq.empty())
            pq.pop();
        scanf(" %d",&n);
        for(i=0;i<n;i++)
        {
            scanf(" %d",&in.val);
            in.ind=(char)(i+'A');
            pq.push(in);
        }
        printf("Case #%d:",p);

        if(n==2)
        {
            int aa=pq.top().ind;
            pq.pop();
            int bb=pq.top().ind;
            for(i=0;i<pq.top().val;i++)
                printf(" %c%c",aa,bb);
            printf("\n");
            pq.pop();
            continue;
        }

        while(pq.size()>2)
        {
            in=pq.top();
            pq.pop();
            in.val--;
            printf(" %c",in.ind);
            if(in.val>0)
            {
                pq.push(in);
            }
        }
        printf(" %c",pq.top().ind);
        pq.pop();
        printf("%c",pq.top().ind);
        pq.pop();
        printf("\n");
    }

    return 0;
}

