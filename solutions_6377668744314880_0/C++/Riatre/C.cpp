#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <assert.h>
#include <math.h>

using namespace std;

typedef long long ll;

template<typename T,typename HT>
class POINT2D_META
{
public:
	T x;
	T y;
	int id;
	POINT2D_META() { x = y = 0; id = -1; }
	POINT2D_META(T _x,T _y):x(_x),y(_y) { id = -1; }
	inline POINT2D_META operator+(const POINT2D_META& b) const { return POINT2D_META(x+b.x,y+b.y); }
	inline POINT2D_META operator-(const POINT2D_META& b) const { return POINT2D_META(x-b.x,y-b.y); }
	inline HT operator*(const POINT2D_META& b) const { return (HT)x*b.y-(HT)b.x*y; }
	inline HT dot(const POINT2D_META& b) const { return (HT)x*b.x+(HT)y*b.y; }
	inline HT hypot2() const { return (HT)x*x+(HT)y*y; }
	inline T hypot() const { return ::hypot(x,y); }
	//inline int read() { return scanf("%lf %lf",&x,&y); }
	inline int read() { return scanf("%d %d",&x,&y); }
	// h-v order
	inline bool operator<(const POINT2D_META& b) const { return x == b.x ? y < b.y : x < b.x; }
};
typedef POINT2D_META<int,ll> POINT;
//typedef POINT2D_META<double,double> POINT;

const double eps = 1e-8;

template<typename T>
inline T valsign(T x) { return x < 0 ? -1 : (x > 0 ? 1 : 0); }
//inline double valsign(double x) { return x < -eps ? -1 : (x > eps ? 1 : 0); }

// hit on the edge will return true
bool is_segment_intersect(const POINT& A,const POINT& B,const POINT& C,const POINT& D)
{
	if(max(C.x,D.x) < min(A.x,B.x) || max(C.y,D.y) < min(A.y,B.y)) return false;
	if(max(A.x,B.x) < min(C.x,D.x) || max(A.y,B.y) < min(C.y,D.y)) return false;
	if(valsign((B-A)*(C-A))*valsign((B-A)*(D-A)) > 0) return false;
	if(valsign((D-C)*(A-C))*valsign((D-C)*(B-C)) > 0) return false;
	return true;
}

POINT get_perpfoot(const POINT& LineA,const POINT& LineB,const POINT& P)
{
	if(LineA.x == LineB.x) return POINT(LineA.x,P.y);
	if(LineA.y == LineB.y) return POINT(P.x,LineA.y);
	double k = (LineA.y-LineB.y)/(LineA.x-LineB.x);
	double x = (k*(k*LineA.x+(P.y-LineA.y))+P.x)/(k*k+1.0);
	return POINT(x,k*(x-LineA.x)+LineA.y);
}

bool is_point_onseg(const POINT& LineA,const POINT& LineB,const POINT& P)
{
	if(! (min(LineA.x,LineB.x) <= P.x && P.x <= max(LineA.x,LineB.x) &&
		  min(LineA.y,LineB.y) <= P.y && P.y <= max(LineA.y,LineB.y)) )
		return false;
	if(valsign((P-LineA)*(LineB-LineA)) == 0) return true;
	return false;
}

// NOT Kevin :D
// P is input and Hull is output.

int Graham(POINT* P,POINT* Hull,int n)
{
	sort(P,P+n);
	int HTop = 0;
	for(int i = 0;i < n;i++)
	{
		// delete collinear points
		while(HTop > 1 && valsign((P[i]-Hull[HTop-2])*(Hull[HTop-1]-Hull[HTop-2])) > 0) HTop--;
		Hull[HTop++] = P[i];
	}
	int LTop = HTop;
	for(int i = n-2;i >= 0;i--)
	{
		while(HTop > LTop && valsign((P[i]-Hull[HTop-2])*(Hull[HTop-1]-Hull[HTop-2])) > 0) HTop--;
		if(i) Hull[HTop++] = P[i];
	}
	return HTop;
}

POINT pnt[23];
POINT selected[23];
POINT hull[23];

int popcount[1 << 15];

int main(void)
{
	for(int i = 1;i < (1 << 15);i++) popcount[i] = popcount[i-(i&-i)]+1;
	int T = 0;
	int TK = 0;
	scanf("%d",&T);
	while(T--)
	{	
		printf("Case #%d:\n", ++TK);

		int N = 0;
		scanf("%d",&N);
		for(int i = 0;i < N;i++) pnt[i].read();

		for(int i = 0;i < N;i++)
		{
			int ans = ~0U>>1;
			for(int j = 0;j < (1 << N);j++)
			{
				if(j & (1 << i)) continue;

				int sn = 0;
				for(int k = 0;k < N;k++)
				{
					if(j & (1 << k)) continue;
					selected[sn++] = pnt[k];
				}
				int cnt = Graham(selected, hull, sn);
				for(int k = 0;k < cnt;k++)
				{
					if(hull[k].x == pnt[i].x && hull[k].y == pnt[i].y)
					{
						ans = min(ans, popcount[j]);
					}
				}
			}
			printf("%d\n",ans);
		}
	}
	return 0;
}
