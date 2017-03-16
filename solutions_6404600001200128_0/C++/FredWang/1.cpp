#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#pragma warning(disable:4996)
using namespace std;
int answer1[1000000];
int answer2[1000000];
vector<int> v;
int max(int a, int b)
{
	return a > b ? a : b;
}
int wunaochi()
{
	int ans = 0;
	for (int i = 0; i < v.size()-1; ++i)
	{
		if (v[i] <= v[i + 1])continue;
		else ans += (v[i] - v[i + 1]);
	}
	return ans;
}
int hengdingsulv()
{
	int sulv = 0;
	for (int i = 0; i < v.size()-1; ++i)
	{
		if (v[i] < v[i + 1])continue;
		else
		{
			sulv = max(sulv, v[i] - v[i + 1]);
		}
	}
	int ans = 0;
	for (int i = 0; i < v.size()-1; ++i)
	{
		if (v[i] >= sulv)ans += sulv;
		else ans += v[i];
	}
	return ans;
}
int main()
{
	int n;
	ifstream f1;
	f1.open("C:\\Users\\ty\\Desktop\\codejam2015\\A.txt");
	f1 >> n;
	for (int i = 0; i < n; ++i)
	{
		int number;
		f1 >> number;
		for (int k = 0; k < number; ++k)
		{
			int e;
			f1 >> e;
			v.push_back(e);
		}
		answer1[i] = wunaochi();
		answer2[i] = hengdingsulv();
		v.clear();
	}
	ofstream f;
	f.open("C:\\Users\\ty\\Desktop\\codejam2015\\B.txt");
	for (int i = 0; i < n; ++i)
	{
		f << "case #" << i + 1 << ": " << answer1[i] << " " << answer2[i] << endl;
	}
	f.close();
	return 0;
}