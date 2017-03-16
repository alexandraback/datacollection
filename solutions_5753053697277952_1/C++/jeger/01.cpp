#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <list>
#include <set>


using namespace std;

int main()
{
	int tt, sum = 0;
	cin >> tt;

	for(int t = 0;t<tt;t++)
	{
		sum = 0;
		int N;
		cin >> N;
		vector<int> parties(N);
		for(int i=0;i<N;i++)
		{
			cin >> parties[i];
			sum += parties[i];
			//cout << parties[i] << " ";
			//cout << sum << " ";
			//sum %= 2;
		}
		//cout << sum << endl;
		vector<char> v;
		v.reserve(sum);
		bool end = false;
		while(true)
		{
			int maxval = 0, maxplace = -1;
			for(int i=0;i<parties.size();i++)
			{
				if(parties[i]>maxval)
				{
					maxval = parties[i];
					maxplace = i;
				}
			}
			if(maxplace == -1)
			{
				break;
			}
			//cout << maxplace << endl;
			parties[maxplace]--;
			v.push_back(maxplace + 65);
		}
		cout << "Case #" << t+1 << ": ";
		int lol = sum%2;
		if(lol)
		{
			cout << v[0] << " ";
		}
		
		for(int i=lol;i<v.size();i++)
		{	
			cout << v[i];
			if(i%2 != lol) cout << " ";
		}
		cout << endl;

	}

	return 0;
}