#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <utility>
#include <tuple>
#include <numeric>
#include <cstring>

using namespace std;

  long long int kgv(long long int* arr, long long int N) {
  long long int result = arr[0];
  for (int i=1; i<N; ++i) {
    long long int gcd=1;
    for (long long int j=min(result,arr[i]); j>=1; --j)
      if ((!(result%j)) && (!(arr[i]%j))) {
        gcd = j; break;
      }
    result = result*arr[i]/gcd;
  }
  return result;
}

int main() {

  freopen("in", "r", stdin);
  freopen("out", "w", stdout);
  
  int T;
  scanf("%d", &T);

  for (int t=1; t<=T; ++t) {
    printf("Case #%d: ", t);
    long long int B, N;
    cin >> B >> N;
    long long int M[B];
    for (int i=0; i<B; ++i) cin >> M[i];
    long long int k = kgv(M, B);
    long long int n = 0;
    for (int i=0; i<B; ++i) n += k/M[i];
    N = N%n;
    if (N==0) N=n;
    long long int rem[B];
    fill_n(rem, B, 0);
    for (int i=0; i<N-1; ++i) {
      long long int *it = find(rem, rem+B, 0);
      if (it==rem+B) {
        long long int *minit = min_element(rem, rem+B);
        long long int min = *minit;
        for (int j=0; j<B; ++j) rem[j] -= min;
        *minit = M[minit-rem];
      }
      else {
        *it = M[it-rem];
      }
    }
    long long int *it = min_element(rem, rem+B);
    cout << (it-rem)+1 << endl;
  }
}
