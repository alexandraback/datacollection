#include <iostream>
#include <string>
#include <algorithm>
#include <functional>
#include <vector>
#include <utility>

using namespace std;
int main() {
	int t, test, i, n, j;
	cin >> t;
	for (test=1;test<=t;test++) {
		cout << "Case #" << test << ": ";
		cin >> n;
		vector<pair<int, char> > p(n);

		for (i=0;i<n;i++) {
			p[i].second = i+'A';
			cin >> p[i].first;
		}

		sort(p.begin(), p.end(), greater< pair<int, char> >());
		
		while (p[0].first > p[1].first) {
			cout << p[0].second << " ";
			p[0].first--;
			sort(p.begin(), p.end(), greater< pair<int, char> >());
		}

		for (i=2;i<n;i++) {
			for (j=0;j<p[i].first;j++) {
				cout << p[i].second << " ";
			}
		}
		for (j=0;j<p[0].first;j++) {
			cout << p[0].second << p[1].second << " ";
		}
		cout << endl;
	}
	return 0;
}