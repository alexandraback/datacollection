#include <iostream>

using namespace std;

int a, b, q[5][5], w[5][5];
int u[20];

int main(){
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
	int T;
	cin >> T;
	for (int tst = 1; tst <= T; tst++){
		printf("Case #%d: ", tst);
		cin >> a;
		for (int i = 1; i <= 4; i++){
			for (int j = 1; j <= 4; j++){
				cin >> q[i][j];
			}
		}
		cin >> b;
		for (int i = 1; i <= 4; i++){
			for (int j = 1; j <= 4; j++){
				cin >> w[i][j];
			}
		}
		memset(u, 0, sizeof(u));

		for (int i = 1; i <= 4; i++) {
			u[q[a][i]]++;
			u[w[b][i]]++;
		}

		int ans = 0;
		int t = 0;
		for (int i = 1; i <= 16; i++){
			if (u[i] == 2){
				ans = i;
				t++;
			}
		}
		if (t == 0) cout << "Volunteer cheated!\n"; else
			if (t > 1) cout << "Bad magician!\n"; else cout << ans << endl;
	}
	return 0;
}
