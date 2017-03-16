#include <bits/stdc++.h>
using namespace std;
#define ll long long 
#define _ ios::sync_with_stdio(false);
#define mem(x,a) memset(x,(a),(int)(sizeof(x)))
#define pii pair<int,int>
#define fr(i,a,n) for(int i=(a);i<=(n);i++)
#define frd(i,a,n) for(int i=(a);i>=(n);i--)
#define nl cout<<endl
#define sp cout<<" "
#define pb push_back
#define mp make_pair 
#define F first 
#define S second
#define si size()
#define V vector
ll mod=1e9+7;
int main() {_
   int t;cin>>t;
   fr(Z,1,t)
   {
      int n,x,sz;
      cin>>n;
      //priority_queue<pair<int,int> > ;
      V<string> ans;
      int tot=0;
      V<pii> v;
      fr(i,1,n)cin>>x,v.pb(mp(x,i)),tot+=x;
      sort(v.begin(),v.end(),greater<pair<int,int> >());
      
      while(1)
      {
         int top=v[0].F;
         int sec=v[1].F;
         
         if(top==0)break;
         char c1='A'+(v[0].S-1);
         char c2='A'+(v[1].S-1);
         string s;
         //cout<<c1<<" "<<c2<<endl;
         if(top==1)
         {
            if(tot%2==0)s+=c1,s+=c2,v[0].F--,v[1].F--,tot-=2;
            else s+=c1,v[0].F--,tot--;
         }
         else
         {
            if(sec<= tot -2- sec)s+=c1,s+=c1,tot-=2,v[0].F-=2;
            else s+=c1,s+=c2,tot-=2,v[0].F--,v[1].F--;
         }
         //cout<<s<<endl;
         ans.pb(s);
         sort(v.begin(),v.end(),greater<pair<int,int> >());
      }
      cout<<"Case #"<<Z<<": ";
      for(auto i: ans)cout<<i<<" ";nl;
      //for(int i=0;i<ans.size();i++)cout<<ans[i]<<" ";
   }
   
   return 0;
}