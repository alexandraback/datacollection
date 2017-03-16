#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll  long long

///////////
//////////////////////////////////



ll p[1001];
int  main()
{
	ll t,r=1;
	cin>>t;
	while(t--)
	{
		
	priority_queue < pair <ll ,char> > qwe;	
		char ch='A';
		ll n;
		cin>>n;
		
		for(ll i=0;i<n;i++)
		{
			cin>>p[i];
			char aw=ch+i;
			qwe.push (make_pair(p[i],aw));
		}
		
		
		
		
		
		////////////////////////////////////////
		bool gl =false;
		
		
		
		cout<<"Case #"<<r<<": ";
		while(!qwe.empty())
		{
		   pair <ll ,char> r =qwe.top();
		   if(r.first==1&&qwe.size()==3)
		   {
		     qwe.pop();
		   	 cout<<r.second<<" ";
		   	 continue;
		   }
		   qwe.pop();
		     pair <ll ,char> e;
		   if(!qwe.empty())
		   {
		     e =qwe.top();
		    qwe.pop();
		    gl =true;
		   }
		   cout<<r.second<<e.second<<" ";
		   if(gl)
		   {
		    r.first-=1;
		    e.first-=1;
		    if(r.first>0)
		    qwe.push(r);
		    if(e.first>0)
		    qwe.push(e);
		  }
		  else 
		  {
		  	r.first-=2;
		  	if(r.first>0)
		    qwe.push(r);
		  }
		}
		r++;
		
		
		
		
		
		cout<<"\n";
 
	}
}
