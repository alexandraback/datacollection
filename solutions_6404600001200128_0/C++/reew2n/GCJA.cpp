#include <bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define REP(i,b) FOR(i,0,b)
#define F first
#define S second
#define PB push_back 
#define BE(c) c.begin(),c.end()
using namespace std;
typedef long long LL;
typedef complex<int> cld;
typedef LL ut;
typedef vector<ut> VI;
typedef pair<ut,ut> pr;
typedef vector<pr> Vpr;
typedef pair<ut,pr> ppr;
typedef vector<ppr> Vppr;
typedef pair<pr,pr> ppppr;
typedef pair<ut,ppppr> pppppr;
typedef priority_queue<ppr,Vppr> PQ;
typedef vector<ppr> Vppr;
const int SIZE=1+1e+5;
const int INF=1<<30;
const LL p=7+1e+9;
int val[1001];
void solve(int T){
	int N;
	cin >> N;
	int ans1=0,ans2=0;
	int dif=0;
	cin >> val[0];
	FOR(i,1,N){
		cin >> val[i];
		ans1+=max(0,val[i-1]-val[i]);
		dif=max(dif,val[i-1]-val[i]);
	}
	FOR(i,0,N-1){
		ans2+=min(dif,val[i]);
	}
	cout << "Case #"<< T << ": " << ans1 <<" " << ans2 << endl;

}
int main(){
	int T;
	cin >> T;
	FOR(i,1,T+1){
		solve(i);
	}

	return 0;
}