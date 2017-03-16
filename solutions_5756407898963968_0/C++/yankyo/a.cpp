
#include <iostream>

using namespace std;

int main()
{
	int T;
	cin >> T;

	for (int t = 0; t < T; t++)
	{
		int pos[4], a, b;
		cin >> a;
		for (int r = 1; r <= 4; r++)
		{
			if (r == a)
			{
				for (int c = 0; c < 4; c++) cin >> pos[c];
			} else
			{
				int junk;
				for (int c = 0; c < 4; c++) cin >> junk;
			}
		}

		int res = 0;
		cin >> b;

		bool bm = false;

		for (int r = 1; r <= 4; r++)
		{
			if (r == b)
			{
				int card;
				for (int c = 0; c < 4; c++)
				{
					cin >> card;

					bool present = false;
					for (int i = 0; i < 4; i++) present = present || (pos[i] == card);
					
					if (present)
					{
						if (res == 0)
						{
							res = card;
						} else
						{
							bm = true;
						}
					}
				}
			} else
			{
				int junk;
				for (int c = 0; c < 4; c++) cin >> junk;
			}
		}

		cout << "Case #" << (t+1) << ": ";
		if (res == 0)
		{
			cout << "Volunteer cheated!";
		} else if (bm)
		{
			cout << "Bad magician!";
		} else
		{
			cout << res;
		}
		cout << endl;
	}

	return 0;
}
