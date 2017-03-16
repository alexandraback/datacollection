#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
struct st 
{
	int a;
	char c;
} ms[30]; 
int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	int t;
	cin >> t;
	for (int ii = 1; ii <= t; ii++)
	{
		cout << "Case #" << ii << ": ";
		int n, k;
		cin >> n;
		for (int i = 1; i <= n; i++)
		{
			cin >> ms[i].a;
			ms[i].c = 'A' + (i - 1);
		}
		st bf;
		for (int i = 1; i <= n; i++)
			for (int j = i + 1; j <= n; j++)
			{
				if (ms[j].a > ms[i].a)
				{
					bf = ms[j];
					ms[j] = ms[i];
					ms[i] = bf;
				}
			}
		if (ms[1].a == ms[2].a)
		{
			if (n > 2)
			{
				for (int i = 3; i <= n; i++)
					for (int j = 1; j <= ms[i].a; j++)
						cout << ms[i].c <<" ";
			}
			k = ms[1].a;
			for (int i = 1; i <= k; i++)
				cout << ms[1].c << ms[2].c << " ";
		}
		else //ms[1]>
		{
			k = ms[1].a - ms[2].a;
			for (int i = 1; i <= k / 2; i++)
				cout << ms[1].c << ms[1].c << " ";
			if (k % 2)
				cout << ms[1].c << " ";
			ms[1].a -= k;
			if (n > 2)
			{
				for (int i = 3; i <= n; i++)
					for (int j = 1; j <= ms[i].a; j++)
						cout << ms[i].c << " ";
			}
			k = ms[1].a;
			for (int i = 1; i <= k; i++)
				cout << ms[1].c << ms[2].c << " ";
		}
		cout << endl;
	}
	return 0;
}