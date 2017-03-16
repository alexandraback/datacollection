#include <bits/stdc++.h>

#define For(i, a, b) for(int i=(a); i<(b); ++i)
#define INF 1000000000
#define MP make_pair

using namespace std;

typedef long long ll;
typedef pair <int, int> ii;

int A[30];

int main()
{
	//std::ios_base::sync_with_stdio(false);

	int tt, caso = 1;
	scanf("%d", &tt);

	while (tt--)
	{
		int n;
		scanf("%d", &n);

		int sum = 0;
		For(i, 0, n)
		{
			scanf("%d", &A[i]);
			sum += A[i];
		}

		printf("Case #%d: ", caso++);

		while (true)
		{
			bool equal = true;
			For(i, 0, n-1)
				if (A[i] != A[i+1])
				{
					equal = false;
					break;
				}

			if (equal)
				break;

			int maxi = 0, ind = -1;
			For(i, 0, n)
			{
				if (A[i] > maxi)
				{
					maxi = A[i];
					ind = i;
				}
			}

			printf("%c", ind+'A');
			--A[ind];
			--sum;
			if (sum/2 < A[ind])
			{
				printf("%c", ind+'A');
				--A[ind];
				--sum;
			}
			printf(" ");

			For(i, 0, n)
				assert(A[i] <= sum/2);
		}

		int i = 0;
		while (sum)
		{
			printf("%c", i+'A');
			--A[i];
			--sum;
			i = (i+1)%n;
			if ((n == 2 and A[i] > 0) or sum == 1)
			{
				printf("%c", i+'A');
				--A[i];
				--sum;
				i = (i+1)%n;
			}
			printf(" ");

			For(i, 0, n)
				assert(A[i] <= sum/2);
		}
		printf("\n");
	}

	return 0;
}