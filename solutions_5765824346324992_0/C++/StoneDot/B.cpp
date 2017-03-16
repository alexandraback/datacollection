#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <functional>

using namespace std;

struct Barber {
  int id;
  int m;
  long long t;
};

bool operator>(const Barber &left, const Barber &right) {
  return left.t == right.t ? left.id > right.id : left.t > right.t;
}

long long _gcd(long long a, long long b) {
  long long r = b % a;
  if (r == 0) return a;
  else return _gcd(r, a);
}

long long gcd(long long a, long long b) {
  if (a < b) return _gcd(a, b);
  else return _gcd(b, a);
}

long long lcm(long long a, long long b) {
  return a * b / gcd(a, b);
}

int main(void) {
  int T;
  cin >> T;
  for (int t = 1; t <= T; t++) {
    cout << "Case #" << t << ": ";
    int B, N;
    priority_queue<Barber, vector<Barber>, greater<Barber>> queue;
    vector<Barber> input;
    cin >> B >> N;
    for (int i = 1; i <= B; i++) {
      int m; cin >> m;
      queue.push({ i, m, 0 });
      input.push_back({ i, m, 0 });
    }

    long long lcm_count = input[0].m;
    for (int i = 1; i < B; i++) {
      lcm_count = lcm(lcm_count, input[i].m);
    }
    long long cleanuped = 0;
    for (auto b : input) {
      cleanuped += lcm_count / b.m;
    }
    N = N < cleanuped ? N : N % cleanuped + cleanuped;

    for (int i = 0; i < N - 1; i++) {
      auto b = queue.top();
      queue.pop();
      b.t += b.m;
      queue.push(b);
    }
    cout << queue.top().id << endl;
  }
  return 0;
}