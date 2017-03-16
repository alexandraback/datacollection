#include<iostream>

using namespace std;

int tab[17];

int main()
{
    ios_base::sync_with_stdio(0);
    int t;
    cin >> t;
    int l = 1;
    while(t--)
    {
		int x;
		cin >> x;
		int z;
		for (int i = 1; i <= 4; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				cin >> z;
				if (i == x) tab[z]++;
			}
		}
		cin >> x;
		for (int i = 1; i <= 4; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				cin >> z;
				if (i == x) tab[z]++;
			}
		}
		int ans = 0;
		for (int i = 1; i <= 16; i++)
		{
			if (tab[i] == 2)
			{
				if (ans == 0) ans = i;
				else ans = -1;
			}
		}
		cout << "Case #" << l << ": ";
		if (ans == 0) cout << "Volunteer cheated!\n";
		else if (ans == -1) cout << "Bad magician!\n";
		else cout << ans << "\n";
		l++;
		for (int i = 1; i <= 16; i++) tab[i] = 0;
	}


    //system("pause");
    return 0;
}
