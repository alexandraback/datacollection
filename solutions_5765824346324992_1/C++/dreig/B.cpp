#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;
typedef long long ll;
typedef pair<ll, int> pli;
const int Bmax = 1033;


int M[Bmax];
int p[9]={2, 3, 5, 7, 11, 13, 17, 19, 23};

int max(int x, int y) { return x > y ? x : y; }

int main()
{
  int T, N, B;
  cin >> T;
  for (int t = 1; t <= T; t++) {
    cin >> B >> N;
    for (int i = 0; i < B; i++)
     cin >> M[i];
/*    
    int lcm = 1;
    for (int i = 0; i < 9; i++) {
      int e = 0;
      for (int j = 0; j < B; j++) {
        int x = M[j];
        int a = 0;
        while (x % p[i] == 0) {
          x /= p[i];
          a++;
        }
        e = max(e, a);
      }
      while (e) {
        lcm *= p[i];
        e--;
      }
    }
    int mod = 0;
    for (int i = 0; i < B; i++)
      mod += lcm / M[i];
    N = N % mod ? N % mod : mod;
*/
    long double d = 0;
    for (int i = 0; i < B; i++) {
      d += 1.0 / M[i];
    }
    ll est = (N-1) / d;
    ll done = 0;
    priority_queue<pli, vector<pli>, greater<pli> > Q;
    for (int i = 0; i < B; i++) {
      done += est / M[i];
      ll ki = (est / M[i] ) * M[i];
      Q.push({ki, i});
    }
    N -= done;
    for (int i = 1; i < N; i++) {
      pli P = Q.top();
      Q.pop();
      int b = P.second;
      Q.push({P.first+M[b], b});
    }
    int ans = Q.top().second + 1;
    cout << "Case #" << t << ": " << ans << '\n';
  }

  return 0;
}
