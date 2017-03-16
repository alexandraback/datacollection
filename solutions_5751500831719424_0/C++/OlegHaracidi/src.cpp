#include <vector>
#include <string>
#include <algorithm>
#include <fstream>

using namespace std;

bool validate(const string& s, const string& pattern, vector<int>& w) {
	if (s[0] != pattern[0])
		return false;
	w[0] = 1;
	int i = 0;
	for (int j = 1; j < s.length(); j++) {
		if (s[j] != s[j - 1]) {
			i++;
			if (i >= pattern.length() || pattern[i] != s[j])
				return false;
		}
		w[i]++;
	}
	
	return (i == pattern.length() - 1);
}

int main() {
	ifstream fin("A-small-attempt3.in");
	ofstream fout("out.txt");
	int T;
	fin >> T;
	for (int test_case = 1; test_case <= T; test_case++) {
		int n;
		fin >> n;
		vector<string> s(n);
		for (auto& ts : s)
			fin >> ts;

		string pattern(s[0].substr(0, 1));
		for (int i = 1; i < s[0].length(); i++) {
			if (s[0][i] != s[0][i - 1])
				pattern = pattern + s[0][i];
		}
		int k = pattern.length();

		bool valid = true;
		vector< vector<int> > w(n, vector<int>(k));
		for (int i = 0; i < n; i++) {
			if (!validate(s[i], pattern, w[i])) {
				valid = false;
				break;
			}
		}

		if (!valid) {
			fout << "Case #" << test_case << ": Fegla Won" << endl;
			continue;
		}

		int count = 0;
		for (int i = 0; i < k; i++) {
			vector<int> r(n);
			for (int j = 0; j < n; j++)
				r[j] = w[j][i];
			sort(r.begin(), r.end());
			for (int j = 0; j < n; j++)
				count += abs(r[j] - r[n / 2]);
		}

		fout << "Case #" << test_case << ": " << count << endl;
	}
	return 0;
}
