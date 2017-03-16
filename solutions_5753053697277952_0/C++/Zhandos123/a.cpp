#include <bits/stdc++.h>

#define forn(i, n) for(int i = 0; i < (int)(n); ++i)
#define all(x) x.begin(),x.end()
#define sz(x) (int)(x.size())
#define LL long long
#define mp make_pair
#define pb push_back
#define f first
#define s second

using namespace std;

const int N = 1e5 + 7;
const int mod = 1e9 + 7;

int n;
vector< pair<int,int> > a, na;

void solve(int t) {
  cin >> n;
  int tot = 0;
  forn(i, n) {
    int x;
    cin >> x;
    a.pb(mp(x, i));
    tot += x;
  }
  na.clear();
  while(!a.empty()) {
    forn(i, sz(a)) forn(j, sz(a)) {
      if(a[i].f > 0 && a[j].f > 0) {
        a[i].f--;
        a[j].f--;
        tot -= 2;

        bool valid = 1;
        forn(k, sz(a)) 
          if(a[k].f * 2 > tot) 
            valid = 0;
        
        if(!valid) {
          a[i].f++;
          a[j].f++;
          tot += 2;
        }
        else {
          cout << char(a[i].s+'A') << char(a[j].s+'A') << " ";
          goto go;
        }
      }
    }
    forn(i, sz(a)) {
      if(a[i].f > 0) {
        a[i].f--;
        tot --;
        bool valid = 1;
        forn(j, sz(a)) if(a[j].f * 2 > tot)
          valid = 0;
        if(!valid) {
          a[i].f++;
          tot++;
        }
        else {
          cout << char(a[i].s+'A') << " ";
          goto go;
        }
      }
    }
    go:;
    forn(i, sz(a)) if(a[i].f > 0) 
      na.pb(a[i]);
    a = na;
    na.clear();
  }
}

int main() {
  #ifndef ONLINE_JUDGE
  freopen("in", "r", stdin);
  freopen("out", "w", stdout);
  #endif
    int T;
    cin >> T;
    for(int t = 1; t <= T; ++t) {
      cout << "Case #" << t << ": ";
      solve(t);
      cout << "\n";
    }
  return 0;
}
