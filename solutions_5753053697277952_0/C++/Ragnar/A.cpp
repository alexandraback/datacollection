#define HEADER_H
//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#define REP(i,n)	for(auto i=decltype(n)(0); i<(n); ++i)
#define all(v)		begin(v), end(v)
using namespace std;		using ull= unsigned long long;
using ll = long long;		using ld = long double;
using vi = vector<ll>;		using vvi= vector<vi>;
using vb = vector<bool>;	using ii = pair<ll,ll>;
constexpr bool LOG = true;
void Log() { if(LOG) cerr << "\n"; }
template<class T, class... S> void Log(T t, S... s){
	if(LOG) cerr << t << "\t", Log(s...);
} /* ============== END OF HEADER ============== */
int main(){
	ios_base::sync_with_stdio(false); cin.tie(nullptr);

	ll TC; cin >> TC;
	for(ll tc = 1; tc<=TC; ++tc){
		cout << "Case #"<<tc<<":";

		ll n; cin >> n;
		multimap<ll,char> s;
		ll total=0;
		for(ll i=0; i<n; ++i){
			ll x; cin >> x;
			total+=x;
			s.insert({x,'A'+i});
		}

		if(total%2==1){
			auto it = prev(s.end());
			char c1 = it->second;
			if(it->first==1) s.erase(it);
			else{
				s.insert({it->first-1, it->second});
				s.erase(it);
			}
			cout << ' ' << c1;
		}
		
		while(!s.empty()){
			auto it = prev(s.end());
			char c1 = it->second;
			if(it->first==1) s.erase(it);
			else{
				s.insert({it->first-1, it->second});
				s.erase(it);
			}
			if(s.empty()){
				cout << ' ' << c1;
				break;
			}
			it = prev(s.end());
			char c2 = it->second;
			if(it->first==1) s.erase(it);
			else{
				s.insert({it->first-1, it->second});
				s.erase(it);
			}
			cout << ' '<<c1<<c2;
		}

		cout << '\n';
	}
	return 0;
}


