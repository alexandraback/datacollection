#include <iostream>

using namespace std;

int t, n;
int m[10000];

int main() {
	cin >> t;
	for (int i=1; i<= t; i++) {
		cout << "Case #" << i << ": ";
		cin >> n;
		int parsa = 0;
		int s = 0;
		for (int j=0;j<n; j++) {
			cin >> m[j];
			if (j == 0) continue;
			s += max(0,m[j-1]-m[j]);
			if (m[j-1]-m[j] > parsa) parsa = m[j-1]-m[j];
		}
		cout << s << " ";
		s = 0;
		for (int j=1;j<n;j++) {
			s += min(parsa,m[j-1]);
		}
		cout << s << "\n";
	}
}
