#include <iostream>
#include <cstdio>
using namespace std;

int barb(long long l,long long r,int b,int bt[],int n)
{
    long long mid=(l+r)/2;
    //printf("mid: %lld\n",mid);
    long long hasproc=0,rd=0;
    int ret=-1;
    for(int i=0;i<b;i++)
    {
        hasproc+=mid/bt[i];
        if(mid%bt[i])
            hasproc++;

    }
    for(int i=0;i<b;i++)
    {
        if(mid%bt[i]==0)
        {
            rd++;
            if(hasproc+rd==n)
                ret=i;
        }
    }

    if(hasproc>=n)
        ret=barb(l,mid,b,bt,n);
    else if(hasproc+rd<n)
        ret=barb(mid,r,b,bt,n);

    return ret;


}

int main()
{
    freopen("t.in","r",stdin);
    freopen("t.out","w",stdout);
    int t;
    scanf("%d",&t);
    for(int cc=0;cc<t;cc++)
    {
        int b,n;
        int bt[10001];
        scanf("%d%d",&b,&n);
        for(int i=0;i<b;i++)
        {
            scanf("%d",&bt[i]);
        }



        printf("Case #%d: %d\n",cc+1,barb(0,1LL<<60,b,bt,n)+1);
    }

    return 0;
}
