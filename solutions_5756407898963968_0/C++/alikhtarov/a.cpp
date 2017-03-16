#include <iostream>
#include <unordered_set>
using namespace std;

int main() {
  int ncases;
  cin >> ncases;
  for (int ncase = 1; ncase <= ncases; ++ncase) {
    unordered_multiset<int> ms;
    int row, x;
    for (int k = 0; k < 2 && cin >> row; ++k)
      for (int i = 0; i < 4; ++i)
	for (int j = 0; j < 4 && cin >> x; ++j)
	  if (i+1 == row)
	    ms.insert(x);

    int two = 0, guess;
    for (int i = 1; i <= 16; ++i) {
      auto c = ms.count(i);
      if (c == 2) ++two, guess = i;
    }

    cout << "Case #" << ncase << ": ";
    if (!two) cout << "Volunteer cheated!";
    else if (two > 1) cout << "Bad magician!";
    else cout << guess;
    cout << endl;
  }
}
