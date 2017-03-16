#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <map>
#include <vector>

#define FOR(i, s, e) for (int i=(s);i<(e);i++)
#define FOE(i, s, e) for (int i=(s);i<=(e);i++)
#define N 30
using namespace std;

int test, sum, a[N], n, A, B;

int main() {
	scanf("%d", &test);
	FOR(TC, 0, test) {
		scanf("%d", &n);
		sum = 0;
		FOR(i, 0, n) a[i] = 0;
		FOR(i, 0, n){
			scanf("%d", &a[i]);
			sum += a[i];
		}
		printf("Case #%d:", TC + 1);
		
		while (sum > 0) {
			int ok = 0;
			FOR(i, 0, n)
			FOR(j, 0, n)
				if (a[i] > 0 && a[j] > 0) {
				int mx = 0, pos = -1;
				a[i]--, a[j]--;
				FOR(k, 0, n)
					if (mx < a[k]) mx = a[k], pos = k;
				if (mx * 2 <= sum - 2) {
					ok = 1;
					A = i;
					B = j;
				}
				a[i]++, a[j]++;
			}
			
			if (ok) {
				printf(" %c%c", 'A' + A, 'A' + B);
				a[A]--;
				a[B]--;
				sum -= 2;
			}
			else {
				FOR(i, 0, n) if (a[i] > 0) {
					int mx = 0, pos = -1;
					a[i]--;
					FOR(j, 0, n) 
						if (mx < a[j]) mx = a[j], pos = j;
					if (mx * 2 <= sum - 1) {
						ok = 1;
						A = i;
					}
					a[i]++;
				}
				printf(" %c", 'A' + A);
				a[A]--;
				sum--;
			}
		}
		printf("\n");
		
	}
	return 0;
} 
