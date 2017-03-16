#include <cstdio>
#include <set>
#include <algorithm>
using namespace std;
main(void)
{
	int t;
	scanf("%d",&t); 
	int r;
	int c;

	for(int tt=1;tt<=t;++tt)
	{
		printf("Case #%d: ",tt);
		set<int> s1,s2;
		scanf("%d",&r);
		for(int i=0;i<4;++i)
		{
			for(int j=0;j<4;++j)
			{
				scanf("%d",&c);
				if(i==r-1)
					s1.insert(c);
			}
		}
		scanf("%d",&r);
		for(int i=0;i<4;++i)
		{
			for(int j=0;j<4;++j)
			{
				scanf("%d",&c);
				if(i==r-1)
					s2.insert(c);
			}
		}
		set<int> intersect;
		set_intersection(s1.begin(),s1.end(),s2.begin(),s2.end(),
                  std::inserter(intersect,intersect.begin()));
		int n=intersect.size();
		if(n==1)
			printf("%d\n",*intersect.begin());
		else if(n==0)
			printf("Volunteer cheated!\n");
		else 
			printf("Bad magician!\n");

	}
}
