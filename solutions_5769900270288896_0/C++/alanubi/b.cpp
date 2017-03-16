#include <algorithm>
#include <cstdio>
#include <cassert>
using namespace std;

int count(int a1, int a2, int a3, int a4, int fill)
{
	int result = 0;
	if (fill) {
		int dim = min(fill, a4);
		fill -= dim;
		result += dim *4;
	}
	if (fill) {
		int dim = min(fill, a3);
		fill -= dim;
		result += dim *3;
	}
	if (fill) {
		int dim = min(fill, a2);
		fill -= dim;
		result += dim *2;
	}
	if (fill) {
		int dim = min(fill, a1);
		fill -= dim;
		result += dim *1;
	}
	assert(0 == fill);
	return result;
}

void solve()
{
	int r, c, n;
	scanf("%i%i%i", &r, &c, &n);
	int init = (r -1) * c + r * (c -1);
	int fill = r * c - n;
	if (n <= (r * c +1) /2) {
		printf("%i", 0);
	}
	else if (2 <= min(r, c)) {
		int a = r -2;
		int b = c -2;
		if (r %2 && c %2) {
			int a2 = 4;
			int a3 = a + b -2;
			int a4 = (a * b +1) /2;
			int b2 = 0;
			int b3 = a + b +2;
			int b4 = a * b /2;
			printf("%i", init - max(
				count(0, a2, a3, a4, fill),
				count(0, b2, b3, b4, fill)));
		}
		else {
			int a2 = 2;
			int a3 = a + b;
			int a4 = a * b /2;
			printf("%i", init - count(0, a2, a3, a4, fill));
		}
	}
	else {
		int p = max(r, c);
		if (p %2) {
			int a1 = 2;
			int a2 = p /2 -1;
			int b1 = 0;
			int b2 = p /2;
			printf("%i", init - max(
				count(a1, a2, 0, 0, fill),
				count(b1, b2, 0, 0, fill)));
		}
		else {
			int a1 = 1;
			int a2 = p /2 -1;
			printf("%i", init - count(a1, a2, 0, 0, fill));
		}
	}
}

int main()
{
	int t;
	scanf("%i", &t);
	for (int i = 0; i < t; i++) {
		printf("Case #%i: ", i +1);
		solve();
		printf("\n");
	}
	return 0;
}

