#include <bits/stdc++.h>
using namespace std;

typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<string> VS;
typedef pair<int, int> PII;
typedef long long LL;
typedef pair<LL, LL> PLL;

#define ALL(a)  (a).begin(),(a).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define PB push_back
#define EB emplace_back
#define MP make_pair
#define SZ(a) int((a).size())
#define EACH(i,c) for(typeof((c).begin()) i=(c).begin(); i!=(c).end(); ++i)
#define EXIST(s,e) ((s).find(e)!=(s).end())
#define SORT(c) sort((c).begin(),(c).end())

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)

#define FF first
#define SS second
template<class S, class T>
istream& operator>>(istream& is, pair<S,T>& p){
  return is >> p.FF >> p.SS;
}

const double EPS = 1e-10;
const double PI  = acos(-1.0);
const LL MOD = 1e9+7;

int main(){
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  int T; cin >> T;
  FOR(t,1,T+1){
	int N; cin >> N;
	VI xs(N);
	priority_queue<PII> pq;
	int acc = 0;
	REP(i,N){
	  PII p;
	  cin >> p.FF;
	  xs[i] = p.FF;
	  acc += xs[i];
	  p.SS = i;
	  pq.push(p);
	}

	string ans;
	while(!pq.empty()){
	  auto p = pq.top(); pq.pop();
	  ans += " ";
	  ans += ('A'+p.SS);
	  if(--p.FF > 0) pq.push(p);
	  --acc;
	  if(pq.empty()) break;
	  if(acc % 2 == 0) continue;
	  p = pq.top(); pq.pop();
	  ans += ('A'+p.SS);
	  if(--p.FF > 0) pq.push(p);
	  --acc;
	}

	FOR(i,1,SZ(ans)){
	  if(ans[i] == ' '){
		int s = accumulate(ALL(xs),0);
		int mx = *max_element(ALL(xs));
		if(mx*2 > s) cout << "INCORRECT " << t << " at " << i << endl;
	  }
	  else{
		xs[ans[i]-'A']--;
		if(xs[ans[i]-'A'] < 0)
		  cout << "HALT!!!!" << endl;
	  }
	}
	
	cout << "Case #" << t << ":" << ans << endl;
  }

  return 0;
}








