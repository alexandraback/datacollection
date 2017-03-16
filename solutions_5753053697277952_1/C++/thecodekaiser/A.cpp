// Author: thecodekaiser
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve(int CS)
{
	int N;
	cin >> N;

	vector < int > cnt(N);
	int total = 0;

	for(int i = 0; i < N; i++)
	{
		cin >> cnt[i];

		total += cnt[i];
	}

	printf("Case #%d: ", CS);

	while(total > 0)
	{
		// Can we choose one only?
		bool evac = false;

		for(int i = 0; i < N; i++)
		{
			if(!cnt[i])
				continue;

			bool flag = true;
			
			for(int j = 0; j < N; j++)
			{
				if(i == j and (cnt[j] - 1 > ((total-1)/2)))
				{
					flag = false; break;
				}
				else
				{
					if(cnt[j] > (total-1) / 2)
					{
						flag = false; break;
					}
				}
			}

			if(flag)
			{
				// We can just send this one
				cout << (char)(i + 'A') << " ";
				cnt[i]--;
				total -= 1;
				evac = true;
				break;
			}
		}

		if(!evac)
		{
			// We have to do it pair of two
			for(int i = 0; i < N; i++)
			{
				if(!cnt[i])
					continue;

				for(int j = 0; j < N; j++)
				{
					if(!cnt[j])
						continue;

					bool flag = true;

					for (int k = 0; k < N; k++)
					{
						if(i == k and j == k)
						{
							if(cnt[k] - 2 > (total - 2) / 2)
								{flag = false; break;}
						}
						else if(i == k or j == k)
						{
							if(cnt[k] - 1 > (total - 2) / 2)
							{
								flag = false; break;
							}
						}
						else
						{
							if(cnt[k] > (total - 2) / 2)
							{
								flag = false; break;
							}
						}
					}

					if(flag)
					{
						cout << (char)(i + 'A') << (char)(j + 'A') << " ";
						cnt[i]--; cnt[j]--;
						total -= 2;
						evac = true;
						break;
					}
				}

				if(evac) break;
			}
		}	
	}

	cout << "\n";


	return;
}

int main()
{
	int t, CS = 1;
	cin >> t;

	while(t--)
		solve(CS++);

	return 0;
}