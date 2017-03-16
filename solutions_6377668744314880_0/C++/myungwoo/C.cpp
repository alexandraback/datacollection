#include <bits/stdc++.h>
using namespace std;

#define sz(v) (int)v.size()
typedef long long lld;

int T, N;

struct Z{
	int x, y, idx;
	double deg;
};

int ccw(Z a, Z b, Z c) // clockwise -1
{
	lld k=(lld)(b.x-a.x)*(c.y-a.y)-(lld)(c.x-a.x)*(b.y-a.y);
	if (k > 0) return 1;
	if (k < 0) return -1;
	return 0;
}


vector<Z> get_boundary(vector<Z> arr)
{
	int n = sz(arr);
	vector <Z> ret;
	if (n < 4) return arr;
	int t = 0;
	for (int i=0;i<n;i++){
		if (arr[t].y > arr[i].y || arr[t].y == arr[i].y && arr[t].x > arr[i].x) t = i;
	}
	swap(arr[0], arr[t]);
	int x = arr[0].x, y = arr[0].y;
	for (int i=1;i<n;i++) arr[i].deg = atan2((double)(arr[i].y-y), (double)(arr[i].x-x));
	sort(arr.begin()+1, arr.end(), [x, y](const Z &a, const Z &b){
		if (fabs(a.deg-b.deg) < 1e-8)
			return abs(a.x-x)+(a.y-y) < abs(b.x-x)+abs(b.y-y);
		return a.deg < b.deg;
	});
	vector <int> stk(n+1, 0); int scnt = 0;
	stk[++scnt] = 0; stk[++scnt] = 1;
	for (int i=2;i<n;i++){
		while (scnt > 2 && ccw(arr[stk[scnt-1]], arr[stk[scnt]], arr[i]) < 0) stk[scnt--] = 0;
		stk[++scnt] = i;
	}
	for (auto &t: arr){
		bool success = 0;
		for (int i=1;i<=scnt;i++){
			int j = i%scnt+1;
			if (!ccw(arr[stk[i]], arr[stk[j]], t)){
				success = 1;
				break;
			}
		}
		if (success) ret.push_back(t);
	}
	return ret;
}

int main()
{
	int ts = 0;
	for (scanf("%d", &T);T--;){
		printf("Case #%d:\n", ++ts);
		scanf("%d", &N);
		vector <Z> A(N+1, {0, 0, 0, 0});
		for (int i=1;i<=N;i++)
			scanf("%d%d", &A[i].x, &A[i].y), A[i].idx = i;
		vector <int> ans(N+1, N-1);
		for (int msk=1;msk<(1<<N);msk++){
			vector <Z> arr;
			int cutted = 0;
			for (int i=1;i<=N;i++){
				if (msk&(1<<(i-1))) arr.push_back(A[i]);
				else cutted++;
			}
			vector <Z> boundary = get_boundary(arr);
			for (auto &t: boundary) ans[t.idx] = min(ans[t.idx], cutted);
		}
		for (int i=1;i<=N;i++) printf("%d\n", ans[i]);
	}
}
