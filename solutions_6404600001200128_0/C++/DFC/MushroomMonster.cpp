#include<iostream>
using namespace std;
int m[1000];
#define ma 10000000
int main()
{
	freopen("A-small-attempt1.in", "r", stdin);
	freopen("A-small.out", "w", stdout);
	int T; cin >> T; 
	for (int k = 1; k <= T; k++)
	{
		int n; cin >> n;
		for (int i = 0; i < n; i++)
			cin >> m[i];
		int constantSpeed = 0;
		for (int i = 0; i < n - 1; i++)
		{
			int interval = m[i] - m[i + 1];
			if (interval>0)
			{
				if (interval > constantSpeed)
					constantSpeed = interval;
			}
		}
		long long y=0, z=0;
		for (int i = 0; i < n-1; i++)
		{
			if (m[i] < constantSpeed)
				z += m[i];
			else
				z += constantSpeed;
		}
		for (int i = 0; i < n - 1; i++)
		{
			int interval = m[i] - m[i+1];
			if (interval>0)
				y += interval;
		}
		cout << "Case #" << k << ": " << y << " " << z << endl;
	}
	return 0;
}