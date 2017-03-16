#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <queue>
#include <string>
#include <algorithm>
using namespace std;

void eatrows(unsigned int n)
{
	unsigned int temp = 0;
	for (unsigned int j = 0; j < n; ++j)
		for (unsigned int i = 0; i < 4; ++i)
			cin >> temp;
}

int main()
{
	unsigned int count = 0;
	
	cin >> count;
	
	for (unsigned int i = 0; i < count; ++i)
	{
		unsigned int
			answer = 0,
			temp = 0;
		
		cin >> answer;
		
		eatrows(answer - 1);
		
		vector<unsigned int>
			cards,
			results;
		
		for (unsigned int j = 0; j < 4; ++j)
		{
			cin >> temp;
			cards.push_back(temp);
		}
		
		eatrows(4 - answer);
		
		cin >> answer;
		
		eatrows(answer - 1);
		
		for (unsigned int j = 0; j < 4; ++j)
		{
			cin >> temp;
			for (unsigned int k = 0; k < cards.size(); ++k)
			{
				if (cards[k] == temp)
				{
					results.push_back(temp);
					break;
				}
			}
		}
		
		eatrows(4 - answer);
		
		if (!results.size())
		{
			cout << "Case #" << (i + 1) << ": Volunteer cheated!" << endl;
		}
		else if (results.size() == 1)
		{
			cout << "Case #" << (i + 1) << ": " << results[0] << endl;
		}
		else
		{
			cout << "Case #" << (i + 1) << ": Bad magician!" << endl;
		}
	}
	
	return 0;
}
