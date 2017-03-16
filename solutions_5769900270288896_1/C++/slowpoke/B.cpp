#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <array>
#include <string>
#include <deque>
#include <list>
#include <numeric>
#include <limits>
#include <utility>
#include <cmath>
#include <cstdlib>
#include <functional>

using namespace std;

vector<vector<bool>> v, vbest;

int r, c, n;

void comp(int tc){	
	cin >> r >> c >> n;
	int best = 0;

	vector<vector<int>> v(r, vector<int>(c));
	
	set<tuple<int, int, int>> s;

	for (int i = 0; i < r; ++i){
		for (int j = 0; j < c; ++j){
			int cnt = 0;
			if (i > 0) ++cnt;
			if (i < r - 1) ++cnt;
			if (j > 0) ++cnt;
			if (j < c - 1) ++cnt;
			v[i][j] = cnt;
			s.emplace(-cnt, i, j);
		}
	}

	for (int i = 0; i < r*c - n; ++i){
		auto t = *s.begin();
		s.erase(s.begin());		
		int pi = get<1>(t);
		int pj = get<2>(t);
		best += v[pi][pj];
		v[pi][pj] = 0;

		if (pi>0 && v[pi - 1][pj] > 0){
			auto &val = v[pi - 1][pj];
			auto it = s.erase(make_tuple( -val, pi-1, pj ));
			--val;
			s.emplace(-val, pi-1, pj);
		}

		if (pj>0 && v[pi][pj-1] > 0){
			auto &val = v[pi][pj-1];
			auto it = s.erase(make_tuple(-val, pi, pj-1));
			--val;
			s.emplace(-val, pi, pj-1);
		}

		if (pi<r-1 && v[pi + 1][pj] > 0){
			auto &val = v[pi + 1][pj];
			auto it = s.erase(make_tuple(-val, pi + 1, pj));
			--val;
			s.emplace(-val, pi + 1, pj);
		}

		if (pj<c-1 && v[pi][pj + 1] > 0){
			auto &val = v[pi][pj + 1];
			auto it = s.erase(make_tuple(-val, pi, pj + 1));
			--val;
			s.emplace(-val, pi, pj + 1);
		}
	}


	cout << "Case #" << tc << ": " << r*(c-1) + c*(r-1) -best << endl;
	
}

int main(){
	int T;
	cin >> T;
	for (int i = 1; i <= T; ++i){
		comp(i);
	}
}