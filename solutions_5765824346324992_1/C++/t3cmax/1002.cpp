#include<iostream>
#include<cmath>
#include<string.h>
#include<stdio.h>
#include<algorithm>
using namespace std;

int t,b;
long long n;
long long a[1011];
long long INF=1ll<<60ll;

long long gao(long long from,long long to)
{
    long long mid;
    int i;
    long long cur;
    
    while(from!=to)
    {
        mid=(from+to)/2;
        
        
        cur=0;
        for(i=1;i<=b;i++)
        {
            cur+=mid/a[i];
            cur++;
        }
        
        if(cur<n)
        {
            from=mid+1;
        }
        else
        {
            to=mid;
        }
    }
    
    return from;
}



int main()
{
    freopen("B-large.in","r",stdin);
    freopen("ans.out","w",stdout);
    
    int i,j,k,times;
    long long mm;
    long long tt;
    long long cur;
    cin>>t;
    
    for(times=1;times<=t;times++)
    {
        cin>>b>>n;
        
        mm=INF;
        for(i=1;i<=b;i++)
        {
            cin>>a[i];
            mm=min(mm,a[i]);
        }
        
        tt=gao(0,mm*n);
        
        
        cur=0;
        for(i=1;i<=b;i++)
        {
            cur+=(tt-1)/a[i];
            cur++;
        }
        cur=n-cur;
        
        for(i=1;i<=b;i++)
        {
            if(tt%a[i]==0)
            {
                if(cur==1)
                {
                    break;
                }
                else
                {
                    cur--;
                }
            }
        }
        
        cout<<"Case #"<<times<<": "<<i<<endl;
    }
    
    
    return 0;
}
