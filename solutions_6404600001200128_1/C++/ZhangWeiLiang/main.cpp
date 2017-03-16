# include<cstdio>
# include<algorithm>
# include<iostream>
# include<cstring>
# include<string>
# include<cmath>
# include<queue>

# define N 1010
# define M 100010

typedef long long ll;

using namespace std;

int a[N];
int n;

int main()
{
    freopen("C:\\Users\\DELL\\Desktop\\A\\A-large.in","r",stdin);
    freopen("C:\\Users\\DELL\\Desktop\\A\\out.out","w",stdout);
    int test;scanf("%d",&test);
    for(int T=1;T<=test;T++)
    {
        scanf("%d",&n);
        for(int i=0;i<n;i++)    scanf("%d",&a[i]);
        int res1=0,res2=0;
        int rate=0;
        for(int i=0;i<n-1;i++)
        {
            if(a[i] > a[i+1])   res1+=a[i]-a[i+1];
        }
        for(int i=0;i<n-1;i++)  rate=max(rate,a[i]-a[i+1]);
        for(int i=0;i<n-1;i++)
        {
            if(a[i] <= rate)    res2+=a[i];
            else    res2+=rate;
        }
        printf("Case #%d: %d %d\n",T,res1,res2);
    }
    return 0;
}

