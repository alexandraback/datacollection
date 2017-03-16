#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

const int N_MAX = 100;
vector<pair<char, int>> counter[N_MAX];
int T, N;

vector<pair<char, int>> processStr(string& str) {
	vector<pair<char, int>> cnt;
	char last = '!';

	for (int i=0; i<str.length(); i++) {
		if (str[i] == last) {
			cnt[cnt.size()-1].second++;
		} else {
			last = str[i];
			cnt.push_back(make_pair(last, 1));
		}
	}

	return cnt;
}

int find_median(vector<int>& v) {
	sort(v.begin(), v.end());
	return v[v.size()/2];
}

void solve(int tc) {
	cin >> N;
	for (int i=0; i<N; ++i) {
		string str;
		cin >> str;
		counter[i] = processStr(str);
	}

	int result = 0;
	int size = counter[0].size();

	for (int i=0; i<N; ++i)
		if (counter[i].size() != size) {
			cout << "Fegla Won" << endl;
			return;
		}

	for (int i=0; i<size; i++) {
		vector<int> nums;
		char c = counter[0][i].first;
		for (int j=0; j<N; j++) {
			if (counter[j][i].first != c) {
				cout << "Fegla Won" << endl;
				return;
			}
			nums.push_back(counter[j][i].second);
		}
		int median = find_median(nums);
		for (int j=0; j<N; j++) { 
			result += abs(counter[j][i].second - median);
		}
	}

	cout << result << endl;
}

int main() 
{
	cin >> T;
	for (int i=1; i<=T; i++) {
		cout << "Case #" << i << ": ";
		solve(i);
	}
	return 0;
}