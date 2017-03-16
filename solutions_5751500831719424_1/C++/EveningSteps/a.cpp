#include <utility>
#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;
typedef vector <int> cstr;

cstr compress (const string &a)
{
	cstr c;
	for (int i = 0; i < a.size(); ++i)
	{
		int cnt = 1;
		while (i < a.size() - 1 and a[i] == a[i+1])
			++cnt, ++i;
		c.push_back (cnt);
	}
	
	return c;
}

int test (vector <string> &v)
{
	int n = v.size(), total = 0, sz = -1;
	vector <cstr> strings (n);
	for (int i = 0; i < n; ++i)
	{
		strings[i] = compress (v[i]);
		if (sz == -1)
			sz = strings[i].size();
		else if (sz != strings[i].size())
			return -1;
	}
	
	int m = strings[0].size();
	vector <int> cur (n, 0);
	for (int j = 0; j < m; ++j)
	{
		for (int i = 0; i < n-1; ++i)
			if (v[i][cur[i]] != v[i+1][cur[i+1]])
				return -1;
		
		for (int i = 0; i < n; ++i)
			cur[i] += strings[i][j];
		
		int mdif = 1e5;
		for (int i = 0; i < n; ++i)
		{
			int curdif = 0;
			for (int k = 0; k < n; ++k)
				curdif += abs (strings[i][j] - strings[k][j]);
			
			mdif = min (mdif, curdif);
		}
		total += mdif;
	}
	
	return total;
}

int main()
{
	int n, t;
	cin >> t;
	for (int q = 0; q < t; ++q)
	{
		cin >> n;
		vector <string> v (n);
		for (int i = 0; i < n; ++i)
			cin >> v[i];
		
		int res = test (v);
		cout << "Case #" << q+1 << ": ";
		if (res == -1)
			cout << "Fegla Won" << endl;
		else cout << res << endl;
	}
	
	return 0;
}