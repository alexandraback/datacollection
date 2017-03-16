#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int x, y, z, n, dir, w, kx,ky, score, N[100][100], W[100], minn, minp, nn;
bool vis[100];
vector<int> V[100];

int main() {
	ios_base::sync_with_stdio(0);
	cin >> z;
	for (int t = 1; t <= z; t++) {
		cin >> x >> y >> n;
		dir = 0;
		w = 0;
		kx = 1;
		ky = 1;
		score = 0;
		while (w < x * y) {
			if (N[kx][ky] == 0) {
				w++;
				N[kx][ky] = w;
			}
			if (dir == 0) {
				if (kx + 1 <= x && N[kx + 1][ky] == 0) {
					kx++;
				}
				else {
					dir = 1;
				}
			}
			else if (dir == 1) {
				if (ky + 1 <= y && N[kx][ky + 1] == 0) {
					ky++;
				}
				else {
					dir = 2;
				}
			}
			else if (dir == 2) {
				if (kx - 1 >= 1  && N[kx - 1][ky] == 0) {
					kx--;
				}
				else {
					dir = 3;
				}
			}
			else if (dir == 3) {
				if (ky - 1 >= 1 && N[kx][ky - 1] == 0) {
					ky--;
				}
				else {
					dir = 0;
				}
			}
		}		
		for (int i = 1; i <= x; i++) {
			for (int j = 1; j <= y; j++) {
				if (i > 1) {
					V[N[i][j]].push_back(N[i - 1][j]);
				}
				if (i < x) {
					V[N[i][j]].push_back(N[i + 1][j]);
				}
				if (j > 1) {
					V[N[i][j]].push_back(N[i][j - 1]);
				}
				if (j < y) {
					V[N[i][j]].push_back(N[i][j + 1]);
				}
			}
		}
		nn = n;
		n = min(n, x * y);
		while (n--) {
			minn = 5;
			minp = x * y + 1;
			for (int i = 1; i <= x * y; i++) {
				if ((i + (x * y) % 2 + nn % 2) % (x * y) == 0) {
					if (!vis[(i + (x * y) % 2 + nn % 2)] && W[(i + (x * y) % 2 + nn % 2)] < minn) {
						minn = W[(i + (x * y) % 2 + nn % 2)];
						minp = (i + (x * y) % 2 + nn % 2);
					}
				}
				else {
					if (!vis[(i + (x * y) % 2 + nn % 2) % (x * y)] && W[(i + (x * y) % 2 + nn % 2) % (x * y)] < minn) {
						minn = W[(i + (x * y) % 2 + nn % 2) % (x * y)];
						minp = (i + (x * y) % 2 + nn % 2) % (x * y);
					}
				}
			}
			vis[minp] = true;
			for (int i = 0; i < V[minp].size(); i++) {
				if (vis[V[minp][i]]) {
					score++;
				}
				else {
					W[V[minp][i]]++;
				}
			}
		}
		cout << "Case #" << t << ": " << score << '\n';
		for (int i = 0; i <= x * y; i++) {
			W[i] = 0;
			vis[i] = false;
			V[i].clear();
			for (int j = 0; j <= x * y; j++) {
				N[i][j] = 0;
			}
		}
	}
}
