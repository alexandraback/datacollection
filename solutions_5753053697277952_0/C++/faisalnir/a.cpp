#include<bits/stdc++.h>
#define pb push_back
#define ll long long
#define pi acos(-1.)
using namespace std;
int a[26];
bool make(int n)
{
    int sum=0;
    for(int i=0;i<n;i++)
    {sum+=a[i];

    }
    for(int i=0;i<n;i++)
    {
        if(a[i]>sum-a[i])return 0;

    }
    return 1;
}
int main()
{
    freopen("A-small-attempt0.in","r",stdin);
    freopen("out.txt","w",stdout);
   int t;
   scanf("%d",&t);
   for(int c=1;c<=t;c++)
   {
        int n;
        scanf("%d",&n);
        int sum=0;
        for(int i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
            sum+=a[i];
        }
        printf("Case #%d:",c);
        while(1)
        {
            int cnt=0;
            int i;
            for( i=0;i<n;i++)
            {

                if(a[i])
                {
                    a[i]--;
                    int x=make(n);
                    if(x)
                    {
                       printf(" %c",i+'A');
                       break;
                    }
                    else a[i]++;
                }
                else cnt++;
            }
            if(cnt==n)break;
            cnt=0;
            if(i==n)
            {
               for(int i=0;i<n;i++)
               {
                   for(int j=0;j<n;j++)
                   {
                       a[i]--;
                       a[j]--;
                       if(a[i]>=0 && a[j]>=0 && make(n))
                       {
                           printf(" %c%c",'A'+i,'A'+j);
                           break;


                       }
                       else{ a[i]++;
                       a[j]++;}
                   }
               }
            }

            if(cnt==n)break;
        }
        printf("\n");
   }

}
