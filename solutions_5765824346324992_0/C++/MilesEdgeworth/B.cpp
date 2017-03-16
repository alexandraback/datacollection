#include <iostream>
#include <algorithm>
#include <map>
#include <set>
#include <vector>

using namespace std;

int gcd(int a, int b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}

int lcm(int a, int b) {
  return a * b / gcd(a, b);
}

int main() {
  int T;
  cin >> T;
  for (int t = 1; t <= T; ++t) {
    int B, M;
    cin >> B >> M;
    int ms[B];
    int lc = 0;
    for (int i = 0; i < B; ++i) {
      cin >> ms[i];
      if (lc == 0) lc = ms[i];
      else {
        lc = lcm(lc, ms[i]);
      }
    }

    int used = 0;
    for (int i = 0; i < B; ++i) {
      used += lc / ms[i];
    }
    
    set<int> open;
    for (int i = 0; i < B; ++i) {
      open.insert(i);
    }
    M -= ((M - 1) / used) * used;

    map<int, vector<int> > event;
    int ts = 0;
    int last_barber = 1;
    for (int i = 0; i < M; ++i) {
      while (open.empty()) {
        int cur_time = event.begin()->first;
        vector<int>& v = event.begin()->second;
        for (int j = 0; j < v.size(); ++j) {
          open.insert(v[j]);
        }
        event.erase(event.begin());
        ts = cur_time;
      }
      int lowest = *open.begin();
      open.erase(open.begin());
      event[ts + ms[lowest]].push_back(lowest);
      last_barber = lowest + 1;
    }
    cout << "Case #" << t << ": " << last_barber << endl;
  }
}
