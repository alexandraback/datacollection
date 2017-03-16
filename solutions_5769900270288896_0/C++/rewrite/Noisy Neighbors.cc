#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <cassert>

#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <cmath>
#include <numeric>
#include <bitset>

#include <cstdio>
#include <cstring>

using namespace std;

#define rep(i, n) for (int i = 0, _n = (int)(n); i < _n; i++)
#define fer(i, x, n) for (int i = (int)(x), _n = (int)(n); i < _n; i++)
#define rof(i, n, x) for (int i = (int)(n), _x = (int)(x); i-- > _x; )
#define fch(i, x) for (__typeof(x.begin()) i = x.begin(); i != x.end(); i++)
#define sz(x) (int((x).size()))
#define pb push_back
#define mkp make_pair
#define all(X) (X).begin(),(X).end()

#define X first
#define Y second

template<class T> inline void smin(T &a, T b){if(b<a)a=b;}
template<class T> inline void smax(T &a, T b){if(a<b)a=b;}

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll,ll> pll;
typedef vector<pii> vii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vii> vvii;


typedef vector<char> VC;
typedef vector<string> VS;
typedef vector<ll> VL;
typedef vector<double> VD;
typedef set<int> SI;
typedef set<string> SS;
typedef map<int, int> MII;
typedef map<string, int> MSI;

template<class T> inline void RST(T &A){memset(A, 0, sizeof(A));}
template<class T> inline void FLC(T &A, int x){memset(A, x, sizeof(A));}
template<class T> inline void CLR(T &A){A.clear();}

/** Constant List .. **/ //{
const int dx4[] = {-1, 0, 1, 0};
const int dy4[] = {0, 1, 0, -1};
const int dx8[] = {-1, 0, 1, 0 , -1 , -1 , 1 , 1};
const int dy8[] = {0, 1, 0, -1 , -1 , 1 , -1 , 1};
const int mod = 1000000007;
const int INF = 0x3f3f3f3f;
//}

template<class T> inline T min(T a, T b, T c){return min(min(a, b), c);}
template<class T> inline T max(T a, T b, T c){return max(max(a, b), c);}
template<class T> inline T min(T a, T b, T c, T d){return min(min(a, b), min(c, d));}
template<class T> inline T max(T a, T b, T c, T d){return max(max(a, b), max(c, d));}
template<class T> inline T sqr(T a){return a*a;}
template<class T> inline T cub(T a){return a*a*a;}

////////////////////////////////////////////////////////////////////////////////////////////
/**////////////////////////////////////////////////////////////////////////////////////////////
const int N = 100;
int T,n,r,c;


int work(int r,int c,int n){
	if(n<=1) return 0;
	switch(r){
		case 1:
			if(c&1){
				if(n<=(c+1)/2) return 0;
				else return (n-(c+1)/2)*2;
			}else{
				if(n<=c/2) return 0;
				else if(n==c/2+1) return 1;
				else return (n-(c/2+1))*2+1;
			}
		break;

		case 2:
			if(n<=c) return 0;
			else if(n<=c+2) return (n-c)*2;
			else return 4+(n-(c+2))*3;
		break;

		case 3:
			switch(c){
				case 3:
					if(n<=5) return 0;
					else if(n==8) return 8;
					else return (n-5)*3;
				break;
				case 4:
					if(n<=6) return 0;
					else if(n<=8) return (n-6)*2;
					else if(n<=11) return (n-8)*3+4;
					else return 17;
				break;
				case 5:
					if(n<=8) return 0;
					else if(n==13) return 14;
					else if(n<=14) return (n-8)*3;
					else return 22;
				break;
			}
		break;

		case 4:
			if(n<=8) return 0;
			else if(n<=10) return (n-8)*2;
			else if(n<=14) return (n-10)*3+4;
			else return (n-14)*4+16;
		break;
	}

	return 0;
}

int a[20][20];
int ans = INF;
void fd(int tr,int tc,int tn,int sum){
	if(tn==0){
		smin(ans,sum); return;
	}
	if(tc==c) fd(tr+1,0,tn,sum);
	if(tr==r) return;
	
	int bk = sum;
	a[tr][tc]=1;
	if(tc!=0 && a[tr][tc-1]) sum++;
	if(tr!=0 && a[tr-1][tc]) sum++;
	fd(tr,tc+1,tn-1,sum);
	sum=bk;
	a[tr][tc]=0;
	fd(tr,tc+1,tn,sum);
}

void rfd(int tr,int tc,int tn,int sum){
	if(tn==0){
		smax(ans,sum); return;
	}
	if(tc==c) fd(tr+1,0,tn,sum);
	if(tr==r) return;
	
	int bk = sum;
	a[tr][tc]=1;
	if(tc!=0 && a[tr][tc-1]) sum++;
	if(tr!=0 && a[tr-1][tc]) sum++;
	fd(tr,tc+1,tn-1,sum);
	sum=bk;
	a[tr][tc]=0;
	rfd(tr,tc+1,tn,sum);
}

int sm(int r,int c){
	if(r<c) swap(r,c);
	return (r-1)*c+(c-1)*r;
}

int work2(int r,int c,int n){
	if(n<=1) return 0; 
	memset(a,0,sizeof a);
	if(n*2>r*c){
		ans = 0;
		rfd(0,0, r*c-n,0);
		return sm(r,c)-ans;
	}
	else{
		ans = INF;
		fd( 0,0, n,0);
		return ans;
	}
}

int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	ios_base::sync_with_stdio(0);
	scanf("%d",&T);
	fer(tt,1,T+1){
		scanf("%d%d%d",&r,&c,&n);
		if(r>c) swap(r,c);
		printf("Case #%d: %d\n",tt,work(r,c,n));
	}
	return 0;
}