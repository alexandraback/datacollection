#pragma warning(disable : 4996)  
#include <vector>
#include <iostream>
#include <algorithm>
#include <fstream>
using namespace std;

vector<int> a;
int n,b;

bool check(long long x)
{
	long long num = 0;
	for (int i = 1; i <= b; i++)
		num += x / a[i] + 1;
	return num >= n;
}

long long ef(long long l, long long r)
{
	if (l == r) return l;
	long long mid = (l + r) >> 1;
	if (check(mid)) return ef(l, mid);
	return ef(mid + 1, r);
};

int main()
{
	ifstream fin("1.in");
	int t;
	fin >> t;
	ofstream fout("1.out");
	for (int Case = 1; Case <= t; Case++)
	{
		fin >> b >> n;
		a.resize(b + 1);
		long long maxa = 0;
		for (int i = 1; i <= b; i++)
		{
			fin >> a[i];
			if (a[i] > maxa)
				maxa = a[i];
		};
		long long time = ef(0, maxa*n);
		for (int i = 1; i <= b; i++)
		{
			n -= (time - 1) / a[i] + 1;
		}
		int ans=0;
		for (int i = 1; i <= b; i++)
		if (time%a[i] == 0)
		{
			n--;
			if (n == 0)
			{
				ans = i;
				break;
			}
		}
		fout << "Case #" << Case << ": " << ans << endl;
	}
	fin.close();
	fout.close();
	return 0;
}