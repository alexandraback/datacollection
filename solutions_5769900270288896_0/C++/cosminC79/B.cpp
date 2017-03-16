#include <cstdio>
#define INF 0x3f3f3f3f
#define NMAX 25
#define bit(i) (1 << (i - 1))
#define has_bit(mask, i) (mask & bit(i))
int tests, r, c, n;
bool A[NMAX][NMAX];

inline int nbits(int mask)
{
	return mask ? 1 + nbits(mask & (mask - 1)) : 0;
}

inline int min(int x, int y)
{
	return x < y ? x : y;
}

int main()
{
	freopen("B.in", "r", stdin);
	freopen("B.out", "w", stdout);
	
	scanf("%d", &tests);
	for (int test_no = 1; test_no <= tests; test_no++)
	{
		scanf("%d%d%d", &r, &c, &n);
		int res = INF;
		for (int i = 0; i < (1 << (r * c)); i++)
			if (nbits(i) == n)
			{
				for (int row = 1; row <= r; row++)
					for (int col = 1; col <= c; col++)
						A[row][col] = has_bit(i, (row - 1) * c + col) ? 1 : 0;
				
				int curr = 0;
				for (int row = 1; row <= r; row++)
					for (int col = 1; col < c; col++)
						if (A[row][col] && A[row][col + 1])
							curr++;
				
				for (int col = 1; col <= c; col++)
					for (int row = 1; row < r; row++)
						if (A[row][col] && A[row + 1][col])
							curr++;
				
				res = min(res, curr);
			}
			
		printf("Case #%d: %d\n", test_no, res);
	}
	return 0;
}

