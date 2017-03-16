#include <bits/stdc++.h>
#define REP(a,b) for(int a=0; a<(b); ++a)
#define FWD(a,b,c) for(int a=(b); a<(c); ++a)
#define FWDS(a,b,c,d) for(int a=(b); a<(c); a+=d)
#define BCK(a,b,c) for(int a=(b); a>(c); --a)
#define ALL(a) (a).begin(), (a).end()
#define SIZE(a) ((int)(a).size())
#define VAR(x) #x ": " << x << " "
#define popcount __builtin_popcount
#define popcountll __builtin_popcountll
#define gcd __gcd
#define x first
#define y second
#define st first
#define nd second
#define pb push_back

using namespace std;

template<typename T> ostream& operator<<(ostream &out, const vector<T> &v){ out << "{"; for(const T &a : v) out << a << ", "; out << "}"; return out; }
template<typename S, typename T> ostream& operator<<(ostream &out, const pair<S,T> &p){ out << "(" << p.st << ", " << p.nd << ")"; return out; }

typedef long long LL;
typedef pair<int, int> PII;
typedef long double K;
typedef vector<int> VI;

const int dx[] = {0,0,-1,1}; //1,1,-1,1};
const int dy[] = {-1,1,0,0}; //1,-1,1,-1};

int solve(int n, int m, int k){
	int res = n*m*4;
	vector<int> S;
	FWD(i,0,n*m-k) S.push_back(0);
	FWD(i,0,k) S.push_back(1);
	do{
		int cur = 0;
		FWD(i,0,n) FWD(j,0,m-1) if(S[i*m+j] && S[i*m+j+1]) ++cur;
		FWD(i,0,n-1) FWD(j,0,m) if(S[i*m+j] && S[i*m+m+j]) ++cur;
		res = min(res, cur);
	}while(next_permutation(S.begin(), S.end()));
	return res;
}

int main(){
	/*FWD(n,1,17)
		FWD(m,1,17){
			if(n*m > 16) continue;
			printf("%d X %d\n", n, m);
			FWD(k,(n*m+1)/2,n*m+1) printf("%d %d\n", k, solve(n, m, k));
		}*/
	int z;
	scanf("%d", &z);
	FWD(cas,1,z+1){
		int n, m, k;
		scanf("%d %d %d", &n, &m, &k);
		printf("Case #%d: %d\n", cas, solve(n, m, k));
	}
	return 0;
}
