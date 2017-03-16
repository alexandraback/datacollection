#include <bits/stdc++.h>

using namespace std;
 
typedef long long ll;
typedef vector<ll> vl;
typedef vector<string> vs;
typedef pair<ll, ll> pll;
 
const ll oo = 0x3f3f3f3f3f3f3f3fll;
const double eps = 1e-9;
 
#define sz(c) int((c).size())
#define all(c) (c).begin(), (c).end()
#define FOR(i,a,b) for (ll i = (a); i < (b); i++)
#define FORD(i,a,b) for (ll i = ll(b)-1; i >= (a); i--)
#define FORIT(i,c) for(__typeof__((c).begin()) i=(c).begin(); i!=(c).end(); i++)
#define mp make_pair
#define pb push_back
#define has(c,i) ((c).find(i) != (c).end())
#define DBG(...) { if(1) fprintf(stderr, __VA_ARGS__); }
#define DBGDO(X) { if(1) cerr << "DBGDO: " << (#X) << " = " << (X) << endl; }
 
ll compute(int i, int j, int N, int R, int C, vector<vector<bool>> &state){
  if(i == R){
    if(!N)
      return 0;
    else
      return oo;
  }
  int ni = (j == C-1) ? i+1 : i;
  int nj = (j == C-1) ? 0 : j+1;
  ll res = compute(ni, nj, N, R, C, state);
  ll evil = 0;
  if(i && state[i-1][j])
    evil++;
  if(j && state[i][j-1])
    evil++;
  state[i][j] = true;
  res = min(res, compute(ni, nj, N-1, R, C, state) + evil);
  state[i][j] = false;
  return res;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int TC;
  cin >> TC;
  FOR(tc, 1, TC+1){
    int R, C, N;
    cin >> R >> C >> N;
    vector<vector<bool>> state(R, vector<bool>(C, false));
    cout << "Case #" << tc << ": " << compute(0, 0, N, R, C, state) << endl;
  }
}
