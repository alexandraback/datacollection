#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
	int T;
	cin >> T;

	for(int t = 1; t <= T; ++t) {
		int n;
		cin >> n;
		vector<int> v(n);
		for(int i = 0; i < n; ++i) {
			cin >> v[i];
		}

		int y = 0;
		for(int i = 0; i < n - 1; ++i) {
			y += max(0, v[i] - v[i + 1]);
		}

		int d = -1;

		for(int i = 0; i < n - 1; ++i) {
			d = max(d, max(0, v[i] - v[i + 1]));
		}

		int z = 0;
		for(int i = 0; i < n - 1; ++i) {
			z += min(d, v[i]);
		}

		cout<< "Case #" << t << ": " << y << ' ' << z << endl;
	}
}
