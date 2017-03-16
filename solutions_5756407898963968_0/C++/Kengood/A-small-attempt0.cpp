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

int cases , Case = 1;
////////////


int inMask()
{
	int t;
	cin >> t;
	int a = 0;

	for(int i = 0 ; i < 4; ++i)
	{
		for(int j = 0 ; j < 4; ++j)
		{
			int z; cin >>z;
			if(i == t-1)
			{
				a |= 1<<z;
			}
		}
	}

	return a;
}

int main()
{	
	scanf("%d" , &cases);	
	while( cases-- )
	{
		printf("Case #%d: " , Case++);   
		
		int a = inMask();
		int b = inMask();
		int target = a&b;
		if( target )
		{
			if( ( target & (target-1) ) )
			{
				puts("Bad magician!");
			}
			else
			{
				for(int i =0; i < 17; ++i)
				{
					if( target& (1<<i) )
						printf("%d\n" , i);
				}
			}
				
		}
		else
		{
			puts("Volunteer cheated!");
		}
		
		/*
		
		
		*/
	}

	

	return 0;
}

