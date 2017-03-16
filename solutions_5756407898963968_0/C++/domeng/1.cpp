#include <stdio.h>
#include <algorithm>
#include <set>
#include <vector>
using namespace std;
int main(int argc, char const *argv[])
{
	int T;scanf("%d",&T);
	for (int kase = 1; kase <= T; kase++)
	{
		vector<int> c[2];
		for (int t = 0;t <= 1;++t)
		{
			int r;
			int data[4][4];
			scanf("%d",&r);
			for (int y = 0; y < 4; y++)
			{
				for (int x =0; x < 4; x++)
					scanf("%d",&data[y][x]);
			}
			c[t] = vector<int>(data[r-1],data[r-1]+4);
			sort(c[t].begin(),c[t].end());
		}
		vector<int> res;
		set_intersection(c[0].begin(),c[0].end(),
						 c[1].begin(),c[1].end(),
						 std::back_inserter(res));
		printf("Case #%d: ",kase);
		if (res.size() == 0) 		printf("Volunteer cheated!\n");
		else if (res.size() == 1)	printf("%d\n",res[0]);
		else						printf("Bad magician!\n");	
	}
	return 0;
}