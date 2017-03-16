#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool PeopleInDanger(int P[27], int N)
{
	for (int i = 0; i < N; i++)
		if (P[i] > 0)
			return true;

	return false;
}

bool OddNumberOfMaxParties(int P[27], int N)
{
	int partiesWithPeople[1001] = {};
	for (int i = 0; i < N; i++)
		partiesWithPeople[P[i]]++;

	for (int people = 1000; people > 0; people--)
		if (partiesWithPeople[people])
		{
			return partiesWithPeople[people] % 2 != 0;
		}

	return false;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int T;
	cin >> T;

	for (int t = 1; t <= T; t++)
	{
		int N;
		cin >> N;

		int P[27] = {};
		for (int i = 0; i < N; i++) cin >> P[i];

		vector<string> evacuationPlan;
		while (PeopleInDanger(P, N))
		{
			if (OddNumberOfMaxParties(P, N))
			{
				int maxParty = 0;
				for (int i = 0; i < N; i++)
					if (P[i] > P[maxParty])
						maxParty = i;

				P[maxParty]--;

				string s(1, 'A' + maxParty);
				evacuationPlan.push_back(s);
			}
			else
			{
				int maxParty1 = 0;
				for (int i = 0; i < N; i++)
					if (P[i] > P[maxParty1])
						maxParty1 = i;

				int maxParty2 = 0;
				int maxVal = 0;
				for (int i = 0; i < N; i++)
					if (P[i] > maxVal && i != maxParty1)
					{
						maxParty2 = i;
						maxVal = P[i];
					}

				P[maxParty1]--;
				P[maxParty2]--;

				string s;
				s.push_back('A' + maxParty1);
				s.push_back('A' + maxParty2);
				evacuationPlan.push_back(s);
			}
		}

		cout << "Case #" << t << ": ";
		for (auto s : evacuationPlan) cout << s << " ";
		cout << endl;
	}
}