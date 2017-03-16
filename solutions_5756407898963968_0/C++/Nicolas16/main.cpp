#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <set>
#include <queue>

using namespace std;


int main()
{
	int T;
	int a, x;
	bool poss[17];
	
	scanf("%d", &T);
	
	for(int t = 1; t <= T; t++)
	{
		scanf("%d", &a);
	
		for(int i = 1; i <= 4; i++)
		{
			for(int j = 1; j <= 4; j++)
			{
				scanf("%d", &x);
				if(i == a) poss[x] = true;
				else poss[x] = false;
			}
		}
	
		scanf("%d", &a);
	
		for(int i = 1; i <= 4; i++)
		{
			for(int j = 1; j <= 4; j++)
			{
				scanf("%d", &x);
				if(i == a && poss[x]) poss[x] = true;
				else poss[x] = false;
			}
		}
	
		int rep;
		int comb = 0;
	
		for(int i = 1; i <= 16; i++)
		{
			if(poss[i])
			{
				rep = i;
				comb++;
			}
		}
		
		printf("Case #%d: ", t);
		if(comb == 1)
		{
			printf("%d\n", rep);
		}
		else if(comb == 0)
		{
			printf("Volunteer cheated!\n");
		}
		else printf("Bad magician!\n");
	}

	return 0;
}
