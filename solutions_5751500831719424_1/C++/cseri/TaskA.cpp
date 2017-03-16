#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <vector>
#include <deque>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <functional>
#include <utility>
#include <bitset>

#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <cassert>


//#include <boost/multiprecision/cpp_int.hpp> 
typedef long long ll;

using namespace std;



struct Task
{
	ll solve(int n, vector<string> input)
	{
		vector<int> inputat(n);
		vector<vector<int>> c(n);
		while (true) {
			char curr = input[0][inputat[0]];
			if ('*' == curr) break;
			for (int i = 0; i < n; ++i) {
				int u = 0;
				while (input[i][inputat[i]] == curr) {
					++inputat[i];
					++u;
				}
				if (0 == u) {
					cerr << "Cannot find " << curr << " in string " << (i + 1) << endl;
					return -1;
				}
				c[i].push_back(u);
			}
		}

		//debug
		/*for (int i = 0; i < n; ++i) {
			for (int j = 0; j < (int)c[0].size(); ++j) {
				cerr << setw(5) << c[i][j] << " ";
			}
			cerr << endl;
		}*/

		for (int i = 0; i < n; ++i) {
			char curr = input[i][inputat[i]];
			if ('*' != curr) {
				cerr << "String " << (i + 1) << " is longer" << endl;
				return -1;
			}
		}


		int penalty = 0;
		
		/*for (int i = 0; i < (int)c[0].size(); ++i) {
			penalty += abs(c[0][i] - c[1][i]);
		}*/

		for (int j = 0; j < (int)c[0].size(); ++j) {
			vector<int> foo;
			for (int i = 0; i < n; ++i) {
				foo.push_back(c[i][j]);
			}

			sort(foo.begin(), foo.end());
			int target = foo[foo.size() / 2];

			for (int i = 0; i < n; ++i) {
				penalty += abs(c[i][j] - target);
			}
		}

		return penalty;
	}
};



int main() {
	string fnsuffix = "_A-large.txt";
	ifstream f("input" + fnsuffix);
	ofstream o("output" + fnsuffix);
	istream &in = f;

	int tn = -1;
	in >> tn;
	if (tn < 0)
	{
		cerr << "Error reading input." << endl;
	}

	for (int ti = 0; ti < tn; ++ti)
	{
		int n;
		in >> n;

		vector<string> input;
		for (int i = 0; i < n; ++i)
		{
			string x;
			in >> x;
			x += "*";
			input.push_back(x);
		}

		Task t;
		auto sol = t.solve(n, input);

		string res = -1 == sol ? string("Fegla Won") : to_string(sol);

		o << "Case #" << (ti + 1) << ": " << res << endl;
		cerr << "Case #" << (ti + 1) << ": " << res << endl;
	}

	system("pause");

	return 0;
}


