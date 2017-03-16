#include <iostream>
using namespace std;

void readInput(int & q, int (&a) [16]) {
  cin >> q;
  for(int i = 0; i < 16; i++) {
    cin >> a[i];
  }
}

void solveCase() {
  int q1, q2;
  int a1[16];
  int a2[16];
  readInput(q1, a1);
  readInput(q2, a2);
  int inter;
  int count = 0;
  for(int i = (q1-1)*4;i<4*q1;i++) {
    for(int j = (q2-1)*4;j<4*q2;j++) {
      if(a1[i] == a2[j]) {
        inter = a1[i];
        count++;
      }
    }
  }
  if(count == 0) {
    cout << "Volunteer cheated!";
  
  } 
  else if(count > 1) {
    cout << "Bad magician!";
  }
  else {
    cout << inter;
  }
}

int main() {
  int T;
  cin >> T;
  for(int i = 1; i <= T; i++) {
    cout << "Case #" << i << ": ";
    solveCase();
    cout << endl;
  }
}