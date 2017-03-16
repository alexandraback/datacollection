#include <cstdio>
using namespace std;
int get(int i) {
	int ret = 0;
	while (i > 0) {
		i = i &(i-1);
		ret ++;
	}
	return ret;
}
int main() {
	freopen("B-small-attempt0.in", "r", stdin);
	freopen("Bout.txt", "w", stdout);
	int T, r, c, n, ans;
	scanf("%d", &T);
	for (int _ = 1; _ <= T; ++_) {
		scanf("%d%d%d", &r, &c, &n);
		ans = 2000000000;
		if (n <= (r*c+1) >> 1)
			printf("Case #%d: 0\n", _);
		else {
			int len = 1 << (r * c);
			for (int i = 0; i < len; ++i) {
				int tmp = 0;
				if (get(i) != n)
					continue;
				for (int j = 0; j < r*c; ++j) {
					if (i & (1 << j)) {
						if (j % c) {
							tmp += (i & (1 << (j-1))) > 0;
						}
						if (j % c != c-1){
							tmp += (i & (1 << (j+1))) > 0;
						}
						if (j / c) {
							tmp += (i & (1 << (j-c))) > 0;
						}
						if (j / c < r-1) {
							tmp += (i & (1 << (j+c))) > 0;
						}
					}
				}
				if (ans > tmp)
					ans = tmp;
			}
			printf("Case #%d: %d\n",_, ans/2);
		}
	}
	return 0;
}