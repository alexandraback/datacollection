#pragma warning(disable : 4996)  
#include <vector>
#include <iostream>
#include <algorithm>
#include <fstream>
using namespace std;

int main()
{
	ifstream fin("1.in");
	int t;
	fin >> t;
	ofstream fout("1.out");
	for (int Case = 1; Case <= t; Case++)
	{
		int n;
		fin >> n;
		vector<int> a(n);
		for (int i = 0; i < n; i++)
		{
			fin >> a[i];
		}
		int ans1 = 0;
		int ans2 = 0;
		int maxgap = 0;
		for (int i = 1; i < n; i++)
		if (a[i] < a[i - 1])
		{
			ans1 += a[i-1]-a[i];
			if (a[i - 1] - a[i]>maxgap)
				maxgap = a[i - 1] - a[i];
		}
		for (int i = 0; i < n - 1; i++)
			ans2 += a[i]>maxgap ? maxgap : a[i];
		fout << "Case #" << Case << ": " << ans1 <<' ' << ans2 << endl;
	}
	fin.close();
	fout.close();
	return 0;
}