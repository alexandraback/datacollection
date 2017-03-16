#include <bits/stdc++.h>

using namespace std;

#define ll				long long int
#define vi				vector<int>
#define vl				vector<ll>
#define pii				pair<int,int>
#define pil				pair<int, ll>
#define pll				pair<ll, ll>
#define pli				pair<ll, int>
#define pb				push_back
#define mp				make_pair
#define MOD				1000000007
#define F				first
#define S				second

ll pow_mod(ll a, ll b) {
	ll res = 1;
	while(b) {
		if(b & 1)
			res = (res * a);
		a = (a * a);
		b >>= 1;
	}
	return res;
}

int main(){

	ios_base::sync_with_stdio(0);

	int t;
	cin >> t;

	for(int ti = 1;ti <=t;ti++){

		int n;
		cin >> n;
		vector < pair <int , char > > p;


		for(int i=0;i<n;i++){
			int cnt;
			cin >> cnt;
			p.pb(mp(cnt, (char)('A' + i)));
		}

		sort(p.begin(), p.end());

		cout << "Case #" << ti << ": ";

		for(int i = n-2;i >= 0;i -= 1){

			int diff = p[i+1].F - p[i].F;
			int blcks = (n-1 - i);
			int evac = diff*blcks;

			if(blcks%2 == 0){

				while(diff){

					for(int j=i+1;j<n;j+=2){
						cout << p[j].S << p[j+1].S << " ";
						p[j].F--; p[j+1].F--;
					}
					diff--;
				}

			}
			else{

				int mv = diff;

				if(mv%2 == 1){
					cout << p[i+1].S << " ";
					p[i+1].F--;
					mv--;
				}

				while(mv){
					cout << p[i+1].S << p[i+1].S << " "; 
					p[i+1].F -= 2;
					mv -= 2;
				}

				while(diff){

					for(int j=i+2;j<n;j+=2){
						cout << p[j].S << p[j+1].S << " ";
						p[j].F--; p[j+1].F--;
					}
					diff--;
				}

			}

		}

		if(n%2 == 1){

			int mv = p[0].F;

			if(mv%2 == 1){
				cout << p[0].S << " ";
				p[0].F--;
				mv--;
			}

			while(mv){
				cout << p[0].S << p[0].S << " "; 
				p[0].F -= 2;
				mv -= 2;
			}	
			p.erase(p.begin());
			n--;
		}

		while(p[n-1].F > 0){

			for(int i=0;i<n;i+=2){
				cout << p[i].S << p[i+1].S << " ";
				p[i].F--;
				p[i+1].F--;
			}

		}
		cout << "\n";

	}

	return 0;
}
