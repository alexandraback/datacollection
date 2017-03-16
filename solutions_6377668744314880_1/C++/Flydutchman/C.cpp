#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<ctime>
#include<map>
#include<string>
#include<vector>
#include<set>

using namespace std;
#define For(i,l,r) for (int i = l; i <= r; ++i)
#define Cor(i,l,r) for (int i = l; i >= r; --i)
#define Fill(a,b) memset(a,b,sizeof(a))
#define FI first
#define SE second
#define MP make_pair
#define PII pair<int,int>
#define flt double
#define INF (0x3f3f3f3f)
#define MaxN 1020304
#define MaxNode 1020304
#define MD 1000000007

struct Point {
	int x, y;
	Point() {}
	Point(int _x, int _y) : x(_x), y(_y) {};
	Point operator - (const Point &b) const {
		return Point(x - b.x, y - b.y);
	}
	Point operator * (int b) const {
		return Point(x * b, y * b);
	}
	long long operator * (const Point &b) const {
		return (long long)x * b.y - (long long)y * b.x;
	}
	double ang() {
		return atan2(y, x);
	}
	bool operator == (const Point &b) const {
		return x == b.x && y == b.y; 
	}
	void read() { scanf("%d%d", &x, &y); }

}A[MaxN];

const double eps = 1e-8;
int dcmp(double x) {
	return (x < -eps) ? -1 : (x > eps);
}

const double Pi = acos(-1.0);
int n, ans[MaxN];
double B[MaxN];
int main() {
	//freopen("input.txt","r",stdin); //freopen("output.txt","w",stdout);
	int T; cin >> T;
	For(TK,1,T) {
		printf("Case #%d:\n", TK);
		cin >> n;
		For(i,1,n) A[i].read();
		For(i,1,n) {
			int Tot = 0;
			For(j,1,n) if (i != j) {
				Point tmp = (A[j] - A[i]);
				B[++Tot] = (A[j] - A[i]).ang();
			}
			sort(B + 1, B + Tot + 1);
			For(j,1,Tot) B[Tot + j] = B[j] + 2 * Pi;
			int p = 1;
			ans[i] = n - 1;
			For(j,1,Tot) {
				while (p < Tot + Tot && dcmp(B[j] + Pi - B[p + 1]) >= 0) ++p;
				ans[i] = min(ans[i], n - (p - j + 2));
			}
		}
		For(i,1,n) printf("%d\n", ans[i]);
	}
	return 0;
}

