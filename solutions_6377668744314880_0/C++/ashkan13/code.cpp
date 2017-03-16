// In the Name of Allah
// AD13

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
using namespace std;

typedef long long ll;		//	typedef unsigned long long  ull;
typedef pair <int, int> pii;//	typedef pair <double, double> pdd;
typedef vector <int> VI;
#define MP make_pair
const int INF = 2147483647, MOD = 1000*1000*1000 + 7;
const double eps = 1e-8; // (eps < 1e-15) is the fact (1e-14)
#define For(i, n) for (int i = 0; i < (n); i++)
#define For1(i, n) for (int i = 1; i <= (n); i++)
//#define debug(x) { cerr << #x << " = _" << (x) << "_" << endl; }
void Error(string err) { cout << err; cerr << "_" << err << "_"; exit(0); }
int gcd(int a, int b) { return (b==0)? a: gcd(b, a%b); }
/*-------------------------------------------------------------------------------------*/

struct Poll{ 
	ll x, y; 
	Poll(){}
	Poll(ll a, ll b):x(a), y(b){}
	bool operator < (const Poll & p) const {
		if (x != p.x) return x < p.x;
		return y < p.y;
	}
};

ll cross (Poll &o, Poll &a, Poll &b)
{
	ll d1 = (a.x - o.x) * (b.y - o.y);
	ll d2 = (a.y - o.y) * (b.x - o.x);
	return d1 - d2;
}

vector<Poll> convex_hull (vector<Poll> & vp)
{
	ll n = vp.size(), k = 0;
	vector<Poll> ret (n + n);
 
	sort(vp.begin(), vp.end());
 
	// lower hull
	For (i, n) {
		while (k >= 2 && cross (ret[k-2], ret[k-1], vp[i]) <= 0) k--;
		ret[k++] = vp[i];
	}
 
	// build uh
	for (ll i = n-2, t = k+1; i >= 0; i--) {
		while (k >= t && cross (ret[k-2], ret[k-1], vp[i]) <= 0) k--;
		ret[k++] = vp[i];
	}
 
	ret.resize (k);
	return ret;
}

bool is_left_of(Poll a, Poll b, Poll p){
	float ax = a.x, ay = a.y,
		bx = b.x, by = b.y,
		px = p.x, py = p.y;
	return (bx-ax)*(py-ay) - (by-ay)*(px-ax) > 0;
	//return (py-ay > (by-ay)*(px-ax)/(bx-ax));
}
bool is_right_of(Poll a, Poll b, Poll p){
	return !is_left_of(a,b,p);
	// X     == colinear
}

bool isInside () {
	// is inside convex?
	bool is_in = true;
	/*for(ll i=0; is_in && i<poll_size; i++){
		Poll a = poll[i], b = poll[0];
		if(i != poll_size-1) b = poll[i+1];
		if(is_right_of(a,b,inside)) 
			is_in = false;
	}*/
	return is_in;
}

void getGeneralLineEq (ll & a, ll & b, ll& c,
	ll x1, ll y1, ll x2, ll y2) {
	// ax + by + c = 0 // cal. from y - y1 = m (x - x1) // m = dy / dx
	a = y1 - y2;
	b = x2 - x1;
	c = -b * y1 - a * x1;
}
bool isOnLine (ll x1, ll y1, ll a, ll b, ll c) {
	// is poll (x1, y1) in the line 'ax+by+c=0'?
	double cc = a * x1 + b * y1 + c;
	return (cc == 0);
}

bool lies (Poll p, Poll x, Poll y) {
	// p lies on a-b
	ll a, b, c;
	getGeneralLineEq (a, b, c, x.x, x.y, y.x, y.y);
	return isOnLine(p.x, p.y, a, b, c);
}

ll n;
bool is[3030];
Poll arr[3030];
ll ans[3030];

void check (ll ind) {
	if (ind == n) {
		// check
		vector <Poll> v;
		For (i, n)
			if (is[i])
				v.push_back(arr[i]);
		if (v.size() < 4) return;

		auto ch = convex_hull (v);
		
		/*if (v.size() == n) {
			cout << "ch of " << v.size() << " -> " << ch.size() << endl;
			For (i, ch.size()) cout << ch[i].x << "," << ch[i].y << " "; cout << endl;
		}*/
		
		For (k, n) {
			if (!is[k]) continue;
			ll x = arr[k].x, y = arr[k].y;
			bool has = false;
			For (j, ch.size()) {
				if (ch[j].x == x && ch[j].y ==y) {
					has = true;
					break;
				}
				if (j != 0) {
					// lies on any
					if (lies(arr[k], ch[j-1], ch[j])) {
						has = true;
						break;
					}
				}
			}
			if (has) {
				ll nw = n - v.size();
				ans[k] = min (ans[k], nw);
			}
		}

		return;
	}
	is[ind] = false;
	check (ind + 1);
	is[ind] = true;
	check (ind + 1);
}

/*_____________________________________________________________________________________*/
int main() {
	//*
	freopen("c.in", "r", stdin);
	freopen("c.out", "w", stdout);
	//*/
	ll T;
	cin >> T;
	For1 (tc, T) {
		cerr << "--> " << tc << " / " << T << endl;
		cin >> n;
		For (i, n) cin >> arr[i].x >> arr[i].y;

		if (n > 3) {
			For (i, n) ans[i] = n - 3;
			check (0);
		}
		else For (i, n) ans[i] = 0;

		cout << "Case #" << tc << ":\n";
		For (i, n) {
			cout << ans[i] << endl;
		}
	}
	
	return 0;
}
/*

*/