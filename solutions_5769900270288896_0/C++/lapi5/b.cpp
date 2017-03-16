#include<iostream>
#include<fstream>
#include<vector>
#include<stack>
#include<queue>
#include<algorithm>
#include<functional>
#include<bitset>


using namespace std;

int main()
{
	ifstream in("input.txt");
	ofstream out("output.txt");
	
	int T;
	in >> T;

	for(int kase = 1; kase <= T; ++kase)
	{
		int R, C, N;
		in >> R >> C >> N;
		if(R < C) swap(R, C);

		int ans = 987654321;
		for(int t = 0; t < (1 << R*C); ++t)
		{
			int cnt = 0;
			if(__builtin_popcount(t) != N) continue;
			for(int i = 0; i < R; ++i)
			{
				for(int j = 0; j < C; ++j)
				{
					int k = i * C + j;
					if((t & (1 << k)) == 0) continue;
					
					int k2;
					if(i != 0)
					{
						k2 = k - C;
						if((t & (1 << k2)) != 0) ++cnt;
					}
					if(i != R - 1)
					{
						k2 = k + C;
						if((t & (1 << k2)) != 0) ++cnt;
					}
					if(j != 0)
					{
						k2 = k - 1;
						if((t & (1 << k2)) != 0) ++cnt;
					}
					if(j != C - 1)
					{
						k2 = k + 1;
						if((t & (1 << k2)) != 0) ++cnt;
					}
				}
			}

			cnt /= 2;
			if(ans > cnt) ans = cnt;

		}

		out << "Case #" << kase << ": " << ans << endl;
	}

	in.close();
	out.close();
	return 0;
}

