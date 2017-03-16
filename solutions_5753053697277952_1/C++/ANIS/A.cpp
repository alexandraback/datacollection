#include <algorithm>
#include <iostream>
#include <vector>

#define endl "\n"
#define fr first
#define se second

using namespace std;

int main() { ios::sync_with_stdio(0); cin.tie(0);
	int T, X = 1;
	cin >> T;
	while(T--) {
		int n, t, sum = 0;
		cin >> n;
		vector <pair <int, int> > v;
		for(int i=0; i<n; i++) {
			cin >> t;
			sum += t;
			v.push_back(make_pair(t , i));
		}
		cout << "Case #" << X++ << ": ";
		while(sum) {
			sort(v.begin(), v.end());
			reverse(v.begin(), v.end());
			if(v[1].fr > (sum-1)/2) {
				v[1].fr--;
				v[0].fr--;
				cout << (char) ('A' + v[0].se) << (char) ('A' + v[1].se) << " ";
				sum -= 2;
			}
			else {
				v[0].fr--;
				cout << (char) ('A' + v[0].se) << " ";
				sum--;
			}
		}
		cout << endl;
	}
	return 0;
}