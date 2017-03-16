#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int T;
	cin >> T;
	for (int case_num = 1; case_num <= T; ++case_num)
	{
		vector<bool> possible(17, false);
		int choice, card;
		cin >> choice;
		for (int row = 0; row < 4; ++row)
		{
			if (row != (choice - 1))
				cin >> card >> card >> card >> card;
			else
			{
				for (int col = 0; col < 4; ++col)
				{
					cin >> card;
					possible[card] = true;
				}
			}
		}

		cin >> choice;
		int answer = 0;
		for (int row = 0; row < 4; ++row)
		{
			if (row != (choice - 1))
				cin >> card >> card >> card >> card;
			else
			{
				for (int col = 0; col < 4; ++col)
				{
					cin >> card;
					if (possible[card])
						answer = (answer == 0) ? card : -1;
				}
			}
		}

		cout << "Case #" << case_num << ": ";
		if (answer == 0)
			cout << "Volunteer cheated!" << endl;
		else if (answer < 0)
			cout << "Bad magician!" << endl;
		else
			cout << answer << endl;
	}

	return 0;
}