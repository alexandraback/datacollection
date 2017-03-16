#include<bits/stdc++.h>
using namespace std;

int main()
{
	#ifdef DBG
	//freopen("case.in", "r" , stdin);
	#endif
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T,N,t,c=1;
	long long ans1,ans2;
	cin>>T;
	vector<long long> v;
	while(T--)
	{
		cin>>N;
		v.clear();
		for(int i=0;i<N;++i)
		{
			cin>>t;
			v.push_back(t);
		}
		ans1 = 0;
		for(int i=1;i<N;++i)
		{
			if( v[i-1] > v[i] )
				ans1+=v[i-1]-v[i];
		}
		
		long long mg = 0;
		ans2 = 0;
		for(int i=1;i<N;++i)
			if( v[i-1] > v[i] )
				mg = max( mg , v[i-1] - v[i] );
		for(int i=0;i<N-1;++i)
			if( v[i]<=mg )ans2+=v[i];
			else ans2+=mg;
		cout<<"Case #"<<c++<<": "<<ans1<<' '<<ans2<<'\n';
	}
}

