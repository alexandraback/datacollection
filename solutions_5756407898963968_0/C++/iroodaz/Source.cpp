#include <iostream>

using namespace std;

int ary1[5][5],ary2[5][5];
int main()
{
	int T, g1, g2;
	cin >> T;
	for (int tt = 1; tt <= T; tt++)
	{
		cin >> g1;
		for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
			cin >> ary1[i][j];

		cin >> g2;
		for (int i = 0; i < 4;i++)
		for (int j = 0; j < 4; j++)
			cin >> ary2[i][j];

		int ans = 0;
		g1--; g2--;
		for (int i = 0; i < 4;i++)
		for (int j = 0; j < 4;j++)
		if (ary1[g1][i] == ary2[g2][j])
			ans = (ans ? 17 : ary1[g1][i]);
		cout << "Case #" << tt << ": ";
		if (ans == 0)
			cout << "Volunteer cheated!\n";
		else if (ans == 17)
			cout << "Bad magician!\n";
		else
			cout << ans << endl;
	}
}