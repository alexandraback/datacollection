#include <bits/stdc++.h>
#define ll long long
#define int ll
#define mod 1000000007
using namespace std;

main(){
	ios::sync_with_stdio(0);
	freopen("A-large.in", "r", stdin);
	freopen("A-large.out", "w", stdout);
	
	int t, c = 1, n;
	int p;
	cin >> t;
	while(t--) {
		cin >> n;
		int tot = 0;
		priority_queue <pair <int, int>, vector <pair <int, int> >, less <pair <int, int> > > q;
		for(int i = 0; i < n; i++) {
			cin >> p;
			tot += p;
			q.push(make_pair(p, i));
		}
		cout << "Case #" << c++ << ":";
		while(!q.empty()) {
			if(tot != 3) {
				cout << " ";
				for(int i = 0; i < 2; i++) {
					pair <int, int> next = q.top();
					q.pop();
					cout << (char)(next.second + 'A');
					next.first -= 1;
					if(next.first != 0) {
						q.push(next);
					}
				}
				tot -= 2;
			} else {
				cout << " ";
				pair <int, int> next = q.top();
				q.pop();
				cout << (char)(next.second + 'A');
				next.first -= 1;
				if(next.first != 0) {
					q.push(next);
				}
				tot -= 1;
			}
		}
		cout << endl;
	}
}

