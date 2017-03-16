// C.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <map>
#include <set>
#include <list>
#include <string>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <cassert>
#include <cassert>
#include <math.h>
//http://www.ttmath.org/
#include "ttmath\ttmath.h"

using namespace std;

ifstream in("C-small-attempt3.in");
ofstream out("out.txt");
///LLONG_MAX,INT_MA
#define FOR(i,a,b) for(int i=(a),_b=(b);i<=_b;i++)
#define REP(i,n) FOR(i,0,(n)-1)
#define FORD(i,a,b) for(int i=(a),_b=(b);i>=_b;i--)
#define sz size()
template<class T> inline int size(const T& c) { return c.sz; }
#define FORA(i,c) REP(i,size(c))

#define itype(c) __typeof((c).begin())
#define FORE(e,c) for(itype(c) e=(c).begin();e!=(c).end();e++)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define SORT(x) sort(all(x))
#define REVERSE(x) reverse(all(x))
#define CLEAR(x,c) memset(x,c,sizeof(x)) 
#define amfor(Iterator, Container) 	for ( auto Iterator = begin(Container); (Iterator) != end(Container); ++(Iterator) )
#define ramfor(Iterator, Container) for ( auto Iterator = Container.rbegin(); (Iterator) != Container.rend(); ++(Iterator) )
template<class C, class E> inline bool contains(const C& container, const E& element){	return container.find(element) != container.end() ;}

template<class T> inline void checkmin(T &a,T b){if(b<a) a=b;}//asigna en a el minimo
template<class T> inline void checkmax(T &a,T b){if(b>a) a=b;}//asigna en a el maximo

///typedef ttmath::Int<10> ii;

#define max(a,b)            (((a) > (b)) ? (a) : (b))
#define min(a,b)            (((a) < (b)) ? (a) : (b))

///typedef ttmath::Int<10> II;///640 bits
typedef __int64 II;
//typedef ttmath::Big<1,10> DD;/// 64 exp ,640bits mant
typedef double DD;
#define INF LLONG_MAX

typedef  int IType ;
// Implementation of Andrew's monotone chain 2D convex hull algorithm.
// Asymptotic complexity: O(n log n).
// Practical performance: 0.5-1.0 seconds for n=1000000 on a 1GHz machine.
#include <algorithm>
#include <vector>
using namespace std;

typedef double coord_t;         // coordinate type
typedef double coord2_t;  // must be big enough to hold 2*max(|coordinate|)^2
/*
struct Point {
	Point():x(0),y(0){}
	Point(int _x,int _y):x(_x),y(_y){}
	coord_t x, y;

	bool operator <(const Point &p) const {
		return x < p.x || (x == p.x && y < p.y);
	}
	bool operator ==(const Point &p) const {
		return x == p.x && y == p.y;
	}
	Point operator - (const Point &other) const
	{
		return Point(x-other.x,y-other.y);
	}
};
*/

typedef __int64 DType;




IType SX,SY;
template<class T>
class GPoint
{
public:
	GPoint():m_x(0),m_y(0){};
	GPoint(T x,T y):m_x(x),m_y(y){}

	GPoint operator + (const GPoint &other) const
	{
		return GPoint(other.m_x+m_x,other.m_y+m_y);
	}
	GPoint operator - (const GPoint &other) const
	{
		return GPoint(m_x-other.m_x,m_y-other.m_y);
	}
	T operator * (const GPoint &other) const
	{
		return other.m_x*m_x+other.m_y*m_y;
	}

	GPoint operator * (IType i) const
	{
		return GPoint(m_x*i,m_y*i);
	}


	GPoint &operator *= (IType i) 
	{
		m_x *= i;
		m_y *= i;
		return *this;
	}

	GPoint operator / (IType i) const
	{
		return GPoint(m_x/i,m_y/i);
	}


	GPoint &operator /= (IType i) 
	{
		m_x /= i;
		m_y /= i;
		return *this;
	}

	bool operator == (const GPoint p) const
	{
		return m_x == p.m_x && m_y == p.m_y;
	}

	bool operator != (const GPoint p) const
	{
		return m_x != p.m_x || m_y != p.m_y;
	}

	bool operator < (const GPoint &other) const
	{
		return m_x < other.m_x || (m_x == other.m_x && m_y < other.m_y );
	}


	bool Valid() const ///para maze
	{
		return m_x >= 0 && m_y >= 0 && m_x < SX && m_y < SY;
	}

	T SDist(const GPoint p) const ///dist cuadrado
	{
		GPoint delta = *this-p;
		return delta*delta;
	}

	T m_x;
	T m_y;
};
typedef GPoint<IType> Point;
// 2D cross product of OA and OB vectors, i.e. z-component of their 3D cross product.
// Returns a positive value, if OAB makes a counter-clockwise turn,
// negative for clockwise turn, and zero if the points are collinear.
coord2_t cross(const Point &O, const Point &A, const Point &B)
{
	return (A.m_x - O.m_x) * (B.m_y - O.m_y) - (A.m_y - O.m_y) * (B.m_x - O.m_x);
}

// Returns a list of points on the convex hull in counter-clockwise order.
// Note: the last point in the returned list is the same as the first one.
vector<Point> convex_hull(vector<Point> P)
{
	int n = P.size(), k = 0;
	vector<Point> H(2*n);

	// Sort points lexicographically
	sort(P.begin(), P.end());

	// Build lower hull
	for (int i = 0; i < n; ++i) {
		while (k >= 2 && cross(H[k-2], H[k-1], P[i]) <= 0) k--;
		H[k++] = P[i];
	}

	// Build upper hull
	for (int i = n-2, t = k+1; i >= 0; i--) {
		while (k >= t && cross(H[k-2], H[k-1], P[i]) <= 0) k--;
		H[k++] = P[i];
	}

	H.resize(k);
	return H;
}

IType Cross(const Point &a,const Point &b) 
{
	return a.m_x * b.m_y - a.m_y * b.m_x;
}

///inlcuye extremos
bool InRange(IType from,IType to,IType a)
{
	if(from < to)
		return a >= from && a <= to;
	else
		return a <= from && a >= to;
}

///ir de a -> b -> c implica doblar der en b. Ojo que colineales es false
IType Turn(const Point &a,const Point &b,const Point &c)
{
	return Cross(b-a,c-a);
}

///ir de a -> b -> c implica doblar a la izq en b. Ojo que colineales es false
bool LeftTurn(const Point &a,const Point &b,const Point &c)
{
	return Turn(a,b,c) > 0;
}
///ir de a -> b -> c implica doblar der en b. Ojo que colineales es false
bool RightTurn(const Point &a,const Point &b,const Point &c)
{
	return Turn(a,b,c) < 0;
}

bool Colinear(const Point &a,const Point &b,const Point &c)
{
	return Turn(a,b,c) == 0;
}


class Segment : public pair<Point,Point> 
{
public:
	Segment(){}
	Segment(Point a, Point b):pair<Point,Point>(a,b){}
	Point Delta() const
	{
		return second-first;
	}
};


///Incluye tocarse segemnto con linea
bool IntersectLS (const Segment &line,const  Segment &seg)
{
	IType ang1 = Cross((seg.first-line.first),line.Delta());
	IType ang2 = Cross((seg.second-line.first),line.Delta());
	return ang1 == 0 || ang2 == 0 || ((ang1 > 0) != (ang2 > 0));

}

///Incluye tocarse 2 segementos
bool Intersect (const Segment &s1,const  Segment &s2)
{
	return IntersectLS(s1,s2) && IntersectLS(s2,s1);
}



///Incluye tocarse HalfLine Sefment halfLine.first cominezo de half line
///Rayo con segmento
bool IntersectHLS (const Segment &halfLine,const  Segment &seg)
{
	if(IntersectLS(halfLine,seg))
	{
		IType ang1 = Cross(halfLine.Delta(),seg.first - halfLine.first);
		if(ang1 == 0)//el punto del segemetno esta sobre la recta
			return (halfLine.Delta() * (seg.first - halfLine.first)) >= 0;
		else
		{
			IType ang2 = Cross(seg.Delta(),halfLine.first-seg.first);
			return ang2 == 0 || ((ang1 > 0) != (ang2 > 0));
		}

	}
	else
		return false;
}


///incluye extremos
bool PointInSegment(const Point &p,const Segment &s)
{
	return InRange(s.first.m_x,s.second.m_x,p.m_x) && InRange(s.first.m_y,s.second.m_y,p.m_y) && Colinear(p,s.first,s.second);
}

class Poly
{
public:
	vector<Point> m_p;
	inline Segment GetSegment(unsigned int i)
	{
		assert(i < m_p.size());
		if(i < m_p.size()-1)
			return Segment(m_p[i],m_p[i+1]);
		else
			return Segment(m_p.back(),m_p[0]);
	}
	inline void Add(const Point &p)
	{

	}
	inline void Add(IType x,IType y)
	{
		m_p.push_back(Point(x,y));
	}

	inline double Area() const
	{
		return static_cast<double>(DoubleArea()/2);////ojo que se puede perder precision
	}

	inline IType DoubleArea() const
	{
		IType area = 0;
		//We will triangulate the polygon
		//into triangles with points p[0],p[i],p[i+1]
		for(unsigned int i = 1; i+1<m_p.size(); i++)
			area += Cross(m_p[i]-m_p[0],m_p[i+1]-m_p[0]);
		return abs(area);
	}
	bool Inside(const Point &p)
	{
		return InsideEx(p) == 1;	
	}
	///1 si, -1 no, 0 en el borde
	int InsideEx(const Point &p)
	{
		bool bInside = false;
		for(unsigned int i = 0;i < m_p.size();++i)
		{
			int s = _RayFromPointToRightCrossesSegment(p,GetSegment(i));
			if(s == 0)
				return 0;
			if(s == 1)
				bInside = !bInside ;
		}
		return bInside?1:-1;
	}

	//Helper para inside
	///contesta si tirando un rayo desde el punto hacia la derecha (x > p.m_x)
	///1 si, -1 no , 0 punto en segmento.
	///incluye primer punto pero no segundo
	int _RayFromPointToRightCrossesSegment(const Point &p, Segment s)
	{
		///Borde
		if(s.first == p || s.second == p)
			return 0;
		if(s.first == s.second)//no rompan las pelotas
			return -1;
		///normaliazo, siempre el primero es el de mas abajo
		if(s.first.m_y > s.second.m_y)
			swap(s.first.m_y,s.second.m_y);
		//Elimino casos obvios, p debajo o arriba u horizontal
		if(p.m_y < s.first.m_y || p.m_y > s.second.m_y)
			return -1;
		if(s.first.m_y == s.second.m_y)
		{
			if(InRange(s.first.m_x,s.second.m_x,p.m_x))
				return 0;
			else
				return -1;
		}
		///aca el segmento no es horizontal y tiene algo de interseccion con la coord y
		///casos especiales, si el punto toca uno de los extremos solo se cuanta cuando el segmento baja en el otro.
		///Como first es el mas bajo si p.y == first.y es que sube y si p.y == second.y es que baja.
		if(p.m_y == s.first.m_y)
			return -1;
		if(p.m_y == s.second.m_y)
			return 1;
		///Aca p.y esta en (s.first.y,s.second.y)
		IType t  = Turn(s.first,p,s.second);
		if(t > 0)///left turn-> no cruza ya que el punto esta a la derecha
			return -1;
		else if(t == 0)///colineales
			return 0;
		else
			return 1;
	}

};


int N;
vector<Point> p;
int current;
int minVal ;
void TestSub(vector<bool> &included)
{
	if(!included[current])
		return;
	vector<Point> test;
	Point thePoint = p[current];
	int count = 0;
	REP(i,included.size())
	{
		if(included[i])
		{
			test.push_back(p[i]);
			++count;
		}
	}
	vector<Point> rr = convex_hull(test);
	Poly poly;
	REP(i,rr.size()-1)
	{
		poly.Add(rr[i]);
		if(thePoint == rr[i] /*|| Colinear(rr[i],rr[i+1],thePoint)*/)
		{
			checkmin(minVal,(int)(p.size()-count));
		}
	}
	if(poly.InsideEx(thePoint) == 0)
		checkmin(minVal,(int)(p.size()-count));
/*	FORA(i,included)
	{
		cout << included[i] << " ";
	}
	cout << " = ";
	FORA(i,data)
	{
		if(included[i])
			cout << data[i] << " ";
	}
	++testCount;
	cout << endl;*/
}

void AllSub(int pos,vector<bool> &included)
{
	if(pos == included.size())
	{
		TestSub(included);
		return;
	}
	included[pos] = false;
	AllSub(pos+1,included);
	included[pos] = true;
	AllSub(pos+1,included);
}

void AllSub()
{
	vector<bool> included(p.size());
	AllSub(0,included);
}



int GetRes(int i)
{
	current = i;
	minVal = 10000;
	AllSub();
	return minVal; 
}
void Solve()
{
	in >> N;
	p = vector<Point>(N);
	REP(i,N)
	{
		in >> p[i].m_x >> p[i].m_y;
	}
	REP(i,N)
	{
		out << endl;
		out << GetRes(i);
	}
	//	out << n;
}

int _tmain(int argc, _TCHAR* argv[])
{
	
	int ccc;
	in >> ccc;
	cout << ccc << endl;
	out << std::setprecision(15);
	out << std::fixed;

	REP(c,ccc)
	{
		cout << c << endl;
		out << "Case #" << c+1 << ": ";
		Solve();
		out << endl;
	}	return 0;
}

