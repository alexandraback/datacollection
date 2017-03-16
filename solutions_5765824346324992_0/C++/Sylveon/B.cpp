#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
lls M[1000];
ll N,K,c=1;


inline ll peo(ll p)
{
	ll res = N;
	for(int i=0;i<N;++i)
		res += p/M[i];
	return res;
}

int main()
{
	#ifdef DBG
	//freopen("case.in", "r" , stdin);
	#endif
	//ios::sync_with_stdio(false);
	//cin.tie(0);
	int T;
	cin>>T;
	int ans;
	
	while(T--)
	{
		cin>>N>>K;
		for(int i=0;i<N;++i)
		{
			cin>>M[i];
		}
		ll L=-1;
		ll R=K* *max_element(M,M+N) +1;
		ll m;
		while( L+1<R )
		{
			//cout<<L<<' '<<R<<endl;
			m = (L+R)/2;
			//cout<<" m:"<<m<<' '<<peo(m)<<endl;
			if( peo(m)>=K ) R=m;
			else L = m;
			//cout<<"D"<<L<<' '<<R<<endl;
		}
		ll nowpid = peo(R);
		ans = -1;
		for(int i=N-1;i>=0;--i)
		{
			if( R%M[i]==0 )
			{
				if( nowpid == K ){
					ans = i+1;
					break;
				}
				nowpid--;
			}
		}
		assert(ans!=-1);
		cout<<"Case #"<<c++<<": "<<ans<<'\n';
	}
}

