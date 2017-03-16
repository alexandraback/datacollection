#include<bits/stdc++.h>
#define mod 1000000007
#include<bits/stdc++.h>
#define mod 1000000007
#define pp pair<ll,ll>
#define mp make_pair
#define ll long long
#define ff first
#define ss second
#define big 100000000000000000
using namespace std;

ll n,tc,p[50];
vector<ll> hsh[1010];

int main(){
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
//	ios::sync_with_stdio(0);
	
	cin>>tc;
	for(ll t=1;t<=tc;t++){
		cout<<"Case #"<<t<<": ";
		for(ll i=1;i<=1000;i++)
			hsh[i].clear();
		cin>>n;
		for(ll i=0;i<n;i++){
			cin>>p[i];
			hsh[p[i]].push_back(i);
		}
		ll temp,cnt;
		for(ll i=1000;i>0;i--){
			ll sz = hsh[i].size();
			if(sz == 0)
				continue;
			else if(sz % 2){
				cout<<char('A'+hsh[i][sz-1])<<" ";
				hsh[i-1].push_back(hsh[i][sz-1]);
				sz--;
				hsh[i].pop_back();
			}
			for(ll j=sz-1;j>=0;j-=2){
				cout<<char('A'+hsh[i][j])<<char('A'+hsh[i][j-1])<<" ";
				hsh[i-1].push_back(hsh[i][j]);
				hsh[i-1].push_back(hsh[i][j-1]);
			}
		}
		cout<<"\n";
	}
	return 0;
}

