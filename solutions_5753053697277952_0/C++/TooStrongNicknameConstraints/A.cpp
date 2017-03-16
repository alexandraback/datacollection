#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;

#define FOR(i,a,b) for(ll i=(a); i < (b); i++) 
#define FORD(i,a,b) for(ll i=(b)-1; i >= (a); i++)

ll counter;
vector<pair<char, ll>> p;
bool checkmajority() {
	FOR(i,0,p.size()) {
		if(counter < (2*p[i].second)) {
			return false;
		}
	}
	return true;
}

bool comp(vector<pair<char, ll>> a1, vector<pair<char, ll>> a2) {
	return true;
//	return a1.second > a2.second;
}

int main() {
	ios_base::sync_with_stdio(false);
	
	ll t;
	cin >> t;
	FOR(q,0,t) {
	
		ll n;
		cin >> n;
		p.clear();
		counter = 0;
		char a = 'A';
		FOR(i,0,n) {
			ll input;
			cin >> input;
			counter+=input;
			pair <char,ll> inp(a,input);  
			p.push_back(inp);
			a++;
		}
		string evac;
		cout << "Case #" << q+1 << ": ";
		while(counter > 0) {
			sort(p.begin(), p.end(), [](const pair<char,ll> &left, const pair<char,ll> &right) {
    return left.second > right.second;
});
	/*
			cerr << "LEFT IN ROOM"<< endl;
			FOR(i,0,p.size()) {
				cerr << p[i].first << " " << p[i].second << endl;
			}
	*/	
			p[0].second--;
			counter--;
			evac=evac+""+p[0].first;
			bool flag = false;
                        ll index = 0;
			if(p[0].second < p[1].second) {
				index = 1;
			}	
			p[index].second--;
			counter--;
			flag = checkmajority();
			if(!flag) {
				p[index].second++;
				counter++;
			} else {
				evac=evac+""+p[index].first;
			}
			evac=evac+" ";
		}
		cout << evac << endl;	
	}

}
