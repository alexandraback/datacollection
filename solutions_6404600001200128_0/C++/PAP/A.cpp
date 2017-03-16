#include<iostream>
#include<algorithm>

using namespace std;

int a[1005];

int main()
{
	int t;
	cin >> t;
	for(int tt = 1; tt <= t; tt++)
	{
		int n;
		cin >> n;
		int MAX = 0, sum = 0, sum2 = 0;;
		for(int i = 0; i < n; i++)
		{
			cin >> a[i];
			if(i > 0)
			{
				MAX = max(MAX, a[i - 1] - a[i]);
				sum += max(0, a[i - 1] - a[i]);
			}
		}
		for(int i = 0; i < n - 1; i++)
			sum2 += min(a[i], MAX);
		cout << "Case #" << tt << ": ";
		cout << sum << ' ' << sum2 << endl;
	}
	return 0;
}
