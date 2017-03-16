#include<iostream>
#include<string>
#include<fstream>
#include<algorithm>
#include<vector>
using namespace std;
int main()
{
	int t, smax = 0;
	ifstream infile("small.in");
	ofstream outfile("small.out");
	infile >> t;
	//cin >> t;
	for (int index = 0; index < t; index++)
	{
		int n;
		infile >> n;
		vector<int> v(n,0);
		int rate = 0;
		for (int i = 0; i < n; i++)
		{
			infile >> v[i];
			if (i - 1 >= 0 && v[i-1] - v[i] > rate)rate = v[i-1] - v[i];
		}
		int sum1 = 0;
		int sum2 = 0;
		for (int i = 1; i < n; i++)
		{
			if (v[i - 1] > v[i])sum1 += v[i - 1] - v[i];
			if (v[i - 1] - v[i] < rate)sum2 +=min(v[i - 1],rate); else sum2 += rate;
		}
		outfile << "Case #" << index + 1 << ": " << sum1 << " " << sum2 << endl;
		//outfile << "Case #" << index + 1 << ": " << str<< endl;
	}
	infile.close();
	outfile.close();
	return 0;
}