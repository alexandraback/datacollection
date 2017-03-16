#include <iostream>
#include <string>
#include <vector>

using namespace std;
typedef long long ll;
const int Nmax = 100;

ll X[Nmax], Y[Nmax];

int min (int x, int y) { return x < y ? x : y; }

int main()
{
  
  int T, N;
  cin >> T;
  for (int t = 1; t <= T; t++) {
    cin >> N;
    for (int i = 0; i < N; i ++) {
      cin >> X[i] >> Y[i];
    }
    cout << "Case #" << t << ":\n";
    for (int i = 0; i < N; i++) {
      int best = N-1;
      for (int j = 0; j < N; j++) {
        if (i == j)
          continue;
        int l = 0, r = 0;
        for (int k = 0; k < N; k++) {
          if (k == i || k == j)
            continue;
          ll d = 1ll*(Y[j]-Y[i])*(X[k]-X[i]) - 1ll*(X[j]-X[i])*(Y[k]-Y[i]);
          if (d > 0) l++;
          else if (d < 0) r++;
        }
        best = min(best, min(l, r));
      }
      cout << best << '\n';
    }
  }

  return 0;
}
