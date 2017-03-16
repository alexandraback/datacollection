#include <list>
#include <map>
#include <set>
#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <memory.h>
#include <ctime>
#include <bitset>
#include <vector>
#include <string>

using namespace std;

#define ABS(a) (((a) > 0)? (a): -(a))
#define MIN(a, b) (((a) < (b))? (a): (b))
#define MAX(a, b) (((a) < (b))? (b): (a))
#define MFOR(i, a, n) for (int i = (a); i < (n); i++)
#define FOR(i, a, n) for (int i = (a); i <= (n); i++)
#define DFOR(i, a, n) for (int i = (a); i >= (n); i--)
#define SORT(a, first_element, last_element) sort(&(a)[(first_element)], &(a)[(last_element) + 1])
#define SQR(a) (a) * (a)
#define PI 3.14159265358979323846264
#define MEMS(a, b) memset((a), (b), sizeof(a))
#define MP make_pair
#define PB push_back
#define endl '\n'
#define LL long long
#define UN unsigned
#define Or ||
#define And &&
/////////////////////////////////////////////

char q[10050][10050];

int ans[20][20][20];

int check(int x, int y)
{
	if (q[x][y] == 1)
		return -1;
	return (q[x + 1][y] + q[x][y + 1] + q[x - 1][y] + q[x][y - 1]);
}

int ccheck(int x, int y)
{
	if (q[x][y] == 0)
		return -1;
	return (q[x + 1][y] + q[x][y + 1] + q[x - 1][y] + q[x][y - 1]);
}

int sol(int r, int c, int n)
{
	int ans = 0;
	int x = r * c;

	FOR(now, 0, 4)
	{
		FOR(i, 1, r)
		{
			FOR(j, 1, c)
			{
				if (check(i, j) == now)
				{
					ans += now;
					q[i][j] = 1;
				}
			}
		}
	}

	if (x == n)
		return ans;

	DFOR(now, 4, 0)
	{
		FOR(i, 1, r)
		{
			FOR(j, 1, c)
			{
				if (ccheck(i, j) == now)
				{
					ans -= now;
					x--;
					q[i][j] = 0;
					if (x == n)
						return ans;
				}
			}
		}
	}
}

void init()
{
ans[1][1][0] = 0;
ans[1][1][1] = 0;
ans[1][2][0] = 0;
ans[1][2][1] = 0;
ans[1][2][2] = 1;
ans[1][3][0] = 0;
ans[1][3][1] = 0;
ans[1][3][2] = 0;
ans[1][3][3] = 2;
ans[1][4][0] = 0;
ans[1][4][1] = 0;
ans[1][4][2] = 0;
ans[1][4][3] = 1;
ans[1][4][4] = 3;
ans[1][5][0] = 0;
ans[1][5][1] = 0;
ans[1][5][2] = 0;
ans[1][5][3] = 0;
ans[1][5][4] = 2;
ans[1][5][5] = 4;
ans[1][6][0] = 0;
ans[1][6][1] = 0;
ans[1][6][2] = 0;
ans[1][6][3] = 0;
ans[1][6][4] = 1;
ans[1][6][5] = 3;
ans[1][6][6] = 5;
ans[1][7][0] = 0;
ans[1][7][1] = 0;
ans[1][7][2] = 0;
ans[1][7][3] = 0;
ans[1][7][4] = 0;
ans[1][7][5] = 2;
ans[1][7][6] = 4;
ans[1][7][7] = 6;
ans[1][8][0] = 0;
ans[1][8][1] = 0;
ans[1][8][2] = 0;
ans[1][8][3] = 0;
ans[1][8][4] = 0;
ans[1][8][5] = 1;
ans[1][8][6] = 3;
ans[1][8][7] = 5;
ans[1][8][8] = 7;
ans[1][9][0] = 0;
ans[1][9][1] = 0;
ans[1][9][2] = 0;
ans[1][9][3] = 0;
ans[1][9][4] = 0;
ans[1][9][5] = 0;
ans[1][9][6] = 2;
ans[1][9][7] = 4;
ans[1][9][8] = 6;
ans[1][9][9] = 8;
ans[1][10][0] = 0;
ans[1][10][1] = 0;
ans[1][10][2] = 0;
ans[1][10][3] = 0;
ans[1][10][4] = 0;
ans[1][10][5] = 0;
ans[1][10][6] = 1;
ans[1][10][7] = 3;
ans[1][10][8] = 5;
ans[1][10][9] = 7;
ans[1][10][10] = 9;
ans[1][11][0] = 0;
ans[1][11][1] = 0;
ans[1][11][2] = 0;
ans[1][11][3] = 0;
ans[1][11][4] = 0;
ans[1][11][5] = 0;
ans[1][11][6] = 0;
ans[1][11][7] = 2;
ans[1][11][8] = 4;
ans[1][11][9] = 6;
ans[1][11][10] = 8;
ans[1][11][11] = 10;
ans[1][12][0] = 0;
ans[1][12][1] = 0;
ans[1][12][2] = 0;
ans[1][12][3] = 0;
ans[1][12][4] = 0;
ans[1][12][5] = 0;
ans[1][12][6] = 0;
ans[1][12][7] = 1;
ans[1][12][8] = 3;
ans[1][12][9] = 5;
ans[1][12][10] = 7;
ans[1][12][11] = 9;
ans[1][12][12] = 11;
ans[1][13][0] = 0;
ans[1][13][1] = 0;
ans[1][13][2] = 0;
ans[1][13][3] = 0;
ans[1][13][4] = 0;
ans[1][13][5] = 0;
ans[1][13][6] = 0;
ans[1][13][7] = 0;
ans[1][13][8] = 2;
ans[1][13][9] = 4;
ans[1][13][10] = 6;
ans[1][13][11] = 8;
ans[1][13][12] = 10;
ans[1][13][13] = 12;
ans[1][14][0] = 0;
ans[1][14][1] = 0;
ans[1][14][2] = 0;
ans[1][14][3] = 0;
ans[1][14][4] = 0;
ans[1][14][5] = 0;
ans[1][14][6] = 0;
ans[1][14][7] = 0;
ans[1][14][8] = 1;
ans[1][14][9] = 3;
ans[1][14][10] = 5;
ans[1][14][11] = 7;
ans[1][14][12] = 9;
ans[1][14][13] = 11;
ans[1][14][14] = 13;
ans[1][15][0] = 0;
ans[1][15][1] = 0;
ans[1][15][2] = 0;
ans[1][15][3] = 0;
ans[1][15][4] = 0;
ans[1][15][5] = 0;
ans[1][15][6] = 0;
ans[1][15][7] = 0;
ans[1][15][8] = 0;
ans[1][15][9] = 2;
ans[1][15][10] = 4;
ans[1][15][11] = 6;
ans[1][15][12] = 8;
ans[1][15][13] = 10;
ans[1][15][14] = 12;
ans[1][15][15] = 14;
ans[1][16][0] = 0;
ans[1][16][1] = 0;
ans[1][16][2] = 0;
ans[1][16][3] = 0;
ans[1][16][4] = 0;
ans[1][16][5] = 0;
ans[1][16][6] = 0;
ans[1][16][7] = 0;
ans[1][16][8] = 0;
ans[1][16][9] = 1;
ans[1][16][10] = 3;
ans[1][16][11] = 5;
ans[1][16][12] = 7;
ans[1][16][13] = 9;
ans[1][16][14] = 11;
ans[1][16][15] = 13;
ans[1][16][16] = 15;
ans[2][2][0] = 0;
ans[2][2][1] = 0;
ans[2][2][2] = 0;
ans[2][2][3] = 2;
ans[2][2][4] = 4;
ans[2][3][0] = 0;
ans[2][3][1] = 0;
ans[2][3][2] = 0;
ans[2][3][3] = 0;
ans[2][3][4] = 2;
ans[2][3][5] = 4;
ans[2][3][6] = 7;
ans[2][4][0] = 0;
ans[2][4][1] = 0;
ans[2][4][2] = 0;
ans[2][4][3] = 0;
ans[2][4][4] = 0;
ans[2][4][5] = 2;
ans[2][4][6] = 4;
ans[2][4][7] = 7;
ans[2][4][8] = 10;
ans[2][5][0] = 0;
ans[2][5][1] = 0;
ans[2][5][2] = 0;
ans[2][5][3] = 0;
ans[2][5][4] = 0;
ans[2][5][5] = 0;
ans[2][5][6] = 2;
ans[2][5][7] = 4;
ans[2][5][8] = 7;
ans[2][5][9] = 10;
ans[2][5][10] = 13;
ans[2][6][0] = 0;
ans[2][6][1] = 0;
ans[2][6][2] = 0;
ans[2][6][3] = 0;
ans[2][6][4] = 0;
ans[2][6][5] = 0;
ans[2][6][6] = 0;
ans[2][6][7] = 2;
ans[2][6][8] = 4;
ans[2][6][9] = 7;
ans[2][6][10] = 10;
ans[2][6][11] = 13;
ans[2][6][12] = 16;
ans[2][7][0] = 0;
ans[2][7][1] = 0;
ans[2][7][2] = 0;
ans[2][7][3] = 0;
ans[2][7][4] = 0;
ans[2][7][5] = 0;
ans[2][7][6] = 0;
ans[2][7][7] = 0;
ans[2][7][8] = 2;
ans[2][7][9] = 4;
ans[2][7][10] = 7;
ans[2][7][11] = 10;
ans[2][7][12] = 13;
ans[2][7][13] = 16;
ans[2][7][14] = 19;
ans[2][8][0] = 0;
ans[2][8][1] = 0;
ans[2][8][2] = 0;
ans[2][8][3] = 0;
ans[2][8][4] = 0;
ans[2][8][5] = 0;
ans[2][8][6] = 0;
ans[2][8][7] = 0;
ans[2][8][8] = 0;
ans[2][8][9] = 2;
ans[2][8][10] = 4;
ans[2][8][11] = 7;
ans[2][8][12] = 10;
ans[2][8][13] = 13;
ans[2][8][14] = 16;
ans[2][8][15] = 19;
ans[2][8][16] = 22;
ans[3][3][0] = 0;
ans[3][3][1] = 0;
ans[3][3][2] = 0;
ans[3][3][3] = 0;
ans[3][3][4] = 0;
ans[3][3][5] = 0;
ans[3][3][6] = 3;
ans[3][3][7] = 6;
ans[3][3][8] = 8;
ans[3][3][9] = 12;
ans[3][4][0] = 0;
ans[3][4][1] = 0;
ans[3][4][2] = 0;
ans[3][4][3] = 0;
ans[3][4][4] = 0;
ans[3][4][5] = 0;
ans[3][4][6] = 0;
ans[3][4][7] = 2;
ans[3][4][8] = 4;
ans[3][4][9] = 7;
ans[3][4][10] = 10;
ans[3][4][11] = 13;
ans[3][4][12] = 17;
ans[3][5][0] = 0;
ans[3][5][1] = 0;
ans[3][5][2] = 0;
ans[3][5][3] = 0;
ans[3][5][4] = 0;
ans[3][5][5] = 0;
ans[3][5][6] = 0;
ans[3][5][7] = 0;
ans[3][5][8] = 0;
ans[3][5][9] = 3;
ans[3][5][10] = 6;
ans[3][5][11] = 9;
ans[3][5][12] = 12;
ans[3][5][13] = 15;
ans[3][5][14] = 18;
ans[3][5][15] = 22;
ans[4][4][0] = 0;
ans[4][4][1] = 0;
ans[4][4][2] = 0;
ans[4][4][3] = 0;
ans[4][4][4] = 0;
ans[4][4][5] = 0;
ans[4][4][6] = 0;
ans[4][4][7] = 0;
ans[4][4][8] = 0;
ans[4][4][9] = 2;
ans[4][4][10] = 4;
ans[4][4][11] = 7;
ans[4][4][12] = 10;
ans[4][4][13] = 13;
ans[4][4][14] = 16;
ans[4][4][15] = 20;
ans[4][4][16] = 24;
}

void solution()
{
	int T;
	cin >> T;
	init();
	FOR(t, 1, T)
	{
		int r, c, n;
		cin >> r >> c >> n;
		if (r > c)
			swap(r, c);
		MEMS(q, 0);

		printf("Case #%d: %d\n", t, min(ans[r][c][n], sol(r, c, n)));
	}
}


/*-------------------*/

int main()
{
#ifdef Files
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
/*Test*/
//freopen("input.txt", "w", stdout);

double OcZ2X = clock();
#else
//freopen("unionday.in", "r", stdin);
//freopen("unionday.out", "w", stdout);
#endif

solution();

#ifdef Time
double P2HxQ = clock();
printf("\n*** Total time = %.3f sec ***\n", (P2HxQ - OcZ2X) / CLOCKS_PER_SEC);
#endif
}