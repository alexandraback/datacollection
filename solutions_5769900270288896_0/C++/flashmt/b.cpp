#include <bits/stdc++.h>
using namespace std;
const int oo = 27081993;
const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, 1, 0, -1};

int main()
{
  ios::sync_with_stdio(0);
	freopen("b.in", "r", stdin); 
	freopen("b.out", "w", stdout);
	int test;
	cin >> test;
	for (int noTest = 1; noTest <= test; noTest++)
	{
		cerr << "Running test " << noTest << endl;
    int m, n, k;
    cin >> m >> n >> k;
    int ans = oo;
    for (int mask = 0; mask < 1 << (m * n); mask++)
      if (__builtin_popcount(mask) == k)
      {
        int score = 0;
        for (int i = 0; i < m; i++)
          for (int j = 0; j < n; j++)
            for (int k = 0; k < 4; k++)
            {
              int ii = i + dx[k], jj = j + dy[k];
              if (ii < 0 || ii >= m || jj < 0 || jj >= n) continue;
              if ((mask >> (i * n + j) & 1) && (mask >> (ii * n + jj) & 1))
                score++;
            }
        
        ans = min(ans, score);
      }
    
    
		printf("Case #%d: %d\n", noTest, ans / 2);
	}
}
