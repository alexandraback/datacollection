#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef pair < ll, ll > pll;

#define x first
#define y second

pll pivot;

ll ccw(const pll &p, const pll &q, const pll &r) {
	return p.x*q.y + q.x*r.y + r.x*p.y - p.y*q.x - q.y*r.x - r.y*p.x;
}

//f가 s보다 빠르면 true
bool byAngle(const pair < pll, int > &f, const pair < pll, int > &s) {
	ll ccwResult = ccw(pivot, f.first, s.first);

	if (ccwResult == 0)
		return abs(f.first.x - pivot.x)+abs(f.first.y - pivot.y) < abs(s.first.x - pivot.x)+abs(s.first.y - pivot.y);

	return ccwResult > 0;
}

vector < int > convexHull(vector < pair < pll, int > > data) {
	vector < pair < pll, int > > sorted;

	int i, minIndex = 0;
	for (i = 0; i < data.size(); i++) {
		sorted.push_back(make_pair(data[i].first, i));

		//y가 가장 작은 점 중 x가 가장 작은 점
		if (data[minIndex].y > data[i].y || (data[minIndex].y == data[i].y && data[minIndex].x > data[i].x))
			minIndex = i;
	}

	pivot = data[minIndex].first;
	sort(sorted.begin(), sorted.end(), byAngle);

	vector < pair < pll, int > > stack;
	stack.push_back(sorted[0]);

	int last = 1;
	for (i = sorted.size()-2; i >= 0; i--) {
		if (ccw(pivot, sorted[sorted.size()-1].first, sorted[i].first) == 0)
			last++;
		else break;
	}

	for (i = 1; i < sorted.size()-last; i++) {
		int top;
		while ((top = stack.size()) >= 2 && ccw(stack[top-2].first, stack[top-1].first, sorted[i].first) < 0)
			stack.pop_back();
		stack.push_back(sorted[i]);
	}

	for (i = 1; i <= last; i++) {
		int top;
		while ((top = stack.size()) >= 2 && ccw(stack[top-2].first, stack[top-1].first, sorted[sorted.size()-i].first) < 0)
			stack.pop_back();
		stack.push_back(sorted[sorted.size()-i]);
	}

	vector < int > convexIndex;
	for (i = 0; i < stack.size(); i++) {
		convexIndex.push_back(stack[i].second);
	}

	sort(convexIndex.begin(), convexIndex.end());

	return convexIndex;
}

int main() {
	freopen("C.out", "w", stdout);

	int numCase, nowCase;
	scanf("%d", &numCase);
	for (nowCase = 1; nowCase <= numCase; nowCase++) {
		int n, ans[3020];
		scanf("%d", &n);

		vector < pair < pll, int > > point;

		int i;
		for (i = 0; i < n; i++) {
			pll temp;
			scanf("%lld%lld", &temp.x, &temp.y);
			point.push_back(make_pair(temp, i));

			ans[i] = n;
		}

		for (i = 1; i < (1<<n); i++) {
			vector < pair < pll, int > > forest;

			int bitCount = n, j;
			for (j = 0; j < n; j++) {
				if ((i >> j) & 1) {
					bitCount--;
					forest.push_back(point[j]);
				}
			}

			vector < int > convexIndex = convexHull(forest);

			for (j = 0; j < convexIndex.size(); j++) {
				int &target = ans[forest[convexIndex[j]].second];
				target = min(target, bitCount);
			}
		}

		printf("Case #%d:\n", nowCase);
		for (i = 0; i < n; i++) {
			printf("%d\n", ans[i]);
		}
	}

	return 0;
}