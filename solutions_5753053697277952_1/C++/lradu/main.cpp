#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>
#include <math.h>
#include <queue>
#include <set>
#include <map>

#define pb push_back
#define mk make_pair
#define mod 1000000007

using namespace std;

int t,n,x;
string s="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
int main() {
    freopen("A-large.in","r",stdin);
    freopen("dataA.out","w",stdout);
    cin>>t;
    for(int j=1; j<=t; j++)
    {
        cin>>n;
        vector<pair<int,int> > a;
        for(int i=0; i<n; i++)
        {
            cin>>x;
            a.pb(mk(x,i));
        }
        cout<<"Case #"<<j<<": ";
        sort(a.rbegin(),a.rend());
        while(a[0].first!=0)
        {
            if(a[0].first>a[1].first)
            {
                if(a[0].first>2)
                {
                    a[0].first-=2;
                    cout<<s[a[0].second]<<s[a[0].second]<<' ';
                }
                else
                {
                    a[0].first--;
                    cout<<s[a[0].second]<<' ';
                }
            }
            else
            {
               int c=0;
               for(int i=0; i<a.size(); i++)
                    if(a[i].first)
                        c++;
               if(c%2==1)
               {
                cout<<s[a[0].second]<<' ';
                a[0].first--;
               }
               else
               {
                cout<<s[a[0].second]<<s[a[1].second]<<' ';
                a[0].first--;
                a[1].first--;
               }
            }
            sort(a.rbegin(),a.rend());
        }
        cout<<'\n';
    }
}
