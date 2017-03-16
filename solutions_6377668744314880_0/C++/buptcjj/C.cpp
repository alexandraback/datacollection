#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<cstring>
#define maxn 3008
using namespace std;

struct point
{
    long long x,y;

    long long operator * (const point k)const
    {
        return x * k.y - y * k.x;
    }

    point operator - (const point k)const
    {
        point tmp;
        tmp.x = x - k.x;
        tmp.y = y - k.y;
        return tmp;
    }
};

point a[maxn];
int n;
long long sum[maxn];

void f(int x,int y)
{
    int i,l=0,r=0;
    long long k;
    point tmp,s = a[y] - a[x];

    for (i = 1 ; i <= n ; i++)
    {
        tmp = a[i] - a[x];
        k = tmp * s;
        if (k > 0) l++;
        else if (k < 0) r++;
    }

    k = min(l , r);
    sum[x] = min(sum[x] , k);
    sum[y] = min(sum[y] , k);
}





int main()
{
    int T,tt=0,i,j;
    freopen("C-small-attempt0.in","r",stdin);
    freopen("C-small-attempt00.out","w",stdout);
    cin>>T;

    while (T--)
    {
        memset(a,0,sizeof(a));
        printf("Case #%d:\n",++tt);
        cin>>n;
        for (i = 1 ; i <= n ; i++)
        {
            cin>>a[i].x>>a[i].y;
            sum[i]=n;
        }


        for (i = 1 ; i < n ; i++)
            for ( j = i+1 ; j <= n ; j++)
                f(i,j);
//cout<<"debug"<<endl;
        for (i = 1 ; i <= n ; i++)
            cout<<sum[i]<<endl;

    }

    return 0;
}
