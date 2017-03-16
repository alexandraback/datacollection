#include <cstdio>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int t;
	scanf("%d", &t);
	
	for(int c=1;c<=t;c++)
	{
		set<int> set1, set2;		
		int line1, line2;
		int tmp;
		
		scanf("%d", &line1);
		for(int j=1;j<=4;j++)
		{
			for(int i=0;i<4;i++)
			{
				scanf("%d", &tmp);
				if(j==line1)
					set1.insert(tmp);
			}
		}
		
		scanf("%d", &line2);
		for(int j=1;j<=4;j++)
		{
			for(int i=0;i<4;i++)
			{
				scanf("%d", &tmp);
				if(j==line2)
					set2.insert(tmp);
			}
		}
		
		vector<int> inboth(4);
		inboth.resize(
			set_intersection(
				set1.begin(), set1.end(),
				set2.begin(), set2.end(),
				inboth.begin()
			) - inboth.begin()
		);
		
		printf("Case #%d: ", c);
		if(inboth.size() == 0)
			printf("Volunteer cheated!");
		else if(inboth.size() > 1)
			printf("Bad magician!");
		else
			printf("%d", inboth[0]);
			
		printf("\n");
	}
}
