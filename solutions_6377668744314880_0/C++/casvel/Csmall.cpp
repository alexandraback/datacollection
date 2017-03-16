#include <bits/stdc++.h>

#define For(i, a, b) for(int i=(a); i<(b); ++i)
#define INF 1000000000
#define EPS 10e-9
#define MP make_pair

using namespace std;

typedef long long ll;
typedef pair <int, int> ii;

struct point{ double x, y;
	point(){ x = y = 0.0; }
	point(double _x, double _y) : x(_x), y(_y) {}
	bool operator < (point other) const {
		if(fabs(x - other.x) > EPS)
			return x < other.x;
		return y < other.y; } 
		
	bool operator == (point other) const {
		return (fabs(x - other.x) < EPS && (fabs(y - other.y) < EPS)); }
};

struct vec { double x, y;
	vec(double _x, double _y) : x(_x), y(_y) {} };
	
vec toVec(point a, point b) {
	return vec(b.x - a.x, b.y - a.y);
}

point pivot(0, 0);

double cross(vec a, vec b) { return a.x * b.y - a.y * b.x; }

bool collinear(point p, point q, point r) {
	return fabs(cross(toVec(p, q), toVec(p, r))) < EPS; 
}

bool ccw(point p, point q, point r) { 
	return cross(toVec(p, q), toVec(p, r)) > 0;//cambiar si se aceptan colineales 
}

double dist(point p1, point p2) {
	return hypot(p1.x - p2.x, p1.y - p2 .y);
}

bool angleCmp(point a, point b) {
	if(collinear(pivot, a, b))
		return dist(pivot, a) < dist(pivot, b);
		
	double d1x = a.x - pivot.x, d1y = a.y - pivot.y;
	double d2x = b.x - pivot.x, d2y = b.y - pivot.y;
	
	return (atan2(d1y, d1x) - atan2(d2y, d2x)) < 0;
}

vector<point> CH(vector<point> P ) {
	int i, j, n = (int) P.size();
	if(n <= 3) {
		if(!(P[0] == P[n - 1])) P.push_back(P[0]);
		return P; }
		
	//PO = indice del pivote
	int PO = 0;
	for(i = 1; i < n; i++)
		if(P[i].y < P[PO].y || (P[i].y == P[PO].y && P[i].x > P[PO].x))
			PO = i;
			
	point temp = P[0]; P[0] = P[PO]; P[PO] = temp; //cambia el pivote al principio
	
	pivot = P[0];
	sort(P.begin() + 1, P.end(), angleCmp);
	
	vector<point> S;

	S.push_back(P[n - 1]); S.push_back(P[0]); S.push_back(P[1]);
	i = 2;
	while(i < n) {
		j = (int) S.size() - 1;
		//cout << ":" << j <<":" << endl;
		if(ccw(S[j - 1], S[j], P[i]) or j < 3) S.push_back(P[i++]);
		else S.pop_back(); }
	
	return S;
}	

int main()
{
	//std::ios_base::sync_with_stdio(false);

	int tt, caso = 1;
	scanf("%d", &tt);

	while (tt--)
	{
		int n;
		scanf("%d", &n);

		vector <point> P(n);
		For(i, 0, n)
			scanf("%lf %lf", &P[i].x, &P[i].y);

		printf("Case #%d:\n", caso++);

		For(i, 0, n)
		{
			int ans = n;
			For(S, 1, 1 << n)
			{
				if (!(S & (1 << i)))
					continue;

				vector <point> aux;
				For(j, 0, n)
					if (S & (1 << j))
						aux.push_back(P[j]);

				vector <point> boundary = CH(aux);
				bool ok = false;
				For(j, 0, boundary.size()-1) 
					if (boundary[j] == P[i] or collinear(boundary[j], P[i], boundary[j+1]))
					{
						ok = true;
						break;
					}

				if (ok)
					ans = min(ans, n-__builtin_popcount(S));
			}

			printf("%d\n", ans);
		}
	}

	return 0;
}