#include <algorithm>
#include <cctype>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <utility>
#include <vector>

using namespace std;

int bs(long long time, long long x, vector<long long> &v, long long &ans)
{
	vector<long long> va;
	for (int i=0; i<v.size(); i++)
	{
		if (time % v[i] == 0)
			va.push_back(i+1);
		x -= time / v[i] + (bool)(time % v[i]);
	}

	if (x <= 0) return 1;
	if (x <= va.size())
	{
		ans = va[x-1];
		return 0;
	}
	return -1;
}

int main()
{
	int cn; cin >> cn;
	for (int cc=1; cc<=cn; cc++)
	{
		long long n, x;
		cin >> n >> x;
		vector<long long> v(n);
		for (int i=0; i<n; i++)
			cin >> v[i];

		long long time = 0, one = 1;
		long long ans;
		for (int i=60; i>=0; i--)
		{
			int t = bs(time + (one << i), x, v, ans);
			if (t == 0) break;
			if (t < 0) time += one << i;
		}
		bs(time, x, v, ans);

		cout << "Case #" << cc << ": " << ans << endl;
	}
	return 0;
}
