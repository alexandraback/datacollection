#include <iostream>
#include <string>

using namespace std;

int main()
{
	int t;
	int n;
	int m[10000] = {0};
	int answer1 = 0;
	int answer2 = 0;
	int max2 = 0;
	int temp;
	
	cin >> t;
	
	for(int i = 0; i < t; i++)
	{
		answer1 = 0;
		answer2 = 0;
		max2 = 0;
		cin >> n;
		
		for(int j = 0; j < n; j++)
			cin >> m[j];
		
		for(int j = 1; j < n; j++)
		{
			if(m[j - 1] > m[j])
			{
				temp = m[j - 1] - m[j];
				answer1 += temp;
				if(temp > max2)
					max2 = temp;
			}
		}
		for(int j = 0; j < n - 1; j++)
		{
			if(m[j] > max2)
				answer2 += max2;
			else
				answer2 += m[j];
		}
		
		
		cout << "Case #" << i + 1 << ": " << answer1 << " " << answer2 << "\n";
	}
	
	return 0;
}