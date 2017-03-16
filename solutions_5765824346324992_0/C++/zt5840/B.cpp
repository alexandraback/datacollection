#include <bits/stdc++.h>
#define ALL(x) x.begin(), x.end()
#define SIZE(x) (int)(x.size())
#define FOR(i, s, e) for (int i = int(s); i < int(e); ++i)
#define FORIT(i, c) for (__typeof((c).begin()) i = (c).begin(); i != (c).end(); ++i)
using namespace std;

typedef long long LL;
typedef pair<int, int> PII;
typedef pair<long long, long long> PLL;
const int MOD = 1000000007;
const LL INF = (LL)10e14;
const int MAX = 1010;

char str_template[] = "Case #%d: %d";
char str_answer[sizeof(str_template)];

LL M[MAX];

int main() {
	freopen("output.txt", "w", stdout);
	int T;
	cin >> T;
	for (int testcase = 1; testcase <= T; ++testcase) {
		LL B, N;
		cin >> B >> N;
		for (int i = 0; i < B; ++i) {
			cin >> M[i];
		}
		LL left = 0, right = INF;

		while (left < right) {
			LL mid = (left + right) >> 1;
			LL sum = 0;
			for (int i = 0; i < B; ++i) {
				sum += ((mid / M[i]) + 1);
			}
			if (sum < N) {
				left = mid + 1;
			} else {
				right = mid;
			}
		}
		LL temp = 0;
		int ans = 0;

		for (int i = 0; i < B; ++i) {
			temp += ((right / M[i]) + 1);
			if (right % M[i] == 0) {
				temp--;
			}
		}
		temp = N - temp;
		//cout << right << " " << temp << endl;

		for (int i = 0; i < B; ++i) {
			if (right % M[i] == 0) {
				temp--;
				if (temp == 0) {
					ans = i + 1;
					break;
				}
			}
		}
		sprintf(str_answer, str_template, testcase, ans);
		cout << str_answer << endl;
	}
	return 0;
}
