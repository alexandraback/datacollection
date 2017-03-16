#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int n1[5][5];
int n2[5][5];

int main()
{
	freopen("1.in", "r", stdin);
	freopen("1.out", "w", stdout);

	int T, cases = 1;
	int a, b, cnt, ans;

	scanf("%d", &T);
	while( T-- )
	{
		scanf("%d", &a);
		for( int i = 0; i < 4; ++i )
			for( int j = 0; j < 4; ++j )
				scanf("%d", &n1[i][j]);
		scanf("%d", &b);
		for( int i = 0; i < 4; ++i )
			for( int j = 0; j < 4; ++j )
				scanf("%d", &n2[i][j]);

		cnt = 0;
		a--, b--;
		for( int i = 0; i < 4; ++i )
			for( int j = 0; j < 4; ++j )	if( n1[a][i] == n2[b][j] )
			{
				cnt++;
				ans = n1[a][i];
			}	

		printf("Case #%d: ", cases++);
		if( cnt == 0 )
			puts("Volunteer cheated!");
		else if( cnt == 1 )
			printf("%d\n", ans);
		else
			puts("Bad magician!");
	}

	return 0;
}
