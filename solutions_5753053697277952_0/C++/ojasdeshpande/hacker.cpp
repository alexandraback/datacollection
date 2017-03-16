#include <bits/stdc++.h>
using namespace std;
#define int long long
#define MOD 1000000007

signed main() {
	freopen("a.txt","r",stdin);
	freopen("out.txt","w",stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int tt;
	cin >> tt;
	for(int t=1;t<=tt;t++){
		cout << "Case #" << t << ": ";
		int n;
		cin >> n;
		int a[n];
		int tot = 0;
		set<pair<int,int> > s;
		for(int i=0;i<n;i++){
			cin >> a[i];
			tot += a[i];
			s.insert({a[i],i});
		}
		while(tot > 0){
			set<pair<int,int> > :: iterator it = s.end();
			it--;
			pair<int,int> p = *it;
			it--;
			pair<int,int> q = *it;
			if(max(p.first-1,q.first) <= (tot-1)/2){
				s.erase(p);
				p.first -= 1;
				s.insert(p);
				cout << char('A'+p.second) << " ";
				tot -= 1;
			}
			else{
				tot -= 2;
				if(p.first - 1 > q.first){
					s.erase(p);
					p.first -= 2;
					s.insert(p);
					cout << char('A'+p.second) << char('A' + p.second) << " ";
				}
				else{
					s.erase(p);
					s.erase(q);
					p.first -= 1;
					q.first -= 1;
					s.insert(p);
					s.insert(q);
					cout << char('A'+p.second) << char('A' + q.second) << " ";
				}
			}
		}
		cout << "\n";
	}
    return 0;
}
