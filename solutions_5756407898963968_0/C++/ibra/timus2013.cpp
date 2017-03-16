#include <stdio.h>
#include <math.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <sstream>
#include <queue>
#include <algorithm>
#include <iostream>
#include <stack>                                                                                                                                                                                  
#include <map>                                                                                                                                                                                    
#include <iostream>                                                                                                                                                                               
#include <set>                                                                                                                                                                                    
#include <cmath>                                                                                                                                                                                  
#include <cassert>                                                                                                                                                                                
#include <ctime>                                                                                                                                                                                  
#include <string>                                                                                                                                                                                 
using namespace std;    
int nextint(){int _;scanf("%d",&_);return _;}

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	int t = nextint();
	for(int test = 1; test <= t; test++)
	{
		int id1 = nextint()-1;
		vector<vector<int> > g1(4, vector<int> (4));
		for(int i = 0; i < 4; i++)
			for(int j = 0; j < 4; j++)
				g1[i][j] = nextint();
		
		int id2 = nextint()-1;
		vector<vector<int> > g2(4, vector<int> (4));
		for(int i = 0; i < 4; i++)
			for(int j = 0; j < 4; j++)
				g2[i][j] = nextint();

		set<int> res;
		for(int i = 0; i < 4; i++)
		{
			for(int j = 0; j < 4; j++)
			{
				if(g1[id1][i] == g2[id2][j])
				{
					res.insert(g1[id1][i]);
				}
			}
		}

		if(res.size() == 0)
		{
			printf("Case #%d: Volunteer cheated!\n", test);
		}
		else if(res.size() == 1)
		{
			printf("Case #%d: %d\n", test, *res.begin());
		}
		else
		{
			printf("Case #%d: Bad magician!\n", test);
		}
	}

	return 0;
}
