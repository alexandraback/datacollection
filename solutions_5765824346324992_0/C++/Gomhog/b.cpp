#include <iostream>
#include <vector>
#include <algorithm>

#define ll long long

using namespace std;

int t;
int b, n;
int m[1000];
vector<pair<int,int>> v;

int main() {
	cin >> t;
	for (int i=1; i<= t; i++) {
		cout << "Case #" << i << ": ";
		cin >> b >> n;
		for (int j=0;j<b;j++) {
			cin >> m[j];
		}
		ll a = 0;
		ll u = ((ll) n)*100000;
		while (a < u) {
			ll c = (a+u)/2;
			ll s = 0;
			for (int j=0;j<b;j++) {
				s += c/m[j];
				if (s >= n-1) break;
			}
			if (s >= n-b) u = c;
			else {
				a=c+1;
			}
		}
		int apu = 0;
		for (int j=0;j<b;j++) {
			apu += a/m[j];
		}
		apu = (n-1)-apu;
		for (int j=0;j<b;j++) {
			v.push_back(make_pair(-(a%m[j]),j));
		}
		sort(v.begin(),v.end());
		int res = v[apu].second;
		v.clear();
		cout << res+1 << "\n";
	}
}
