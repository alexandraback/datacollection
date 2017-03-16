#define FOR(i,n) for (int i=0; i<n; i++)
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string>

using namespace std;
int f(int n, int c2, int c3, int c4) {
	if (n < 0) return 0;
	
	int sum = 0;
	if (n <= c2) {
		sum = n * 2;
		return sum;
	}
	
	sum += c2 * 2;
	n -= c2;

	if (n <= c3) {
		sum += n * 3;
		return sum;
	}
	sum += c3 * 3;
	n -= c3;

	if (n <= c4) {
		sum += n * 4;
		return sum;
	}
	return -1;
	

}
int min(int a, int b) {
	if (a > b) return b;
	return a;
}

int main(void) {
	freopen("c:\\input.txt", "r", stdin);
	freopen("c:\\output.txt", "w", stdout);

	int t; scanf("%d", &t);
	FOR(i, t) {
		int r, c, n; scanf("%d %d %d", &r, &c, &n);
		int ret;
		if (r*c % 2 == 1) { //both odd
			
			ret = min( f( n - (r*c+1)/2, 0, r+c-2, (r*c-1)/2 - (r+c-2)), f( n-(r*c-1)/2, 4, r+c-6, (r*c+1)/2 -(r+c-6) -4 ));

		}
		else {
			ret = f(n - r*c / 2, 2, r + c - 4, r*c / 2 - (r + c - 4) - 2);
			/*if (r % 2 == 0 && c % 2 == 0) { //both even
			
			}
			else { //one odd, other even
				ret = f(r*c /2 , 2, r+)



			}*/

		}
		printf("Case #%d: %d\n", i + 1, ret);
	}

	return 0;
}
