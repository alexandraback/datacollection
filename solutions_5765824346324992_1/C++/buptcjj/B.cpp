#include<cstdio>
#include<cstdlib>
#include<iostream>
#define maxn 1008
using namespace std;
long long a[maxn];
long long n;
int b;

long long f(long long x)
{
    int i;
    long long s=0;
    for (i = 1 ;i <= b ;i++)
    {
        s += x/a[i]+1;
    }
    return s;
}

int main()
{
    int T,tt=0,i;
    freopen("B-large.in","r",stdin);
    freopen("B-large.out","w",stdout);
    cin>>T;

    while (T--)
    {
        printf("Case #%d: ",++tt);

        cin>>b>>n;

        for (i = 1 ; i <= b ; i++)
            cin>>a[i];

        if (n <= b) cout<<n<<endl;
        else
        {
            int ans=0;
            long long l = 0,r = 100000000000000LL,m;

            while (l + 1 != r)
            {
                m = (l + r + 1) / 2 ;
                if (f(m) >= n) r = m;
                else l = m;
            }
          //  cout<<r<<endl;
            long long s = f(l);

            for (i = 1 ;i <= n;i++)
            {
                if (r % a[i] == 0) s++;
                if (s == n) {ans=i;break;}
            }

            cout<<ans<<endl;

        }


    }

    return 0;
}
