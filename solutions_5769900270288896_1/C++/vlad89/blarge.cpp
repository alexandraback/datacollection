#include <cstring>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n) FOR(i,0,n)
#define all(a) (a).begin(),(a).end()
#define UN(a) sort(all(a)),(a).resize(unique(all(a))-(a).begin())
#define sz(a) ((int) (a).size())
#define pb push_back
#define CL(a,b) memset ((a), (b), sizeof (a))
#define X first
#define Y second

typedef vector<int> vi;
typedef pair<int, int> pii;
typedef long long ll;

string problemName = "B";
string smallFileName = problemName + "-small-attempt0";
string largeFileName = problemName + "-large";

//string fileName(1, tolower(problemName[0]));
//string fileName = smallFileName;
string fileName = largeFileName;

string inputFileName = fileName + ".in";
string outputFileName = fileName + ".out";

bool a[11000];
int d[11000];

int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};

void recount(int i, int j, int n, int m, set<pii>& p) {
  int pe = 0;
  REP (dir, 4) {
    int y = i + dy[dir];
    int x = j + dx[dir];
    if (y < 0 || x < 0 || y >= n || x >= m) continue;
    pe += a[y*m + x];
  }
  d[i * m + j] = pe;
  p.insert(pii(pe, i * m + j));
}

int dumb1(int x, int n, int m) {
  set<pii> s;
  memset(a, 0, sizeof(a));
  REP (i, n) {
    REP (j, m) {
      recount(i, j, n, m, s);
    }
  }
  int ans = 0;
  REP (q, x) {
    //    D(s);
    while (1) {
      pii g = *s.begin();
      s.erase(s.begin());
      if (d[g.Y] != g.X) continue;
      int i = g.Y / m;
      int j = g.Y % m;
      if (a[i*m + j]) continue;
      a[i * m + j] = true;
      //      cout << i << ' ' << j << endl;
      ans += g.X;
      REP (dir, 4) {
	int y = i + dy[dir];
	int x = j + dx[dir];
	if (y < 0 || x < 0 || y >= n || x >= m) continue;
	recount(y, x, n, m, s);
      }
      break;
    }
  }
  return ans;
}

int dumb2(int x, int n, int m) {
  set<pii> s;
  memset(a, true, sizeof(a));
  REP (i, n) {
    REP (j, m) {
      recount(i, j, n, m, s);
    }
  }
  int ans = (n-1)*m + (m-1)*n;
  REP (q, n*m-x) {
    //    D(s);
    while (1) {
      pii g = *--s.end();
      s.erase(--s.end());
      if (d[g.Y] != g.X) continue;
      int i = g.Y / m;
      int j = g.Y % m;
      if (!a[i*m + j]) continue;
      a[i * m + j] = false;
      //      cout << i << ' ' << j << endl;
      ans -= g.X;
      REP (dir, 4) {
	int y = i + dy[dir];
	int x = j + dx[dir];
	if (y < 0 || x < 0 || y >= n || x >= m) continue;
	recount(y, x, n, m, s);
      }
      break;
    }
  }
  return ans;
}

int dumb(int x, int n, int m) {
  return min(dumb1(x, n, m), dumb2(x, n, m));
}

int main () {
  freopen(inputFileName.data(), "r", stdin);
  if (fileName == smallFileName || fileName == largeFileName)
    {
      freopen(outputFileName.data(), "w", stdout);
    }
  int T;
  cin >> T;
  REP (test, T) {
    cout << "Case #" << (test + 1) << ": ";
    int r, c, n;
    cin >> r >> c >> n;
    cout << dumb(n, r, c) << endl;
  }
  return 0;
}
