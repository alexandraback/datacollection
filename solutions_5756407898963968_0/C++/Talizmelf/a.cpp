#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define FORi(m) for( int i = 0; i < (m); ++i )
#define FOR(i, M) for( int i = 0; i < (M); ++i )
#define FOR1(i, M) for( int i = 1; i <= (M); ++i )
#define DEBUGGING 1
#define CERRL() if (DEBUGGING) { std::cerr << '\n'; }
#define EXAM(var) if (DEBUGGING) { std::cerr << #var << ": " << (var) << '\n'; }
#define EXAMARR(var, size) if (DEBUGGING) { std::cerr << #var << ": "; for(int __i__ = 0; __i__ < (size); ++__i__) std::cerr << (var)[__i__] << " "; std::cerr << '\n'; }


constexpr int S = 4;

vector<int> read() {
	vector<int> a(S);
	int r;
	cin >> r;
	cin.ignore(9999, '\n');
	FOR1(i, S) {
		if (i == r) {
			FOR(j, S) {
				cin >> a[j];
			}
			cin.ignore(9999, '\n');
		}
		else {
			cin.ignore(9999, '\n');
		}
	}
	sort(a.begin(), a.end());
	return a;
}

void solve(int T) {
	FOR1(t, T) {
		vector<int> a = read();
		vector<int> b = read();
		vector<int> r(S);
		auto it = set_intersection(a.begin(), a.end(), b.begin(), b.end(), r.begin());
		r.resize(it-r.begin());
		
		cout << "Case #" << t << ": ";
		switch (r.size()) {
			case 0: cout << "Volunteer cheated!"; break;
			case 1: cout << r[0]; break;
			default: cout << "Bad magician!";
		}
		cout << endl;
	}
}


int main() {
	int T;
	cin >> T;
	solve(T);
}


