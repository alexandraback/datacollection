#include<iostream>
#include<vector>
#include<string>
#include<map>
#include<set>
#include<stack>
#include<queue>
#include<algorithm>
#include<string.h>
#include<cmath>
#include<complex>
using namespace std;

const double EPS = 1e-5;
const double PI = acos(-1.0);
const double ZERO = 0;
const double DOUBLE_MAX = 1/ZERO;
typedef complex<double> point;
#define X real()
#define Y imag()
#define rad(p) (atan2(((p).Y),((p).X)))
#define dot(a,b) ((conj(a)*(b)).real())
#define cross(a,b) ((conj(a)*(b)).imag())
#define length(a) hypot((a).X,(a).Y)
#define normalize(p) ((p)/length(p))
#define rotate(p,origin,ang) (((p)-(origin))*exp(point(0,(ang)))+(origin))
#define collinear(a,b,c) ( fabs( cross((a)-(b),(c)-(b))) < EPS)
#define bisector(a,b) (((a)+(b))/2.0) // return the mid point
#define polar(r,theta) (point((r),0)*exp(point(0,(theta))))
#define vec(a,b) ((b)-(a))
#define sz(a) (a.size())

struct cmp {
	point about;
	cmp(point c) {
		about = c;
	}
	bool operator()(const point& p, const point& q) const {
		double cr = cross(vec(about,p), vec(about,q));
		if (fabs(cr) < EPS)
			return make_pair(p.Y, p.X) < make_pair(q.Y, q.X);
		return cr > 0;
	}
};

void sortAntiClockWise(vector<point>& pnts) {
	point mn(1 / 0.0, 1 / 0.0);
	for (int i = 0; i < sz(pnts); i++)
		if (make_pair(pnts[i].Y, pnts[i].X) < make_pair(mn.Y, mn.X))
			mn = pnts[i];
	sort(pnts.begin(), pnts.end(), cmp(mn));
}

void convexHull(vector<point> pnts, vector<point> &convex) {
	sortAntiClockWise(pnts);
	convex.clear();
	convex.push_back(pnts[0]);
	if (sz(pnts) == 1)
		return;
	convex.push_back(pnts[1]);
	for (int i = 2; i <= sz(pnts); i++) {
		point c = pnts[i % sz(pnts)];
		while (sz(convex) > 1) {
			point b = convex.back();
			point a = convex[sz(convex) - 2];
			if (cross(vec(b,a),vec(b,c)) < -EPS)
				break;
			convex.pop_back();
		}
		if (i < sz(pnts))
			convex.push_back(pnts[i]);
	}
}

bool isPointInRay(point a, point b, point p)	{

	if(length(a-p)<EPS) return true;  // use EPS

	point p1=normalize(b-a);
	point p2=normalize(p-a);

	return  length(p1-p2)<EPS; // use EPS

}

bool onBoundary(vector<point> pol, point p)
{
	for(int i=0;i<pol.size();i++) {
		int j = (i+1)%pol.size();
		if(cross(vec(pol[i], pol[j]), vec(pol[i], p)) == 0)
			return true;
	}
	return false;
}

#define SMALL 1
//#define LARGE 1

int main() {
#ifdef LARGE
	freopen("c_large.i", "rt", stdin);
	freopen("c_large.o", "wt", stdout);
#elif SMALL
	freopen("c_small_3.i", "rt", stdin);
	freopen("c_small_3.o", "wt", stdout);
#else
	freopen("c_sample.i", "rt", stdin);
#endif

	int t;
	cin>>t;
	for(int tt=1;tt<=t;tt++) {
		int n,x,y;
		cin>>n;
		vector<point> v(n);
		for(int i = 0; i < n; i++) {
			cin>>x>>y;
			v[i] = point(x,y);
		}
		vector<int> ans(n, 1000000);
		for(int i=1;i<(1<<n);i++) {
			vector<point> v2;
			for(int j=0;j<n;j++) {
				if(i&(1<<j))
					v2.push_back(v[j]);
			}
			vector<point> con;
			convexHull(v2, con);
			for(int j=0;j<n;j++) {
				if((i&(1<<j)) && (v2.size() <= 3 || onBoundary(con, v[j])))
					ans[j] = min(ans[j], (int)(v.size()-v2.size()));
			}
		}
		cout << "Case #"<<tt<<": "<<endl;
		for(int i=0;i<n;i++) {
			cout<<ans[i]<<endl;
		}
	}

	return 0;
}
