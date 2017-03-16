#include <iostream>
#include <cstdio>
#include <set>

using namespace std;

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int T;
	cin >> T;
	for(int t = 1; t <= T; ++t)
	{
		int ans1, ans2;
		int grid1[4][4], grid2[4][4];
		cin >> ans1;
		for(int i = 0; i < 4; ++i)
			for(int j = 0; j < 4; ++j)
				cin >> grid1[i][j];
		cin >> ans2;
		for(int i = 0; i < 4; ++i)
			for(int j = 0; j < 4; ++j)
				cin >> grid2[i][j];
		--ans1, --ans2;
		set<int> ans;
		ans.insert(grid1[ans1], grid1[ans1] + 4);
		
		for(int i = 0; i < 4; ++i)
			if(i != ans2)
				for(int j = 0; j < 4; ++j)
					ans.erase(grid2[i][j]);
		
		cout << "Case #" << t << ": ";
		if(ans.size() == 1)
			cout << *ans.begin() << endl;
		else if(ans.size() == 0)
			cout << "Volunteer cheated!" << endl;
		else
			cout << "Bad magician!" << endl;
	}

	return 0;
}