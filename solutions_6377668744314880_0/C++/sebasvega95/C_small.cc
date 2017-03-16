#include <bits/stdc++.h>
#define endl '\n'
#define D(x) cout << #x ": " << (x) << endl;
using namespace std;

typedef long long int ll;
typedef unsigned long long int ull;
typedef pair<ll,ll> pii;

#define REMOVE_REDUNDANT

typedef double T;
const T EPS = 1e-7;

struct PT { 
  double x, y; 
  PT() {}
  PT(double x, double y) : x(x), y(y) {}
  PT(const PT &p) : x(p.x), y(p.y)    {}
  PT operator + (const PT &p)  const { return PT(x+p.x, y+p.y); }
  PT operator - (const PT &p)  const { return PT(x-p.x, y-p.y); }
  PT operator * (double c)     const { return PT(x*c,   y*c  ); }
  PT operator / (double c)     const { return PT(x/c,   y/c  ); }
  bool operator<(const PT &rhs) const { return make_pair(y,x) < make_pair(rhs.y,rhs.x); }
  bool operator==(const PT &rhs) const { return make_pair(y,x) == make_pair(rhs.y,rhs.x); }
};

double dot(PT p, PT q)     { return p.x*q.x+p.y*q.y; }
double dist2(PT p, PT q)   { return dot(p-q,p-q); }
double cross(PT p, PT q)   { return p.x*q.y-p.y*q.x; }
T area2(PT a, PT b, PT c) { return cross(a,b) + cross(b,c) + cross(c,a); }

#ifdef REMOVE_REDUNDANT
bool between(const PT &a, const PT &b, const PT &c) {
  return (fabs(area2(a,b,c)) < EPS && (a.x-b.x)*(c.x-b.x) <= 0 && (a.y-b.y)*(c.y-b.y) <= 0);
}
#endif

void ConvexHull(vector<PT> &pts) {
  sort(pts.begin(), pts.end());
  pts.erase(unique(pts.begin(), pts.end()), pts.end());
  vector<PT> up, dn;
  for (int i = 0; i < pts.size(); i++) {
    while (up.size() > 1 && area2(up[up.size()-2], up.back(), pts[i]) >= 0) up.pop_back();
    while (dn.size() > 1 && area2(dn[dn.size()-2], dn.back(), pts[i]) <= 0) dn.pop_back();
    up.push_back(pts[i]);
    dn.push_back(pts[i]);
  }
  pts = dn;
  for (int i = (int) up.size() - 2; i >= 1; i--) pts.push_back(up[i]);
  
#ifdef REMOVE_REDUNDANT
  if (pts.size() <= 2) return;
  dn.clear();
  dn.push_back(pts[0]);
  dn.push_back(pts[1]);
  for (int i = 2; i < pts.size(); i++) {
    if (between(dn[dn.size()-2], dn[dn.size()-1], pts[i])) dn.pop_back();
    dn.push_back(pts[i]);
  }
  if (dn.size() >= 3 && between(dn.back(), dn[0], dn[1])) {
    dn[0] = dn.back();
    dn.pop_back();
  }
  pts = dn;
#endif
}

PT ProjectPointSegment(PT a, PT b, PT c) {
  double r = dot(b-a,b-a);
  if (fabs(r) < EPS) return a;
  r = dot(c-a, b-a)/r;
  if (r < 0) return a;
  if (r > 1) return b;
  return a + (b-a)*r;
}

bool PointOnPolygon(const vector<PT> &p, PT q) {
  for (int i = 0; i < p.size(); i++)
    if (dist2(ProjectPointSegment(p[i], p[(i+1)%p.size()], q), q) < EPS)
      return true;
    return false;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int T;
	cin >> T;

	for (int cn = 0; cn < T; cn++) {
		int n;
		cin >> n;

		vector<PT> F(n);
		for (int i = 0; i < n; i++) {
			cin >> F[i].x >> F[i].y;
		}

		bool del[n];
		vector<PT> aux;
		vector<ll> mins(n, (ll)1E9);

		for (ll bm = 0; bm < (1LL << n); bm++) {
			memset(del, false, sizeof del);
			aux.clear();

			for (int j = 0; j < n; j++) {
				if ((bm >> j) & 1)
					del[j] = true;
			}

			for (int i = 0; i < n; i++) {
				if (!del[i])
					aux.push_back(F[i]);
			}

			ConvexHull(aux);
			for (int i = 0; i < n; i++) {
				if (find(aux.begin(), aux.end(), F[i]) != aux.end() or PointOnPolygon(aux, F[i])) {
					ll nOfOnes = __builtin_popcountll(bm);
					mins[i] = min(mins[i], nOfOnes);
				}
			}
		}

		cout << "Case #" << cn+1 << ":" << endl;
		for (int i = 0; i < n; i++) {
			cout << mins[i] << endl;
		}
	}

	return 0;
}