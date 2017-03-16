#include <iostream>
#include <cassert>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

const long long minCoord = -1000000;
const long long maxCoord = 1000000;

long long gcd(long long a, long long b) {
	while (b) {
		a %= b;
		swap(a, b);
	}
	return a;
}

struct point {
	long long x, y;
	point& operator-=(const point& other) {
		x -= other.x;
		y -= other.y;
		return *this;
	}
	point& operator+=(const point& other) {
		x += other.x;
		y += other.y;
		return *this;
	}
	bool operator==(const point& other) const {
		return x == other.x && y == other.y;
	}
	long long operator*(const point& other) const {
		return x * other.y - y * other.x;
	}
	point& reduce() {
		if (x == 0 && y == 0) return *this;
		long long g = gcd(abs(x), abs(y));
		x /= g;
		y /= g;
		if (y < 0 || (y == 0 && x < 0)) {
			x *= -1;
			y *= -1;
		}
		return *this;
	}
	bool operator<(const point& other) const {
		return (*this * other ) > 0;
	}
	friend istream& operator>>(istream& is, point& p) {
		is >> p.x >> p.y;
		assert(p.x >= minCoord && p.x <= maxCoord);
		assert(p.y >= minCoord && p.y <= maxCoord);
		return is;
	}
	friend ostream& operator<<(ostream& os, const point& p) {
		os << "(" << p.x << "," << p.y << ")";
		return os;
	}
};

point points[3000];
point reduced[3000];

int N;

void findAnswer(int q) {
	point shift = points[q];
	map<point,int> inside, outside;
	set<point> events;
	int currentlyOutside = 0;
	for (int i = 0; i < N; i++) {
		points[i] -= shift;
		reduced[i] = points[i];
		reduced[i].reduce();
		if (i == q) continue;
		assert(points[i].x != 0 || points[i].y != 0);
		events.insert(reduced[i]);
		if (points[i].y < 0 || (points[i].y == 0 && points[i].x < 0)) {
			outside[reduced[i]]++;
			currentlyOutside++;
		}
		else {
			inside[reduced[i]]++;
		}
	}
	int best = currentlyOutside;
	//cerr << endl << "  working on point " << shift << endl;
	for (int i = 0; i < 4; i++) { // 2 entire revolutions, should be plenty
		for (set<point>::iterator it = events.begin(); it != events.end(); it++) {
			//if (i == 0) cerr << "  " << *it << endl;
			best = min(best, currentlyOutside - outside[*it]);
			int a = outside[*it];
			int b = inside[*it];
			currentlyOutside += b - a;
			inside[*it] = a;
			outside[*it] = b;
		}
	}
	assert(best >= 0 && best < N);
	cout << best << endl;
	for (int i = 0; i < N; i++) {
		points[i] += shift;
	}
}

void solve() {
	cin >> N;
	assert(N >= 1 && N <= 3000);
	for (int i = 0; i < N; i++) {
		cin >> points[i];
		assert(find(points, points + i, points[i]) == points + i);
	}
	for (int i = 0; i < N; i++) {
		findAnswer(i);
	}
}

int main() {
	int T;
	cin >> T;
	assert(T >= 1 && T <= 100);
	for (int i = 1; i <= T; i++) {
		cerr << "Case #" << i << endl;
		cout << "Case #" << i << ":" << endl;
		solve();
	}
	return 0;
}
