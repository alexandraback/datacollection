#include <bits/stdc++.h>

using namespace std;

int minV = 1000000;
bool o[16][16];
//int save[16][16];

int numWalls(int r, int c)
{
  int rightW = 0, downW = 0;
  for (int i = 0; i < r; ++i) {
    for (int j = 0; j < c; ++j) {
      if (j != c - 1 && o[i][j] && o[i][j + 1]) {
	++rightW;
      }
      if (i != r - 1 && o[i][j] && o[i + 1][j]) {
	++downW;
      }
    }
  }
  return rightW + downW;
}

void dfs(int r, int c, int n, int d, int p)
{
  if (d == n) {
    int v = min(minV, numWalls(r, c));
    if (minV > v) {
      minV = v;
//      for (int i = 0; i < r; ++i) {
//	for (int j = 0; j < c; ++j) {
//	  save[i][j] = o[i][j];
//	}
//      }
    }
    return;
  }

  for (int i = p + 1; i < r * c; ++i) {
    o[i / c][i % c] = true;
    dfs(r, c, n, d + 1, i);
    o[i / c][i % c] = false;
  }
}

int main()
{
  ios_base::sync_with_stdio(false);
  ifstream in("b.in");
  ofstream out("sol.out");
  int _c;
  in >> _c;

  for(int _cc = 1; _cc <= _c; ++_cc)	{
    out << "Case #" << _cc << ": ";

    int r, c, n;
    in >> r >> c >> n;

    dfs(r, c, n, 0, -1);

    // for (int i = 0; i < r; ++i) {
    //   for (int j = 0; j < c; ++j) {
    //     cout << save[i][j] << ' ';
    //   }
    //   cout << '\n';
    // }

    out << minV << '\n';
    minV = 1000000;
    for (int i = 0; i < r; ++i) {
      for (int j = 0; j < c; ++j) {
	o[i][j] = false;
      }
    }
  }

  return 0;
}

