#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdio>
#include <string>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
#include <set>
#include <map>
#include <stack>
#include <ctime>
using namespace std;

#define inf 2147483647
#define eps 0.0000000001
#define e  2.718281828459
#define pi 3.1415926535897932
#define mod 1000000007

#define LL long long
#define ULL unsigned long long
#define LD long double
#define ULD unsigned long double
#define topcoder classname

const int N = 100005;

//	srand(time(NULL));
//	cout<<fixed<<setprecision(3)<<"\nExecution time="<<clock()/1000.0<<endl;
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);

int T;
int n, m, i, j, k, q, s, w, v, ans;
int b[17][17];
int ind[17];

int main()
{
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	//  printf("Case #%d: ", ++T);

	cin >> w;
	while (w--)
	{
		cin >> n >> m >> k;
		ans = 1e9;


		int c = pow(2, n*m);

		for (int i = 0; i < c; i++)
		{
			q = 0;
			for (int j = 1; j <= n*m; j++)
			{	
				if (ind[j] == 1)
					q++;
			}

			if (q == k)
			{
				for (int z = 1; z <= n; z++)
					for (int h = 1; h <= m; h++)
						b[z][h] = 0;

				for (int j = 1; j <= n*m; j++)
				{
					if (ind[j] == 1)
					{
						int xx, yy;
						if (j%m == 0)
							yy = m;
						else
							yy = j%m;
						xx = j / m;
						if (j%m != 0)
							xx++;

						b[xx][yy] = 1;
					}
				}
				s = 0;
				for (int z = 1; z <= n; z++)
				{
					for (int h = 1; h <= m; h++)
					{
						if (b[z][h] == 1)
						{
							if (z - 1 >= 1 && b[z - 1][h] == 1)
								s++;
							if (h - 1 >= 1 && b[z][h - 1] == 1)
								s++;
						}
					}
				}
				ans = min(ans, s);
			}

			for (int j = 1; j <= n*m; j++)
			{
				ind[j]++;
				if (ind[j] < 2)
					break;
				ind[j] = 0;
			}
		}

		printf("Case #%d: %d\n", ++T, ans);
	}
	return 0;
}
		
