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
const LL INF=1LL<<60;
const LL p=7+1e+9;
LL B,N,M[1001];

LL ables(LL times){
	if(times<0) return 0;
	LL sum=0;
	REP(i,B){
		sum+=times/M[i]+1;
	}
	return sum;
}
void solve(int T){
	cin >> B >> N;
	REP(i,B)
		cin >> M[i];
	LL s=0,e=INF;
	while(s<=e){
		LL f=(s+e)/2;
		if(ables(f)>=N)
			e=f-1;
		else
			s=f+1;
	}
	LL need=N-ables(e);
	REP(i,N){
		if(s%M[i]==0){
			need--;
			if(need==0){
				cout << "Case #"<<T<<": " << i+1 << endl;
				return;
			}
		}
	}
}
int main(){
	int T;
	cin >> T;
	FOR(i,1,T+1){
		solve(i);
	}

	return 0;
}