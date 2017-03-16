#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <set>
#include <string>

using namespace std;

int main()
{
	int t;
	cin >> t;
	for (int tt = 1; tt <= t; tt++)
	{
		cout << "Case #" << tt << ": ";
		int n;
		cin >> n;
		vector<string> a(n);
		for (int i = 0; i < n; i++)
			cin >> a[i];
	   	//sort(a.begin(), a.end());
	   	int ans = 0;
	   	char c = '-';
	   	bool f = true;
	   	for (int i = 0; i < n; i++)
			if (c == '-' || c == a[i][0]) c = a[i][0];
			else f = false;
		if (!f) 
		{
			cout << "Fegla Won\n";
			continue;
		}
		int cur = 1;
		bool ff = true;
		while (true) 
		{
			
			ff = false;
			for (int i = 0; i < n; i++)
				if (cur <= a[0].length())
				{ 
					ff = true;
					break;
				}
			if (!ff) break;
			int t1 = 0, t2 = 0, t3 = 0;
			char c1 = a[0][cur-1];
			char c2 = '-';
			for (int i = 0; i < n; i++)
			{
				if (a[i][cur] == c1) t1++;
				else if (c2 == '-' || c2 == a[i][cur]) c2 = a[i][cur], t2++;
				else t3++;// cerr << c1 << " " << c2 << " " << a[i][cur] << endl;
			}
		//	cerr << ans << endl;
		//	cerr << "t3 " << t3 << endl;	
			if (t3 > 0) { f = false; break;}
			ans += min(t1, t2);
		//	cerr << "t1 t2:" << t1 << " " << t2 << endl;
			if (t1 != 0)
			for (int i = 0; i < n; i++)
			{
				if (a[i][cur] != c1) a[i].insert(a[i].begin() + cur, c1);
			//	cerr << a[i] << endl;
			}
			cur++;
			//cerr << cur << " " << a[0] << " " << a[0].length() << endl;
		}
		cerr << "ans\n";
		for (int i = 0; i < n; i++)
			if (a[i] != a[0]) f = false;
		if (!f) 
		{
			cout << "Fegla Won\n";
			continue;
		}

		cout << ans << "\n";
	}
}