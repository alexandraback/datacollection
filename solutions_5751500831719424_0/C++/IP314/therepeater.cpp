#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
using namespace std;

class therepeater
{
	private:
		const char delimit;

		int n;
		vector<string> strs;

	public:
		therepeater() : delimit('.') {}

		void input() {
			cin >> n;
			strs.resize(n);
			for (int i = 0; i < n; ++i) {
				cin >> strs.at(i);
			}
		}

		string solve() {
			ostringstream oss;
			for (int i = 0; i < n; ++i) {
				strs.at(i) += delimit;
			}
			int sol = 0;
			vector<int> prefsizes;
			prefsizes.reserve(n);
			while (strs.at(0).size() > 0) {
				prefsizes.clear();
				char ce = strs.at(0).at(0);
				for (int i = 0; i < n; ++i) {
					unsigned int pl = 0;
					for (; (pl < strs.at(i).size()) && (strs.at(i).at(pl) == ce); ++pl) /* no-op */;
					if (pl == 0) {
						oss << "Fegla Won";
						return oss.str();
					}
					prefsizes.push_back(pl);
					strs.at(i) = strs.at(i).substr(pl);
				}
				sort(prefsizes.begin(), prefsizes.end());
				int target = prefsizes.at(n / 2);
				for (int i = 0; i < n; ++i) {
					sol += abs(target - prefsizes.at(i));
				}
			}
			oss << sol;
			return oss.str();
		}
};

int main(void) {
	int nt;
	cin >> nt;
	for (int znj = 0; znj < nt; ++znj) {
		therepeater task;
		task.input();
		cout << "Case #" << (znj + 1) << ": " << task.solve() << endl;
	}
	return 0;
}
