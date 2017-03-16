/*

jsrkrmciB

*/

#include <algorithm>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

#define clear(x) memset((x), 0, sizeof(x))
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define mp make_pair
#define sz size()
#define Fora(i, st, en) for(int i=(st); i<=(int)(en); i++)
#define Ford(i, st, en) for(int i=(st); i>=(int)(en); i--)
#define fora(i, n) for(int i=0; i<(int)(n); i++)
#define ford(i, n) for(int i=(n)-1; i>=0; i--)
#define foreach(c,itr) for(__typeof((c).begin()) itr=(c).begin();itr!=(c).end();itr++)
#define output(x) cout << (x)
#define ST first
#define ND second
#define br printf("\n")
#define getnum(x) scanf("%d", &x);
#define GCJ(x,y)  printf("Case #%d: %d\n", x+1, y);
#define getline(x) 	scanf("\n%[^\n]",x);

template <class _T> inline _T sqr(const _T& x) { return x * x; }
template <class _T> inline string tostr(const _T& a) { ostringstream os(""); os << a; return os.str(); }
template <class _T> inline istream& operator << (istream& is, const _T& a) { is.putback(a); return is; }

typedef long double ld;
typedef signed   long long i64;
typedef unsigned long long u64;
typedef set < int > SI;
typedef vector < ld > VD;
typedef vector < int > VI;
typedef vector < bool > VB;
typedef vector < string > VS;
typedef map < string, int > MSI;
typedef pair < int, int > PII;

const ld PI  = 3.1415926535897932384626433832795;
const ld EPS = 1e-11;

#define DEBUG

#ifdef DEBUG
#define debug(x) cout << #x << ":" << x << "\n";
#define dprintf(fmt,...) fprintf(stderr,fmt,__VA_ARGS__)
#else
#define debug //
#define dprintf(fmt,...)
#endif

// Global Variable
int qq;

int lcm2(int a,int b){
    int t = a;
    while(1){
         if(t % b == 0 && t % a == 0)
             break;
         t++;
    }
   return t;
}

int lcm(int m[1000], int B){
	int mm=m[0];
	fora(i,B){
		mm=lcm2(mm,m[i]);
	}
	return mm;
}

int main() {
	freopen("B-small-attempt0.in", "rt", stdin); 
	freopen("B-small-attempt0.out", "wt", stdout); 
	getnum(qq);
	fora(T,qq){
		int B,N,NN,m[1000],d[1000],ans;
		getnum(B);
		getnum(N);
		fora(i,B){
			getnum(m[i]);
		}
		int l = lcm(m,B);
		int t=0;
		fora(i,B){
			t+=l/m[i];
		}
		N=N%t;

		if(N==0){
			int minm=1000000000,mini;
			fora(i,B){
				minm=min(minm,m[i]);
				if(m[i]==minm) mini=i;
			}
			printf("Case #%d: %d\n", T+1, mini+1);
			continue;
		}
		t=0;
		int i=0;
		while(1){
			fora(j,B){
				if(i%m[j]==0) t+=1;
				if(t>=N){
					ans=j;
					break;
				}
			}
			if(t>=N) break;
			i++;
		}
		printf("Case #%d: %d\n", T+1,ans+1);
	}
	return 0;
}