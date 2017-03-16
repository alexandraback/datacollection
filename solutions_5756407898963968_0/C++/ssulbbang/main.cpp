#include <iostream>
#include <fstream>
#include <map>


using namespace std;


int main(int argc, char** argv)
{
	int T;


	cin >> T;
	for(int t = 1; t <= T; t++)
	{
		int answer1, answer2;
		map<int, int> count;

		cin >> answer1;
		for(int i = 0; i < 4; i++)
		{
			for(int j = 0; j < 4; j++)
			{
				int number;
				cin >> number;
				if(answer1 == i + 1)
				{
					count[number]++;
				}
			}
		}

		cin >> answer2;
		for(int i = 0; i < 4; i++)
		{
			for(int j = 0; j < 4; j++)
			{
				int number;
				cin >> number;
				if(answer2 == i + 1)
				{
					count[number]++;
				}
			}
		}

		int answer = -1;
		for(map<int, int>::iterator it = count.begin(); it != count.end(); it++)
		{
			if(it->second == 2)
			{
				if(answer == -1)
				{
					answer = it->first;
				}
				else
				{
					answer = -2; // Bad magician!
				}
			}
		}

		if(answer == -1)
		{
			cout << "Case #" << t << ": Volunteer cheated!" << endl;
		}
		else if(answer == -2)
		{
			cout << "Case #" << t << ": Bad magician!" << endl;
		}
		else
		{
			cout << "Case #" << t << ": " << answer << endl;
		}
	}
	return 0;
}