#include <bits/stdc++.h>
using namespace std;

void test()
{
	int n;
	cin >> n;
	
	int maxdiff = 0;
	int sumdiff = 0;
	
	std::vector<int> data(n);
	for (size_t i = 0; i<n; i++)
	{
		cin >> data[i];
		if (i>0 && data[i]<data[i-1])
		{
			maxdiff = max(maxdiff, data[i-1]-data[i]);
			sumdiff += data[i-1] - data[i];
		}
	}
	
	int regular_total = 0;
	for (size_t i = 0; i<n-1; i++)
	{
		regular_total += min(data[i], maxdiff);
	}
	
	cout << sumdiff << " " << regular_total;
		
		
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
