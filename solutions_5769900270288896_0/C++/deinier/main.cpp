#include <map>
#include <set>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <cctype>
#include <cstdio>
#include <string>
#include <vector>
#include <climits>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <iomanip>
#include <numeric>
#include <sstream>
#include <utility>
#include <iostream>
#include <algorithm>

using namespace std;

typedef long long int ll;
typedef pair<int, int> par;
#define mp make_pair

#define MAXN 20
#define MOD 1000000007

// Define Variables/
ll c, k, sol, fil, col, n, i, j, l, m, movX[4] = { 0, 1, 0, -1 }, movY[4] = {1,0,-1,0}, o, nextX, nextY, firstOne;
// Define Variables

bool t[MAXN][MAXN], M[MAXN][MAXN];

int Amount(ll numb)
{
	int ret = 0;
	
	for (j = 0; j < 32; j++)
	{
		ret += (numb >> j) & 1;

		if ((numb >> j) & 1)
			firstOne = j;
	}

	return ret;
}

ll Solve(int x)
{
	int pos = 0;

	ll ret = 0;
	
	for (l = 0; l < fil; l++)
	{
		for (m = 0; m < col; m++)
		{
			t[l][m] = (x >> pos) & 1;

			M[l][m] = 1;

			pos++;
		}
	}

	//for (l = 0; l < fil; l++)
	//{
	//	for (m = 0; m < col; m++)
	//	{
	//		cout << t[l][m] << " ";

	//		//pos++;
	//	}

	//	cout << endl;
	//}

	for (l = 0; l < fil; l++)
	{
		for (m = 0; m < col; m++)
		{
			if (t[l][m])
			{
				for (o = 0; o < 4; o++)
				{
					nextX = l + movX[o];

					nextY = m + movY[o];

					if (nextX >= 0 && nextX < fil && nextY >= 0 && nextY < col && M[nextX][nextY] && t[nextX][nextY])
					{
						ret++;
					}
				}

				M[l][m] = 0;
			}			
		}

		cout << endl;
	}
	
	return ret;
}

int main()
{
	ios::sync_with_stdio(false);

	ifstream in("B-small.in");
	ofstream out("B-small.out");

	in >> c;

	for (k = 1; k <= c; k++)
	{
		sol = 1000000000;
		
		in >> fil >> col >> n;

		for (i = 0; i < 65536; i++)
		{
			firstOne = 0;			
			
			if (Amount(i) == n && firstOne + 1 <= fil * col)
			{
				sol = min(sol, Solve(i));
			}
		}

		out << "Case #" << k << ": " << sol << endl;
	}

	//input.close();
	//output.close();

	return 0;
}