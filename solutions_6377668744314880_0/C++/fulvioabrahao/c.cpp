#include <bits/stdc++.h>
#define EPS 1e-9
using namespace std;
struct point { double x, y;
    point() { x = y = 0.0; }
    point(double _x, double _y) : x(_x), y(_y) {}
    bool operator == (point other) const {
    return (fabs(x - other.x) < EPS && (fabs(y - other.y) < EPS)); }
    bool operator < (point other) const { // override less than operator
        if (fabs(x - other.x) > EPS) // useful for sorting
        return x < other.x; // first criteria , by x-coordinate
return y < other.y; } }; // second criteria, by y-coordinate
// in int main(), assuming we already have a populated vector<point> P
double dist(point p1, point p2) { // Euclidean distance
    // hypot(dx, dy) returns sqrt(dx * dx + dy * dy)
return hypot(p1.x - p2.x, p1.y - p2.y); } // return double
point rotate(point p, double theta) {
    double rad = theta*M_PI/180.0;//DEG_to_RAD(theta); // multiply theta with PI / 180.0
    return point(p.x * cos(rad) - p.y * sin(rad),
p.x * sin(rad) + p.y * cos(rad)); }
struct line { double a, b, c; }; // a way to represent a line
void pointsToLine(point p1, point p2, line &l) {
    if (fabs(p1.x - p2.x) < EPS) { // vertical line is fine
        l.a = 1.0; l.b = 0.0; l.c = -p1.x; // default values
        } else {
        l.a = -(double)(p1.y - p2.y) / (p1.x - p2.x);
        l.b = 1.0; // IMPORTANT: we fix the value of b to 1.0
        l.c = -(double)(l.a * p1.x) - p1.y;
} }
bool areParallel(line l1, line l2) { // check coefficients a & b
return (fabs(l1.a-l2.a) < EPS) && (fabs(l1.b-l2.b) < EPS); }
bool areSame(line l1, line l2) { // also check coefficient c
return areParallel(l1 ,l2) && (fabs(l1.c - l2.c) < EPS); }
bool areIntersect(line l1, line l2, point &p) {
    if (areParallel(l1, l2)) return false; // no intersection
    // solve system of 2 linear algebraic equations with 2 unknowns
    p.x = (l2.b * l1.c - l1.b * l2.c) / (l2.a * l1.b - l1.a * l2.b);
    // special case: test for vertical line to avoid division by zero
    if (fabs(l1.b) > EPS) p.y = -(l1.a * p.x + l1.c);
    else p.y = -(l2.a * p.x + l2.c);
return true; }
struct vec { double x, y; // name: ‘vec’ is different from STL vector
vec(double _x, double _y) : x(_x), y(_y) {} };

vec toVec(point a, point b) { // convert 2 points to vector a->b
return vec(b.x - a.x, b.y - a.y); }
vec scale(vec v, double s) { // nonnegative s = [<1 .. 1 .. >1]
return vec(v.x * s, v.y * s); } // shorter.same.longer
point translate(point p, vec v) { // translate p according to v
return point(p.x + v.x , p.y + v.y); }
double dot(vec a, vec b) { return (a.x * b.x + a.y * b.y); }
double norm_sq(vec v) { return v.x * v.x + v.y * v.y; }
// returns the distance from p to the line defined by
// two points a and b (a and b must be different)
// the closest point is stored in the 4th parameter (byref)
double distToLine(point p, point a, point b, point &c) {
    // formula: c = a + u * ab
    vec ap = toVec(a, p), ab = toVec(a, b);
    double u = dot(ap, ab) / norm_sq(ab);
    c = translate(a, scale(ab, u)); // translate a to c
return dist(p, c); } // Euclidean distance between p and c
// returns the distance from p to the line segment ab defined by
// two points a and b (still OK if a == b)
// the closest point is stored in the 4th parameter (byref)
double distToLineSegment(point p, point a, point b, point &c) {
    vec ap = toVec(a, p), ab = toVec(a, b);
    double u = dot(ap, ab) / norm_sq(ab);
    if (u < 0.0) { c = point(a.x, a.y); // closer to a
    return dist(p, a); } // Euclidean distance between p and a
    if (u > 1.0) { c = point(b.x, b.y); // closer to b
    return dist(p, b); } // Euclidean distance between p and b
return distToLine(p, a, b, c); } // run distToLine as above
double angle(point a, point o, point b) { // returns angle aob in rad
    vec oa = toVec(o, a), ob = toVec(o, b);
return acos(dot(oa, ob) / sqrt(norm_sq(oa) * norm_sq(ob))); }
double cross(vec a, vec b) { return a.x * b.y - a.y * b.x; }
// note: to accept collinear points, we have to change the ‘> 0’
// returns true if point r is on the left side of line pq
bool ccw(point p, point q, point r) {
return cross(toVec(p, q), toVec(p, r)) >= 0; }
// returns true if point r is on the same line as the line pq
bool collinear(point p, point q, point r) {
return fabs(cross(toVec(p, q), toVec(p, r))) < EPS; }


point pivot(0, 0);
bool angleCmp(point a, point b) { // angle-sorting function
    if (collinear(pivot, a, b)) // special case
    return dist(pivot, a) < dist(pivot, b); // check which one is closer
    double d1x = a.x - pivot.x, d1y = a.y - pivot.y;
    double d2x = b.x - pivot.x, d2y = b.y - pivot.y;
return (atan2(d1y, d1x) - atan2(d2y, d2x)) < 0; }


vector<point> CH(vector<point> P) { // the content of P may be reshuffled
    int i, j, n = (int)P.size();
    if (n <= 3) {
        if (!(P[0] == P[n-1])) P.push_back(P[0]); // safeguard from corner case
    return P; } // special case, the CH is P itself
    // first, find P0 = point with lowest Y and if tie: rightmost X
    int P0 = 0;
    for (i = 1; i < n; i++)
    if (P[i].y < P[P0].y || (P[i].y == P[P0].y && P[i].x > P[P0].x))
    P0 = i;
    point temp = P[0]; P[0] = P[P0]; P[P0] = temp; // swap P[P0] with P[0]
    // second, sort points by angle w.r.t. pivot P0
    pivot = P[0]; // use this global variable as reference
    sort(++P.begin(), P.end(), angleCmp); // we do not sort P[0]
    vector<point> S;
    S.push_back(P[n-1]); S.push_back(P[0]); S.push_back(P[1]); // initial S
    i = 2; // then, we check the rest
    while (i < n) { // note: N must be >= 3 for this method to work
        j = (int)S.size()-1;
        if (ccw(S[j-1], S[j], P[i])) S.push_back(P[i++]); // left turn, accept
    else S.pop_back(); } // or pop the top of S until we have a left turn
return S; }



double cross(const point &O, const point &A, const point &B)
{
	return (A.x - O.x) * (B.y - O.y) - (A.y - O.y) * (B.x - O.x);
}
 
// Returns a list of points on the convex hull in counter-clockwise order.
// Note: the last point in the returned list is the same as the first one.
vector<point> convex_hull(vector<point> P)
{
	int n = P.size(), k = 0;
	vector<point> H(2*n);
 
	// Sort points lexicographically
	sort(P.begin(), P.end());
 
	// Build lower hull
	for (int i = 0; i < n; ++i) {
		while (k >= 2 && cross(H[k-2], H[k-1], P[i]) < 0) k--;
		H[k++] = P[i];
	}
 
	// Build upper hull
	for (int i = n-2, t = k+1; i >= 0; i--) {
		while (k >= t && cross(H[k-2], H[k-1], P[i]) < 0) k--;
		H[k++] = P[i];
	}
 
	H.resize(k);
	return H;
}

int main(){
    int t,ca = 1;
    cin>>t;

    while(t--){
        printf("Case #%d: \n",ca++);
        int n;
        cin>>n;
        vector<point> P;
        for(int i = 0;i<n;i++){
        	double a, b;
        	cin>>a>>b;
        	P.push_back(point(a,b));
        }
        for(int i = 0;i<n;i++){
        	int resp = 1000000;
        	for(int j = 0;j<(1<<n);j++){
        		if(resp<=__builtin_popcount(j))
        			continue;
        		vector<point> pnt;
        		pnt.push_back(P[i]);
        		for(int k = 0;k<n;k++){
        			if(k == i)continue;
        			if((j&(1<<k)) == 0){
        				pnt.push_back(P[k]);
        			}
        		}
        		std::vector<point> Pol = convex_hull(pnt);
        		for(int l = 0;l<Pol.size();l++){
        			if(Pol[l] == P[i]){
        				resp = min(resp,__builtin_popcount(j));
        				break;
        			}
        		}
        	}
        	cout<<resp<<endl;
        }
    }
    return 0;
}