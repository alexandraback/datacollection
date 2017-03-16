#include<iostream>
#include<assert.h>
#include<fstream>
#include<vector>
#include<map>
#include<set>
#include<deque>
#include<queue>
#include<functional>
#include<algorithm>
#include<unordered_map>
#include<unordered_set>
#include<cstdlib>
#include<cstring>
#include<cmath>
using namespace std;
int INF = 1000000000;

vector<pair<char,int>> get_str_info(string s) {
	pair<char,int> p;
	p.first = 0;
	vector<pair<char,int>> vp;
	for(int i = 0; i < s.size(); ++i) {
		if (s[i] != p.first) {
			if (p.first != 0)
				vp.push_back(p);
			p.first = s[i];
			p.second = 1;
		} else p.second++;
	}
	vp.push_back(p);
	return vp;
}
int casen2(vector<string> vs, int t){
	auto info1 = get_str_info(vs[0]);
	auto info2 = get_str_info(vs[1]);
	if (info1.size() != info2.size())
		return INF;
	for(int i = 0; i < info1.size(); ++i)
		if (info1[i].first != info2[i].first)
			return INF;
	int sol = 0;
	for(int i = 0; i < info1.size(); ++i) {
		sol += abs(info1[i].second - info2[i].second);
		if (t == 4)
		cerr << "Best for " << info1[i].second << " is " <<abs(info1[i].second - info2[i].second) << endl;
	}
	return sol;
}
int main() {
	int T, N;
	istream & in = cin;
	//ifstream in("a.0.in");
	in >> T;
	vector<string> s;

	for(int t = 1; t <= T; ++t) {
		in >> N;
		s.clear();
		for(int i = 0; i < N; ++i) {
			string str;
			in >> str;
			s.push_back(str);
		}
		int best_sol = INF;
		int sol = 0;
		vector<vector<pair<char, int>>> infos;
		if (N == -2) {
			best_sol = casen2(s, t);
			goto end;
		}
		for(int i = 0; i < N; ++i) {
			auto info = get_str_info(s[i]);
			infos.push_back(info);
		}
		for(int i = 0; i < infos.size(); ++i) {
			if (infos[i].size() != infos[0].size()) {
				goto end;
			}
			for(int j = 0; j < infos[i].size(); ++j) {
				if (infos[i][j].first != infos[0][j].first)
					goto end;
			}
		}
		for(int i = 0; i < infos[0].size(); ++i) {
			int best = INF;
			int best_j = -1;
			for(int j = 0; j <= 100; ++j) {
				int curr = 0;
				for(int k = 0; k < N; ++k) {
					curr += abs(j - infos[k][i].second);
				}
				if (curr < best) {
					best_j = j;
					best = curr;
				}
			}
			assert(best != INF);
			sol += best;
			if (t == 4) {
				//cerr << "Best for " << infos[0][i].first << " is " << best  << " best_j=" << best_j<< endl;
			}
		}
		best_sol = sol;
end:
		cout << "Case #" << t << ": ";
		if(best_sol != INF) {
			cout << best_sol;
		} else cout << "Fegla won";
		cout << endl;
	}
	return 0;
}
