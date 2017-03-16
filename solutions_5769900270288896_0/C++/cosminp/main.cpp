#include <fstream>
using namespace std;

int solve(int R, int C, int N)
{
	int best = 4 * R * C;

	for (int fill = 0; fill < (1 << (R*C)); fill++)
	{
		int c = 0;
		int tmp = fill;

		while (tmp)
		{
			tmp &= (tmp - 1);
			c++;
		}

		if (c != N) continue;

		c = 0;
		for (int i = 0; i < R; i++)
		{
			for (int j = 0; j < C; j++)
			{
				if (fill & (1 << (i*C + j)))
				{
					if ( (j > 0) && (fill & (1 << (i*C + j-1))) ) c++;
					if ( (i > 0) && (fill & (1 << ((i-1)*C + j))) ) c++;
				}
			}
		}

		if (c < best) best = c;
	}

	return best;
}

int main()
{
	ifstream 	f("in.txt");
	ofstream 	g("out.txt");
	int 		T, R, C, N;

	f >> T;
	for (int test = 1; test <= T; test++)
	{
		f >> R >> C >> N;
		g << "Case #" << test << ": " << solve(R, C, N) << endl;
	}

	return 0;
}
