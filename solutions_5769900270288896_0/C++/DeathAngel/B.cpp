#include <stdio.h>
#include <string.h>
#include <math.h>
#include <algorithm>
#include <vector>
#include <climits>

using namespace std;

int main(int argc, char** argv)
{
	int T, R, C, N;
	scanf("%d", &T);
	for (int i = 1; i <= T; ++i)
	{
		scanf("%d %d %d", &R, &C, &N);
		vector<int> v;
		for (int j = 0; j < R*C - N; ++j)
		{
			v.push_back(0);
		}
		for (int j = 0; j < N; ++j)
		{
			v.push_back(1);
		}
		int min_count = INT_MAX;
		int len = v.size();
		do {
			int count = 0;
			// for (int j = 0; j < len; ++j)
			// {
			// 	printf("%d ", v[j]);
			// }
			// printf("\n");
			for (int j = 0; j < v.size(); ++j)
			{
				if (v[j] == 1)
				{
					int up = j + C;
					if (up < len && v[up] == 1)
					{
						// printf("up: %d ", j);
						++count;
					}
					int down = j - C;
					if (down >= 0 && v[down] == 1)
					{
						// printf("down: %d ", j);
						++count;
					}
					int left = j-1;
					if (left >= 0 && (j % C) != 0 && v[left] == 1)
					{
						// printf("left: %d ", j);
						++count;
					}
					int right = j+1;
					if (right < len && (right % C) != 0 && v[right] == 1)
					{
						// printf("right: %d ", j);
						++count;
					}
				}
				// printf("%d ", v[j]);
			}
			min_count = min(min_count, count);
		} while (next_permutation(v.begin(),v.end()));
		printf("Case #%d: %d\n", i, min_count/2);
	}
}