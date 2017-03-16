#include <vector>
#include <string>
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <map>
#include <cmath>
#include <sstream>
using namespace std;

void Solve()
{
	int R, C, N;
	cin >> R >> C >> N;
	// Make sure that R as always less than C
	if (R > C)
	{
		swap(R, C);
	}
	int profiles = 1 << R;
	vector<vector<int>> last(N + 1, vector<int>(profiles, 2 * R * C)), current(N + 1, vector<int>(profiles, 0));
	last[0][0] = 0;
	for (int i = 1; i <= C; ++i)
	{
		//cout << i << endl;
		for (int NC = 0; NC <= N; ++NC)
		{
			for (int c = 0; c < profiles; ++c)
			{
				current[NC][c] = 2 * R * C;
			}
		}
		for (int NL = 0; NL <= N; ++NL)
		{
			for (int l = 0; l < profiles; ++l)
			{
				if (last[NL][l] < 2 * R * C)
				{
					//cout << NL << " " << l << " " << last[NL][l] << " " << 2 * R * C << endl;
					for (int c = 0; c < profiles; ++c)
					{
						// total tenants
						int total = NL;
						int neighbors = 1;
						while (neighbors <= c)
						{
							if ((c & neighbors) == neighbors)
							{
								++total;
							}
							neighbors *= 2;
						}
						if (total > N)
						{
							continue;
						}
						// count row neighbors
						neighbors = 3;
						int rowneighbors = 0;
						while (neighbors <= c)
						{
							if ((neighbors & c) == neighbors)
							{
								++rowneighbors;
							}
							neighbors *= 2;
						}
						// count between tow neighbors
						int betweenrow = 0;
						neighbors = 1;
						while (neighbors <= l && neighbors <= c)
						{
							if (((l & neighbors) == neighbors) && ((c & neighbors) == neighbors))
							{
								++betweenrow;
							}
							neighbors *= 2;
						}
						current[total][c] = min(current[total][c], last[NL][l] + rowneighbors + betweenrow);
						//cout << NL << " " << l << " " << c << " " << rowneighbors << " " << betweenrow << " " << total << " " << current[total][c] << " " << last[NL][l] << endl;
					}
 				}
			}
		}
		last = current;
	}
	int result = last[N][0];
	for (int i = 1; i < profiles; ++i)
	{
		result = min(result, last[N][i]);
	}
	cout << result;
}

int main() {
	int T;
	cin >> T;
	for (int i = 0; i < T; ++i)
	{
		cout << "Case #" << i + 1 << ": ";
		Solve();
		cout << endl;
	}
	return 0;
}