#include<iostream>

using namespace std;

long long gcd(long long a, int b)
{
	if (a == 0 || b == 0)
		return a + b;
	return gcd(b, a%b);
}

long long lcm1(long long a, int b)
{
	return a*b / gcd(a, b);
}

void main()
{
	int T, B, N, i, lcm, cust;
	int a[100000], b[100000];
	cin >> T;
	for (int t = 1; t <= T; t++)
	{
		cin >> B >> N;

		for (i = 0; i < B; i++)
		{
			cin >> a[i];
			b[i] = a[i];
		}

		lcm = 1;
		for (i = 0; i < B; i++)
			lcm = lcm1(lcm, a[i]);

		cust = 0;
		for (i = 0; i < B; i++)
			cust += lcm / a[i];

		for (i = 1; i*cust < N; i++);

		N -= (i - 1)*cust;

		if (N <= B)
		{
			i = N - 1;
			N = 0;
		}
		else
			N -= B;

		while (N != 0)
		{
			for (i = 0; i < B && N != 0; i++)
			{
				a[i]--;
				if (a[i] == 0)
				{
					N--;
					a[i] = b[i];
					if (N == 0)
						break;
				}
			}
		}

		cout << "Case #" << t << ": " << i + 1 << endl;
	}
}