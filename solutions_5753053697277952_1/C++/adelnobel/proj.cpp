#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
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
#include <cstring>

using namespace std;

typedef pair<int, int> pi;
typedef pair<int, char> pc;
typedef long long ll;

#define pb push_back
ll const MOD = 1000000007;


int main() {
#ifndef ONLINE_JUDGE
  freopen("in.in", "r", stdin);
  freopen("in.out", "w", stdout);
#endif

  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int T, n, cnt;
  cin >> T;

  for(int t = 1; t <= T; t++) {
    cin >> n;
    priority_queue< pair<int, char> > pq;
    for(int i = 0; i < n; i++) {
      cin >> cnt;
      pq.push(make_pair(cnt, 'A' + i));
    }
    cout << "Case #" << t << ":";
    while(pq.size() > 2) {
      pc top = pq.top(); pq.pop();
      cout << " " << top.second;
      --top.first;
      if (top.first > 0) {
        pq.push(top);
      }
    }
    pc first = pq.top(); pq.pop();
    pc second = pq.top(); pq.pop();

    while(first.first > second.first) {
      cout << " " << first.second;
      --first.first;
    }

    while(second.first > 0) {
      cout << " " << first.second << second.second;
      --second.first;
    }

    cout << endl;
  }

  return 0;
}
