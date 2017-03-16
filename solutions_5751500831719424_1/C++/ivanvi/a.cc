#include <cstdio>
#include <string>
#include <vector>

using namespace std;

#define ABS(a) (((a) < (0)) ? (-(a)) : (a))

void input(void);
void solve(void);
string canonical_value(string s);
vector <int> get_lengths(string s);

int n;
vector <string> vs;
int case_cnt = 1;

int main(void) {
  int t;
  scanf("%d", &t);
  while (t--) {
    input();
    solve();
  }
  return 0;
}

void input(void) {
  scanf("%d", &n);
  vs.clear();
  for (int i = 0; i < n; i++) {
    char s[128];
    scanf(" %s", s);
    vs.push_back(s);
  }
}

void solve(void) {
  bool good = true;
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      if (canonical_value(vs[i]) != canonical_value(vs[j])) {
        good = false;
        break;
      }
    }
    if (!good) break;
  }

  if (!good) {
    printf("Case #%d: Fegla Won\n", case_cnt++);
    return;
  }

  vector <vector <int> > lens;
  for (int i = 0; i < n; i++) {
    lens.push_back(get_lengths(vs[i]));
  }

  int res = 0;
  for (int j = 0; j < lens[0].size(); j++) {
    int best = 1000000;
    for (int k = 1; k <= 100; k++) {
      int sum = 0;
      for (int i = 0; i < n; i++) sum += ABS(lens[i][j] - k);
      if (sum < best) best = sum;
    }
    res += best;
  }

  printf("Case #%d: %d\n", case_cnt++, res);
}

string canonical_value(string s) {
  string res;
  for (int i = 0; i < s.size(); i++) {
    if (i == 0 || s[i - 1] != s[i]) res += s[i];
  }
  return res;
}

vector <int> get_lengths(string s) {
  vector <int> res;
  int cnt = 1;
  for (int i = 1; i < s.size(); i++) {
    if (s[i - 1] != s[i]) {
      res.push_back(cnt);
      cnt = 1;
    } else {
      cnt++;
    }
  }
  res.push_back(cnt);
  return res;
}


