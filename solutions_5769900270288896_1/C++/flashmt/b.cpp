#include <bits/stdc++.h>
using namespace std;
const int oo = 27081993;
const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, 1, 0, -1};

int calc(int m, int n, int k, int parity)
{
  int cnt[5] = {0};
  for (int i = 0; i < m; i++)
    for (int j = 0; j < n; j++)
      if ((i + j) % 2 == parity)
      {
        int neighbor = 0;
        for (int k = 0; k < 4; k++)
        {
          int ii = i + dx[k], jj = j + dy[k];
          if (ii < 0 || ii >= m || jj < 0 || jj >= n) continue;
          neighbor++;
        }
        cnt[neighbor]++;
      }
      else k--;
  
  int res = 0;    
  for (int i = 1; i <= 4; i++)
  {
    int use = min(k, cnt[i]);
    res += use * i;
    k -= use;
  }
  return res;
}

int main()
{
  ios::sync_with_stdio(0);
	freopen("b-large.in", "r", stdin); 
	freopen("b-large.out", "w", stdout);
	int test;
	cin >> test;
	for (int noTest = 1; noTest <= test; noTest++)
	{
		cerr << "Running test " << noTest << endl;
    int m, n, k, ans = 0;
    cin >> m >> n >> k;
    if (k > (m * n + 1) / 2)
      ans = min(calc(m, n, k, 0), calc(m, n, k, 1));
		printf("Case #%d: %d\n", noTest, ans);
	}
}
