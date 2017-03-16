
#include <bits/stdc++.h>

using namespace std;

#define EACH(i,c) for(__typeof((c).begin()) i = (c).begin();i!=(c).end();i++)
#define FOR(i,a,b)  for(int i=(a);i<(b);i++)
#define dbg(e)  cout<<(#e)<<" : "<<e<<endl
#define set(v,i) memset(v,i,sizeof(v))
#define all(x) x.begin(),x.end()
#define sz(x) int((x).size())
#define REP(i,n) FOR(i,0,n)
#define pb  push_back
#define mp make_pair

typedef long long ll;

char pp(int i) {
	return 'A' + i;
}

int main() {
	int tt;
	cin >> tt;
	REP(test,tt) {
		vector<pair<int,int> > V;
		int N, a[30], tmp;
		
		cin >> N;
		REP(i,N) {
			cin >> tmp;
			V.pb(mp(tmp,i));
		}
		sort(V.rbegin(), V.rend());
		cout << "Case #" << test + 1 << ": ";
		int cnt = N;
		while(true) {
			if(V[0].first == 0) break;
			if(V[0].first > V[1].first) {
				cout << pp(V[0].second) << " ";
				V[0].first--;
			}
			else if(V[0].first == V[1].first) {
				if(cnt == 2 || cnt > 3) {
					cout << pp(V[0].second) << pp(V[1].second) << " ";
					V[0].first--; V[1].first--;
				} else {
					cout << pp(V[0].second) << " ";
					V[0].first--;
				}
			}
			sort(V.rbegin(),V.rend());
			while(cnt > 0 && V[cnt-1].first == 0) cnt--;
		}
		cout << endl;
	}
}

