#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<climits>
using namespace std;
int a[1005];
int b[1005];
int n;
int gcd(int x,int y)
{
    return y==0?x:gcd(y,x%y);
}
int lcm(int x,int y)
{
    return x*y/gcd(x,y);
}
int func()
{
    int ans=a[0];
    for(int i=1;i<n;i++)
    {
        ans=lcm(ans,a[i]);
    }
    return ans;
}
int main()
{
    freopen("B-small-attempt0.in","r",stdin);
    freopen("out.txt","w",stdout);
    int T;
    cin>>T;
    for(int tt=1;tt<=T;tt++)
    {
        int m;
        cin>>n>>m;
        memset(a,0,sizeof(a));
        memset(b,0,sizeof(b));
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
        }
        int num=func();
        int len=0;
        for(int i=0;i<n;i++)
        {
            len+=num/a[i];
        }
        int x=m%len;
        if(x==0)
        {
            x=m-(m/len-1)*len;
        }
        int ans=0;
        for(int i=0;i<x;i++)
        {
            int index=0;
            int temp=INT_MAX;
            for(int j=0;j<n;j++)
            {
                if(b[j]<temp)
                {
                    temp=b[j];
                    index=j;
                }
            }
            b[index]+=a[index];
            ans=index;
        }
        cout<<"Case #"<<tt<<": "<<ans+1<<endl;
    }
    return 0;
}

