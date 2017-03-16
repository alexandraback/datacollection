#include<iostream>
#include<cstdio>
#include<cstring>
#include<string.h>
#include<vector>
#include<algorithm>
using namespace std;

int a[5][5];
int b[5][5];

int main()
{
	freopen("input.in", "r", stdin);
	freopen("output.out", "w", stdout);
	int T; cin >> T;
	int Cas = 0;
	while (T--)
	{
		int r1; scanf("%d", &r1);
		for (int i = 1; i <= 4;++i)
		for (int j = 1; j <= 4; ++j)
			scanf("%d", &a[i][j]);
		int r2; scanf("%d", &r2);
		for (int i = 1; i <= 4;++i)
		for (int j = 1; j <= 4; ++j)
			scanf("%d", &b[i][j]);
		vector<int> v;
		for (int j = 1; j <= 4; ++j)
			v.push_back(a[r1][j]);
		for (int j = 1; j <= 4; ++j)
			v.push_back(b[r2][j]);
		sort(v.begin(), v.end());
		int cnt = 0;
		int ret = 0;
		for (int i = 0; i < v.size() - 1;++i)
		if (v[i] == v[i + 1]) ++cnt, ret = v[i];
		++Cas;
		printf("Case #%d: ", Cas);
		if (cnt == 1) printf("%d\n", ret);
		else if (cnt >= 2) printf("Bad magician!\n");
		else printf("Volunteer cheated!\n");
	}
}