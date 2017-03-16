#pragma comment(linker, "/STACK:536870912")
#define _USE_MATH_DEFINES
#define _CRT_NO_DEPRECEATE
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <cstring>
#include <vector>
#include <utility>
#include <algorithm>
#include <functional>
#include <set>
#include <map>
#include <cmath>
#include <queue>
#include <memory.h>
#include <sstream>
#include <cassert>
#include <ctime>
#include <iomanip>


#define pb push_back
#define mp make_pair
#define sq(x) ((x)*(x))
#define INF (2e9)
#define EPS (1e-8)
#define PI (3.1415926535897932384626433832795)
#define _STRESS 0
#define y1 asdf_1
#define y0 asdf_2

using namespace std;

#define MOD(x) ((x) % (123456791LL))
#define BASE (1103LL)

int t, r1, r2;

class Solver
{
public:
	void init()
	{
#ifdef _MY_DEBUG
		freopen("input.txt", "rt", stdin);
		freopen("output.txt", "wt", stdout);
#else
		//freopen("ragnarok.in","rt", stdin);
		//freopen("ragnarok.out","wt", stdout);
#endif
	}

	int solve()
	{
		cin >> t;
		int r1[4], r2[4], tr[4], ti;
		vector<int> ans;
		for (int cs = 1; cs <= t; cs++)
		{
			cin >> ti;
			for (int i = 0; i < 4; i++)
			for (int j = 0; j < 4; j++)
			{
				if (i == ti - 1) cin >> r1[j];
				else cin >> tr[j];
			}
			cin >> ti;
			for (int i = 0; i < 4; i++)
			for (int j = 0; j < 4; j++)
			{
				if (i == ti - 1) cin >> r2[j];
				else cin >> tr[j];
			}
			ans.clear();
			for (int i = 0; i < 4; i++)
			for (int j = 0; j < 4; j++)
			{
				if (r1[i] == r2[j]) ans.pb(r1[i]);
			}
			cout << "Case #" << cs << ": ";
			if (ans.size() == 0)
			{
				cout << "Volunteer cheated!";
			}
			else if (ans.size() == 1)
			{
				cout << ans[0];
			}
			else
			{
				cout << "Bad magician!";
			}
			cout << endl;
		}

		return 0;
	}

	void finalize()
	{

	}
};

Solver solver;

class Tester
{
public:
	void randinit()
	{
	}

	void solve_slow()
	{
	}

	void stresstest()
	{
	}
};

#if _STRESS
Tester tester;
#endif

int main()
{
#if _STRESS
	tester.stresstest();
#else
	solver.init();
	solver.solve();
	solver.finalize();
#endif
	return 0;
}