#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <cctype>
#include <stack>
#include <queue>
#include <list>
#include <vector>
#include <map>
#include <sstream>
#include <cmath>
#include <bitset>
#include <utility>
#include <set>
#include <numeric>
#include <ctime>

#define INF 2147483647
#define PI acos(-1.0)

using namespace std;

vector < vector <bool> > A;
int r, c;

int check()
{
	int res = 0;
	for(int i = 0; i + 1 < r; ++i)
	{
		for(int j = 0; j + 1 < c; ++j)
		{
			if(A[i][j] && A[i][j + 1])
				++res;
			if(A[i][j] && A[i+1][j])
				++res;
		}
		if(A[i][c - 1] && A[i+1][c-1])
			++res;
	}

	for(int j = 0; j + 1 < c; ++j)
	{
		if(A[r-1][j] && A[r-1][j+1])
			++res;
	}
	return res;
}

int rec(int n, int i, int j)
{
	if(n == 0)
		return check();
	if(i == r)
		return INF;
	int res = INF;
	A[i][j] = true;
	res = min(res, rec(n - 1, i + (j + 1) / c, (j + 1) % c));
	A[i][j] = false;
	res = min(res, rec(n, i + (j + 1) / c, (j + 1) % c));
	return res;
}

int main(int argc, const char ** argv)
{
	freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);

	int t;
	cin >> t;

	for(auto tt = 1; tt <= t; ++tt)
	{
		int n;
		cin >> r >> c >> n;
		A.resize(r, vector<bool>(c));

		int res = rec(n, 0, 0);

		cout << "Case #" << tt << ": " << res << endl;
	}


	return 0;
}
