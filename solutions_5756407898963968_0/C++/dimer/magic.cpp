#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

int main () {
  ifstream input;
  input.open("input");

  int ntest;
  input >> ntest;

  for (int k=0;k<ntest;k++) {
    int ans0, ans1;
    int arr0[4][4], arr1[4][4];

    input >> ans0;
    ans0--;
    for (int i=0;i<4;i++)
      for (int j=0;j<4;j++)
        input >> arr0[i][j];

    input >> ans1;
    ans1--;
    for (int i=0;i<4;i++)
      for (int j=0;j<4;j++)
        input >> arr1[i][j];

    int nboth = 0;
    int iboth;
    for (int j0=0;j0<4;j0++) {
      bool is1 = false;
      for (int j1=0;j1<4;j1++) {
        is1 |= (arr1[ans1][j1] == arr0[ans0][j0]);
      }
      if (is1) {
        nboth++;
        iboth = arr0[ans0][j0];
      }
    }

    if (nboth == 0)
      cout << "case #" << k+1 << ": Volunteer cheated!" << endl;
    else if (nboth > 1)
      cout << "case #" << k+1 << ": Bad magician!" << endl;
    else
      cout << "case #" << k+1 << ": " << iboth << endl;
  }

  input.close();
  return 0;
}
