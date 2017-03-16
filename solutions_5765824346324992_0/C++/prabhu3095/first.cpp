#include<bits/stdc++.h>
#define ll long long int

using namespace std;

ll gcd(int a,int b)
{
    if(b==0)
        return a;
    return gcd(b,a%b);
}

int A[10];
int main()
{
    freopen("B-small-attempt1.in","r",stdin);
    freopen("output1.txt","w",stdout);
    int t;
    cin>>t;
        for(int j=1;j<=t;j++)
        {
        long int n,m,ans;
        cin>>m>>n;
        int B[m+1];
        for(int i=1;i<=m;i++)
            cin>>B[i];
        int g=B[1];
        ll mult=B[1];
        for(int i=2;i<=m;i++)
        {
            g=gcd(g,B[i]);
            mult=mult*B[i];
        }
        ll lcm=mult/g;
        memset(A,0,sizeof(A));
        ll sum=0,sum1=0;
        for(int i=1;i<=m;i++)
        {
            sum=sum+lcm/B[i];
        }
        int f=0;
        while(n>sum1)
        {
            sum1=sum1+sum;
            f=1;
            if(sum1>=n)
            {
                sum1-=sum;
                break;
            }
        }

        //cout<<"sum1 "<<sum1<<endl;
        for(long int i=sum1+1; i<=n; i++)
        {
            long int p=1,mi=INT_MAX;
            for(int j=1;j<=m;j++)
            {
                if(A[j]<mi)
                {
                    p=j; mi=A[j];
                }
            }
            A[p]=A[p]+B[p];
            ans=p;
        }
        cout<<"Case #"<<j<<": "<<ans<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}


