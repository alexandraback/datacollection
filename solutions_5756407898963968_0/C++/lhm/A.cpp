#include <iostream>
#include <string.h>
#include <stdio.h>

using namespace std;

int T,row1,row2;
int a[10][10],b[10][10];

int main()
{
	freopen("A-small-attempt3.in","r",stdin);
	freopen("A-small-attempt3.out","w",stdout);
	scanf("%d",&T);
	for ( int cas = 1; cas <= T; cas++ )
	{
		scanf("%d",&row1);
		for ( int i = 1; i <= 4; ++i )
			for ( int j = 1; j <= 4; ++j )
				scanf("%d",&a[i][j]);

		scanf("%d",&row2);
		for ( int i = 1; i <= 4; ++i )
			for ( int j = 1; j <= 4; ++j )
				scanf("%d",&b[i][j]);

		int ge = 0,number = 0;
		for ( int i = 1; i <= 4; ++i )
			for ( int j = 1; j <= 4; ++j )
				if ( a[row1][i] == b[row2][j] ) ++ge,number = a[row1][i];
		printf("Case #%d: ",cas);
		if ( ge == 1 ) printf( "%d\n",number);
		if ( ge > 1 ) printf("Bad magician!\n");
		if ( ge == 0 ) printf("Volunteer cheated!\n");

	}
	return 0;
}