#include <iostream>
#include <algorithm>
using namespace std;

class point {
public:
	long long x, y;
};

point p[3010];

int main() {
	int T;
	cin.sync_with_stdio(false);
	cin >> T;
	for (int cas = 1; cas <= T; cas++) {
		int N;
		cin >> N;
		long long res[3010];
		for (int i = 0; i < N; i++) {
			cin >> p[i].x >> p[i].y;
			res[i] = N == 1 ? 0 : N;
		}
		cout << "Case #" << cas << ":" << endl;
		for (int i = 0; i < N; i++) {
			for (int j = i + 1; j < N; j++) {
				long long a = p[j].y - p[i].y;
				long long b = p[i].x - p[j].x;
				long long c = p[j].x * p[i].y - p[i].x * p[j].y;
				long long pos = 0, neg = 0;
				for (int k = 0; k < N; k++) {
					long long temp = a * p[k].x + b * p[k].y + c;
					if (temp > 0) {
						pos++;
					}
					else if (temp < 0) {
						neg++;
					}
				}
				long long small = min(pos, neg);
				res[i] = min(res[i], small);
				res[j] = min(res[j], small);
			}
			cout << res[i] << endl;
		}
	}
}