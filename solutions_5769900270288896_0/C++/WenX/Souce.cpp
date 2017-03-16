#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <map>
#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

int tt, r, c, n;
char maps[20][20];
int best_ans = -1;

void dfs(int i,int ans)
{
	if (i == r*c)
	{
		if (n != 0)
			return;
		if (best_ans == -1)
			best_ans = ans;
		best_ans = min(best_ans, ans);
		return;
	}
	int ri, ci;
	ri = i / c;
	ci = i%c;

	maps[ri][ci] = 0;
	dfs(i + 1, ans);

	if (n > 0)
	{
		n--;
		maps[ri][ci] = 1;
		if (ri != 0 && maps[ri - 1][ci])
			ans++;
		if (ci != 0 && maps[ri][ci - 1])
			ans++;

		dfs(i + 1,ans);
		n++;
	}
}
int main()
{
	cin >> tt;
	for (int cc = 1; cc <= tt; cc++)
	{
		cin >> r >> c >> n;
		best_ans = -1;
		dfs(0, 0);
		cout << "Case #" << cc << ": " << best_ans << endl;
	}
	return 0;
}