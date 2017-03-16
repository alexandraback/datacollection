#include <iostream>
#include <algorithm>
using namespace std;

int T;

int main() {
  cin >> T;
  for (int t=1; t<=T; t++) {
    int N, a, b, rate, m[1024];
    cin >> N;
    for (int i=0; i<N; i++)
      cin >> m[i];
    a = b = rate = 0;
    for (int i=1; i<N; i++) {
      int d = m[i-1]-m[i];
      if (d > 0) a += d;
      rate = max(rate, d);
    }
    for (int i=0; i<N-1; i++)
      b += min(m[i], rate);
    cout << "Case #" << t << ": " << a << " " << b << endl;
 }
}
