#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <cstring>
#include <string>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#define LL long long
#define pi 3.1415926535897932384626433 
#define sqr(a) ((a)*(a))

using namespace std;

int a[10][10], b[10][10];

int main()
{
#ifndef ONLINE_JUDGE
    freopen("a.in", "r", stdin);
    freopen("a.out", "w", stdout);	
#endif
	int T; cin >> T;
	for (int t = 1; t <= T; t ++)
	{
		cout << "Case #" << t << ": ";
		int r1, r2;
		cin >> r1;
		for (int i = 1; i <= 4; i ++)
			for (int j = 1; j <= 4; j ++)
				cin >> a[i][j];
		cin >> r2;
		for (int i = 1; i <= 4; i ++)
			for (int j = 1; j <= 4; j ++)
				cin >> b[i][j];
		vector<int> ans; ans.clear();
		for (int i = 1; i <= 4; i ++)
		{
			int flag = 0;
			for (int j = 1; j <= 4; j ++)
				if (b[r2][j] == a[r1][i])
					flag = 1;
			if (flag) ans.push_back(a[r1][i]);
		}
		if (ans.size() < 1)
			cout << "Volunteer cheated!" << endl;
		else if (ans.size() > 1)
			cout << "Bad magician!" << endl;
		else cout << ans[0] << endl;
	}
	return 0;
}
