#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <string>
#include <complex>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <cstring>
#include <climits>
#include <ctime>

#include<unordered_map>
#include<unordered_set>
using namespace std;


//think later, use PC Power
int main(int a, char **ag)
{	
	int Case, cases = 0;
	scanf("%d" , &Case);
	int SKIP = -1, START = -1;
	if (a > 1 )
	{
		SKIP = atoi(ag[2]);
		START = atoi(ag[1]);
	}

	while (Case--)	
	{
		int ans;
		int b , n;
		cin >> b >> n;
		vector<long long> mk(b), free(b);
		for (int i = 0 ; i < b; ++i)
			cin >> mk[i];

		if (START!=-1)
		{
			if (++cases < START)
				continue;
			--cases;
		}

		if (SKIP!=-1)
		{
			if (++cases > SKIP)
				return 0;
			--cases;
		}

		for (int i = 0 ; i < n; ++i)
		{
			long long  min = LLONG_MAX;
			int bb = 0;
			for (int j = 0 ; j < b; ++j)
			{
				if (free[j] < min )
				{
					min = free[j];
					bb = j;
				}
			}
			free[bb] += mk[bb];
			ans = bb+1;
		}
		

		printf("Case #%d: %d\n" , ++cases, ans);
		
	}

	return 0;
}

