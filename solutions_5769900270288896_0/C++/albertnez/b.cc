#include <iostream>
#include <vector>
using namespace std;
typedef vector<int> VI;
typedef vector<VI> MI;

MI mat;
int N, R, C;

int calc() {
  int ans = 0;
  for (int i = 0; i < R; ++i) {
    for (int j = 0; j < C; ++j) {
      if (mat[i][j]) {
        if (i+1 < R && mat[i+1][j]) ++ans;
        if (j+1 < C && mat[i][j+1]) ++ans;
      }
    }
  }
  return ans;
}


int best = 10000000;
void bt(int i, int j, int n) {
  //cout << i << " " << j << " " << n << endl;
  if (i == R) {
    if (n > 0) return;
    best = min(best, calc());
  }
  else {
    if (n == 0) return;
    //cout << "i: " << i << " j : " << j << " r: " << R << " c: " << C << endl;
    mat[i][j] = 1;
    bt(i+(j+1)/C, (j+1)%C, n-1);
    mat[i][j] = 0;
    bt(i+(j+1)/C, (j+1)%C, n);
  }
}

int main() {
  int T; cin >> T;
  int ncase = 0;
  while (T--) {
    best = 10000000;
    cin >> R >> C >> N;
    mat = MI(R, VI(C, 0));
    if (N == 0) best = 0;
    bt(0, 0, N);
    cout << "Case #" << ++ncase << ": " << best << endl;
  }
}
