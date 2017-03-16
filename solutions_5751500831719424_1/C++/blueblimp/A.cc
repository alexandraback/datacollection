#include <algorithm>
#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <vector>
using namespace std;

#define FR(i,a,b) for(int i=(a);i<(b);++i)
#define FOR(i,n) FR(i,0,n)
#define CLR(x,a) memset(x,a,sizeof(x))
#define setmin(a,b) a = min(a,b)
#define PB push_back
#define FORALL(i,v) for(typeof((v).end())i=(v).begin();i!=(v).end();++i)
#define MP make_pair
#define A first
#define B second
#define RF(i,a,b) for(int i=(a)-1;i>=(b);--i)
#define BEND(v) (v).begin(),(v).end()
#define SZ(v) int((v).size())
#define FORI(i,v) FOR(i,SZ(v))
typedef long double ld;
typedef long long ll;

#define dlog printf
//#define dlog(...)

int N;
int ans;
string wire[128];
typedef pair<int, char> pic;
vector<pic> groups[128];

bool compute()
{
  ans = 0;
  FOR(i,128) groups[i].clear();
  FOR(i,N) {
    int p = 0;
    while (p < wire[i].size()) {
      int q = p;
      while (q < wire[i].size() && wire[i][p] == wire[i][q]) ++q;
      groups[i].push_back(pic(q-p, wire[i][p]));
      p = q;
    }
  }
  int ngroups = groups[0].size();
  FOR(i,N) if (groups[i].size() != ngroups) return false;

  vector<int> nums;
  FOR(g,ngroups) {
    nums.clear();
    FOR(i,N) {
      if (groups[i][g].second != groups[0][g].second) return false;
      nums.push_back(groups[i][g].first);
    }
    sort(BEND(nums));
    int median = nums[nums.size() / 2];
    FOR(i,N) {
      ans += abs(median - nums[i]);
    }
  }
  return true;
}

void doit(int cas)
{
  scanf(" %d", &N);
  assert(1 <= N && N <= 100);
  FOR(i,N) {
    char buf[128];
    scanf(" %s", buf);
    wire[i] = string(buf);
  }

  bool poss = compute();

  printf("Case #%d: ", cas);
  if (poss) {
    printf("%d", ans);
  } else {
    printf("Fegla Won");
  }
  printf("\n");
}

int T;
int main() {
  scanf(" %d", &T);
  assert(1 <= T && T <= 100);
  FOR(cas,T) doit(cas+1);
  return 0;
}
