// ================================================================================================
//  A - Magic Trick.cpp
//  Written by Luis Garcia, 2014
// ================================================================================================

#include <cstdio>
#include <cstring>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <string>
#include <iterator>
#include <numeric>
#include <iostream>

using namespace std;

#if defined _OJ_PROJECT
_BEGIN_PROBLEM(_GCJ14_01A, "GCJ14 01A")
#endif // _OJ_PROJECT

#define infinite_loop for (;;)

int main(
	) {
		static const double EPS = 1.e-6;

		int T, a, b;
		cin >> T;

		for (int _T = 1; _T <= T; ++_T) {
			vector<vector<int>> A(4, vector<int>(4)), B(4, vector<int>(4));
			cin >> a;
			for (int i = 0; i < 4; ++i) for (int j = 0; j < 4; ++j) cin >> A[i][j];
			cin >> b;
			for (int i = 0; i < 4; ++i) for (int j = 0; j < 4; ++j) cin >> B[i][j];

			vector<int> v;
			for (int i = 0; i < 4; ++i)
				for (int j = 0; j < 4; ++j)
					if (A[a - 1][i] == B[b - 1][j])
						v.push_back(A[a - 1][i]);

			if (v.size() == 1)
				cout << "Case #" << _T << ": " << v[0] << endl;
			else if (v.empty())
				cout << "Case #" << _T << ": Volunteer cheated!" << endl;
			else
				cout << "Case #" << _T << ": Bad magician!" << endl;
		}

		return 0;
	}

#if defined _OJ_PROJECT
_END_PROBLEM
#endif // _OJ_PROJECT

// ================================================================================================
//  End of file.
// ================================================================================================
