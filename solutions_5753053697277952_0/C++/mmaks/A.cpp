#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
	freopen("inAs.txt", "r", stdin);
	freopen("outAs.txt", "w", stdout);
	ll t;
	cin>>t;
	for(int cases = 1; cases <=t; cases++) {
		ll n;
		cin>>n;
		vector<pair<ll, ll> > v;
		v.clear();

		for(int i=0;i<n;i++) {
			ll p;
			cin>>p;
			v.push_back(make_pair(p, i));
		}
		cout<<"Case #"<<cases<<": ";
		while(v.size()) {

			sort(v.begin(), v.end());
			reverse(v.begin(), v.end());
			int flag = 0;
			while(v.size() == 2) {
				flag = 1;
				cout<<char(v[0].second + 'A')<<char(v[1].second + 'A');
				cout<<" ";
				v[0].first--;
				v[1].first--;
				if(v[0].first == 0) {
					break;
				}
			}
			if(flag)	break;
			if(flag == 0) {
				cout<<char(v[0].second + 'A');
				v[0].first --;
				while(v[0].first == 0) {
					v.erase(v.begin());
				}
				cout<<" ";
			}
		}
		cout<<"\n";
	}
	return 0;
}