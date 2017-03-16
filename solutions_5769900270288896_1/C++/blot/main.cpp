#include <algorithm>
#include <cstdint>
#include <fstream>
#include <functional>
#include <iostream>
#include <string>
#include <utility>
#include <vector>
#include <set>

using namespace std;

//ifstream input("./test.txt");
ifstream input("./B-large.in");

ofstream output("./out2.txt");

int tmp(vector<int>& vect, int n) {
	int res = 0;

	for (int i = vect.size() - 1; i >= 0; i--)
	{
		int a = min(n, vect[i]);
		res += a * (i + 1);
		n -= a;
	}

	return res;
}

int solve(int n, int r, int c) {
	int spaces = c * r - n;

	if (r == 1 && c == 1)
		return 0;

	int worst = (c - 1) * (r - 1) * 2 + c + r - 2;

	vector<int> a = { 0, 0, 0, 0 };
	vector<int> b = { 0, 0, 0, 0 };

	for (int i = 0; i < r; i++)
		for (int j = 0; j < c; j++) {
			int ind = 3;
			if (i == 0 )
				ind--;

			if (i == r - 1)
				ind--;

			if (j == 0 )
				ind--;

			if (j == c - 1)
				ind--;

			if ((i + j) % 2) {
				a[ind]++;
			}
			else {
				b[ind]++;
			}
		}

	int ans = max(tmp(a, spaces), tmp(b, spaces));
	ans = worst - ans;
	return max(0, ans);
}

int main(int argc, char** argv)
{
	int t;
	input >> t;
	

	for (int i = 1; i <= t; i++) {
		int n, r, c;
		input >> r >> c >> n;
		output << "Case #" << i << ": " << solve(n, r, c) << endl;
	}

	return 0;
}