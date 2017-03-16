#include <iostream>
using namespace std;

int main()
{
	int T;
	cin >> T;
	for (int i = 0; i < T; i++)
	{
		int N;
		cin >> N;
		int sen[N];
		int sum = 0;
		for (int j = 0; j < N; j++)
		{
			cin >> sen[j];
			sum += sen[j];
		}

		int evac = 0;
		cout << "Case #" << i+1 << ": ";

		while (evac < sum)
		{
			int top = -1;
			for (int j = 0; j < N; j++)
			{
				if (sen[j] > top)
				{
					top = sen[j];
				}
			}
			int counttop = 0;
			for (int j = 0; j < N; j++)
			{
				if (sen[j] == top)
				{
					counttop += 1;
				}
			}

			int party1;
			int party2;
			char party1c;
			char party2c;

			if (counttop != 2)
			{
				for (int j = 0; j < N; j++)
				{
					if (sen[j] == top)
					{
						counttop += 1;
						party1 = j;
					}
				}
			
				party1c = party1 + 65;
				cout << party1c << " ";
				evac += 1;
				sen[party1] -= 1;
			}
			else
			{
				for (int j = 0; j < N; j++)
				{
					if (sen[j] == top)
					{
						counttop += 1;
						party1 = j;
					}
				}


				for (int j = N-1; j >= 0; j--)
				{
					if (sen[j] == top)
					{
						counttop += 1;
						party2 = j;
					}

				}

				party1c = party1 + 65;
				party2c = party2 + 65;
				cout << party1c << party2c << " ";
				evac += 2;
				sen[party1] -= 1;
				sen[party2] -= 1;
			}
		}

		cout << endl;
	}
	
}