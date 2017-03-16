#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#define X first
#define Y second

using namespace std;

using LL = long long;

int test_case, n;

const int MaxN = 1000;
const double eps = 1e-8;
struct Coordinate{
	int x, y;
	int idx;
	Coordinate() : x(0), y(0) {}
	Coordinate(double x, double y) : x(x), y(y) {}
	bool operator< (const Coordinate&a) const {
		return x != a.x ? x < a.x : y < a.y;
	}
	Coordinate operator- (const Coordinate&a) const {
		return Coordinate(x - a.x, y - a.y);
	}
	LL operator% (const Coordinate&a) const {
		return (LL) x * a.y - (LL) y * a.x;
	}
	LL length() {
		return (LL) x * x + (LL) y * y;
	}
}O;

vector<Coordinate> a, b;
vector<int> ans;

int sgn(LL x){
	return x < 0LL ? -1 : x > 0;
}

vector<Coordinate> makeHull(vector<Coordinate> cor){
	vector<Coordinate> hull;
	sort(cor.begin(), cor.end());
	for (int i = 0;i < (int) cor.size(); ++i){
		while(hull.size() > 1 && sgn((hull.back() - hull[hull.size() - 2]) % (cor[i] - hull.back())) < 0)
			hull.pop_back();
		hull.push_back(cor[i]);
	}
	int bot = hull.size(); 
	for (int i = cor.size() - 1; i >= 0; --i){
		while(hull.size() > bot && sgn((hull.back() - hull[hull.size() - 2]) % (cor[i] - hull.back())) < 0)
			hull.pop_back();
		hull.push_back(cor[i]);
	}
	return hull;
}

void dfs(int dep) {
	if (dep < n) {
		b.push_back(a[dep]);
		dfs(dep + 1);
		b.pop_back();
		dfs(dep + 1);
	} else {
		if (b.size() > 2) {
			static int cnt = 0;
			//cout << ++cnt << "checking..." << endl;
			auto hull = makeHull(b);
			//cout << "hull made..." << endl;
			for (auto &cur : hull) {
				ans[cur.idx] = min(ans[cur.idx], (int) (a.size() - b.size()));
				//cout << "T_T" << endl;
			}
			//cout << "return" << endl;
		}
	}
}

int main() {
	cin >> test_case;
	for (int cur_case = 1; cur_case <= test_case; ++cur_case) {
		cin >> n;
		a.clear();
		b.clear();
		ans.clear();
		for (int i = 0; i < n; ++i) {
			Coordinate tmp;
			cin >> tmp.x >> tmp.y;
			tmp.idx = i;
			a.push_back(tmp);
			ans.push_back(n + 1);
		}
		dfs(0);
		cout << "Case #" << cur_case << ":" << endl;
		for (int i = 0; i < n; ++i) {
			cout << ans[i] << endl;
		}
	}
	return 0;
}
