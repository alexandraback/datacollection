#include <iostream>

using namespace std;

int P[26];

int main() {
  int T, N, numSenators;
  cin >> T;
  for(int i=0; i<T; i++) {
    numSenators = 0;
    cin >> N;
    for(int j=0; j<N; j++) {
      cin >> P[j];
      numSenators += P[j];
    }

    cout << "Case #" << (i+1) << ": ";

    while(numSenators > 0) {
      int P1 = 0;
      int s1 = P[0];
      for(int k=0; k<N; k++) {
        if(P[k] > s1) {
          P1 = k;
          s1 = P[k];
        }
      }

      int P2 = P1 == 0 ? 1 : 0;
      int s2 = P[P2];
      for(int k=0; k<N; k++) {
        if(k == P1) continue;
        if(P[k] > s2) {
          P2 = k;
          s2 = P[k];
        }
      }

      if(s2 != 0 && s2*2 > numSenators-1) {
        cout << (char)('A'+P1) << (char)('A'+P2);
        numSenators -= 2;
        P[P1]--;
        P[P2]--;
      } else {
        cout << (char)('A'+P1);
        numSenators -= 1;
        P[P1]--;
      }

      if(numSenators != 0)  cout << " ";
    }

    cout << endl;
  }
  return 0;
}