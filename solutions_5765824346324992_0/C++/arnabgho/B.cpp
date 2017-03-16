#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

using namespace std;
typedef long long ll;

ll gcd(ll a,ll b){
	if(b==0)
		return a;
	return gcd(b,a%b);
}

std::vector<ll> v;
std::vector<ll> memo(1e6);
ll lcm(int i){
	if(i==v.size()-1)
		return v[i];
	ll b=lcm(i+1);
	ll a=v[i];
	return (a*b)/gcd(a,b);
}

int main() {
	ll t;
	cin>>t;
	for (int cas = 1; cas <=t ; ++cas)
	{
		v.clear();
		fill(memo.begin(),memo.end(),0);
		ll n,b;
		cin>>b>>n;
		for (int i = 0; i < b; ++i)
		{
			ll x;
			cin>>x;
			v.push_back(x);
		}
		ll l=lcm(0);
		// cout<<"l "<<l<<endl;
		// std::vector<ll> memo(5*l+10);
		ll cur=0;
		for (ll i = 0; i <l; ++i)
		{
			for (ll j = 0; j <b ; ++j)
			{
				if(i%v[j]==0){
					// cout<<"i "<<i<<" j "<<j<<endl;
					// cout<<"cur "<<cur<<endl;
					memo[cur++]=j+1;
				}
			}
		}
		// cur--;
		// cout<<cur<<endl;
		n--;
		ll ans=memo[n%cur];
		cout<<"Case #"<<cas<<": "<<ans<<endl;
	}
	return 0;
}