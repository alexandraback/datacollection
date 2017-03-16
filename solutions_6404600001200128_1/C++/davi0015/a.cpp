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

int main() {
  int T;
  cin >> T;

  forn(i, T) {
    int N;
    cin >> N;

    vector<int> m(N);
    forn(j, N) {
      cin >> m[j];
    }

    int met1 = 0, met2 = 0;
    int maxDiff = 0;
    forn(j, N-1) {
      if(m[j] > m[j + 1]) {
        met1 += m[j] - m[j + 1];
      }
      if(maxDiff < m[j] - m[j + 1]) {
        maxDiff = m[j] - m[j + 1];
      }
    }

    forn(j, N-1) {
      met2 += maxDiff > m[j] ? m[j] : maxDiff;
    }

    cout << "Case #" << i + 1  << ": " << met1 << " " << met2 << endl;
  }

  return 0;
}
