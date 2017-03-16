//============================================================================
// Name        : Round1B_A.cpp
// Author      : Peiqian Li
//============================================================================

#include <iostream>
#include <string>
#include <vector>
using namespace std;

int myabs(int n) {
	return n<0 ? -n: n;
}

int solve(vector <int> &t) {
	//for(int i=0; i<t.size(); ++i) cout << t[i] << ' ';
	//cout << endl;
	int result = 10000000;
	for(int r = 1; r<111; ++r) {
		int sum = 0;
		for(int i=0; i<t.size(); ++i) sum += myabs(r-t[i]);
		if(sum<result) result = sum;
	}
	return result;
}

int main() {
	int nc;
	cin >> nc;
	for(int cid=1; cid<=nc; ++cid) {
		int n;
		string s;
		cin >> n;
		vector< vector<pair<char, int> > > lib;
		for(int i=0; i<n; ++i) {
			cin >> s;
			int len = s.size();
			vector<pair<char, int> > t;
			t.clear();
			for(int j=0; j<len; ++j) {
				if(j>0 && s[j]==s[j-1]) ++((t.end()-1)->second);
				else t.push_back(make_pair(s[j], 1));
			}
			lib.push_back(t);
		}
		bool flag = true;
		for(int k=1; k<lib.size() && flag; ++k) {
			if(lib[k].size() != lib[0].size()) {
				flag = false;
				break;
			}
			for(int j=0; j<lib[k].size(); ++j)
				if(lib[0][j].first != lib[k][j].first) {
					flag = false;
					break;
				}
		}
		printf("Case #%d: ", cid);
		if(flag) {
			int m = lib[0].size();
			int ans = 0;
			for(int i=0; i<m; ++i) {
				vector<int> t;
				for(int j=0; j<n; ++j) t.push_back(lib[j][i].second);
				ans += solve(t);
			}
			cout << ans << endl;
		} else {
			cout << "Fegla Won" << endl;
		}
	}
	return 0;
}
