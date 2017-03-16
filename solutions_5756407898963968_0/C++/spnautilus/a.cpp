#include <cstdio>
#include <cstring>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef pair <int, int> PII;
typedef vector <int> VI;

int T;

int A[20];

int main()
{
	scanf("%d", &T);
	for(int tt = 1; tt <= T; ++tt)
	{
		int i, j, k;

		for(k = 0; k < 2; ++k)
		{
			int a;
			scanf("%d", &a);
			--a;

			for(i = 0; i < 4; ++i)
			{
				for(j = 0; j < 4; ++j)
				{
					int b;
					scanf("%d", &b);

					if(i == a)
						++A[b];
				}
			}
		}

		printf("Case #%d: ", tt);

		int c = 0;
		int a;

		for(i = 1; i <= 16; ++i)
		{
			if(A[i] == 2)
			{
				++c;
				a = i;
			}
		}

		if(c == 0)
			printf("Volunteer cheated!\n");
		else if(c == 1)
			printf("%d\n", a);
		else
			printf("Bad magician!\n");

		memset(A, 0, sizeof(A));
	}

	return 0;
}
