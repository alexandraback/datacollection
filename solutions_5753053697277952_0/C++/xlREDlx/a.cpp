#include <iostream>
#include <bitset>
#include <iomanip>
#include <vector>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <string>
#include <algorithm>
#include <cmath>
#include <queue>
using namespace std;

bool shouldOne(priority_queue<pair<int, int> > q) {
	auto p1 = q.top(); q.pop();
	auto p2 = q.top(); q.pop();
	//cerr << "p " << p1.first << ' ' << p2.first << endl;
	return p1.first == p2.first;
}

int main() {
	int cases;
	cin >> cases;
	for (int cas = 1; cas <= cases; ++cas) {
		cout << "Case #" << cas << ":";
		priority_queue<pair<int, int> > q;
		int n;
		cin >> n;
		vector<int> v(n);
		for (int i = 0; i < n; ++i) {
			int t;
			cin >> t;
			v[i] = t;
			q.push(pair<int, int>(t, i));
		}
		int cont = 0;
		while (!q.empty()) {
			//for (int i = 0; i < n; ++i) cout << char(i + 'A') << ' ' << v[i] << endl;
			bool space = (cont%2 == 0 || (q.size() == 2 && shouldOne(q)));
			auto p = q.top(); q.pop();
			if (space) {
				cout << ' ';
				cont = 0;
			}
			cout << char(p.second + 'A');
			p.first--;
			v[p.second]--;
			if (p.first > 0) q.push(p);
			++cont;
		}
		cout << endl;
	}
}

