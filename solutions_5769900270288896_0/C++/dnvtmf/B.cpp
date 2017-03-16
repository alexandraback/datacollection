#include <cstdio>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <cstdlib>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <stack>
#include <algorithm>
#include <cmath>
#include <ctime>
#include <climits>
#define INF 1000000007
#define MP make_pair
const int NUM = 100010;
const double EPS = 1e-10, PI = acos(-1.0);
using namespace std;
typedef pair <int, int> P;
typedef long long LL;
typedef unsigned long long uLL;
int r, c, n;
int a[20][20];
int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1};
int unhappy;
void dfs(int i, int j, int t, int sum)
{
	if(i == r && j == 0 )
	{
		if(t == n)
			unhappy = min(unhappy, sum);
		return ;
	}
	int ii = i, jj = j + 1;
	if(jj == c) ii++, jj = 0;
	dfs(ii, jj, t, sum);
	if(t == n)
		return ;
	a[i][j] = 1;
	for(int k = 0; k < 4; k++)
	{
		int x = i + dx[k];
		int y = j + dy[k];
		if(0 <= x && x < r && 0 <= y && y < c && a[x][y] == 1)
			sum++;
	}
	dfs(ii, jj, t + 1, sum);
	a[i][j] = 0;
}
int main()
{
#ifdef ACM_TEST
 //   freopen("in.txt", "r", stdin);
//	freopen("in.txt", "w", stdout);
#endif
    int i, j;
    int T;
    scanf("%d", &T);
    for(int t = 1; t <= T; t++)
    {
        printf("Case #%d: ", t);
        scanf("%d%d%d", &r, &c, &n);
        if((r * c + 1) / 2 >= n)
            printf("0\n");
        else
        {
        	unhappy = INF;
        	dfs(0, 0, 0, 0);
			printf("%d\n", unhappy);
        }
    }
    return 0;
}
