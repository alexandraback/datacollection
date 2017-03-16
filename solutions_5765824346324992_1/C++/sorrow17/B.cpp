#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#define MAXM 100000
#define ll long long
using namespace std;

int T = 0;
int m[MAXM];

void solve(ifstream& fin,ofstream& fout){
  int T = 0;

  fin >> T;
  for (size_t t = 0; t < T; t++) {
    int B = 0;
    int N = 0;
    fin >> B >> N;
    int ans = 1;
    ll M = 0;
    for (size_t i = 0; i < B; i++) {
      fin >> m[i];
      if (m[i]>M) M = m[i];
    }
    ll l = 0;
    ll r = M*N + 1;
    while (l < r-1) {
      ll mid = (l + r) >> 1;
      ll tmp = 0;
      for (size_t i = 0; i < B; i++) {
        tmp += mid / m[i];
      }
      if (B + tmp >= N)r = mid; else l = mid;
    }
    ll mid = r;
    ll sum = 0;
    for (size_t i = 0; i < B; i++) {
      sum += l / m[i];
    }
    if (N <= sum + B) mid = l;
    sum = 0;
    for (size_t i = 0; i < B; i++) {
      sum += (mid - 1) / m[i];
    }
    sum += B;
    for (size_t i = 0; i < B; i++) {
      if (mid%m[i] == 0) {
        sum += 1;
        if (N == sum) {
          ans = i+1;
          break;
        }
      }
    }
    fout << "Case #" << t+1 << ": " << ans << endl;
  }
}