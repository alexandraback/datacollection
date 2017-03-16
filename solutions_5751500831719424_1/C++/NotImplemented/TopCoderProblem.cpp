// BEGIN CUT HERE
// PROBLEM STATEMENT
// 
// We have an infinite strip of paper divided into a sequence of cells.
// All of the cells are initially white.
// We place a robot onto one of the cells.
// Each time the robot stands on a cell, it paints the cell red.
// 
// 
// 
// You are given an int N.
// The robot will now make N steps.
// In each step, the robot will move either one cell to the left or one cell to 
// the right, with equal probability.
// All random choices made by the robot are mutually independent.
// 
// 
// 
// Compute and return the expected number of red cells at the end.
// 
// 
// DEFINITION
// Class:RedPaint
// Method:expectedCells
// Parameters:int
// Returns:double
// Method signature:double expectedCells(int N)
// 
// 
// NOTES
// -Your return value must have an absolute or a relative error at most 10^(-9).
// 
// 
// CONSTRAINTS
// -N will be between 0 and 500, inclusive.
// 
// 
// EXAMPLES
// 
// 0)
// 0
// 
// Returns: 1.0
// 
// No movement. At the end there is a single red cell: the one with the robot.
// 
// 1)
// 1
// 
// Returns: 2.0
// 
// One step. The robot will choose a random direction and move. There will be 
// exactly two red cells: the one where it started and the one where it ended.
// 
// 
// 2)
// 2
// 
// Returns: 2.5
// 
// In the third step the robot will color a third cell red with probability 1/2. 
// Hence, the expected number of red cells is 0.5*2 + 0.5*3 = 2.5.
// 
// 
// 3)
// 4
// 
// Returns: 3.375
// 
// 
// 
// END CUT HERE
#include <algorithm>
#include <functional>
#include <iostream>
#include <sstream>
#include <string>
#include <utility>
#include <vector>
#include <cmath>
#include <queue>
#include <map>
#include <set>

using namespace std;

#define VT vector
typedef VT<int> VI;
typedef VT<VI> VVI;
typedef VT<string> VS;
typedef VT<double> VD;
#define REP(i,n) for(int _n=n, i=0;i<_n;++i)
#define FOR(i,a,b) for(int i=(a),_b=(b);i<=_b;++i)
#define ALL(c) c.begin(),c.end()
#define PB push_back
#define MP make_pair
#define FS first
#define SC second
#define SZ size() 

void solve(VS& words, int test)
{
	vector<vector<pair<char, int> > > table;

	REP(i, words.size())
	{
		vector<pair<char, int> > t;

		int last = 0;
		char c;
		REP(j, words[i].size())
		{
			if (j == 0)
			{
				c = words[i][j];
				last++;
			}
			else
			{
				if (words[i][j] != words[i][j-1])
				{
					t.push_back(MP(c, last));
					last = 0;
				}

				c = words[i][j];
				last++;
			}
		}

		if (last)
		{
			t.push_back(MP(c, last));
		}

		if (table.size())
		{
			bool ok = true;
			if (t.size() != table[0].size())
				ok = false;
			else
				REP(j, t.size())
					if (table[0][j].first != t[j].first)
						ok = false;

			if (!ok)
			{
				cout << "Case #" << test << ": Fegla Won\n";
				return;
			}
		}

		table.push_back(t);
	}

	int result = 0;
	REP(j, table[0].size())
	{
		VI chars;
		REP(i, table.size())
			chars.push_back(table[i][j].second);

		int mn = *min_element(ALL(chars));
		int mx = *max_element(ALL(chars));

		int best_sum = INT_MAX;

		FOR(k, mn, mx)
		{
			int s = 0;
			REP(j, chars.size())
				s += abs(chars[j] - k);

			if (s < best_sum)
			{
				best_sum = s;
			}
		}

		result += best_sum;
	}

	cout << "Case #" << test << ": " << result << "\n";

}


int main(int argc, char* argv[])
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);

	int T;
	cin >> T;

	REP(t, T)
	{
		int N;
		cin >> N;
		VS words;
		REP(i, N)
		{
			string str;
			cin >> str;
			words.push_back(str);
		}

		solve(words, t+1);
	}

}
