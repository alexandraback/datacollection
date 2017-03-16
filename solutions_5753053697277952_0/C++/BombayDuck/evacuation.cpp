#include <iostream>

using namespace std;

int main()
{
	int count;
	cin >> count;

	for(int i = 0; i < count; i++)
	{
		int number;
		cin >> number;
		int *senetor = new int[number];
		int sum = 0;
		char party;

		for(int j = 0; j < number; j++)
		{
			cin >> senetor[j];
			sum += senetor[j];
		}

		cout << "Case #" << (i + 1) << ":";

		while(sum > 0)
		{
			if(sum == 3)
			{
				int max = 0;
				int loc = -1;
				for(int j = 0; j < number; j++)
				{
					if(max < senetor[j])
					{
						max = senetor[j];
						loc = j;
					}
				}
				senetor[loc]--;
				party = 'A' + loc;
				cout << " " << party;
				sum--;
			}
			else
			{
				int max = 0;
				int loc = -1;
				for(int j = 0; j < number; j++)
				{
					if(max < senetor[j])
					{
						max = senetor[j];
						loc = j;
					}
				}
				senetor[loc]--;
				party = 'A' + loc;
				cout << " " << party;
				sum--;
				max = 0;
				loc = -1;
				for(int j = 0; j < number; j++)
				{
					if(max < senetor[j])
					{
						max = senetor[j];
						loc = j;
					}
				}
				senetor[loc]--;
				party = 'A' + loc;
				cout << party;
				sum--;
			}

		}
		cout << endl;
	}
	return 0;
}
