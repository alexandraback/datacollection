#include <iostream>

using namespace std;

int arr[20][20];
int t, r, c, n;

int main() {
	
	freopen("Bsmall.in", "r", stdin);
	freopen("Bsmall.out", "w", stdout);
	
	cin >> t;
	for(int C = 1;C <= t;C++) {
		cin >> r >> c >> n;
		int area = (r * c);
		int mn = (-1u/2);
		for(int i = 0;i < (1 << area);i++) {
			if(__builtin_popcount(i) != n) {
				continue;
			}
			for(int j = 0;j < area;j++) {
				arr[j / c][j % c] = !!(i & (1 << j));
			}
			int cnt = 0;
			for(int i = 0;i < r;i++) {
				for(int j = 0;j < c;j++) {
					if(i > 0) {
						cnt += arr[i][j] && arr[i-1][j];
					}
					if(j > 0) {
						cnt += arr[i][j] && arr[i][j-1];
					}
				}
			}
			if(cnt < mn) {
				mn = cnt;
			}
		}
		cout << "Case #" << C << ": " << mn << endl;
	}
	return 0;
}
