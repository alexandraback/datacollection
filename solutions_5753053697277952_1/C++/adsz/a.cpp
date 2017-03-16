#include <bits/stdc++.h>
using namespace std;

void test()
{
	int n;
	cin >> n;
	
	map<int /* senators */, set<int> /* party*/> data;
	for(size_t i = 0; i<n; ++i)
	{
		int x;
		cin >> x;
		data[x].insert(i);
	}
	
	for(;;)
	{
		if (data.size() == 0) break;
		
		int topCount = data.rbegin()->first;
		//cout << "Analyzing top = " << topCount << endl;
		if (topCount > 1)
		{
			if (data[topCount].size() > 1)
			{
				int party1 = *data[topCount].begin();
				int party2 = *(++data[topCount].begin());
				
				cout << (char)('A' + party1) << (char)('A' + party2) << " ";
				
				data[topCount].erase(party1);
				data[topCount-1].insert(party1);
				data[topCount].erase(party2);
				data[topCount-1].insert(party2);
			}
			else
			{
				int party = *data[topCount].begin();
				
				cout << (char)('A' + party) << " ";
				
				data[topCount].erase(party);
				data[topCount-1].insert(party);
			}
			
			if (data[topCount].size() == 0)
				data.erase(topCount);
		}
		else
		{
			//cout << "data[0].size = " << data[1].size() << endl;
			if (data[1].size() == 0) break;
			if (data[1].size() % 2 == 1)
			{
				int p1 = *data[1].begin();
				cout << (char)('A' + p1) << " ";
				data[1].erase(p1);
			}
			else
			{
				int p1 = *data[1].begin();
				int p2 = *(++data[1].begin());
				cout << (char)('A' + p1) << (char)('A' + p2)<< " ";
				data[1].erase(p1);
				data[1].erase(p2);
			}
		}
	}
}

int main()
{
	size_t c;
	std::cin >> c;
	for (size_t i = 1; i<=c; ++i)
	{
		std::cout << "Case #" << i << ": ";
		test();
		std::cout << std::endl;
	}
}
