using namespace std;

#include "stdio.h"
#include "algorithm"

int Count[ 20 ];

int main()
{
	int ntc;

	scanf("%d", &ntc);
	for (int tc = 1; tc <= ntc; tc++)
	{
		int vAnswer;

		for (int i = 0; i < 20; i++) Count[ i ] = 0;

		scanf("%d", &vAnswer);
		for (int i = 1; i <= 4; i++)
			for (int j = 1; j <= 4; j++)
			{
				int x;
				scanf("%d", &x);
				if ( i == vAnswer ) Count[ x ]++;
			}

		scanf("%d", &vAnswer);
		for (int i = 1; i <= 4; i++)
			for (int j = 1; j <= 4; j++)
			{
				int x;
				scanf("%d", &x);
				if ( i == vAnswer ) Count[ x ]++;
			}

		int cc = count( Count, Count + 20, 2 );

		if ( cc == 0 ) printf("Case #%d: Volunteer cheated!\n", tc);
		else if ( cc == 1 )
		{
			int Answer;
			for (int i = 1; i <= 16; i++)
				if ( Count[ i ] == 2 )
					Answer = i;

			printf("Case #%d: %d\n", tc, Answer);
		}
		else printf("Case #%d: Bad magician!\n", tc);
	}

	return 0;
}
