#include <stdio.h>
#include <algorithm>
#include <memory.h>
using namespace std;

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int test;
	scanf("%d", &test);
	for (int t = 1; t <= test; t++) {
		int r, c, n;
		scanf("%d %d %d", &r, &c, &n);
		int value = 0;

		if (r % 2 == 1) { swap(r, c); }

		if ((r * c + 1) / 2 >= n) {
			printf("Case #%d: 0\n", t);
		}
		else {
			if (r == 1 || c == 1) {
				int n1 = n - (r * c + 1) / 2;
				int n2 = n - (r * c) / 2;

				int t1 = 0;
				int t2 = 1999999999;

				if ((r * c) % 2 == 1) {
					t1 = n1 * 2;
					t2 = 0;
					if (n2 <= 2) {
						t2 = n2 * 1;
						n2 = 0;
					}
					else {
						t2 = 2;
						n2 -= 2;
					}

					t2 += n2 * 2;
				}
				else {
					if (n1 <= 1) {
						t1 = 1;
						n1 = 0;
					}
					else {
						t1 = (n1 - 1) * 2 + 1;
					}
				}

				if (t1 < t2) {
					value = t1;
				}
				else {
					value = t2;
				}
			}
			else {
				if ((r * c) % 2 == 0 && (r + c) % 2 == 0) {
					n -= (r * c + 1) / 2;
					// e * e
					if (n <= 2) {
						value = 2 * n;
						n = 0;
					}
					else {
						value = 4;
						n -= 2;
					}

					int f = (r / 2 - 1) * 2 + (c / 2 - 1) * 2;
					if (f >= n) {
						value += n * 3;
					}
					else {
						value += f * 3;
						n -= f;
						value += n * 4;
					}
				}
				else if ((r * c) % 2 == 0 && (r + c) % 2 == 1) {
					n -= (r * c + 1) / 2;
					// e * o
					if (n <= 2) {
						value = 2 * n;
						n = 0;
					}
					else {
						value = 4;
						n -= 2;
					}

					int f = (r / 2 - 1) * 2 + (c / 2) + ((c + 1) / 2 - 2);
					if (f >= n) {
						value += n * 3;
					}
					else {
						value += f * 3;
						n -= f;
						value += n * 4;
					}
				}
				else {
					// o * o
					int n1 = n - (r * c + 1) / 2;
					int n2 = n - (r * c) / 2;

					int t1 = 0;
					int t2 = 0;

					// case #1
					
					int f = (r / 2) * 2 + (c / 2) * 2;
					if (f >= n1) {
						t1 = n1 * 3;
					}
					else {
						t1 = f * 3;
						n1 -= f;
						t1 += n1 * 4;
					}

					// case #2

					if (n2 <= 4) {
						t2 = 2 * n2;
						n2 = 0;
					}
					else {
						t2 = 8;
						n2 -= 4;
					}

					f = ((r + 1) / 2 - 2) * 2 + ((c + 1) / 2 - 2) * 2;
					if (f >= n2) {
						t2 += n2 * 3;
					}
					else {
						t2 += f * 3;
						n2 -= f;
						t2 += n2 * 4;
					}

					if (t1 < t2) {
						value = t1;
					}
					else {
						value = t2;
					}
				}
			}
			printf("Case #%d: %d\n", t, value);
		}
	}
}