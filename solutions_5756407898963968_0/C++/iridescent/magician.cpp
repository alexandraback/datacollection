#include <iostream>
#include <cstring>

using namespace std;

int possible[17];

int main()
{
	int T;
	cin >> T;
	for(int t = 1; t <= T; t++)
	{
		cout << "Case #" << t << ": ";
		memset(possible, 0, sizeof(possible));
		for(int i = 0; i < 2; i++)
		{
			int R;
			cin >> R;
			for(int r = 1; r <= 4; r++)
				for(int c = 1; c <= 4; c++)
				{
					int x;
					cin >> x;
					if(r == R) possible[x]++;
				}
		}
		bool bad = false;
		int val = -1;
		for(int i = 1; i <= 16; i++)
		{
			if(possible[i] == 2)
			{
				if(val != -1)
				{
					cout << "Bad magician!\n";
					bad = true;
					break;
				}
				val = i;
			}
		}
		if(val == -1) cout << "Volunteer cheated!\n";
		else if(!bad) cout << val << endl;
	}
}
