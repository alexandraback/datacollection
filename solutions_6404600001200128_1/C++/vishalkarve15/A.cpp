#include<bits/stdc++.h>

using namespace std;

#define pii pair<int,int>
#define mp make_pair
#define pb push_back
#define ll long long

int m[1010];

int main()
{
    int t;
    scanf("%d",&t);
    for(int tt=1;tt<=t;tt++)
    {
        int n;
        scanf("%d",&n);

        for(int i=0;i<n;i++)
            scanf("%d",&m[i]);
        int ans1=0;
        for(int i=0;i+1<n;i++) {
            if(m[i]<=m[i+1])
                continue;
            ans1+=m[i]-m[i+1];
        }
        int ans2=INT_MAX;
        int maxd=0;
        for(int i=0;i+1<n;i++)
            if(m[i]-m[i+1]>maxd)
                maxd=m[i]-m[i+1];

        int lo=0,hi=maxd;
        int mid;
        while(lo<=hi)
        {
            mid=(lo+hi)/2;
            int cand=0;
            bool imp=0;
            for(int i=1;i<n;i++)
            {
                if(m[i-1]-mid>m[i])
                {
                    imp=1;
                    break;
                }
                if(m[i-1]-mid<0)
                    cand+=m[i-1];
                else
                    cand+=mid;
            }
            if(imp)
            {
                lo=mid+1;
            }
            else
            {
                ans2=min(ans2,cand);
                hi=mid-1;
            }
        }
        printf("Case #%d: %d %d\n",tt,ans1,ans2);
    }
    return 0;
}
