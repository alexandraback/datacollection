#include<iostream>
#include<cmath>
#include<string.h>
#include<stdio.h>
#include<algorithm>
using namespace std;


int t,n;
int a[1011];
int ans1,ans2;
int main()
{
    freopen("A-large.in","r",stdin);
    freopen("ans.out","w",stdout);
    
    int i,j,k,times;
    int mm;
    cin>>t;
    for(times=1;times<=t;times++)
    {
        cin>>n;
        for(i=1;i<=n;i++)
        {
            cin>>a[i];
        }
        
        ans1=ans2=0;
        mm=-1;
        for(i=1;i<=n-1;i++)
        {
            ans1+=max(a[i]-a[i+1],0);
            /*
            mm=max(0,a[i]-a[i+1])/10;
            if(max(0,a[i]-a[i+1])%10!=0)
            {
               mm++;
            }
            */
            mm=max(mm,max(0,a[i]-a[i+1]));
        }
        //cout<<mm<<endl;
        for(i=1;i<=n-1;i++)
        {
           ans2+=min(a[i],mm);
        }
        
        cout<<"Case #"<<times<<": "<<ans1<<" "<<ans2<<endl;
    }
    
    return 0;
}
