#pragma comment(linker, "/STACK:512000000")
#include <iostream>
#include <vector>
#include <iomanip>
#include <set>
#include <queue>
#include <deque>
#include <map>
#include <list>
#include <algorithm>
#include <stdlib.h>
#include <stdio.h>
#include <cstring>
#include <ctime>
#include <string>
#include <sstream>
#include <math.h>
#include <stack>

using namespace std;

#define eprintf(...) fprintf(stderr, __VA_ARGS__)


bool field[20][20];

int ans[20][20][400];

int col = 0;
int ansval;
int R, C;
void check(int x, int y, int r) {
	if (x == R + 1) {
		++y;
		if (y == C + 1) {
			return;
		}
		x = 0;
	}

	if (col > ansval || r < (C - y) * R + R - x) return;

	if (r == 0) {
		ansval = col;
		return;
	}

	if (field[x-1][y] || field[x][y-1]) {
		check(x + 1, y, r);
	
		field[x][y] = 1;
		col += field[x-1][y];
		col += field[x][y-1];
		check(x + 1, y, r - 1);
		col -= field[x-1][y];
		col -= field[x][y-1];	
	} else {
		field[x][y] = 1;
		col += field[x-1][y];
		col += field[x][y-1];
		check(x + 1, y, r - 1);
		col -= field[x-1][y];
		col -= field[x][y-1];
		check(x + 1, y, r);
	}
}

void checke(int x, int y, int r) {
	if (x == R + 1) {
		++y;
		if (y == C + 1) {
			return;
		}
		x = 0;
	}



	if (r == 0) {
		ansval = col;
		return;
	}
}


int get(int i, int j) {
	return field[i-1][j]  + field[i][j-1] + field[i+1][j] + field[i][j+1];
}

struct pa {
	int x;
	int y;

	pa(int x, int y) : x(x), y(y) {}

	bool operator < (const pa& other) const {
		if (x == other.x && y == other.y) return 0;
		//cerr << x << " " << y << " " << other.x << " " << other.y << endl;
		if (get(x, y) != get(other.x, other.y)) return get(x, y) > get(other.x, other.y);
		if (x != other.x) return x < other.x;
		return y < other.y;;
	}

	
};

int solve(int r, int c, int n) {
	memset(field, 0, sizeof(field));
	for (int i = 1; i <= r; ++i) {
		for (int j = 1; j <= c; ++j) {
			field[i][j] = 1;
		}
	}
	set< pa > s;
	for (int i = 1; i <= r; ++i) {
		for (int j = 1; j <= c; ++j) {
			s.insert(pa(i, j));
		}
	}

	int dx[] = {-1, 1, 0, 0};
	int dy[] = {0, 0, -1, 1};
	while(s.size() != n) {
		int x = s.begin() -> x;
		int y = s.begin() -> y;

		s.erase(s.begin());
		for (int z = 0; z < 4; ++z) {
			int nx = x + dx[z];
			int ny = y + dy[z];
			if (field[nx][ny]) {
				s.erase(pa(nx, ny));
			}
		}

		field[x][y] = 0;
		for (int z = 0; z < 4; ++z) {
			int nx = x + dx[z];
			int ny = y + dy[z];
			if (field[nx][ny]) {
				s.insert(pa(nx, ny));
			}
		}
	}

	int ans = 0;
	for (int i = 1; i <= r; ++i) {
		for (int j = 1; j <= c; ++j) {
			if (field[i][j]) ans += get(i, j);
		}
	}

	return (ans ) / 2;
}

int main() {

	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
	   freopen("output.txt","w",stdout);
	#else
	#define taskname "cutting"
		//freopen(taskname".in","r",stdin);
		//freopen(taskname".out","w",stdout);
	#endif

	
	int tests_; cin >> tests_;
	for (int test_ = 1; test_ <= tests_; ++test_) {
		int r, c, n;
		cin >> r >>c >> n;

		cout << "Case #"<< test_ << ": ";
		cout << solve(r, c, n) << endl;
	}
	
	return 0;
}