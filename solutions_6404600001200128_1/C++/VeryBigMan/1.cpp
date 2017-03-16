#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
using namespace std;
int a[1005];
int main()
{
    freopen("A-large.in","r",stdin);
    freopen("out.txt","w",stdout);
    int T;
    cin>>T;
    for(int tt=1;tt<=T;tt++)
    {
        int n;
        cin>>n;
        memset(a,0,sizeof(a));
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
        }
        int ans1=0;
        for(int i=1;i<n;i++)
        {
            if(a[i]<a[i-1])
            {
                ans1+=a[i-1]-a[i];
            }
        }
        int ans2=0;
        int len=0;
        for(int i=1;i<n;i++)
        {
            if(a[i]<a[i-1])
            {
                if(a[i-1]-a[i]>len)
                {
                    len=a[i-1]-a[i];
                }
            }
        }
        for(int i=0;i<n-1;i++)
        {
            if(a[i]<len)
            {
                ans2+=a[i];
            }
            else
            {
                ans2+=len;
            }
        }
        cout<<"Case #"<<tt<<": "<<ans1<<" "<<ans2<<endl;
    }
    return 0;
}
