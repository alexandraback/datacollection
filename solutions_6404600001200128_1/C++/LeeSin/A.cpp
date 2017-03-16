#include <cstdio>
#include <algorithm>
#define N 1005
#define fi(a, b, c) for(int a = (b); a < (c); a++)
#define fd(a, b, c) for(int a = (b); a > (c); a--)
#define FI(a, b, c) for(int a = (b); a <= (c); a++)
#define FD(a, b, c) for(int a = (b); a >= (c); a--)
#define fe(a, b, c) for(int a = (b); a; a = c[a])
using namespace std;

int t, n, a[N], m, x, y;

int main(){
	freopen("A-large.in", "r", stdin);
	freopen("A-large.out", "w+", stdout);
	scanf("%d", &t);
	FI(z, 1, t){
		m = x = y = 0;
		scanf("%d", &n);
		fi(i, 0, n) scanf("%d", &a[i]);
		fi(i, 1, n){
			x += max(0, a[i - 1] - a[i]);
			m = max(m, a[i - 1] - a[i]);
		}
		fi(i, 1, n) y += min(a[i - 1], m);
		printf("Case #%d: %d %d\n", z, x, y);
	}
}
