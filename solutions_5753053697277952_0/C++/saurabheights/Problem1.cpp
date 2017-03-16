#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

bool majorityRuleViolated(int* arr, int n)
{
	int majorityParty = 0;
	int totalElements = 0;
	for (int i = 0; i < n; i++)
	{
		totalElements += arr[i];
		if (arr[i] > arr[majorityParty])
		{
			majorityParty = i;
		}
	}

	if ((arr[majorityParty] << 1) > totalElements)
		return true;
	return false;
}

int main() {
	int testCases;
	long long int N, K; //Starting variables
	string a, b; //Starting variables
	cin >> testCases;

	for (int t = 1; t <= testCases; t++)
	{
		cin >> N;
		int partyMembersCount[50];
		int output = 0;
		int totalMembers = 0;
		cout << "Case #" << t << ": ";

		for (int i = 0; i < N; i++)
		{
			cin >> partyMembersCount[i];
			totalMembers += partyMembersCount[i];
		}

		while (totalMembers > 0)
		{
			int firstIndex = -1, secondIndex = -1;
			bool isSelected = false;

			for (int i = 0; i < N && !isSelected; i++)
			{
				if (partyMembersCount[i] > 0)
				{

					partyMembersCount[i]--;

					//Check for majority violation
					if (!majorityRuleViolated(partyMembersCount, N))
						isSelected = true;

					if (!isSelected)
					{
						partyMembersCount[i]++;
					}
					else
					{
						firstIndex = i;
						totalMembers--;
					}
				}
			}

			if (!isSelected)
			{
				for (int i = 0; i < N && !isSelected; i++)
				{
					if (partyMembersCount[i] > 0)
					{
						for (int j = 0; j < N && !isSelected; j++)
						{
							if ((partyMembersCount[j] > 0 && i != j) || (partyMembersCount[j] > 1 && i == j))
							{
								partyMembersCount[i]--;
								partyMembersCount[j]--;

								//Check for majority violation
								if (!majorityRuleViolated(partyMembersCount, N))
									isSelected = true;

								if (!isSelected)
								{
									partyMembersCount[i]++;
									partyMembersCount[j]++;
								}
								else
								{
									firstIndex = i;
									secondIndex = j;

									totalMembers -= 2;
								}
							}
						}
					}
				}
			}

			cout << (char)('A' + firstIndex);
			if (secondIndex != -1)
			{
				cout << (char)('A' + secondIndex);
			}

			if (totalMembers > 0)
				cout << " ";
		}
		cout << endl;
	}

	return 0;
}