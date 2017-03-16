#include <iostream>
#include "Solver.h"
using namespace std;

int main() {
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
	int R, C, N;
	cin >> R >> C >> N;
	cout << "Case #" << t << ": " << solve(R, C, N) << endl;
    }
}
