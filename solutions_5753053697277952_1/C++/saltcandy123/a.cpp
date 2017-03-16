#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <vector>
#include <utility>

using namespace std;

typedef pair<int, char> Pair;

int main() {
  int t, n, r, p;
  cin >> t;
  for (int case_num = 1; case_num <= t; ++case_num) {
    priority_queue<Pair> heap;
    cin >> n;
    for (int i = 0; i < n; ++i) {
      cin >> p;
      heap.push(Pair(p, 'A' + i));
      r += p;
    }
    cout << "Case #" << case_num << ":";
    while (heap.top().first > 0) {
      Pair top = heap.top();
      heap.pop();
      --r;
      --top.first;
      cout << ' '  << top.second;
      heap.push(top);
      if (heap.top().first * 2 > r) {
        Pair top2 = heap.top();
        heap.pop();
        --r;
        --top2.first;
        cout << top2.second;
        heap.push(top2);
      }
    }
    cout << endl;
  }
  return 0;
}
