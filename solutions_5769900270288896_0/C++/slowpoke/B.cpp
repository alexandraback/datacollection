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

vector<vector<bool>> v;

int r, c, n;
int best;

void rec(int cr, int cc, int cn){
	if (cn == 0){
		int res = 0;
		for (int i = 0; i < r; ++i){
			for (int j = 0; j < c; ++j){
				if (i + 1 < r){
					res += (v[i][j] && v[i + 1][j]);
				}
				if (j + 1 < c){
					res += (v[i][j] && v[i][j + 1]);
				}
			}
		}
		best = min(best, res);
		return;
	}

	int nc = cc + 1;
	int nr = cr;
	if (nc == c){
		nc = 0;
		++nr;
	}

	if (nr == r)
		return;

	v[nr][nc] = true;
	rec(nr, nc, cn-1);
	v[nr][nc] = false;
	rec(nr, nc, cn);

}

void comp(int tc){	
	cin >> r >> c >> n;
	v.assign(r, vector<bool>(c, false));
	best = numeric_limits<int>::max();

	rec(-1, c-1, n);

	cout << "Case #" << tc << ": " << best << endl;
}

int main(){
	int T;
	cin >> T;
	for (int i = 1; i <= T; ++i){
		comp(i);
	}
}