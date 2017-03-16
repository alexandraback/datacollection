#include <iostream>
#include <sstream>
#include <vector>
#include <cmath>
#include <set>

using namespace std;

stringstream out;

int *p;

void function()
{
	int n;
	cin >> n;
	p = new int[n];
	int sum = 0;

	for (int i = 0; i < n; i++)
	{
		cin >> p[i];
		sum += p[i];
	}


	while (1) {
		int b1 = 0, big1 = 0, b2 = 0, big2 = 0;
		for (int i = 0; i < n; i++)
		{
			if (p[i] > big2)
			{
				if (p[i] > big1)
				{
					big2 = big1;
					b2 = b1;
					big1 = p[i];
					b1 = i;
				}
				else if (sum != 3)
				{
					big2 = p[i];
					b2 = i;
				}
			}
		}
		if (big1 == 0 && big2 == 0) break;
		if (big2 == 0)
		{
			p[b1]--;
			sum--;
			out << (char)('A' + b1) << " ";
		}
		else
		{
			p[b2]--;
			p[b1]--;
			sum -= 2;
			out << (char)('A' + b2) << (char)('A' + b1) << " ";
		}
	}
	out << endl;
	delete[] p;
}

int main()
{
	ios_base::sync_with_stdio(0);
	int t;
	cin >> t;
	for (int i = 1; i <= t; i++)
	{
		out << "Case #" << i << ": ";
		function();
	}
	
	cout << out.str() << endl;
	return 0;
}