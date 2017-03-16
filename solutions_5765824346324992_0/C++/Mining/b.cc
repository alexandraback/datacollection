#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstdio>
#include <functional>

struct working {
  int tFinished;
  int id;
  working(int a, int b) {id = a; tFinished = b;}
  working(){}
  bool operator<(working b) const {return tFinished > b.tFinished;}
};

void solve(int c, int p, const std::vector<int> &v)
{
  int barber;
  int t = 0;
  bool b = true;
  std::priority_queue<int, std::vector<int>, std::greater<int> > available;
  std::priority_queue<working> waiting;
  for (int i = 0; i < v.size(); i++) {
    available.push(i);
  }
  for (int i = 0; i < p; i++) {
    if (available.empty()) {
      t = waiting.top().tFinished;
    }
    while (!waiting.empty() && waiting.top().tFinished <= t) {
      available.push(waiting.top().id);
      waiting.pop();
    }
    if (b && waiting.empty() && i != 0) {
      i = ((p/i)-1)*i;
      b = false;
      t = 0;
    }
    barber = available.top();
    waiting.push(working(barber, t+v[barber]));
    available.pop();
  }
  std::cout << "Case #" << c << ": " << barber+1 << std::endl;
}

int main()
{
  int T;
  std::cin >> T;
  for (int t = 1; t <= T; t++) {
    int n, p;
    std::cin >> n;
    std::cin >> p;
    std::vector<int> v(n);
    for (int i = 0; i < n; i++) {
      std::cin >> v[i];
    }
    solve(t, p, v);
  }
}
