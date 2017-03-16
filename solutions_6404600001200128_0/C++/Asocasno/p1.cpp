#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cstring>

using namespace std;

int main()
{
	int tests;
	cin >> tests;

	for(int a=0; a<tests; a++)
	{
		int qty;
		cin >> qty;
		vector<int> counts(qty, 0);

		for(int i=0; i<qty; i++)
		{
			cin >> counts[i];
		}

		long long ansOne = 0, ansTwo = 9999999999;

		int start = counts[0];
		for(int i=1; i<counts.size(); i++)
		{
			if(counts[i] > start)
			{
				start = counts[i];
			}
			else if(counts[i] < start)
			{
				ansOne += (start - counts[i]);
				start = counts[i];
			}
		}


		for(int i=0; i<10000; i++)
		{
			int start = counts[0];
			long long curAns = 0;
			bool valid = true;

			for(int j=1; (j<counts.size()) && valid; j++)
			{
				if(counts[j] > start)
				{
					curAns += min(i, start);
					start = counts[j];
				}
				else if(counts[j] == start)
				{
					curAns += min(i, start);
				}
				else
				{
					int minEaten = start - counts[j];
					if(minEaten > i)
					{
						valid = false;
					}
					curAns += min(i, start);
					start = counts[j];
				}
			}


			if(valid)
			{
//				if(curAns < ansTwo)
//				{
//					cout << "Case " << i << " generates: " << curAns << endl;
//				}
				ansTwo = min(curAns, ansTwo);
			}
		}


		cout << "Case #" << (a+1) << ": " << ansOne << " " << ansTwo << endl;
	}

	return 0;
}
