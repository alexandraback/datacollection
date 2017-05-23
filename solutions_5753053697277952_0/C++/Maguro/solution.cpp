#include<bits/stdc++.h>
#define X first
#define Y second
#define MP make_pair
#define EB emplace_back
using namespace std;
int a[30];
priority_queue<pair<int,int> > pq;
int main()
{
    int t,T,i,j,k,sum=0,w,id,n;
//    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    scanf("%d",&T);
    for(t=1;t<=T;t++)
    {
        scanf("%d",&n);
        sum=0;
        for(i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
            sum+=a[i];
            if(a[i]>0)
                pq.emplace(a[i],i);
        }
        printf("Case #%d:",t);
        while(!pq.empty())
        {
            printf(" ");
            if(sum!=3)
            {
                tie(w,id)=pq.top();
                pq.pop();
                printf("%c",id+'A');
                if(w-1>0)
                    pq.emplace(w-1,id);
                tie(w,id)=pq.top();
                pq.pop();
                printf("%c",id+'A');
                if(w-1>0)
                    pq.emplace(w-1,id);
                sum-=2;
            }
            else
            {
                tie(w,id)=pq.top();
                pq.pop();
                printf("%c",id+'A');
                if(w-1>0)
                    pq.emplace(w-1,id);
                sum--;
            }
        }
        printf("\n");
    }
}

