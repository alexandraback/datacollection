#include <iostream>
#include <iomanip>
#include <cstdio>
#include <vector>
#include <queue>
#include <set>
#include <stack>
#include <string.h>
#include <algorithm>
#include <fstream>
#include <cassert>
#include <limits>
#include <numeric>
#include <map>
#define NDEBUG
#ifdef NDEBUG
  #define DEBUG( x )
#else
  #define DEBUG( x )  x
#endif
using namespace std;
typedef long long int ll;
typedef long double ld;

class CaseSolver {
    public:
        void static precompute();
        void read(istream& is);
        void solve();
        void write(ostream& os);
    private:
        const static int maxM;
        int b;
        ll n;
        vector<int> m;
        int result;
};
const int CaseSolver::maxM = 100000;

void CaseSolver::precompute() {
}

void CaseSolver::read(istream& is) {
    is >> b >> n;
    m.resize(b);
    for (int i = 0; i < b; ++i) {
        is >> m[i];
    }
}

void CaseSolver::solve() {
    ll l = 0;
    ll r = n * maxM;
    while (l < r) {
        ll mid = l + (r - l)/2;
        ll cnt = 0;
        for (int i = 0; i < b; ++i) {
            cnt += mid / m[i] + 1;
        }
        if (cnt >= n) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }
    DEBUG (cout << "waiting for " << l << endl;)
    for (int i = 0; i < b; ++i) {
        DEBUG (cout << "barber [" << i << "]: " << (l - 1)  / m[i] + 1 << ", ";)
        n -= (l - 1) / m[i] + 1;
    }
    DEBUG(cout << endl;)
    for (result = 0; result < b && n > 0; ++result) {
        if (l % m[result] == 0) {
            n--;
        }
    }

}

void CaseSolver::write(ostream& os) {
    os << result;
}


int main() {
    CaseSolver::precompute();
    int numberOfCases;
	cin >> numberOfCases;
	for(int testCase = 1; testCase <= numberOfCases; ++testCase) {
        CaseSolver caseSolver;
        caseSolver.read(cin);
        caseSolver.solve();
        cout << "Case #" << testCase << ": ";
        caseSolver.write(cout);
        cout << "\n";
	}
}
