#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

struct GameString {
  vector<char> c;
  vector<int> l;
  int total;

  void get_total() {
    total = 0;
    for (auto li : l) {
      total += li;
    }
  }
};

vector<GameString> gs;

int main() {

  int T;
  cin >> T;

  for (int t = 1; t <= T; t++) {
    gs.clear();
    int N;
    cin >> N;
    string s;
    getline(cin, s);
    gs.resize(N);

    for (int i = 0; i < N; i++) {
      getline(cin, s);

      char prev = s[0];
      int num_prev = 1;
      for (int j = 1; j < int(s.size()); j++) {
        if (s[j] != prev) {
          gs[i].c.push_back(prev);
          gs[i].l.push_back(num_prev);
          prev = s[j];
          num_prev = 1;
        } else {
          num_prev++;
        }
      }
      gs[i].c.push_back(prev);
      gs[i].l.push_back(num_prev);

      gs[i].get_total();
    }

    // check if possible
    bool fegla_won = false;
    for (int i = 1; i < N; i++) {
      if (gs[i].c != gs[0].c) {
        fegla_won = true;
      }
    }

    int min_total = 0;

    if (!fegla_won) {
      for (int letter = 0; letter < int(gs[0].c.size()); letter++) {
        int min_total_letter = 1000000;

        for (int goal = 1; goal <= 100; goal++) {
          int total = 0;
          for (int i = 0; i < N; i++) {
            total += abs(gs[i].l[letter]-goal);
          }
          if (total < min_total_letter) {
            min_total_letter = total;
          }
        }

        min_total += min_total_letter;
      }
    }

    cout << "Case #" << t << ": ";
    if (fegla_won) {
      cout << "Fegla Won";
    } else {
      cout << min_total;
    }
    cout << endl;
  }

  return 0;
}
