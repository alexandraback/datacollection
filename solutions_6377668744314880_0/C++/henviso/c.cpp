#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <stack>
#include <algorithm>
#include <cctype>
#include <vector>
#include <queue>
#include <tr1/unordered_map>
#include <cmath>
#include <map>
#include <bitset>
#include <set>
#include <iomanip>
#include <cstring>
#include <unistd.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector< ii > vii;
///////////////////////////////UTIL/////////////////////////////////
#define ALL(x) (x).begin(),x.end()
#define CLEAR0(v) memset(v, 0, sizeof(v))
#define CLEAR(v, x) memset(v, x, sizeof(v))
#define COPY(a, b) memcpy(a, b, sizeof(a))
#define CMP(a, b) memcmp(a, b, sizeof(a))
#define REP(i,n) for(int i = 0; i<n; i++)
#define REPP(i,a,n) for(int i = a; i<n; i++)
#define REPD(i,n) for(int i = n-1; i>-1; i--)
#define REPDP(i,a,n) for(int i = n-1; i>=a; i--)
#define pb push_back
#define pf push_front
#define sz size()
#define mp make_pair
/////////////////////////////NUMERICAL//////////////////////////////
#define INF 0x3f3f3f3f
#define EPS 1e-11
/////////////////////////////BITWISE////////////////////////////////
#define CHECK(S, j) (S & (1 << j))
#define CHECKFIRST(S) (S & (-S)) 
#define SET(S, j) S |= (1 << j)
#define SETALL(S, j) S = (1 << j)-1  
#define UNSET(S, j) S &= ~(1 << j)
#define TOOGLE(S, j) S ^= (1 << j)
///////////////////////////////64 BITS//////////////////////////////
#define LCHECK(S, j) (S & (1ULL << j))
#define LSET(S, j) S |= (1ULL << j)
#define LSETALL(S, j) S = (1ULL << j)-1ULL 
#define LUNSET(S, j) S &= ~(1ULL << j)
#define LTOOGLE(S, j) S ^= (1ULL << j)
//__builtin_popcount(m)
//scanf(" %d ", &t);

#define PI 3.14159265359
#define DEGtoRAD(x) (x * PI / 180.0)

typedef double real;

struct point{ 
	real x, y;
	point(){ };
	point(real _x, real _y){ x = _x; y = _y; }
	bool operator < (point other) const{
		if(fabs(x - other.x) >= EPS) return x < other.x;
		return y < other.y;
	}
	bool operator == (point other){
		return fabs(x - other.x) < EPS && fabs(y - other.y) < EPS;
	}
	double dist(point other){
		return hypot(x - other.x, y - other.y);		
	}
	point rotate(double theta){
		double rad = DEGtoRAD(theta);
		return point(x * cos(rad) - y * sin(rad), x * sin(rad) + y * cos(rad));
	}
	friend istream& operator >>(istream &is, point &p);
    friend ostream& operator <<(ostream &os, const point &p);
};

ostream& operator<<(ostream& os, const point& p){
	os << "(" << p.x << "," << p.y << ")";
}

istream& operator>>(istream& is, point& p){
	is >> p.x >> p.y;
}

double cross(point p, point q, point r){
	return (r.x - q.x) * (p.y - q.y) - (r.y - q.y) * (p.x - q.x);
}

bool collinear(point p, point q, point r){
	return fabs(cross(p, q, r)) < EPS;
}

bool ccw(point p, point q, point r){
	return cross(p,q,r) > 0;
}

point pivot;

bool angleCmp(point a, point b){
	if(collinear(pivot, a, b)) return pivot.dist(a) < pivot.dist(b);
	double d1x = a.x - pivot.x, d1y = a.y - pivot.y;
	double d2x = b.x - pivot.x, d2y = b.y - pivot.y;
	return (atan2(d1y, d1x) - atan2(d2y, d2x)) < 0;
}

vector<point> CH(vector<point> P){
	int i, j, n = P.size();
	if(n <= 3){
		if(!(P[0] == P[n-1])) P.push_back(P[0]);
		return P;
	}
	
	int P0 = 0;
	for(i = 1; i<n; i++) if(P[i].y < P[P0].y || (P[i].y == P[P0].y && P[i].x > P[P0].x)) P0 = i;
	
	point temp = P[0]; P[0] = P[P0]; P[P0] = temp;
	
	pivot = P[0];
	sort(++P.begin(), P.end(), angleCmp);
	
	//cout << "ORDEM DOS PONTOS " << endl;
	//REP(k, P.size()){
	//	cout << P[k] << " ";
	//}
	
	vector<point> S;
	S.push_back(P[n-1]); S.push_back(P[0]); S.push_back(P[1]);
	i = 2;
	
	
	//cout << endl;
	
	while(i < n){
		//cout << "TAM S " << S.size() << endl;
		j = S.size()-1;
		if(ccw(S[j-1], S[j], P[i])) S.push_back(P[i++]);
		else S.pop_back();
	}
	return S;
}

int T, N;
point a[100];

int main(){
	cin >> T; 
	REPP(tc, 1, T+1){
		cin >> N;
		REP(i, N){
			cin >> a[i].x >> a[i].y;
			//a[i].x += 10^6;
			//a[i].y += 10^6;
		}	
		cout << "Case #" << tc << ":\n";
		REP(i, N){
			
				int ans = N-1;
				for(int msk = (1 << N-1)-1; msk>=0; msk--){
					int val = N-1 - __builtin_popcount(msk);
					if(val >= ans) continue;
					vector<point> b; b.push_back(a[i]);
					int j = 0;
					REP(k, N-1){
						if(j == i) j++;
						if(msk&(1<<k)) b.push_back(a[j]);
						j++;
					}
					//REP(j, b.size()) cout << b[j] << " ";
					//cout << endl;
					bool allCol = true;
					REP(I, b.size())
					REP(J, b.size())
					REP(K, b.size()){
						if(I == J || I == K || K == J) continue;
						if(!collinear(b[I], b[J], b[K])) allCol = false;
					}
					if(!allCol){
						b = CH(b);
						pivot = point(0, 0);
						bool pos = false;
						//cout << "CH DO PONTO " << i << " COM MASCARA " << msk << endl;
						REP(j, b.size()){
							//cout << b[j] << " ";
							if(b[j] == a[i]){
								pos = true;
								break;
							} 
							if(j < b.size()-1 && collinear(b[j], b[j+1], a[i])){
								pos = true;
								break;
							}
						}
						//cout << endl;
						if(pos) ans = min(ans, val);
					}
					else ans = min(ans, val);
				}
				cout << ans << endl;
		}
		
	}
}
