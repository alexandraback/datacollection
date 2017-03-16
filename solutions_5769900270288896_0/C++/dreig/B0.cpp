#include <iostream>
#include <bitset>
#include <string.h>

using namespace std;
const int inf = 0x3f3f3f3f;

int A[17][17][17];

char bd[17][17];
int main() {
  
  int T, N, R, C;

  memset(A, inf, sizeof(A));

  for (int r = 1; r <= 16; r++)
  for (int c = r; c*r <= 16; c++) {
    int s = r*c;
    for (int n = 0; n < (1 << s); n++) {
      int bits = 0;
      for (int k = 0; k < s; k++)
        if (n & (1 << k))
          bits++;
          
      memset(bd, 0, sizeof(bd));
      
      int noise = 0;
      for (int i = 0; i < r; i++)
      for (int j = 0; j < c; j++) {
        if (n & (1<<(i*c + j))) {
          bd[i][j] = 1;
          if (i > 0 && bd[i-1][j])
            noise++;
          if (j > 0 && bd[i][j-1])
            noise++;
        }
      }
      if (A[bits][r][c] > noise)
        A[bits][r][c] = noise;
    }
  }
  cin >> T;
  for (int t = 1; t <= T; t++) {
    cin >> R >> C >> N;
    if (R > C)
      swap(R, C);
    cout << "Case #" << t << ": " << A[N][R][C] << '\n';
  }
  
/*
  for (int r = 1; r <= 6; r++)
  for (int c = r; c*r <= 16; c++) {
    cout << r << 'x' << c << '\n';
    for (int s = 0; s <= r*c; s++)
      cout << s << ": " << A[s][r][c] << '\n';
  }
*/

  return 0;
}
