// TwT514 {{{
#include <bits/stdc++.h>
#define SZ(x) ((int)(x).size())
#define FOR(i,c) for (auto i=(c).begin(); i!=(c).end(); i++)
#define REP(i,n) for (int i=0; i<(n); i++)
#define REP1(i,a,b) for (int i=(int)(a); i<=(int)(b); i++)
#define ALL(x) (x).begin(),(x).end()
#define MS0(x,n) memset(x,0,(n)*sizeof(*x))
#define MS1(x,n) memset(x,-1,(n)*sizeof(*x))
#define MP make_pair
#define PB push_back
#define RI(a) scanf("%d",&(a))
#define RII(a,b) scanf("%d%d",&(a),&(b))
#define RIII(a,b,c) scanf("%d%d%d",&(a),&(b),&(c))
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
typedef vector<int> VI;
// }}}

int r,c;

int solve1(int b){
	int k = min(b, (r-2)*(c-2)/2);
	int ans = 4*k;
	b-=k;
	if(b==0) return ans;
	k = min(b, r-2+c-2);
	ans += 3*k;
	b-=k;
	if(b==0) return ans;
	k = min(b,2);
	ans += 2*k;
	return ans;
}

int solve2(int b){
	int k = min(b, (r-2)*(c-2)/2);
	int ans = 4*k;
	b-=k;
	if(b==0) return ans;
	k = min(b, r-1+c-1);
	ans += 3*k;
	b-=k;
	return ans;
}

int solve3(int b){
	int k = min(b, ((r-2)*(c-2)+1)/2);
	int ans = 4*k;
	b-=k;
	if(b==0) return ans;
	k = min(b, r-3+c-3);
	ans += 3*k;
	b-=k;
	if(b==0) return ans;
	k = min(b,4);
	ans += 2*k;
	return ans;
}

int solve(){
	int b;
	RIII(r,c,b);
	if(b<=(r*c+1)/2) return 0;
	b = r*c-b;
	if(r==1) return c-1-2*b;
	if(c==1) return r-1-2*b;
	if((r*c)%2==0)
		return r*(c-1) + (r-1)*c - solve1(b);
	else
		return r*(c-1) + (r-1)*c - max(solve2(b), solve3(b));
}

int main() {
	int zn;
	RI(zn);
	REP(zi, zn){
		printf("Case #%d: %d\n", zi+1, solve());
		
	}
    return 0;
}

