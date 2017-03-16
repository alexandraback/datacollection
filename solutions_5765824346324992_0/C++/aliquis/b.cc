#include <cstdio>
#include <queue>
#include <vector>
#include <thread>

struct barber {
  int number;
  int time;
  long long available;
  bool operator<(barber const &o) const {
    if (available != o.available)
      return available > o.available;
    return number > o.number;
  }
};

std::vector<int> Ns;
std::vector<std::priority_queue<struct barber> > ps;
std::vector<int> answer;
std::vector<std::thread> threads;

void solve(int const x) {
  int const N = Ns[x];
  std::priority_queue<struct barber> p = ps[x];
  for (int i = 1; i < N; ++i) {
    struct barber B = p.top();
    p.pop();
    B.available += B.time;
    p.push(B);
  }
  answer[x] = p.top().number;
}

int main()
{
  int T;
  scanf("%d", &T);
  answer.resize(T);
  for (int casenr = 0; casenr < T; ++casenr) {
    int B, N;
    scanf("%d%d", &B, &N);
    std::priority_queue<struct barber> p;
    for (int i = 1; i <= B; ++i) {
      int M;
      scanf("%d", &M);
      struct barber B;
      B.number = i;
      B.time = M;
      p.push(B);
    }
    Ns.push_back(N);
    ps.push_back(p);
  }
  for (int casenr = 0; casenr < T; ++casenr) {
    threads.push_back(std::thread(solve, casenr));
  }
  for (int casenr = 0; casenr < T; ++casenr) {
    threads[casenr].join();
    printf("Case #%d: %d\n", casenr + 1, answer[casenr]);
  }
  return 0;
}
