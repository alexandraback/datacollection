#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <boost/lexical_cast.hpp>
using namespace std;

typedef unsigned int uint;

#define do_times(N) for (uint i = 0; i < N; i++)

string solve_case(istream &input) {
  // do stuff here
  uint n, m;
  uint temp;
  vector<uint> v(4);

  input >> n;
  do_times(4 * (n - 1)) input >> temp; // skip n - 1 rows
  do_times(4) {
    input >> temp;
    v.push_back(temp);
  }
  do_times(4 * (4 - n)) input >> temp; // skip remaining rows

  uint cnt = 0;
  uint card = 0;
  input >> m;
  do_times(4 * (m - 1)) input >> temp; // skip m - 1 rows
  do_times(4) {
    input >> temp;
    if (count(v.begin(), v.end(), temp) == 1) {
      card = temp;
      cnt++;
    }
  }
  do_times(4 * (4 - m)) input >> temp; // skip remaining rows
 
  if (cnt == 0) return "Volunteer cheated!";
  if (cnt > 1) return "Bad magician!";
  return boost::lexical_cast<string>(card);
}

int main(int argc, char** argv) {
  if (argc < 2) {
    cout << "Usage: " << argv[0] << " <filename>" << endl;
    return 0;
  }
  ifstream file(argv[1]);
  if (file == NULL) {
    cerr << "Can't open file " << argv[1] << endl;
  }
  uint N; // Number of cases
  file >> N;
  do_times(N) {
    string result = solve_case(file);
    cout << "Case #" << i + 1 << ": " << result << endl;
  }
}
