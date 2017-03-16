#include <cstdio>
using namespace std;

// Grid
int grid[4][4];

// Two rows
int rows[2][4];

// Main
int main(void)
{
	int tc,cs,row,col,id,ans,ansc,i,j;

	// Read Input
	scanf("%d",&tc);
	for(cs=1;cs<=tc;cs++)
	{
		// First
		scanf("%d",&id);
		for(row=0;row<4;row++)
			for(col=0;col<4;col++)
				scanf("%d",&grid[row][col]);
		for(col=0;col<4;col++) rows[0][col]=grid[id-1][col];

		// Second
		scanf("%d",&id);
		for(row=0;row<4;row++)
			for(col=0;col<4;col++)
				scanf("%d",&grid[row][col]);
		for(col=0;col<4;col++) rows[1][col]=grid[id-1][col];

		// Compare
		ansc=0;
		for(i=0;i<4;i++)
			for(j=0;j<4;j++)
				if(rows[0][i]==rows[1][j])
				{
					ans=rows[0][i];
					ansc++;
				}

		// Output
		printf("Case #%d: ",cs);
		if(!ansc) printf("Volunteer cheated!\n");
		else if(ansc==1) printf("%d\n",ans);
		else puts("Bad magician!");
	}
	return 0;
}