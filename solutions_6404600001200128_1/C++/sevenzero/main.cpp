#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    freopen("t.in","r",stdin);
    freopen("t.out","w",stdout);
    int t;
    scanf("%d",&t);
    for(int cc=0;cc<t;cc++)
    {
        int n;
        scanf("%d",&n);
        int num[10001];
        for(int i=0;i<n;i++)
            scanf("%d",&num[i]);
        int s1=0,s2=0,maxdf=0;
        for(int i=0;i<n-1;i++)
        {
            if(num[i]>num[i+1])
            {
                s1+=num[i]-num[i+1];
                maxdf=max(maxdf,num[i]-num[i+1]);
            }

        }
        for(int i=0;i<n-1;i++)
        {
            if(num[i]<maxdf)
                s2+=num[i];
            else
                s2+=maxdf;
        }
        printf("Case #%d: %d %d\n",cc+1,s1,s2);
    }
    return 0;
}
