#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;

double mmod(double x) {
  return x < 0 ? x + 2 * M_PI : x;
}

int main() {
  int Z;
  cin >> Z;
  for (int z=1; z<=Z;++z) {
    int n;
    cin >> n;
    vector<int> x(n), y(n);
    for (int i=0; i<n;++i){
      cin >> x[i] >> y[i];
    }
    cout << "Case #" << z << ":" << endl;
    for (int q=0; q<n; ++q) {
      if (n <= 3) { cout << 0 << endl; continue; }
      vector<double> a;
      a.reserve(n - 1);
      for (int i=0; i<n; ++i) if (i!=q)
        a.push_back(atan2(y[i]-y[q], x[i]-x[q]));
      sort(a.begin(), a.end());
      a.resize(2 * a.size());
      for (int i=n-1;i<2*(n-1);++i)a[i] = a[i - (n-1)];
      int best = n - 3;
      int j = 0;
      for (int i = 0; i < n - 1; ++i) {
        while (j - i < n - 1 && mmod(a[j] - a[i]) < M_PI + 1e-9) ++j;
        best = min(best, n - 1 - (j - i));
      }
      cout << best << endl;
    }
  }
}
