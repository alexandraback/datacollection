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
long long int t,ans,a[10000],ans1,maxi,n,mini,lo,hi,mid,b;


int main(int argc, char const *argv[])
{
        cin.sync_with_stdio(0);
        cin>>t;

        for (int j = 0; j < t; ++j)
        {   
            cin>>b>>n;
            maxi=0;
            ans=ans1=0;
            mini=10000000;
            for (int i = 0; i < b; ++i)
            {
                cin>>a[i];
                mini=(mini,a[i]);
            }
            if(n<=b)
            {
                cout<<"Case #"<<j+1<<": "<<n<<endl;
                continue;
            }
            lo=mini-1;
            hi=mini*(n);
            while(lo<hi)
            {
                mid=(lo+hi)>>1;
                ans1=0;
                
                for (int i = 0; i < b; ++i)
                {
                    ans1=ans1 + 1 + (mid-1)/a[i];
                }   

                if(ans1==n-1)
                {
                    lo=hi=mid;
                    break;
                }
               // cout<<ans1<<" "<<mid<<endl;;
                if(ans1 > n-1)
                {
                    hi=mid-1;
                }
                if(ans1 < n-1)
                {
                    lo=mid+1;
                }
            }
            ans1=0;
             for (int i = 0; i < b; ++i)
                {
                    ans1=ans1 + 1 + (lo-1)/a[i];
                }   
            
            //cout<<lo<<endl;
            //cout<<ans1<<endl;
            while(ans1 >= n)
            {
                ans1=0;
                lo--;
                for (int i = 0; i < b; ++i)
                {
                    ans1=ans1 + 1 + (lo-1)/a[i];
                }

            }
            //cout<<lo<<endl;
            //cout<<ans1<<endl;


            int index=n-ans1;
            set<pair<long long int ,long long int > > st;
            set<pair<long long int ,long long int > >::iterator it;

            for (int i = 0; i < b; ++i)
            {
                st.insert(make_pair((a[i]-lo%a[i])%a[i],i) );
            }
            it=st.begin();
            for( int i = 1; i <index; ++i )
            {
                it++;
            }
            cout<<"Case #"<<j+1<<": "<<(*it).second+1<<endl;
        }
        return 0;
}