#include<iostream>
#include<stdio.h>
using namespace std;
int a[10020];
int main()
{
    int i,j,k;
    int t,n,c;
    cin>>t;
    c=1;
    while(t--)
    {
        cin>>n;
        int sum=0,mx;
        int now,past;
        past=0;
        mx=0;
        for(i=0;i<n;i++)
        {
            cin>>now;
            a[i]=now;
            if(now<past)
            {
                sum+=past-now;
                if(mx<past-now)mx=past-now;
            }
            past=now;
        }
        int sum2=0;
        for(i=0;i<n-1;i++)
        {
            if(a[i]<mx)
            {
                sum2+=mx-a[i];
            }
        }
        cout<<"Case #"<<c<<": "<<sum<<' '<<mx*(n-1) - sum2<<endl;
        c++;
    }

}
