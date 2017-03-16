#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <utility>
#include <vector>

using namespace std;
typedef unsigned long long ull;

int r,c,n;
int mat[16][16];
int best;

void count()
{
  int cnt = 0;
  for (int i=0; i<r; ++i)
  {
    for (int j=0; j<c; ++j)
    {
      if (mat[i][j] == 0) continue;
      if (i+1 < r) cnt += mat[i+1][j];
      if (j+1 < c) cnt += mat[i][j+1];
    }
  }
  if (cnt < best) best = cnt;
}

void magic(int x, int y, int left)
{
  //cout << x << " " << y << " " << left << endl;
  if (left == 0){
    count();
    return;
  }
  if (x == r) {
    magic(-1, y+1, left);
    return;
  }
  if (y == c) return;
  if (x >= 0) mat[x][y] = 1;
  for (int i=x+1; i<=r; ++i)
  {
    magic(i, y, left - (x>=0));
  }
  if (x>=0) mat[x][y] = 0;
}

void solve()
{
  scanf("%d %d %d", &r, &c, &n);
  memset(mat, 0, sizeof(mat));
  best = 1e9;
  magic(-1,0, n);
  printf("%d", best);
  return;
}

int main()
{
  int C;
  cin >> C;
  for (int i=1; i<=C; ++i)
  {

    printf("Case #%d: ", i);
    solve();
    printf("\n");    
  }
  return 0;
}
