#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <sstream>
using namespace std;

string calc() {
    vector<string> vs;
    int n;
    cin >> n;
    string s;
    string s0;
    for (int i = 0; i < n; ++i) {
        cin >> s;
        vs.push_back(s);

        s.resize(unique(s.begin(), s.end()) - s.begin());
        if (i == 0) {
            s0 = s;
        } else if (s != s0) {
            return "Fegla Won";
        }
    }

    int ans = 0;
    vector<int> next(n, 0);
    for (int i = 0; i < s0.length(); ++i) {
        vector<int> lens;
        for (int j = 0; j < n; ++j) {
            int a = next[j];
            while (next[j] < vs[j].length() && vs[j][next[j]] == s0[i]) next[j]++;
            lens.push_back(next[j] - a);
        }
        sort(lens.begin(), lens.end());

        int a = 0;
        int b = lens.size() - 1;
        while (a < b) {
            ans += lens[b] - lens[a];
            ++a;
            --b;
        }
    }

    stringstream ss;
    ss << ans;
    return ss.str();
}

int main(void)
{
	int T;
	cin >> T;

	for (int ca=1; ca<=T; ++ca) {
		cout << "Case #" << ca << ": " << calc() << endl;
	}
	return 0;
}
