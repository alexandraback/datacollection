//GCJ 2016 round1C A
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>
#include <queue>
#define MAXN 30
using namespace std;
int p[MAXN];
int N;
int sum;
struct S
{
    int c;
    int id;
    bool operator<(const S& t)const
    {
        return c<t.c;
    }
}tmp;
priority_queue<S>pq;
void solve()
{
    while(pq.size()>0)
    {
        if(pq.size()==2)
        {

            tmp=pq.top();
            pq.pop();
            printf(" %c",tmp.id+'A');
            tmp.c-=1;
            if(tmp.c>0)pq.push(tmp);

            tmp=pq.top();
            pq.pop();
            printf("%c",tmp.id+'A');
            tmp.c-=1;
            if(tmp.c>0)pq.push(tmp);
            sum-=2;
        }
        else if(sum==2)
        {
            tmp=pq.top();
            pq.pop();
            printf(" %c",tmp.id+'A');
            tmp=pq.top();
            pq.pop();
            printf("%c",tmp.id+'A');
            sum=0;
            return;
        }
        else
        {
            tmp=pq.top();
            pq.pop();
            if(tmp.c>=1)
            {
                printf(" %c",tmp.id+'A');
                tmp.c-=1;
                sum--;
                if(tmp.c==0);
                else pq.push(tmp);
            }
        }
    }
}
int main()
{
    freopen("A-large.in","r",stdin);
    freopen("A-large.out","w",stdout);
    int Case;
    scanf("%d",&Case);
    for(int t=1;t<=Case;++t)
    {
        while(pq.size()>0)
            pq.pop();
        scanf("%d",&N);
        sum=0;
        for(int i=0;i<N;++i)
        {
            scanf("%d",&p[i]);
            sum+=p[i];
            tmp.c=p[i];
            tmp.id=i;
            pq.push(tmp);
        }
        printf("Case #%d: ",t);
        solve();
        printf("\n");

    }
    return 0;
}
