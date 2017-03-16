#include <bits/stdc++.h>

using namespace std;

ifstream fin("A.in");
ofstream fout("output.out");

// #define fin cin
// #define fout cout

int main(int argc, char const *argv[])
{
	ios::sync_with_stdio(false);
	int t;
	fin >> t;
	int u = 0;
	while (u++ < t)
	{
		fout << "Case #" << u << ": ";
		int n;
		fin >> n;
		vector<int> vec(n);
		int sum = 0;
		for (int i = 0; i < n; ++i)
		{
			fin >> vec[i];
			sum += vec[i];
		}
		if (n > 2)
		{
			while(sum > 2)
			{
				int maxN = 0, maxI = -1;
				for (int i = 0; i < n; ++i)
				{
					if (maxN < vec[i])
					{
						maxN = vec[i];
						maxI = i;
					}
				}
				vec[maxI]--;
				sum--;
				fout << (char)((int)'A' + maxI) << " ";
			}
			for (int i = 0; i < n; ++i)
			{
				if (vec[i] != 0)
				{
					fout << (char)((int)'A' + i);
				}
			}
		}
		else
		{
			for (int i = 0; i < sum/2; ++i)
			{
				fout << "AB" << " ";
			}
		}
		fout << endl;
	}
	return 0;
}