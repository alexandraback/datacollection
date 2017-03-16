#include <bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin>>t;
	for(int tt=1;tt<=t;tt++)
	{
		cout<<"Case #"<<tt<<":";
		int n,s=0;
		cin>>n;
		vector<pair<int,char>>v;
		for(int j=0;j<n;j++)
		{
			int x;
			cin>>x;
			v.push_back({x,'A'+j});
			s+=x;
		}
		int nn=v.size();
		sort(v.begin(),v.end());
		if(s&1)
		{
			while(s>3)
			{
				//cerr<<"nn = "<<nn<<'\n';
				s-=2;
				cout<<" "<<v[nn-1].second<<v[nn-2].second;
				v[nn-1].first--;
				v[nn-2].first--;
				sort(v.begin(),v.end());
			}
			cout<<" "<<v[nn-1].second<<" "<<v[nn-2].second<<v[nn-3].second<<'\n';
		}
		else
		{
			while(s>0)
			{
				while(v[nn].first)nn++;
				s-=2;
				cout<<" "<<v[nn-1].second<<v[nn-2].second;
				v[nn-1].first--;
				v[nn-2].first--;
				sort(v.begin(),v.end());
			}
			cout<<'\n';
		}
		
		
	}
}
