#include <iostream>
#include <fstream>
using namespace std;

#define BAD_MAGICIAN        -1
#define VOLUNTEER_CHEATED   -2

int a[4][4];
int b[4][4];

int solve(int r1, int r2) {
  int r = VOLUNTEER_CHEATED;

  for (int i = 0; i < 4; i++)
    for (int j = 0; j < 4; j++) {
      if (a[r1][i] == b[r2][j]) {
        if (r != VOLUNTEER_CHEATED)
          return BAD_MAGICIAN;
        else
          r = a[r1][i];
      }
    }

  return r;
}

int main() {
  ifstream in("A-small-attempt0.in");
  ofstream out("A-small-attempt0.out");

  int tests;
  in >> tests;
  for (int i = 1; i <= tests; i++) {
    int r1, r2;
    in >> r1;
    for (int j = 0; j < 4; j++)
      for (int k = 0; k < 4; k++)
        in >> a[j][k];

    in >> r2;
    for (int j = 0; j < 4; j++)
      for (int k = 0; k < 4; k++)
        in >> b[j][k];

    out << "Case #" << i << ": ";
    int r = solve(r1 - 1, r2 - 1);
    if (r == VOLUNTEER_CHEATED)
      out << "Volunteer cheated!" << endl;
    else {
      if (r == BAD_MAGICIAN)
        out << "Bad magician!" << endl;
      else
        out << r << endl;
    }
  }
    
  in.close();
  out.close();

  return 0;
}
    
