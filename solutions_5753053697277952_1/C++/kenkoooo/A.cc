/*
                   _ooOoo_
                  o8888888o
                  88" . "88
                  (| -_- |)
                  O\  =  /O
               ____/`---'\____
             .'  \\|     |//  `.
            /  \\|||  :  |||//  \
           /  _||||| -:- |||||-  \
           |   | \\\  -  /// |   |
           | \_|  ''\---/''  |   |
           \  .-\__  `-`  ___/-. /
         ___`. .'  /--.--\  `. . __
      ."" '<  `.___\_<|>_/___.'  >'"".
     | | :  `- \`.;`\ _ /`;.`/ - ` : | |
     \  \ `-.   \_ __\ /__ _/   .-` /  /
======`-.____`-.___\_____/___.-`____.-'======
                   `=---='
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
            pass System Test!
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
template <typename T>
std::ostream &operator<<(std::ostream &out, const std::vector<T> &v) {
  if (!v.empty()) {
    out << '[';
    std::copy(v.begin(), v.end(), std::ostream_iterator<T>(out, ", "));
    out << "\b\b]";
  }
  return out;
}
template <typename T1, typename T2>
std::ostream &operator<<(std::ostream &out, const std::pair<T1, T2> &p) {
  out << "[" << p.first << ", " << p.second << "]";
  return out;
}
template <class T, class U>
void chmin(T &t, U f) {
  if (t > f) t = f;
}
template <class T, class U>
void chmax(T &t, U f) {
  if (t < f) t = f;
}
template <typename T>
void uniq(vector<T> &v) {
  v.erase(unique(v.begin(), v.end()), v.end());
}

bool valid(const vector<int> &members) {
  int sum = accumulate(members.begin(), members.end(), 0);
  for (int p : members)
    if (sum < p * 2) return false;

  return true;
}

vector<string> solve(vector<int> &members) {
  int N = members.size();
  vector<string> ans;
  while (true) {
    int ma = *max_element(members.begin(), members.end());
    if (ma == 0) break;
    vector<int> majority;
    for (int i = 0; i < N; ++i) {
      if (members[i] == ma) majority.push_back(i);
    }
    if (majority.size() % 2 == 0) {
      int i1 = majority[0];
      int i2 = majority[1];
      char c1 = i1 + 'A';
      char c2 = i2 + 'A';
      members[i1]--;
      members[i2]--;
      string s = "";
      s.push_back(c1);
      s.push_back(c2);
      ans.push_back(s);
    } else {
      int i1 = majority[0];
      char c1 = i1 + 'A';
      members[i1]--;
      string s = "";
      s.push_back(c1);
      ans.push_back(s);
    }
    assert(valid(members));
  }
  return ans;
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int T;
  cin >> T;
  for (int testcase = 1; testcase <= T; ++testcase) {
    int N;
    cin >> N;
    vector<int> members(N);
    for (int i = 0; i < N; ++i) cin >> members[i];

    cout << "Case #" << testcase << ": ";
    vector<string> ans = solve(members);
    for (int i = 0; i < ans.size(); ++i) {
      if (i > 0) cout << " ";
      cout << ans[i];
    }
    cout << endl;
  }
}
