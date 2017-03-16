#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

#define endl "\n"
#define all(x) x.begin(), x.end()

typedef long long ll;

int solve(int r, int c, int n, int st)
{
  vector <vector <char> > v(r, vector <char>(c));
  int cnt = 0;
  ll ans = 0;
  for (int i = 0; i < r; i++) {
    for (int j = (i + st) % 2; j < c; j += 2) {
      v[i][j] = 1;
      cnt++;
      if (cnt == n) {
        return ans;
      }
    }
  }

  vector <int> nbs;
  int dx[] = {-1, 1, 0, 0};
  int dy[] = {0, 0, 1, -1};
  for (int i = 0; i < r; i++) {
    for (int j = 0; j < c; j++) {
      if (!v[i][j]) {
        int cnt = 0;
        for (int k = 0; k < 4; k++) {
          int ni = i + dx[k];
          int nj = j + dy[k];
          if (ni >= 0 && nj >= 0 && ni < r && nj < c) {
            cnt += v[ni][nj];
          }
        }
        nbs.push_back(cnt);
      }
    }
  }

  sort(all(nbs));
  for (int i = 0; i < n - cnt; i++) {
    ans += nbs[i];
  }
  return ans;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int test_cases;
  cin >> test_cases;

  for (int t = 1; t <= test_cases; t++) {
    cerr << "Solving " << t << endl;
    cout << "Case #" << t << ": ";
    int r, c, n;
    cin >> r >> c >> n;
    cout << min(solve(r, c, n, 0), solve(r, c, n, 1)) << endl;
  }

  return 0;
}
