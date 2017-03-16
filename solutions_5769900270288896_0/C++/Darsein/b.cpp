#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define rrep(i,n) for(int i=(int)(n)-1;i>=0;i--)
#define all(a) (a).begin(),(a).end()
#define INIT(a) memset((a),0,sizeof(a))
#define fs first
#define sc second
#define pb push_back
#define sz size() 
using namespace std;
typedef long long ll;
typedef double D;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<string> vs;

const static int INF = 1e8;
const static D EPS = 1e-8;

int main(){
  int testcase;

  cin >> testcase;
  for(int casenum=1;casenum<=testcase;casenum++){
    int h,w,n;
    cin >> h >> w >> n;
    int s = h*w;

    if(n == 0){
      cout << "Case #" << casenum << ": " << 0 << endl;
    }else{
      int res = INF;
      for(int bit=1;bit<(1<<s);bit++){
	if(__builtin_popcount(bit) == n){
	  vector< vi > g(h,vi(w,0));
	  rep(i,h)rep(j,w){
	    if( (bit >> (i*w+j)) & 1 ) g[i][j] = 1;
	  }

	  int sum = 0;
	  rep(i,h)rep(j,w){
	    if(i && g[i-1][j] && g[i][j])sum++;
	    if(j && g[i][j-1] && g[i][j])sum++;
	  }
	  res = min(res,sum);
	}
      }
      cout << "Case #" << casenum << ": " << res << endl;
    }
  }
}
