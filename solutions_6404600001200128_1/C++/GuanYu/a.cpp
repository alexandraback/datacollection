#include <cstdio>
#define MAXN 1002
using namespace std;

// Mushroom
int mush[MAXN];

// Main
int main(void)
{
	int tc, cs, n, i, y, z, inv;

	// Read Input
	scanf("%d",&tc);
	for(cs=1;cs<=tc;cs++)
	{
		scanf("%d",&n);
		for(i=0;i<n;i++)
			scanf("%d",&mush[i]);
		y=0;
		for(i=1;i<n;i++)
			if(mush[i]<mush[i-1])
				y+=(mush[i-1]-mush[i]);
		z=0;
		inv=0;
		for(i=1;i<n;i++)
			if(mush[i-1]-mush[i]>inv)
				inv=mush[i-1]-mush[i];
		for(i=0;i<n-1;i++)
			if(mush[i]<inv) z+=mush[i];
			else z+=inv;

		// Output
		printf("Case #%d: %d %d\n",cs,y,z);
	}
	return 0;
}