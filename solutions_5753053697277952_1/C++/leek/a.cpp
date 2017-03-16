#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int T;
int P[26];

int main () {

  cin >> T;

  for(int tc=1;tc<=T;tc++) {
    for(int i=0; i<26; i++) P[i] = 0;
    int N;
    cin >> N;
    for(int i=0; i<N; i++) cin >> P[i];

    printf("Case #%d: ",tc);

    int xx = 0;
    for(int i=0; i<N; i++) {
      xx += P[i];
    }
    if(xx%2 == 1) {
      int k = 0;
      int mx = 0;
      for(int i=0;i<N;i++){
        if(P[i] > mx) {
          mx = P[i];
          k = i;
        }
      }
      P[k] --;
      cout << (char) ('A' + k) << ' ';
    }

    int itm = xx/2;
    for(int it = 0; it< itm;it++) {
      int bi = -1;
      int bv = -1, sv = -1;
      int si = -1;
      for(int i=0; i<N; i++) {
        if(P[i] ==0) continue;
        if(P[i] > bv) {
          sv = bv;
          si = bi;
          bv = P[i];
          bi = i;
        } else if (P[i] >= sv)  {
          sv = P[i];
          si = i;
        }
        if(P[i] * 2 > xx) {
          cout << "BAD" << endl;
        }
      }
      if(bv >= sv + 2) {
        cout << (char) ('A' + bi) << (char)('A'+bi) << ' ' ;
        P[bi] -=2;
      } else {
        cout << (char) ('A' + bi) << (char)('A'+si) << ' ' ;
        P[bi] --;
        P[si] --;
      }
      xx -= 2;
    }


    printf("\n");
  }

  return 0;
}