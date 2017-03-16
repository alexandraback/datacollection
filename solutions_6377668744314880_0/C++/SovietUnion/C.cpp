#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
const int N = 5000;
int T, n, X[N], Y[N], ans[N], X0, Y0;
int sgn(long long x){
	if (x > 0) return 1;
	else if (x < 0) return -1;
	else return 0;
}
int cha(int x1, int y1, int x2, int y2){
	return sgn(1ll * x1 * y2 - 1ll * x2 * y1);
}
int dian(int x1, int y1, int x2, int y2){
	return sgn(1ll * x1 * y1 + 1ll * x2 * y2);
}
class Q{
public:
	int x, y, bh;
	bool operator<(const Q &rhs) const{
		int ans1 = cha(x - X0, y - Y0, rhs.x - X0, rhs.y - Y0);
		if (ans1 > 0) return true;
		else if (ans1 < 0) return false;
		int ans2 = dian(x - X0, y - Y0, rhs.x - x, rhs.y - y);
		if (ans2 > 0) return true;
		else return false;
	}
};
Q a[N], b[N];
int stack[N], size;
void tr(int x, int tot){
	if (x > n){
		if (tot == 0) return;
		int pos, minx = 100000000, miny = 100000000;
		for (int i = 1; i <= tot; ++i) b[i] = a[i];
		for (int i = 1; i <= tot; ++i) if (b[i].y < miny || b[i].y == miny && b[i].x < minx){
			minx = b[i].x, miny = b[i].y;
			pos = i;
		}
		swap(b[1], b[pos]);
		X0 = b[1].x, Y0 = b[1].y;
		//printf("%d %d\n", X0, Y0);
		sort(b + 2, b + tot + 1);
		size = 0;
		pos = tot - 1;
		for (; pos >= 1 && cha(b[pos].x - X0, b[pos].y - Y0, b[tot].x - X0, b[tot].y - Y0) == 0; --pos);
		++pos;
		if (pos < tot) for (int i = pos; i <= (pos + tot) / 2; ++i) swap(b[i], b[tot - (i - pos)]);
		//for (int i = 1; i <= tot; ++i) printf(" %d %d\n", b[i].x, b[i].y);
		//printf("\n");
		for (int i = 1; i <= tot; ++i){
			for (; size >= 2; ){
				int i1 = stack[size - 1], i2 = stack[size];
				if (cha(b[i2].x - b[i1].x, b[i2].y - b[i1].y, b[i].x - b[i2].x, b[i].y - b[i2].y) >= 0) break;
				--size;
			}
			stack[++size] = i;
		}
		for (int i = 1; i <= size; ++i) ans[b[stack[i]].bh] = max(ans[b[stack[i]].bh], tot);//, printf("%d ", b[stack[i]].bh);
		//printf("\n");
		return;
	}
	tr(x + 1, tot);
	++tot;
	a[tot].x = X[x], a[tot].y = Y[x], a[tot].bh = x;
	tr(x + 1, tot);
}
int main(){
	freopen("C.in", "r", stdin);
	freopen("C.out", "w", stdout);
	scanf("%d", &T);
	for (int Ti = 1; Ti <= T; ++Ti){
		scanf("%d", &n);
		for (int i = 1; i <= n; ++i) scanf("%d%d", &X[i], &Y[i]), ans[i] = 0;
		tr(1, 0);
		printf("Case #%d:\n", Ti);
		for (int i = 1; i <= n; ++i) printf("%d\n", n - ans[i]);
	}
	return 0;
}
