#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

#include <string>
using namespace std;

int main()
{
  int n;
  
  cin >> n;

  for (int kase = 1; kase <= n; kase++) {
    int N;
    cin >> N;
    priority_queue<pair<int, char>> senates;
    int total = 0;
    for (int i = 0; i < N; i++) {
      int num;
      cin >> num;
      senates.push(make_pair(num, 'A' + i));
      total += num;
    }

    cout << "Case #" << kase << ": ";
    while (!senates.empty()) {
      int popSize = min(2, (int)senates.size());
      if (total == 3) {
        popSize = 1;
      }
      for (int i = 0; i < popSize; i++) {
        pair<int, char> senate = senates.top(); senates.pop();
        cout << senate.second;
        senate.first--;
        total--;
        if (senate.first != 0) {
          senates.push(senate);
        }
      }
      if (senates.empty()) {
        cout << endl;
      }
      else {
        cout << ' ';
      }
    }
  }

  return 0;
}
