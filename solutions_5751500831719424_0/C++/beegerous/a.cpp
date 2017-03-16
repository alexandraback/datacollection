#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <cstdio>
#include <cmath>
#include <queue>
using namespace std;
const int maxn = 105;
const int INF = 1<<29;
const double eps = 1e-7;
const int mod = 1000000007;
typedef long long LL;

int num[maxn][100];
int n;
char s[maxn];

int main()
{
	int T, nc = 0;
	cin >> T;
	while(T--)
	{
		printf("Case #%d: ", ++nc);
		cin >> n;
		memset(num, 0, sizeof num);

		char fir[maxn], temp[maxn];

		int up;
		bool ok = 1;
		for(int i = 0; i < n; i++) {
			scanf("%s", s);
			if(i == 0) {
				int j, c;

				for(j = 1, c = 0; s[j]; j++)
					if(s[j] != s[j-1]) fir[c++] = s[j-1];
					else num[i][c]++;
				fir[c++] = s[j-1];
				fir[c] = 0;
				up = c;
				//cout << fir << endl;
			} else {
				int j, c;
				for(j = 1, c = 0; s[j]; j++)
					if(s[j] != s[j-1]) temp[c++] = s[j-1];
					else num[i][c]++;
				temp[c++] = s[j-1];
				temp[c] = 0;
				if(strcmp(temp, fir)) ok = 0;
				//cout << temp << endl;
			}
			// for(int j = 0; s[j]; j++)
			// 	num[i][s[j]-'a']++;
		}

		if(!ok) { puts("Fegla Won"); continue; }

		// for(int i = 0; i < n; i++) {
		// 	for(int j = 0; j < up; j++) cout << num[i][j] << ' ';
		// 		cout << endl;
		// }

		int ans = 0;
		for(int i = 0; i < up; i++) {
			int tmp = INF;
			for(int k = 0; k <= 100; k++) {
				int tt = 0;
				for(int j = 0; j < n; j++) tt += abs(num[j][i] - k);
				tmp = min(tmp, tt);
			}
			ans += tmp;
		}
		printf("%d\n", ans);
	}
	return 0;
}