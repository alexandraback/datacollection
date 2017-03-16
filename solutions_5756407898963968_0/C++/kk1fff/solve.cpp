#include <iostream>
#include <fstream>
using namespace std;
void run(istream& in, int T) {
  int a1, a2, ans = -1;
  int buf[17]; // 1-16
  memset(buf, 0, sizeof(buf));
  in >> a1;
  // cout << "a1: " << a1 <<endl;
  for (int i = 0; i < 4; ++i) {
    for (int j = 0; j < 4; ++j) {
      int v;
      in >> v;
      if (i + 1 == a1) {
        // cout << v << " ";
        buf[v] = 1;
      }
    }
  }
  // cout <<endl;

  in >> a2;
  // cout << "a2: " << a2 <<endl;
  for (int i = 0; i < 4; ++i) {
    for (int j = 0; j < 4; ++j) {
      int v;
      in >> v;
      if (i + 1 == a2) {
        if (buf[v]) {
          // match
          // cout << v << " ";
          if (ans == -1) {
            ans = v;
          } else if (ans > 0) {
            ans = 17;
          }
        }
      }
    }
  }

  cout << "Case #" << T << ": ";
  if (ans == -1) {
    cout << "Volunteer cheated!";
  } else if (ans == 17) {
    cout << "Bad magician!";
  } else {
    cout << ans;
  }
  cout << endl;
}

int main() {
  ifstream in("in.txt");
  int T;
  in >> T;
  for (int i = 0; i < T; ++i) {
    run(in, i+1);
  }
}
