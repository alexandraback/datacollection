#include <iostream>
#include <fstream>
#include <map>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <cmath>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;


int main() {
	ios_base::sync_with_stdio(false);
	ifstream cin("input.txt");
	ofstream cout("output.txt");

	int tests;
	cin >> tests;
	for (int test = 1; test <= tests; test++) {
		int n;
		cin >> n;
		vector<int> m(n);
		for (int i = 0; i < n; i++)
			cin >> m[i];
		int ans1 = 0, ans2 = 0;
		int maxi = 0;
		for (int i = 1; i < n; i++) {
			if (m[i] < m[i - 1]) {
				ans1 += m[i - 1] - m[i];
				maxi = max(maxi, (m[i - 1] - m[i]));
			}
		}

		for (int i = 1; i < n; i++) {
			int start = m[i - 1];
			int willbe = max(0, m[i - 1] - maxi);
			ans2 += start - willbe;
		}


		cout << "Case #" << test << ": " << ans1 << " " << ans2 << endl;
	}



	//system("pause");
	return 0;
}