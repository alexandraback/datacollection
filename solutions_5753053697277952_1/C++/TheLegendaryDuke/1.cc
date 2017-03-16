#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  int c;
  cin >> c;
  for(int i = 0; i < c; i++) {
    cout << "Case #" << i+1 << ": ";
    int n;
    cin >> n;
    int people[n];
    for(int j = 0; j < n; j++) {
      cin >> people[j];
    }
    int sum = 0;
    for(int j = 0; j < n; j++) {
      sum += people[j];
    }
    while(sum != 0) {
      int maj = sum / 2 + 1;
//      cerr << maj << endl;
      bool s1 = false;
      for(int j = 0; j < n; j++) {
        if(people[j] >= maj) {
          cout << (char)('A' + j);
          people[j]--;
          sum--;
          s1 = true;
          break;
        }
      }
      if(!s1) {
        for(int j = 0; j < n; j++) {
          if(people[j] > 0) {
            cout << (char)('A' + j);
            people[j]--;
            sum--;
            break;
          }
        }
      }
      maj = sum / 2 + 1;
      for(int j = 0; j < n; j++) {
        if(people[j] >= maj) {
          people[j]--;
          cout << (char)('A' + j);
          sum--;
          break;
        }
      }
      if(sum != 0) {
        cout << " ";
      }else {
        cout << endl;
      }
    }
  }
}
