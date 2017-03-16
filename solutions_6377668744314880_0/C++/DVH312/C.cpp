#include <bits/stdc++.h>
using namespace std;
struct Point{
	long long x, y, cs;
	int operator<(Point r) const{
		return x < r.x || (x == r.x && y < r.y);
	}
};



int nTest;
int n;
int px[3333],py[3333];
int ans[3333];
vector<Point> T;

long long CCW(Point O, Point A, Point B){
	return (A.x - O.x) * (B.y  - O.y) - (A.y - O.y) * (B.x - O.x);
}
vector<Point> convex_hull(vector<Point> P){
	sort(P.begin(), P.end());
	vector <Point> H;
	for (int i = 0; i < P.size(); i++){
		while (H.size() > 1 && CCW(H[H.size() - 2], H.back(), P[i]) < 0) H.pop_back();
		H.push_back(P[i]);
	}
	for (int i = P.size() - 2, t = H.size(); i >= 0; i--){
		while (H.size() > t && CCW(H[H.size() - 2], H.back(), P[i]) < 0) H.pop_back();
		H.push_back(P[i]);	
	}
	return H;
}
int main(){
	freopen("C.inp", "r", stdin);
	freopen("C.out", "w", stdout);
	scanf("%d", &nTest);
	for (int test = 1; test <= nTest; test++){
		scanf("%d", &n);
		for (int i = 1; i <= n; i++){
			scanf("%d %d", px + i, py + i);
		}		
		for (int i = 0; i <= n; i++) ans[i] = n;

		for (int stt = 0; stt < (1 << n); stt++){
			T.clear();
			int cnt_0 = 0;
			for (int j = 0; j < n; j++){
				if (((stt >> j) & 1) == 1) {
					Point tam;
					tam.x = px[j + 1];
					tam.y = py[j + 1];\
					tam.cs = j + 1;
					T.push_back(tam);
				} else cnt_0 ++;
			}
			vector <Point> res;
			res.clear();
			res = convex_hull(T);
			if (!res.empty()) res.pop_back();

			for (int i = 0; i < res.size(); i++){
				ans[res[i].cs] = min(ans[res[i].cs], cnt_0);
			}
		}
		printf("Case #%d:\n", test);
		for (int i = 1; i <= n; i++) printf("%d\n", ans[i]);
	}
	return 0;
}