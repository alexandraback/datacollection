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
        int b,n;
        scanf("%d%d",&b,&n);

        ll mini=INT_MAX;
        for(int i=0;i<b;i++)
        {
            scanf("%d",&m[i]);
            if(m[i]<mini)
                mini=m[i];
        }

        ll lo=0,hi=(ll)mini*(n-1);
        ll mid;
        int ans=-1;
        while(lo<=hi)
        {
            mid=(lo+hi)/2;
            ll cutt=0;
            int numfree=0;
            for(int i=0;i<b;i++)
            {
                cutt+=mid/(ll)m[i];
                if(mid%m[i]==0)
                {
                    numfree++;
                }
                else
                    cutt++;
            }
            //printf("mid %lld cutt %lld numfree %d\n",mid,cutt,numfree);
            if(cutt>n-1)
                hi=mid-1;
            else
            {
                if(cutt+numfree>=n)
                {
                    int freeid=n-cutt-1;
                    for(int i=0;i<b;i++)
                    {
                        if(freeid==0 && mid%m[i]==0)
                        {
                            ans=i;
                            break;
                        }
                        else if(mid%m[i]==0)
                            freeid--;
                    }
                    hi=mid-1;
                }
                else
                {
                    lo=mid+1;
                }
            }
        }
        printf("Case #%d: %d\n",tt,ans+1);
    }
    return 0;
}
