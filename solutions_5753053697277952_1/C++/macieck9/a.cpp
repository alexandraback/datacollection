#include<iostream>

using namespace std;

int T[26];

int mx()
{
	int x = 0;
	for (int i = 0; i < 26; i++)
		if (T[i] > T[x])
			x = i;
	return x;
}

int main()
{
	ios_base::sync_with_stdio(0);
	int tt;
	cin >> tt;
	for (int t = 1; t <= tt; t++)
	{
		int n;
		cin >> n;
		for (int i = 0; i < n; i++)
			cin >> T[i];
		
		cout << "Case #" << t << ": ";
		while(true)
		{
			if (n > 2)
			{
				int m = mx();
				T[m]--;
				if (T[m] == 0) n--;
				cout << char(m + 'A') << " ";
			}
			else
			{
				int a = mx();
				int ma = T[a];
				T[a] = 0;
				int b = mx();
				int mb = T[b];
				T[b] = 0;
				while(ma > mb)
				{
					cout << char(a + 'A') << " ";
					ma--;
				}
				
				while(ma < mb)
				{
					cout << char(b + 'A') << " ";
					mb--;
				}
				
				while(ma > 0)
				{
					cout << char(a + 'A') << char(b + 'A') << " ";
					ma--;
				}
				break;
			}
		}
		cout << "\n";
	}
	
	
	return 0;
}
