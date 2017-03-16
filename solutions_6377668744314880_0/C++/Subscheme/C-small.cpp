#include <iostream>
#include <algorithm>
#include <queue>
#include <utility>
#include <vector>
using namespace std;
#define range(i,a,b) for(int i = (a), _n = (b); i < _n; ++i)
#define fo(i,n) range(i,0,n)

typedef long long ll;
typedef pair<ll,ll> pr;
typedef pair<pr, int> cpr;
const int N = 3100;
pr p[N];
int n;

#define _x first
#define _y second

istream& operator >> (istream& in, pr& p) {
	return in >> p._x >> p._y;
}

ostream& operator << (ostream& out, const pr& p) {
	return out << '(' << p._x << ", " << p._y << ')';
}

ll operator *(const pr& a, const pr& b) {
	return a._x * b._x + a._y * b._y;
}

ll operator ^(const pr& a, const pr& b) {
	return a._x * b._y - a._y * b._x;
}

pr operator +(const pr& a, const pr& b) {
	return pr(a._x + b._x, a._y + b._y);
}

pr operator -(const pr& a) {
	return pr(-a._x, -a._y);
}

pr operator -(const pr& a, const pr& b) {
	return a + (-b);
}

bool ccw(const pr& base, const pr& a, const pr& b) {
	return ((a - base) ^ (b - base)) < 0;
}

bool ccw2(int base, int a, int b) {
	return ccw(p[base], p[a], p[b]);
}

bool ccwComp(const pr& a, const pr& b) {
	return ((a - p[n-1]) ^ (b - p[n-1])) > 0;
}

int cmpTo;
bool cwComp(const pr& a, const pr& b) {
	ll x = ((a - p[cmpTo]) ^ (b - p[cmpTo]));
	if (x > 0) return true;
	if (x == 0 && (a._y > b._y)) return true;
	return false;
}

bool cwComp2(const cpr& a, const cpr& b) {
	return ((a.first - p[n-1]) ^ (b.first - p[n-1])) < 0;
}

bool cwComp3(int a, int b) {
	return cwComp(p[a], p[b]);
}

int results[N];

void go(int bitmask) {
	vector<int> v;
	fo(i,n) if (bitmask & (1 << i)) v.push_back(i);
	
	if (v.size() <= 3) {
		fo(i,v.size()) results[v[i]] = max(results[v[i]], (int)v.size());
		return;
	}

	fo(i,v.size()) if (p[v[i]] < p[v[0]]) swap(v[i], v[0]);
	cmpTo = v[0];
	sort(v.begin()+1, v.end(), cwComp3);
	

	vector<int> h;
	fo(i, v.size()) {
		while (h.size() >= 2) {
			if (ccw2(h[h.size()-2], h.back(), v[i])) {
				h.pop_back();
			} else {
				break;
			}
		}
		h.push_back(v[i]);
	}

	/*
	cout << "Points: ";
	fo(i,v.size()) cout << p[v[i]] << ' ';
	cout << endl;
	cout << "Hull: ";
	fo(i, h.size()) cout << p[h[i]] << ' ';
	cout << endl << endl;
	*/

	fo(i,h.size()) results[h[i]] = max(results[h[i]], (int)v.size());
}

int main() {
	int T;
	cin >> T;
	range(testCase, 1, T+1) {
		cin >> n;
		fo(i,n) cin >> p[i];
		fo(i,n) results[i] = 0;
		fo(i,1<<n) go(i);
		cout << "Case #" << testCase << ":\n";
		fo(i,n) cout << n - results[i] << '\n';
	}
}