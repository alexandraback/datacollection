#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <queue>
using namespace std;
const int N = 30;

struct Data {
	int val, id;
	Data() {}
	Data(int _val, int _id) {
		val = _val, id = _id;
	}
	inline friend bool operator <(const Data &a, const Data &b) {
		return a.val < b.val;
	}
};

int n, a[N];
priority_queue<Data> q;

int main() {

	int tcase;
	scanf("%d", &tcase);
	for (int i = 1; i <= tcase; ++i) {
		printf("Case #%d: ", i);
		scanf("%d", &n);
		int m = 0;
		for (int i = 1; i <= n; ++i) {
			scanf("%d", &a[i]);
			m += a[i];
			q.push(Data(a[i], i));
		}
		static char s[3];
		while (m) {
			int k = 0;
			Data x = q.top();
			q.pop();
			s[++k] = 'A' + x.id - 1;
			if (m > 1) {
				Data y = q.top();
				if (x.val == y.val && x.val * 2 == m) {
					q.pop();
					s[++k] = 'A' + y.id - 1;
					m -= 2;
					if (--y.val) q.push(y);
				}
				else
					--m;
			}
			if (--x.val) q.push(x);
			for (int j = 1; j <= k; ++j)
				printf("%c", s[j]);
			printf(" ");
		}
		puts("");
	}

	return 0;
}
