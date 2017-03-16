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
//#define NDEBUG
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
        int n;
        vector<int> m;
        ll result1;
        ll result2;
};

void CaseSolver::precompute() {
}

void CaseSolver::read(istream& is) {
    is >> n;
    m.resize(n);
    for (int i = 0; i < n; ++i) {
        is >> m[i];
    }
}

void CaseSolver::solve() {
    result1 = result2 = 0;
    int maxd = 0;
    for (int i = 1; i < n; ++i) {
        result1 += max(0, m[i - 1] - m[i]);
        maxd = max(maxd, m[i - 1] - m[i]);
    }
    for (int i = 1; i < n; ++i) {
        result2 += min(m[i-1], maxd);
    }
}

void CaseSolver::write(ostream& os) {
    os << result1 << " " << result2;
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
