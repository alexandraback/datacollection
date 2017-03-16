#include <fstream>
#include <algorithm>

#define MAX_N 16
#define INFINITY 1000000000

using namespace std;

ifstream fin("D:\\Input.txt");
ofstream fout("D:\\Output.txt");

int T, R, C, N, answer, grid[MAX_N][MAX_N];

int sum(int n)
{
	int result = 0;
	for(int i = 0; i < R * C; i++)
	{
		if((n  & (1 << i)) != 0)
			result++;
	}
	return result;
}

int main(int argc, const char* argv[])
{
	fin >> T;
	for(int i = 0; i < T; i++)
	{
		fin >> R >> C >> N;
		answer = INFINITY;
		for(int j = 0; j < (1 << (R * C)); j++)
		{
			if(sum(j) != N)
				continue;
			for(int k = 0; k < R; k++)
				for(int l = 0; l < C; l++)
					grid[k][l] = 0;
			for(int k = 0; k < R * C; k++)
			{
				if((j  & (1 << k)) != 0)
					grid[k / C][k % C] = 1;
			}
			int temp_sum = 0;
			for(int k = 0; k < R; k++)
				for(int l = 0; l < C; l++)
				{
					if(grid[k][l])
					{
						if(l - 1 >= 0 && l - 1 < C)
							temp_sum += grid[k][l - 1];
						if(l + 1 >= 0 && l + 1 < C)
							temp_sum += grid[k][l + 1];
						if(k + 1 >= 0 && k + 1 < R)
							temp_sum += grid[k + 1][l];
						if(k + 1 >= 0 && k + 1 < R)
							temp_sum += grid[k + 1][l];
					}
				}
			temp_sum /= 2;
			answer = min(answer, temp_sum);
		}
		fout << "Case #" << i + 1 << ": " << answer << "\n";
	}
	return 0;
}