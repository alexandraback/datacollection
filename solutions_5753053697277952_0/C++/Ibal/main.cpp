#include <string>
#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;


bool myfunction (pair<int, int> i, pair<int, int> j) { return (i.first<j.first); }

string senateEvacuation(
  std::vector<int> &senators) {

  string plan;
  const int N = senators.size();
  vector<char> letters;
  letters.push_back('A');
  letters.push_back('B');
  letters.push_back('C');
  letters.push_back('D');
  letters.push_back('E');
  letters.push_back('F');
  letters.push_back('G');
  letters.push_back('H');
  letters.push_back('I');
  letters.push_back('J');
  letters.push_back('K');
  letters.push_back('L');
  letters.push_back('M');
  letters.push_back('N');
  letters.push_back('O');
  letters.push_back('P');
  letters.push_back('Q');
  letters.push_back('R');
  letters.push_back('S');
  letters.push_back('T');
  letters.push_back('U');
  letters.push_back('V');
  letters.push_back('W');
  letters.push_back('X');
  letters.push_back('Y');
  letters.push_back('Z');

  int nb = 0;
  vector<pair<int, int> > names(N);
  for (size_t n = 0; n < names.size(); n++) {
    nb += senators[n];
    names[n] = make_pair(senators[n], n);
  }

  while (names.size() > 0) {
    const size_t T = names.size();
    sort(names.begin(), names.end(), myfunction);
    if (T > 1) {
      const int n = std::min(2, names.back().first);
      if (names[T - 2].first <= (nb - n) / 2) {
        names.back().first -= n;
        nb -= n;
        plan += string(n, letters[names.back().second]) + " ";
        if (names.back().first == 0) {
          names.pop_back();
        }
      }
      else {
        names.back().first--;
        names[T - 2].first--;
        nb -= 2;
        plan += letters[names.back().second];
        plan += letters[names[T - 2].second];
        plan += " ";
        if (names.back().first == 0) {
          names.pop_back();
        }
      }
    }
    else {
      const int n = std::min(2, names.back().first);
      names.back().first -= n;
      nb -= n;
      plan += string(n, letters[names.back().second]) + " ";
      if (names.back().first == 0) {
        names.pop_back();
      }
    }
  }

  return plan;
}


//! Main function
int main()
{
  //! Read the first line of the file to know the total of test
  int T;
  cin >> T;

  //! Print the lines after that
  for (int k = 1; k <= T; k++) {

    //! Read the value
    int N;
    cin >> N;
    vector<int> senators(N);
    for (size_t n = 0; n < N; n++) {
      cin >> senators[n];
    }

    //! Save the result
    cout << "Case #" << k << ": " << senateEvacuation(senators) << endl;
  }

  return 0;
}
