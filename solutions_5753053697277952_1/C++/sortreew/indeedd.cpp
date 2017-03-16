#include <bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define REP(i,b) FOR(i,0,b)
#define ALL(c) c.begin(),c.end()
#define PB push_back
#define S second
#define F first
using namespace std;
typedef long long LL;
typedef LL ut;
typedef vector<ut> VI;
typedef pair<ut,ut> pr;
typedef vector<pr> Vpr;
typedef pair<ut,pr> ppr;
typedef vector<ppr> Vppr;
typedef priority_queue<pr,Vpr> PQ;
const int INF=1<<30;
const int SIZE=5+1e+5;
const LL p=7+1e9;
PQ qu;
int main(){
	int T,x;
	cin >> T;
	int sum=0;
	REP(j,T){
		int N;
		cin >> N;
		REP(i,N){
			cin >> x;
			sum+=x;
			qu.push(pr(x,i));
		}
		cout << "Case #"<<(j+1)<<":";
		string s;
		while(!qu.empty()){
			int now=qu.top().S,times=qu.top().F;
			if(times==0) break;
			s+=now+'A';
			qu.pop();
			qu.push(pr(times-1,now));
			if(s.size()==2 || sum&1){
				sum=0;
				cout << " " << s;
				s=""; 
			}
		}
		cout << endl;
	}

	return 0;
}