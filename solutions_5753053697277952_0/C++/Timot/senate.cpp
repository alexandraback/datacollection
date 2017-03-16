#include <iostream>
#include <iomanip>
#include <vector>
#include <list>
#include <queue>
#include <map>

using namespace std;

bool find(vector<int>& senators)
{
	int m = 0;
	int N = senators.size();
	for(int i = 0; i < N; i++)
	{
		m = max(m, senators[i]);
	}
	
	if(m == 0)
		return false;
	if(m == 1)
	{
		int _i = -1, _j = -1, _k = -1, c = 0;
		for(int i = 0; i < N; i++)
		{
			if(senators[i] == m)
			{
				c++;
				if(_i == -1)
					_i = i;
				else if(_j == -1)
					_j = i;
				else if(_k == -1)
					_k = i;
			}
		}

		if(c == 1)
		{
			cout << (char) ('A' + _i);
			senators[_i]--;
		}
		else if(c == 2)
		{
			cout << (char) ('A' + _i) << (char) ('A' + _j);
			senators[_i]--;
			senators[_j]--;
		}
		else if(c >= 3)
		{
			cout << (char) ('A'+ _i);
			senators[_i]--;
		}
		

		return true;
	}
	else
	{
		int d = 0;
		for(int i = 0; i < N; i++)
		{
			if(senators[i] == m && d < 2)
			{
				senators[i]--;
				d++;
				cout << (char) ('A' + i);
			}
		}
		return true;
	}
}




int main()
{
	int T;
	cin >> T;
	
	for(int t = 0; t < T; t++)
	{
		int N;
		cin >> N;
		vector<int> senators(N);
		for(int i = 0; i < N; i++)
			cin >> senators[i];
		
		cout << "Case #" << (t+1) << ": ";				
		while(find(senators))
			cout << " ";
		
		cout << endl;
	}


	return 0;
}
