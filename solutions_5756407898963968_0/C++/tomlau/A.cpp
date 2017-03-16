#include <iostream>
#include <string>
using namespace std;

int i, j, t, T, c, n;

int main(){ 
  cin >> T;
  while (++t<=T) {
    int r1, r2, g1[16], g2[16];
    cin >> r1;
    for (i=0; i<16; cin >> g1[i++]);
    cin >> r2;
    for (i=0; i<16; cin >> g2[i++]);
    cout << "Case #" << t << ": ";
    n = c = 0;
    for (i=0; i<4; i++)
      for (j=0; j<4; j++)
        if (g2[r2*4-4+j] == g1[r1*4-4+i]) c++, n=g1[r1*4-4+i];
    if (c == 1)
      cout << n << endl;
    else 
      cout << (c > 1 ? "Bad magician!" : "Volunteer cheated!") << endl;
  }
}
