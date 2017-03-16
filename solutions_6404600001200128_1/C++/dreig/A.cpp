#include <iostream>

using namespace std;
typedef long long ll;
const int Nmax = 1005;


int m[Nmax];

int max(int x, int y) { return x > y ? x : y; }
int min(int x, int y) { return x < y ? x : y; }

int main()
{
  int T, N;
  cin >> T;
  for (int t = 1; t <= T; t++) {
    cin >> N;
    for (int i = 0; i < N; i++) {
      cin >> m[i];
    }
    int speed = 0;
    int ans1 = 0;
    for (int i = 1; i < N; i++) {
      if (m[i-1] > m[i]) {
        ans1 += m[i-1] - m[i];
        speed = max(speed, m[i-1]-m[i]);
      }
    }
    ll ans2 = 0;
    for (int i = 0; i < N-1; i++) {
      ans2 += min(m[i], speed);
    }
    cout << "Case #" << t << ": " << ans1 << ' ' << ans2 << '\n';
  }

  return 0;
}
