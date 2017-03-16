#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
using namespace std;

int gcd(int a, int b) {
  while (b) {
    int t = b;
    b = a % b;
    a = t;
  }
  return a;
}

int lcm(int a, int b) {
  return a / gcd(a, b) * b;
}

struct Barber {
  int id;
  long long avail;
};

bool operator<(const Barber& b1, const Barber& b2) {
  return b1.avail > b2.avail || (b1.avail == b2.avail && b1.id > b2.id);
}

int run() {
  int B, N;
  cin >> B >> N;
  vector<int> b(B);
  for (int i = 0; i < B; i++) {
    cin >> b[i];
  }
  int l = 1;
  for (auto bb : b) {
    l = lcm(bb, l);
  }
  int M = 0;
  for (auto bb : b) {
    M += l / bb;
  }
  N = (N - 1) % M;
  vector<Barber> barbers;
  for (int i = 0; i < B; i++) {
    barbers.push_back({i, 0});
  }
  make_heap(barbers.begin(), barbers.end());
  int last_barber = -1;
  do {
    pop_heap(barbers.begin(), barbers.end());
    last_barber = barbers.back().id;
    barbers.back().avail += b[last_barber];
    push_heap(barbers.begin(), barbers.end());
  } while (N--);
  return last_barber + 1;
}

int main() {
  int T;
  cin >> T;
  for (int t = 1; t <= T; t++) {
    cout << "Case #" << t << ": " << run() << endl;
  }
}
