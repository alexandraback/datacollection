#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES

#include <algorithm>
#include <cstdio>
#include <ctime>
#include <map>
#include <string>
#include <cstring>
#include <vector>
#include <set>
#include <stack>
#include <queue>
#include <deque>
#include <cassert>
#include <iostream>
#include <cmath>
#include <sstream>
#include <complex>
#include <memory.h>

using namespace std;

#pragma comment(linker, "/STACK:128000000")

typedef long long int64;
typedef unsigned long long uint64;

#define y1 _dsfkjdsfksdj
#define y0 _sfsdkfdop

typedef unsigned uint;
typedef vector<int64> vi64;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> pii;
typedef pair<int,string> pis;
typedef pair<int64,int64> pii64;
typedef pair<int,pii> piii;
typedef pair<pii,pii> piiii;
typedef vector<pii> vpii;
typedef vector<vpii> vvpii;
typedef pair<double,int> pdi;
typedef pair<double,double> pdd;
typedef pair<int,string> pis;

int nt;
int c1, c2;
int a[4][4], b[4][4];

int main()
{	
	freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);

	scanf("%d", &nt);
	for (int tn = 1; tn <= nt; ++tn)
	{
		scanf("%d", &c1);
		for (int i = 0; i < 4; ++i)
			for (int j = 0; j < 4; ++j)
				scanf("%d", &a[i][j]);
		scanf("%d", &c2);
		for (int i = 0; i < 4; ++i)
			for (int j = 0; j < 4; ++j)
				scanf("%d", &b[i][j]);
		--c1, --c2;
		int cnt = 0;
		int ans = -1;
		for (int i = 0; i < 4; ++i)
		{
			for (int j = 0; j < 4; ++j)
			{
				if (a[c1][i] == b[c2][j])
				{
					++cnt;
					ans = a[c1][i];
				}
			}
		}
		printf("Case #%d: ", tn);
		if (!cnt)
		{
			printf("Volunteer cheated!\n");
			continue;
		}
		if (cnt > 1)
		{
			printf("Bad magician!\n");
			continue;
		}
		printf("%d\n", ans);
	}
	
    return 0;
}