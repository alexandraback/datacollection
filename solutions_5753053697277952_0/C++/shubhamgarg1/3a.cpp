#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//string a1[200],a2[200];
//string ans1,ans2;
//int b1[100005],b2[100005],n;
int a[105];
int min1=INT_MAX;
typedef pair<int,int> ii;

ll fk[105];

int main()
{
    ll t,p,i,j,r,c=1,k,n;

    freopen("A-small-attempt0 (5).in","r",stdin);
    freopen("output.txt","w",stdout);
    scanf("%lld",&t);
    while(t--)
    {
        scanf("%lld",&n);
        ll count1=0;
        priority_queue<ii,vector<ii> > pq;
        for(i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
            pq.push(ii(a[i],i));
            count1+=a[i];
        }
        printf("Case #%lld: ",c++);

        while(!pq.empty())
        {
            int v=pq.top().first;
            int d=pq.top().second;

            pq.pop();

            if(count1==3 )
            {
                printf("%c ",d+65);
                v=v-1;
                if(v>0)
                pq.push(ii(v,d));
                count1-=1;
                continue;
            }


            int v1=pq.top().first;
            int d1=pq.top().second;

            if(v>v1)
            {
                printf("%c ",d+65);
                v=v-1;
                count1-=1;
                if(v>0)
                pq.push(ii(v,d));
                continue;
            }

            pq.pop();

            /*if(v>v1)
            {
                printf("%c%c ",d+65,d+65);
                v=v-2;
                if(v>0)
                {
                    pq.push(ii(v,d));
                }
            }
            else
            {*/
                printf("%c%c ",d+65,d1+65);
                v=v-1;
                v1-=1;
                count1-=2;
                if(v>0)
                {
                    pq.push(ii(v,d));
                }
                if(v1>0)
                {
                    pq.push(ii(v1,d1));
                }




        }
         printf("\n");

            //printf("%lld\n",p);


    }
    return 0;
}
