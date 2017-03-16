#include<iostream>
#include<algorithm>
using namespace std;

int apart[22][22];

int bitcnt(int x){
	int ret = 0;
	while (x){
		if (x & 1) ret++;
		x /= 2;
	}
	return ret;
}

int dx[4] = { 1, -1, 0, 0 }, dy[4] = { 0, 0, 1, -1 };

int main(){
	freopen("input.in", "r", stdin);
	freopen("output.txt", "w", stdout);

	int T;
	cin >> T;
	for (int tc = 1; tc <= T; tc++){
		for (int i = 0; i < 22; i++)for (int j = 0; j < 22; j++) apart[i][j] = 0;
		cout << "Case #" << tc << ": ";
		int ans = 987654321;
		int n, r, c;
		cin >> r >> c >> n;

		for (int bit = 0; bit < (1 << (r*c)); bit++){
			if (bitcnt(bit) == n){
				int k = 0;
				for (int i = 1; i <= r; i++){
					for (int j = 1; j <= c; j++){
						apart[i][j] = bit & (1 << k);
						k++;
					}
				}

				int curr = 0;
				for (int i = 1; i <= r; i++){
					for (int j = 1; j <= c; j++){
						for (int k = 0; k < 4; k++){
							if (apart[i][j] && apart[i + dx[k]][j + dy[k]])
								curr++;
						}
					}
				}

				curr /= 2;
				ans = min(ans, curr);
			}
		}

		cout << ans << endl;
	}
}