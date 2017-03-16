#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

using namespace std;
typedef long long ll;
std::vector<ll> v;
int main() {
	ll t;
	cin>>t;
	for (int cas = 1; cas <=t ; ++cas)
	{
		v.clear();
		ll n;
		cin>>n;
		for (int i = 0; i < n; ++i)
		{
			ll m;
			cin>>m;
			v.push_back(m);
		}
		ll res1=0,res2=0;
		ll speed=0;
		for (int i = 1; i <n ; ++i)
		{
			if(v[i]<v[i-1]){
				res1+=abs(v[i-1]-v[i]);
				speed=max(speed,v[i-1]-v[i]);
			}
		}

		ll now=v[0];

		for(int i=1;i<n;i++){
			res2+=min(speed,now);
			now=v[i];
		}



		cout<<"Case #"<<cas<<": "<<res1<<" "<<res2<<endl;
	}
	return 0;
}