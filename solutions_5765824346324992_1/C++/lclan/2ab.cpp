#include<iostream>
using namespace std;
int m[1003];
int t,b,n;
long long fnc(long long time)
{
    long long ret=0;
    for(int i=0;i<b;i++)
    {
        ret += time /m[i];
    }
    return ret;
}

int main()
{
    int i,j,k;

    cin>>t;
    int c=1;
    while(t--)
    {
        cin>>b>>n;
        int mn=-1;
        for(i=0;i<b;i++)
        {
            cin>>m[i];
            if(mn==-1 || m[i]<mn)
            {
                mn= m[i];
            }
        }
        if(b>=n)
        {
            cout<<"Case #"<<c<<": "<<n<<endl;
            c++;
            continue;
        }
        long long time,l,r,mid;
        l=0;
        n-=b;
        r=(long long)mn*(long long)(n);
        while(r>l+1)
        {
            mid=(r+l)/2;
            if(fnc(mid)>=n)
            {
                r=mid;
            }else
            {
                l=mid;
            }
        }
        n-=fnc(l);
        int ans;
        for(i=0;i<b;i++)
        {
            if(r%m[i]==0)
            {
                n--;
                if(n==0)
                {
                    ans=i+1;
                    break;
                }
            }
        }
        cout<<"Case #"<<c<<": "<<ans<<endl;
        c++;
    }
}
