#include <fstream>
#include <iostream>
using namespace std;

ifstream fin("b.in");
ofstream fout("b.out");

int x, y, n, res;
bool st[18][18];

void dfs(int cx, int cy, int d) {
	if (d > n) return;
	if (cy == y) {
		if (d != n) return;
		int unh = 0;
		for (int i = 0; i <= x; i++)
			for (int j = 0; j <= y; j++) {
				if (st[i][j] && st[i + 1][j]) unh++;
				if (st[i][j] && st[i][j + 1]) unh++;
			}
		res = min(res, unh);
		return;
	}
	int nx = cx + 1, ny = cy;
	if (nx == x) nx = 0, ny++;

	for (int i = 0; i < 2; i++) {
		st[cx][cy] = i;
		dfs(nx, ny, d + i);
	}
}

int solve() {
	for (int i = 0; i < 18; i++)
		for (bool &b : st[i]) b = false;
	res = 1 << 30;
	fin >> x >> y >> n;
	dfs(0, 0, 0);
	return res;
}

int main() {
	int a;
	fin >> a;
	for (int i = 0; i < a; i++)
		fout << "Case #" << i+1 << ": " << solve() << endl;
}
