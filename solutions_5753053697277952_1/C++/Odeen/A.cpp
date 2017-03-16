#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int t;

string solve(int n, vector<int> p) {
  string ans = "";
  cerr << "!";
  int f = 0;
  while (true) {
    int count = 0;
    for (auto i : p) count += i;
    f = count%2;
    for (int i : p) assert(i <= count / 2);
    int mx = 0;
    for (int i = 0; i < p.size(); ++i) if (p[mx] < p[i]) mx = i;
    if (p[mx] == 0) break;
    p[mx]--;
    ans += (char)('A' + mx);
    if (f) {f=0;ans+=" ";continue;}
    for (int i = 0; i < p.size(); ++i) if (p[mx] < p[i]) mx = i;
    if (p[mx] == 0) break;
    ans += (char)('A' + mx);
    p[mx]--;
    ans += " ";
  }
  return ans;
}

int main() {
  cin >> t;
  int nmb = 0;
  while (t-->0) {
    int n;
    cin >> n;
    vector<int> p(n);
    for (int i = 0; i < n; ++i) cin >> p[i];
    cout << "Case #" << ++nmb << ": " << solve(n, p) << endl;
  }
  return 0;
}
