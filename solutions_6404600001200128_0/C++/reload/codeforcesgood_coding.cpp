#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
#include <set>
using namespace std;
#define oo 1000000007
long long int gcd(long long int a,long long int b){
      if(b==0)return a;
      return gcd(b,a%b);
}
long long int t,ans,a[10000],ans1,maxi,n;


int main(int argc, char const *argv[])
{
        cin.sync_with_stdio(0);
        cin>>t;

        for (int j = 0; j < t; ++j)
        {   
            cin>>n;
            maxi=0;
            ans=ans1=0;
            for (int i = 0; i < n; ++i)
            {
                cin>>a[i];
            }
            for (int i = 1; i <n; ++i)
            {
                if(a[i]>=a[i-1])
                {
                }
                else{
                    ans=ans+a[i-1]-a[i];
                    maxi=max(a[i-1]-a[i],maxi);
                }
            }
            for (int i = 0; i <n-1; ++i)
            {
                ans1=ans1+min(a[i],maxi);
            }



            cout<<"Case #"<<j+1<<": "<<ans<<" "<<ans1<<endl;
        }
        return 0;
}
  


