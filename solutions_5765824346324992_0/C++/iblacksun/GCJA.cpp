#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>
#include<cstring>
using namespace std;
int a[1005],n,B,b[1005],m;
int gcd(int x,int y)
{
    if(!y) return x;
    return gcd(y,x%y);
}
int main()
{
    freopen("1.in","r",stdin);
    freopen("1.out","w",stdout);
    int t,ca=0;
    scanf("%d",&t);
    int g;
    while(t--)
    {
        m=0;
        memset(b,0,sizeof(b));
        scanf("%d",&B);
        scanf("%d",&n);
        for(int i=0;i<B;i++) scanf("%d",&a[i]);
        g=a[0];
        for(int i=1;i<B;i++)
            g=(g*a[i])/gcd(g,a[i]);
        for(int i=0;i<B;i++)
            m+=g/a[i];
        n%=m;
        if(n==0) n=m;
        printf("Case #%d: ",++ca);
        for(int i=0;i<n;i++)
        {
            int x=0;
            for(int j=1;j<B;j++)
            {
                if(b[x]>b[j]) x=j;
            }
            b[x]+=a[x];
            if(i==n-1) cout<<x+1<<endl;
        }
    }
    return 0;
}
