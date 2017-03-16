#include<bits/stdc++.h>

using namespace std;

int main()
{
    int t,n,i,j;
    cin>>t;
    int count=1;
    while(t--)
    {
        cin>>n;
        pair<int,int>p[n+1];
        pair<int,int>m;
        int arr[27]={0};
        int min=100000;
        for(i=1;i<=n;i++)
        {
            cin>>arr[i];
            m=make_pair(arr[i],i);
            p[i]=m;
            if(arr[i]<min)
                min=arr[i];
        }
        sort(p+1,p+n+1);
        /*for(i=1;i<=n;i++)
            cout<<p[i].second<<" ";*/
        int flag=1;
        cout<<"Case #"<<count<<": ";
        while(flag)
        {
            flag=0;
            for(i=n;i>=1;i--)
            {
                if(p[i].first!=min)
                {
                    p[i].first-=1;
                    flag=1;
                    char ch=64+p[i].second;
                    cout<<ch<<" ";
                }
            }
        }
        if(n%2==0)
        {
            for(i=1;i<=n;i+=2)
            {
                for(j=0;j<min;j++)
                {
                    char ch=64+p[i].second;
                    cout<<ch;
                    ch=65+p[i].second;
                    cout<<ch<<" ";
                }
            }
        }
        else
        {
            char ch=64+p[1].second;
            for(j=0;j<min;j++)
                cout<<ch<<" ";
            for(i=2;i<=n;i+=2)
            {
                for(j=0;j<min;j++)
                {
                    char ch=64+p[i].second;
                    cout<<ch;
                    ch=64+p[i+1].second;
                    cout<<ch<<" ";
                }
            }
        }
        count++;
        cout<<"\n";
    }
    return 0;
}
