#include <algorithm>
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int T, r1, r2;
int A[4][4], B[4][4];

int main() {
  ifstream cin("A-small-attempt0.in");
  ofstream cout("A-small-attempt0.out");
  
  cin >> T;
  for (int Case = 1; Case <= T; Case++) {
    cin >> r1; r1--;
    for (int i = 0; i < 4; i++)
      for (int j = 0; j < 4; j++)
        cin >> A[i][j];
    cin >> r2; r2--;
    for (int i = 0; i < 4; i++)
      for (int j = 0; j < 4; j++)
        cin >> B[i][j];

    sort(A[r1], A[r1] + 4);
    sort(B[r2], B[r2] + 4);
    vector<int> v(10);
    vector<int>::iterator it;
    it = set_intersection(A[r1], A[r1]+4, B[r2], B[r2]+4, v.begin());
    v.resize(it - v.begin());

    cout << "Case #" << Case << ": ";
    if (v.size() == 0) {
      cout << "Volunteer cheated!\n";
    } else if (v.size() > 1) {
      cout << "Bad magician!\n";
    } else {
      cout << v[0] << "\n";
    }
  }
  return 0;
}
