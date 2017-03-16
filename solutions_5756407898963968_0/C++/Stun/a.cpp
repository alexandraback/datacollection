#include <iostream>
#include <algorithm>

using namespace std;

int main (int argc, char const *argv[])
{
	int T;
	cin >> T;
	for (int casen = 1; casen <= T; casen++) {
		int r[2];
		int V[2][4][4];
		cin >> r[0];
		for(size_t i = 0; i < 4; ++i)
		{
			for(size_t j = 0; j < 4; ++j)
			{
				cin >> V[0][i][j];
			}
		}
		cin >> r[1];
		for(size_t i = 0; i < 4; ++i)
		{
			for(size_t j = 0; j < 4; ++j)
			{
				cin >> V[1][i][j];
			}
		}
		
		int cnt = 0, ans;
		r[0]--,r[1]--;
		sort(&V[0][r[0]][0], &V[0][r[0]][4]);
		sort(&V[1][r[1]][0], &V[1][r[1]][4]);		
		for(size_t i = 0; i < 4; ++i)
		{
			if (binary_search(&V[1][r[1]][0],&V[1][r[1]][4],V[0][r[0]][i])) {
				cnt++;
				ans = V[0][r[0]][i];
			}
				
		}
		// cout << cnt << endl;
		std::cout << "Case #" << casen << ": ";
		if (cnt == 1) cout << ans << endl;
		else if (cnt == 0) cout << "Volunteer cheated!" << endl;
		else cout << "Bad magician!" << std::endl;
	}
	return 0;
}