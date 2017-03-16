#include <iostream>

using namespace std;

int main()
{
	int repeat = 0;
	cin >> repeat;
	for (int i = 0; i < repeat; i++)
	{
		int frow, srow, row[4], count = 0, res;
		cin >> frow;
		for (int j = 0; j < 4; j++)
		{
			int tmp[4];
			if (frow == j + 1) 
				cin >> row[0] >> row[1] >> row[2] >> row[3];
			else 
				cin >> tmp[0] >> tmp[1] >> tmp[2] >> tmp[3];
		}

		cin >> srow;
		for (int j = 0; j < 4; j++)
		{
			int tmp[4];
			cin >> tmp[0] >> tmp[1] >> tmp[2] >> tmp[3];
			if (srow == j + 1)
			{
				for (int k = 0; k < 4; k++)
					for (int l = 0; l < 4; l++)
						if (tmp[k] == row[l]) 
						{
							count++;
							res = row[l];
						}
			}
		}
		if (count == 0) cout << "Case #" << (i + 1) << ": Volunteer cheated!" << endl;
		else if (count == 1) cout << "Case #" << (i + 1) << ": " << res << endl;
		else cout << "Case #" << (i + 1) << ": Bad magician!" << endl;
	}
	return 0;
}
