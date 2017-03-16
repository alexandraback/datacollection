#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<string>

using namespace std;
int data[29];

int main()
{
	freopen("A-small-attempt0.in", "r", stdin);
	freopen("A-small-attempt0.out", "w", stdout);
	int t;
	cin >> t;
	for (size_t s = 0; s < t; s++)
	{
		int k,sum;
		sum = 0;
		cin >> k;
		for (size_t i = 1; i <= k; i++)
		{
			cin >> data[i];
			sum += data[i];
		}
		cout << "Case #" << s + 1 << ":";
		int max, id;
		while (sum)
		{
			cout << " ";
			max = 0;
			id = 0;
			for (size_t i = 1; i <= k; i++)
			{
				if (data[i]>max)
				{
					max = data[i];
					id = i;
				}
			}
			printf("%c", 'A' + id - 1);
			data[id]--;
			sum--;
			if (sum != 2 && sum != 0)
			{
				max = 0;
				id = 0;
				for (size_t i = 1; i <= k; i++)
				{
					if (data[i]>max)
					{
						max = data[i];
						id = i;
					}
				}
				printf("%c",'A' + id - 1);
				data[id]--;
				sum--;
			}
		}
		cout << "\n";
	}

}