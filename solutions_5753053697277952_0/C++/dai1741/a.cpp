#include <iostream>
#include <iomanip>
#include <sstream>
#include <vector>
#include <map>
#include <queue>
#include <stack>
#include <algorithm>
#include <cmath>
#include <climits>
#include <complex>
using namespace std;
#define repn(i,s,n) for (int i=int(s); i < int(n); i++)
#define rep(i,n) repn(i,0,n)
#define repd(i,n) for (int i=int(n)-1; i >= 0; i--)

typedef vector<int> VI;
typedef vector<VI> VVI;
typedef VVI Graph;
typedef long long ll;

string solve()
{
  int n;
  cin >> n;
  VI ps(n);
  int pmax = 0;
  int pmaxParty = -1;
  int psum = 0;
  rep(i, n) {
    cin >> ps[i];
    if (pmax < ps[i]) {
      pmax = ps[i];
      pmaxParty = i;
    }
    psum += ps[i];
  }
  int psumMinority = psum - pmax;
  char pmaxPartyC = pmaxParty + 'A';
  stringstream ans;
  while (psumMinority < ps[pmaxParty]) {
    ans << pmaxPartyC << " ";
    ps[pmaxParty]--;
    // omg
  }
  while (psumMinority > ps[pmaxParty]) {
    rep(i, n) {
      if (i != pmaxParty && ps[i] > 0) {
        ans << char(i + 'A') << " ";
        psumMinority--;
        ps[i]--;
        break;
      }
    }
  }
  while (ps[pmaxParty] > 0) {
    ans << pmaxPartyC;
    ps[pmaxParty]--;
    rep(i, n) {
      if (i != pmaxParty && ps[i] > 0) {
        ans << char(i + 'A') << " ";
        ps[i]--;
        break;
      }
    }
  }
  return ans.str();
}

int main() {
  int t;
  cin >> t;
  rep(i, t) cout << "Case #" << i+1 << ": " << solve() << endl;
  return 0;
}
