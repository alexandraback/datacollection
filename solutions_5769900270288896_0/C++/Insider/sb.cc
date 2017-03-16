#include<fstream>
#include<cstdlib>
#include<cstring>
using namespace std;

bool mat[20][20];

void dfs(int rest, int x, int y, int r, int c, int& ret)
{
  if (rest == 0)
  {
    int sum = 0;
    for (int i = 1; i <= r; i ++)
    {
      for (int j = 1; j <= c; j ++)
      {
        if (mat[i][j] && mat[i + 1][j]) sum ++;
        if (mat[i][j] && mat[i][j + 1]) sum ++;
      }
    }
    if (sum < ret)
      ret = sum;
    return;
  }

  for (int i = x; i <= r; i ++)
    for (int j = (i == x) ? y : 1; j <= c; j ++)
    {
      mat[i][j] = true;
      dfs(rest - 1, i, j + 1, r, c, ret);
      mat[i][j] = false;
    }
}

int compute(int r, int c, int n)
{
  memset(mat, 0, sizeof(mat));

  int ret = 0x7fffffff;
  dfs(n, 1, 1, r,  c, ret);

  return ret;
}


int main()
{
  ifstream cin("pb.in");
  ofstream cout("pb.out");

  int t, T;
  cin >> T;
  for (t = 1; t <= T; t ++)
  {
    int r, c, n;
    cin >> r >> c >> n;
    cout << "Case #" << t << ": " << compute(r, c, n) << endl;
  }
  return 0;
}
