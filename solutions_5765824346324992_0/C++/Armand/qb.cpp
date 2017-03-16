#include <iostream>
#include <vector>
#include <cassert>
#include <algorithm>
using namespace std;

unsigned long long started(const vector<unsigned>& B, unsigned long long N){
  unsigned long long ret = 0;
  for (unsigned b : B)
    ret += (N + b - 1) / b;
  return ret;
}

unsigned inwait(const vector<unsigned>& B, unsigned long long N){
  unsigned ret = 0;
  for (unsigned b : B)
    if (N % b == 0)
      ret++;
  return ret;
}

int barber_order(const vector<unsigned>& B, unsigned long long N){
  int max = *max_element(B.begin(), B.end());
  class Recursion {
    const vector<unsigned>& B;
    unsigned long long N;

  public:
    Recursion(const vector<unsigned>& B, unsigned long long N) : B(B), N(N) {}
    unsigned long long operator()(unsigned long long S, unsigned long long E){
      if (E - S <= 1) return S;

      unsigned long long M = ((E - S) >> 1) + S;
      unsigned long long st = started(B, M);
      unsigned w = inwait(B, M);
      if (st >= N)                   return (*this)(S, M);
      else if (st < N && st + w < N) return (*this)(M + 1, E);
      else if (w == 0)               return (*this)(M + 1, E);
      else                           return M;
    }
  } recursion(B, N);

  unsigned long long t = recursion(0, max * N + 1);
  unsigned long long st = started(B, t);
  unsigned w = inwait(B, t);

  unsigned long long K = N - st;
  for (int i = 0; i < B.size(); ++i)
    if (t % B[i] == 0){
      if (K == 1) return i + 1;
      K--;
    }
  return -1;
}

int main(){
  int T; cin >> T;
  for (size_t i = 1; i <= T; ++i){
    int B; unsigned long long N; cin >> B >> N;
    vector<unsigned> V(B);
    for (size_t j = 0; j < B; ++j)
      cin >> V[j];

    cout << "Case #" << i << ": " << barber_order(V, N) << endl;
  }
}
