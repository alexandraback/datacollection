#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

struct Point {
	int x, y;
	int order;
	
	bool operator==(const Point &p) const {
		return x == p.x && y == p.y;
	}
	
	bool operator<(const Point &p) const {
		return order < p.order;
	}
};

int N;
Point P[3000];

bool compareByX(const Point &p1, const Point &p2) {
	if (p1.x == p2.x)
		return p1.y > p2.y;
	return p1.x < p2.x;
}

void computeTopHull(vector<int> &out) {
	vector<int> left, right;
	left.push_back(0);
	for (int i = 1; i < N; i++) {
		if (P[i].x == P[left.back()].x)
			continue;
		if (P[i].y > P[left.back()].y)
			left.push_back(i);
	}
	right.push_back(N-1);
	for (int i = N-2; i >= 0; i--) {
		if (P[i].x == P[right.back()].x)
			right.pop_back(), right.push_back(i);
		else if (P[i].y > P[right.back()].y)
			right.push_back(i);
	}
	if (right.back() == left.back())
		right.pop_back();
	for (int i = 0; i < left.size(); i++)
		out.push_back(P[left[i]].order);
	for (int i = right.size()-1; i >= 0; i--)
		out.push_back(P[right[i]].order);
}

int side(const Point &pa, const Point &pb, const Point &p) {
	return (pb.x - pa.x) * (p.y - pa.y) - (p.x - pa.x) * (pb.y - pa.y);
}

void solve() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> P[i].x >> P[i].y;
		P[i].order = i;
	}
	if (N == 1) {
		printf("0\n");
		return;
	}
	vector<int> hullTop, hullBottom;
	sort(P, P + N, compareByX);
	computeTopHull(hullTop);
	for (int i = 0; i < N; i++)
		P[i].y *= -1;
	sort(P, P + N, compareByX);
	computeTopHull(hullBottom);
	if (hullBottom.back() == hullTop.back())
		hullBottom.pop_back();
	reverse(hullBottom.begin(), hullBottom.end());
	if (!hullBottom.empty() && hullBottom.back() == hullTop[0])
		hullBottom.pop_back();
	hullTop.insert(hullTop.end(), hullBottom.begin(), hullBottom.end());
	for (int i = 0; i < N; i++)
		P[i].y *= -1;
	sort(P, P + N);
	/*for (int i = 0; i < hullTop.size(); i++) {
		int j = hullTop[i];
		printf("%d (%d; %d)\n", j, P[j].x, P[j].y);
	}*/
	
	vector<int> mins(N, INT_MAX);
	
	for (int a = 0; a < hullTop.size(); a++) {
		for (int b = a + 1; b < hullTop.size(); b++) {
			Point &pa = P[hullTop[a]];
			Point &pb = P[hullTop[b]];
			int num_neg = 0, num_pos = 0;
			for (int c = 0; c < N; c++) {
				int s = side(pa, pb, P[c]);
				if (s < 0)
					num_neg++;
				else if (s > 0)
					num_pos++;
			}
			for (int c = 0; c < N; c++) {
				int s = side(pa, pb, P[c]);
				if (s == 0)
					mins[c] = min(mins[c], min(num_neg, num_pos));
				else if (s < 0)
					mins[c] = min(mins[c], num_neg - 1);
				else if (s > 0)
					mins[c] = min(mins[c], num_pos - 1);
			}
		}
	}
	
	for (int i = 0; i < N; i++)
		printf("%d\n", mins[i]);
}

int main() {
	int t;
	cin >> t;
	for (int i = 1; i <= t; i++) {
		printf("Case #%d:\n", i);
		solve();
	}
}
