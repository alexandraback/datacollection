#include<cstdio>
#include<algorithm>
using namespace std;
int arr[200],b;
long long int bin_search(long long int l,long long r,long long int n)
{
    if(l==r)
        return l;
    if(l>r)
        return r;
    long long mid=(l+r)/2;
    int count=0;
    for(int i=1;i<=b;i++)
    {
        count+=(mid/arr[i]);
    }
    if(count==n)
    {
        return mid;
    }
    else
    {
        if(count>n)
        {
            return bin_search(l,mid-1,n);
        }
        else
        {
            return bin_search(mid+1,r,n);
        }
    }
}
int main()
{
    int t,i,j,ans,k,min_time;
    long long time,n,counter;
    scanf("%d",&t);
    for(i=1;i<=t;i++)
    {
        scanf("%d%lld",&b,&n);
        ans=0;
        min_time=1000000000;
        for(j=1;j<=b;j++)
        {
            scanf("%d",arr+j);
            min_time=min(arr[j],min_time);
        }
        if(b>=n)
            ans=n;
        else
        {
            time=bin_search(0,n*min_time,n-b);
            counter=b;
            time-=min_time;
            if(time<0)
                time=0;
            for(j=1;j<=b;j++)
            {
                counter+=time/arr[j];
            }
            time++;
            while(counter<n)
            {
                for(j=1;j<=b;j++)
                {
                    if(time%arr[j]==0)
                    {
                        counter++;
                        if(counter==n)
                        {
                            break;
                        }
                    }
                }
                if(j!=b+1)
                    ans=j;
                time++;
            }
            if(ans==0)
                ans=b;
        }
        printf("Case #%d: %d\n",i,ans);
    }
    return 0;
}
