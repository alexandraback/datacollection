#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <map>
#include <queue>
#include <ctime>
#include <cmath>

using namespace std;

#define forn(I,N) for (int I=0; I<N; I++)
#define fornd(I,N) for (int I=N-1; I>=0; I--)
#define forab(I,A,B) for (int I=A; I<=B; I++)
#define forabd(I,A,B) for (int I=B; I>=A; I--)
#define FOREACH(I,A) for (__typeof__(A)::iterator I=A.begin(); I<A.end(); I++)
#define pb push_back
#define mp make_pair

typedef long long int ll;

ll score(ll time, vector<ll> M) {
  ll val = 0;
  forn(i, M.size()) {
    val += 1 + time / M[i];
  }
  return val;
}

int main() {
  int T;
  cin >> T;

  forn(i, T) {
    ll B, N;
    cin >> B >> N;

    vector<ll> M(B);
    ll maxM = 1000000;
    forn(j, B) {
      cin >> M[j];
      maxM = M[j] * N > maxM ? M[j] * N : maxM;
    }

    ll a = 0;
    ll b = maxM;
    ll c;

    while(a != b) {
      c = (a + b) / 2;
      //cout << a << " " << b << " " << c << endl;
      if(score(c, M) >= N) {
        b = c;
      }
      else {
        a = c + 1;
      }
    }
    //cout << a << endl;

    ll buffer = 0;
    int ans = -1;
    forn(j, B) {
      buffer += (a + M[j] - 1) / M[j];
    }
    forn(j, B) {
      if(a % M[j] == 0) {
        buffer++;
        if(buffer == N) {
          ans = j + 1;
        }
      }
    }

    cout << "Case #" << i + 1 << ": " << ans << endl;
  }
}
