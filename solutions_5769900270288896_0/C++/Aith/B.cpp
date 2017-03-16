#include <bits/stdc++.h>

using namespace std;

ifstream fin("B-small-attempt1.in");
ofstream fout("output.txt");

// #define fin cin
// #define fout cout

int Check(vector<vector<bool> >& vec, bitset<16> state, int r, int c)
{
	int val = 0;
	for (int i = 0; i < r; ++i)
	{
		for (int j = 0; j < c; ++j)
		{
			if(state[i * c + j])vec[i + 1][j + 1] = true;
			else vec[i + 1][j + 1] = false;
		}
	}
	for (int i = 1; i < r + 1; ++i)
	{
		for (int j = 1; j < c + 1; ++j)
		{
			if(vec[i][j] && vec[i][j + 1])val++;
			if(vec[i][j] && vec[i + 1][j])val++;
			if(vec[i][j] && vec[i][j - 1])val++;
			if(vec[i][j] && vec[i - 1][j])val++;
		}
	}
	return val / 2;
}

int main(int argc, char const *argv[])
{
	ios::sync_with_stdio(false);
	int t;
	fin>>t;
	int u = 0;
	while(u++ < t)
	{
		int r, c, n;
		fin>>r>>c>>n;
		vector<vector<bool> > vec(r + 2, vector<bool>(c + 2, false));
		bitset<16> version = 0;
		int ans = 1e9;
		for (int i = 0; i < 1 << (r * c); ++i)
		{
			version = i;
			int bits = 0;
			for (int j = 0; j < r * c; ++j)
			{
				if(version[j])bits++;
			}
			if(bits == n)ans = min(ans, Check(vec, version, r, c));
		}

		fout<<"Case #"<<u<<": "<<ans<<endl;
	}
	return 0;
}
