/**
 * Problem: A
 */
#include <algorithm>
#include <assert.h>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <iterator>
#include <list>
#include <map>
#include <math.h>
#include <set>
#include <sstream>
#include <string>
#include <tuple>
#include <vector>
#include <stdexcept>
#include <typeinfo>

#define SZ(x) (int)(x.size())
#define F0(i,n) for(int i=0;i<n;i++)
#define F1(i,n) for(int i=1;i<=n;i++)

using namespace std;

template<typename T>
string to_string(const T &n) {
  ostringstream s;
  s << n;
  return s.str();
}


typedef vector<string> vs;
typedef long long ll;
typedef long long int lli;
typedef vector<int> vi;
typedef vector<vector<int> > vvi;
typedef vector<ll> vll;


const int inf = 100000;

string LETTERS = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

int P[1005];

int main(int argc, const char **argv) {
  int cases;
  cin >> cases;
  int N, tmp;

  auto max = [&]() {
    int max = 0;
    int k = -1;
    F0(i, N) {
      if (max<P[i]) {
        max = P[i];
        k = i;
        // cout << "k:" << k << endl;
      }
    }
    return k;
  };

  auto isM = [&]() {
    int total = 0;
    F0(i, N) {
      total += P[i];
    }
    if (total == 1) {
      return true;
    }
    return false;
  };

  auto sumP = [&] () {
    int total = 0;
    F0(i, N) {
      total += P[i];
    }
    return total;
  };

  F1(caseI, cases) {
    cin >> N;
    memset(P, 0, sizeof(P));
    F0(i, N) {
      cin >> tmp;
      P[i] = tmp;
    }

    cout << "Case #" << caseI << ":";
    int maxi;
    while (sumP() > 0) {
      cout << " ";
      maxi = max();
      cout << LETTERS[maxi];
      P[maxi] -= 1;

      maxi = max();
      P[maxi] -= 1;
      if (isM()) {
        P[maxi] += 1;
      } else {
        cout << LETTERS[maxi];
      }
    }

    // cout << max() << endl;
    cout << endl;

  }

  return 0;
}
