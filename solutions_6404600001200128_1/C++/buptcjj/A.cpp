#include<cstdio>
#include<cstdlib>
#include<iostream>
#define maxn 10005
using namespace std;
long long a[maxn];

int main()
{
    int T,tt=0;
    freopen("A-large.in","r",stdin);
    freopen("A-large.out","w",stdout);
    cin>>T;

    while (T--)
    {
        printf("Case #%d: ",++tt);

        int n,i;
        cin>>n;
        for (i = 1 ; i <= n ; i++)
            cin>>a[i];

        long long s1=0,s2=0,maxx=0;

        for (i = 1 ;i < n ;i++)
            if (a[i]>a[i+1]) s1+=a[i]-a[i+1],maxx=max(maxx,a[i]-a[i+1]);

        for (i = 1 ;i < n ;i++)
            s2 += a[i] > maxx ? maxx : a[i];


        cout<<s1<<' '<<s2<<endl;

    }

    return 0;
}
