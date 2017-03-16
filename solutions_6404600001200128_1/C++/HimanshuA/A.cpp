#include<iostream>

using namespace std;

void main()
{
	int T,N,a[1000],i,c1,c2,temp;
	cin >> T;
	for (int t = 1; t <= T; t++)
	{
		cin >> N;
		for (i = 0; i < N; i++)
			cin >> a[i];

		c1 = c2 = 0;

		for (i = 0; i < N - 1; i++)
		{
			if (a[i]>a[i + 1])
				c1 += a[i] - a[i + 1];
		}

		temp = 0;
		for (i = 0; i < N - 1; i++)
		{
			if (a[i]>a[i + 1] && a[i] - a[i + 1] > temp)
				temp = a[i] - a[i + 1];
		}

		for (i = 0; i < N - 1; i++)
		{
			if (a[i] <= temp)
				c2 += a[i];
			else
				c2 += temp;
		}

		cout << "Case #" << t << ": " << c1 << " " << c2 << endl;
	}
}