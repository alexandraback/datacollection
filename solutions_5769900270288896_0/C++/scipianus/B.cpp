#include <iostream>
#include <fstream>
#define INF 1000000000
using namespace std;
int T, R, C, n, sol;
bool mat[20][20];

void Back(int x, int y, int now, int ramas)
{
	if(sol <= now)
		return;
	if(ramas == 0)
	{
		sol = min(sol, now);
		return;
	}
	if(ramas > (R - x) * C + C - y + 1)
		return;
	int newnow = now;
	mat[x][y] = false;
	if(y == C)
		Back(x + 1, 1, newnow, ramas);
	else
		Back(x, y + 1, newnow, ramas);
	mat[x][y] = true;
	if(mat[x - 1][y])
		newnow++;
	if(mat[x][y - 1])
		newnow++;
	if(y == C)
		Back(x + 1, 1, newnow, ramas - 1);
	else
		Back(x, y + 1, newnow, ramas - 1);
	mat[x][y] = false;
}

int main()
{
	ifstream fin("B.in");
	ofstream fout("B.out");
	fin >> T;
	for(int t = 1; t <= T; ++t)
	{
		fin >> R >> C >> n;
		sol = INF;
		Back(1, 1, 0, n);
		fout << "Case #" << t << ": " << sol << "\n";
	}
	fin.close();
	fout.close();
	return 0;
}
