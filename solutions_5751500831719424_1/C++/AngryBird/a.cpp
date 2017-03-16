#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void analysis(string s, vector<char> &vc, vector<int> &vi) {
	if (s.size() == 0)
		return;
	char c = s[0];
	int count = 1;
	while(count < s.size() && s[count] == c) {
		count++;
	}
	vc.push_back(c);
	vi.push_back(count);
	analysis(s.substr(count, s.size()-count), vc, vi);
}

int sum(vector<int> v, int k) {
	int s = 0;
	for (int i = 0; i < v.size(); i++) {
		s += abs(v[i]-k);
	}
	return s;
}

void through(vector<int> v, int &min, int &max) {
	for (int i = 0; i< v.size(); i++) {
		if (v[i] < min)
			min = v[i];
		if (v[i] > max)
			max = v[i];
	}
}

int dist(vector<int> v) {
	int n = v.size();
	int min = 1000, max = 0;
	through(v, min, max);
	int d = n * max;
	for (int i = min; i <= max; i++) {
		int r = sum(v, i);
		if (r < d)
			d = r;
	}
	return d;
}

int repeater(vector<vector<char> > vvc, vector<vector<int> > vvi, int p) {
	if (p >= vvc[0].size())
		return 0;
	int n = vvc.size();
	vector<int> vi;
	char c = vvc[0][p];
	vi.push_back(vvi[0][p]);
	for (int i = 1; i < n; i++) {
		if (vvc[i][p] != c) {
			return -1;
		} else {
			vi.push_back(vvi[i][p]);
		}
	}
	int next = repeater(vvc, vvi, p+1);
	if (next < 0)
		return -1;
	else 
		return dist(vi) + next;
}

int main() {
	int T;
	cin >> T;
	int N;
	for (int i = 0; i < T; i++) {
		vector<vector<char> > vvc;
		vector<vector<int> > vvi;
		int l = -1;
		bool mark = false;
		cin >> N;
		for (int j = 0; j < N; j++) {
			string str;
			vector<char> vc;
			vector<int> vi;
			cin >> str;
			analysis(str, vc, vi);
			if (l < 0) {
				l = vc.size();
			} else if (l != vc.size()) {
				mark = true;
			}
			vvc.push_back(vc);
			vvi.push_back(vi);
		}
		cout << "Case #" << i+1 << ": ";
		if (mark) {
			cout << "Fegla Won" << endl;
		} else {
			int count = repeater(vvc, vvi, 0);
			if (count >= 0)
				cout << count << endl;
			else
				cout << "Fegla Won" << endl;
		}
	}
	return 0;
}