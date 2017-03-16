#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void init() {
}

// 変数を書く
int B;
int N;
ll M[1010];

void input() {
  cin >> B >> N;
  for (auto i=0; i<B; i++) {
    cin >> M[i];
  }
}

void output() {
  if (B >= N) {
    cout << N << endl;
    return;
  }
  ll lb = 0;
  ll ub = 1000000000000000;
  while (ub - lb > 1) {
    ll t = (lb+ub)/2;
    ll n = 0;
    for (auto i=0; i<B; i++) {
      n += t/M[i];
      n++;
    }
    if (n < N) {
      lb = t;
    } else {
      ub = t;
    }
  }
  ll ct = lb;
  ll amari = N-1;
  for (auto i=0; i<B; i++) {
    amari -= ct/M[i];
  }
  pair<ll, int> X[1010];
  for (auto i=0; i<B; i++) {
    ll x = M[i] - (ct - (ct/M[i]) * M[i]);
    X[i] = make_pair(x, i);
  }
  sort(X, X+B);
  // cerr << ct << " " << amari << endl;
  /*for (auto i=0; i<B; i++) {
    cerr << "i = " << i << ", wait = "
         << X[i].first << ", b = " << X[i].second << endl;
         }*/
  cout << X[(amari)%B].second + 1 << endl;
}

int main() {
  init();
  int T;
  cin >> T;
  for (auto t=1; t<=T; t++) {
    cout << "Case #" << t << ": "; 
    input();
    output();
  }
}
