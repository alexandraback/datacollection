# include <string>
# include <fstream>
# include <algorithm>
# include <set>
# include <map>
# include <iostream>
# include <vector>
using namespace std;


int main() {
	ifstream cin("input.txt");
	ofstream cout("output.txt");

	int tests;
	cin >> tests;
	for (int test = 1; test <= tests; test++) {
		cout << "Case #" << test << ": ";

		int ans = 0;

		int n;
		cin >> n;
		vector<string> f(n);
		for (int i = 0; i < n; i++)
			cin >> f[i];
		vector<int> pos(n, 0);

		bool ok = true;

		bool anyleft = true;
		while (anyleft) {

			for (int i = 0; i < n; i++)
				if (pos[i] >= f[i].length())
					ok = false;

			if (!ok)
				break;

			char ch = f[0][pos[0]];
			vector<int> len(n, 0);
			for (int i = 0; i < n; i++) {
				if (f[i][pos[i]] != ch) {
					ok = false;
					break;
				}
				else {
					while (pos[i] < f[i].length() && f[i][pos[i]] == ch)
						pos[i]++, len[i]++;
				}
			}

			int mini = 1000000000;
			int left = *min_element(len.begin(), len.end());
			int right = *max_element(len.begin(), len.end());
			for (int maybe = left; maybe <= right; maybe++) {
				int cur = 0;
				for (int j = 0; j < n; j++)
					cur += abs(maybe - len[j]);
				if (cur < mini)
					mini = cur;
			}

			ans += mini;

			anyleft = false;
			for (int i = 0; i < n; i++)
				if (pos[i] < f[i].length())
					anyleft = true;
		}

		if (ok)
			cout << ans;
		else
			cout << "Fegla Won";
		cout << endl;
	}
	
	return 0;
}