#include <iostream>
#include <vector>
#include <iomanip>
#include <queue>
#include <string>
#include <cmath>
#include <algorithm>
#include <map>
#include <climits>
#include <stdint.h>
#include <utility>
#include <set>
#include <stack>
#define DEBUG 0
#define LOG if(DEBUG)
using namespace std;
typedef int64_t intt;
#define MAX_VAL	LLONG_MAX 
#define MAX(x, y) ((x) > (y) ? (x) : (y))
#define MIN(x, y) ((y) > (x) ? (x) : (y))
template <typename T>
void printvec(vector<T> v) {
	for(typename vector<T>::iterator it = v.begin(); it != v.end(); it++) {
		cout << *it << ' ';
	}
}

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

int R, C, N;
bool valid(int x, int y) {
	return x >= 0 && x < R && y >= 0 && y < C;
}

struct loc {
	int r, c, n, w;
	loc(int a, int b, int d, int e) : r(a), c(b), n(d), w(e) {}

	bool operator<(loc l) const {
		if(n != l.n) {
			return n < l.n;
		}
		if(w != l.w) {
			return w < l.w;
		}
		if(r != l.r) {
			return r < l.r;
		}
		return c < l.c;
	}

	bool operator==(loc l) const {
		return r == l.r && c == l.c && n == l.n && w == l.w;
	}
};

int hamming(int i) {
	int h = 0;
	while(i) {
		if(i & 1) h++;
		i >>= 1;
	}

	return h;
}

void code() {
	cin >> R >> C >> N;

	int minunhappy = INT_MAX;
	for(int i = 0; i < (1 << (R * C)); i++) {
		if(hamming(i) != N) continue;
		vector<vector<bool> > f(R, vector<bool>(C, false));
		int unhappy = 0;
		for(int r = 0; r < R; r++) {
			for(int c = 0; c < C; c++) {
				if(i & 1 << (r * C + c)) {
					f[r][c] = true;
					for(int j = 0; j < 4; j++) {
						int nr = r + dx[j];
						int nc = c + dy[j];
						if(valid(nr,nc) && f[nr][nc]) unhappy++;
					}
				}
			}
		}

		if(unhappy < minunhappy) {
			minunhappy = unhappy;
		}
	}
	cout << minunhappy << endl;
}

int main(int argc, char **argv) {
	int T;
	cin >> T;
	for(int t = 1; t <= T; t++) {
		cout << "Case #" << t << ": ";
		code();
	}
}

