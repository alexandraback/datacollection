#include <bits/stdc++.h>

using namespace std;

int v[1004];

long long qa (long long tempo, int N) {
  int i;
  long long x, soma = 0;
  for (i = 0; i < N; i++) {
    x = tempo / v[i];
    if ((long long) v[i] * x < tempo)
      x++;
    soma += x;
  }
  return soma;
}

int main () {
  ios_base::sync_with_stdio(false);
  
  int t, caso, n, i, j, resp, pos;
  
  cin >> t;
  
  for (caso = 1; caso <= t; caso++) {
    cin >> n >> pos;
    for (i = 0; i < n; i++) {
      cin >> v[i];
    }
    if (pos <= n) {
      cout << "Case #" << caso << ": " << pos << endl;
      continue;
    }
    
    long long e = 2;
    long long d = (long long) 100000 * pos / n + 1;
    long long mid;
    long long qtd;
    
    while (e < d) {
      mid = (d - e) / 2 + e;
      qtd = qa (mid, n);
      if (qtd < pos) {
        e = mid + 1;
      }
      else {
        d = mid;
      }
    }
    qtd = qa (d - 1, n);
    long long x;
    for (i = 0; i < n && qtd < pos; i++) {
      if ((d - 1) % v[i] == 0) {
        qtd++;
        if (qtd >= pos)
          break;
      }
    }
    resp = i + 1;
    cout << "Case #" << caso << ": " << resp << endl;
  }
  
  
  
  return 0;
}





