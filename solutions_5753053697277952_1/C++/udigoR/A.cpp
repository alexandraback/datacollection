#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <set>
#include <list>
#include <tuple>
#include <string>
#include <algorithm>
#include <iomanip>

using namespace std;

int main() {
  int T;
  cin >> T;

  for (int testCase=0; testCase < T; ++testCase)
  {
    int N;

    cin >> N;

    multimap<int, char> set;
    int count = 0;
    char p = 'A';

    for (int i =0 ; i < N; ++i) {
      int x;
      cin >> x;
      count += x;
      set.emplace(x, p);
      p++;
    }

    cout << "Case #"<<testCase+1<<": ";

    while (!set.empty()) {
      auto biggest = (++set.rbegin()).base();
      int val1 = biggest->first;
      char part1 = biggest->second;
      set.erase(biggest);

      cout << part1;
      count--;
      int half = count / 2;

      if (val1 != 1)
        set.emplace(val1-1, part1);

      biggest = (++set.rbegin()).base();

      if (biggest->first > half) {
        val1 = biggest->first;
        part1 = biggest->second;
        set.erase(biggest);

        if (val1 != 1)
          set.emplace(val1-1, part1);

        cout << part1;
        count--;
      }

      cout << " ";
    }

    cout << endl;

  }

  return 0;
}