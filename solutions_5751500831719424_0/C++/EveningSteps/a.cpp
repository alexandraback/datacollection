#include <utility>
#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

int eval (string a, string b)
{
	int c = 0;
	vector <int> aa, bb;
	
	for (int i = 0; i < a.size(); ++i)
	{
		int cnt = 1;
		while (i < a.size() - 1 and a[i] == a[i+1])
			++cnt, ++i;
		aa.push_back (cnt);
	}
	
	for (int j = 0; j < b.size(); ++j)
	{
		int cnt = 1;
		while (j < b.size() - 1 and b[j] == b[j+1])
			++cnt, ++j;
		bb.push_back (cnt);
	}
	if (aa.size() != bb.size())
		return 1e7;
		
	int suma = 0, sumb = 0;
	for (int i = 0; i < aa.size(); ++i)
	{
		c += abs (aa[i] - bb[i]);
		if (aa[i] == bb[i] and aa[i] == 1)
		{
			if (a[suma] != b[sumb])
				return 1e7;
		}
		
		suma += aa[i], sumb += bb[i];
	}
				
	return c;
}

int main()
{
	int n, t;
	cin >> t;
	for (int q = 0; q < t; ++q)
	{
		cin >> n;
		vector <string> v (n);
		vector <vector <int> > dist (n, vector <int> (n));
		for (int i = 0; i < n; ++i)
			cin >> v[i];
		
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < n; ++j)
				dist[i][j] = eval (v[i], v[j]);
		/*
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < n; ++j)
				cout << dist[i][j] << " ";
			cout << endl;
		}
		*/
		
		int ms = 1e7;
		for (int i = 0; i < n; ++i)
		{
			int s = 0;
			for (int j = 0; j < n; ++j)
				s += dist[i][j];
			ms = min (ms, s);
		}
		
		cout << "Case #" << q+1 << ": ";
		if (ms >= 1e7)
			cout << "Fegla Won" << endl;
		else cout << ms << endl;
	}
	
	return 0;
}