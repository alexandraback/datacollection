#include <bits/stdc++.h>

using namespace std;

#define maximo 10004

int main () {
  ios_base::sync_with_stdio(false);
  
  int t, caso, n, v[maximo], i;
  
  cin >> t;
  
  for (caso = 1; caso <= t; caso++) {
    cin >> n;
    for (i = 0; i < n; i++)
      cin >> v[i];
    
    long long soma = 0;
    int maior = 0;
    for (i = 1; i < n; i++) {
      if (v[i] < v[i - 1]) {
        soma +=  v[i - 1] - v[i];
        maior = max (v[i - 1] - v[i], maior);
      }
    }
    long long resp2 = 0;
    for (i = 0; i < n - 1; i++) {
      resp2 += min (v[i], maior);
    }
    cout << "Case #" << caso << ": " << soma << " " << resp2 << endl;
  }
  
  return 0;
}










