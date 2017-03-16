#include <iostream>
#include <stdio.h>
#include <limits.h>
#include <string.h>
#include <math.h>
#include <algorithm>
#include <string>
#include <map>
#include <stdlib.h>
#include <vector>

using namespace std;

/*struct data
{
	int customer, brand;
	bool operator <(const data &a){
		if(a.customer == this->customer)
			return a.brand > this->brand;
		return a.customer > this->customer;
	}
};
map<data, int> ma;
*/

string str[110];
string kind[110];
vector<int> ve[110];

int main (void)
{
	freopen("D:\\A-small-attempt1.in", "r", stdin);
	freopen("D:\\A-small-attempt1.out", "w", stdout);
	int t;
	while(scanf("%d", &t) != EOF)
	{
		for(int ca = 0; ca < t; ++ca)
		{
			printf("Case #%d: ", ca + 1);
			int m;
			scanf("%d", &m);
			for(int i = 0; i < m; ++i)
			{
				str[i].clear();
				cin >> str[i];
				kind[i].clear();
				ve[i].clear();
				for(int j = 0; j < str[i].length(); ++j)
				{
					if(kind[i].empty())
					{
						kind[i].push_back(str[i][j]);
						ve[i].push_back(1);
					}
					else
					{
						if(kind[i][kind[i].length() - 1] != str[i][j])
						{
							kind[i].push_back(str[i][j]);
							ve[i].push_back(1);
						}
						else
							ve[i][kind[i].length() - 1]++;
					}
				}
			}
			int flag = 0;
			for(int i = 0; i < m; ++i)
			{
				if(i == 0)
					continue;
				if(kind[i] != kind[i - 1])
				{
					flag = 1;
					break;
				}
			}
			if(flag)
			{
				printf("Fegla Won\n");
				continue;
			}
			int ans = 0;
			for(int i = 0; i < kind[0].length(); ++i)
			{
				int res = 100 * 100 + 1;
				for(int j = 1; j <= 100; ++j)
				{
					int nowres = 0;
					for(int k = 0; k < m; ++k)
					{
						nowres += abs(ve[k][i] - j);
					}
					if(nowres < res)
						res = nowres;
				}
				ans += res;
			}
			printf("%d\n", ans);
		}
	}
	return 0;
}