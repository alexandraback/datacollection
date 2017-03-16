#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;

int main() {
  int T;
  cin >> T;
  for(int i = 1; i <= T; ++i) {
    int N;
    int nrSenators[30];
    cin >> N;
    int total = 0;
    for(int j = 0; j < N; ++j) {
      cin >> nrSenators[j];
      total += nrSenators[j];
    }

    cout << "Case #" << i << ":";

    for(int j = 0; j < total; ++j) {
      int next = -1;
      int two = -1;
      int largest = 0;
      bool third = false;
      for(int h = 0; h < N; ++h) {
        if(nrSenators[h] > largest) {
          largest = nrSenators[h];
          next = h;
          two = -1;
          third = false;
        } else if(nrSenators[h] == largest) {
          if(two != -1) {
            third = true;
          }
          two = h;
        }
      }
      cout << " " << (char)('A' + next);
      --nrSenators[next];
      if(two != -1 && !(third && largest == 1)) {
        cout << (char)('A' + two);
        --nrSenators[two];
        ++j;
      }
    }
    cout << endl;

    // cout << " ";
    // for(int j = 0; j < N; ++j) {
    //   if(nrSenators[j]) {
    //     cout << (char)('A' + j);
    //   }
    // }
    // cout << endl;
  }
  return 0;
}