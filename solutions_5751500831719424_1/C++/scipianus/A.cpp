#include <fstream>
#include <cstring>
#include <algorithm>
#include <cstdlib>
using namespace std;
int T, n, ns[110], v[110];
char s[110][110];

inline int Solve()
{
	char c;
	int i, ind[110], nr, sol = 0;
	for(i = 1; i <= n; ++i)
		ind[i] = 1;
	while(1)
	{
		nr = 0;
		for(i = 1; i <= n; ++i)
			if(ind[i] > ns[i])
				nr++;
		if(nr == n)
			break;
		if(nr > 0)
			return -1;
		c = s[1][ind[1]];
		for(i = 1; i <= n; ++i)
		{
			v[i] = 0;
			while(ind[i] <= ns[i] && s[i][ind[i]] == c)
			{
				v[i]++;
				ind[i]++;
			}
			if(v[i] == 0)
				return -1;
		}
		sort(v + 1, v + n + 1);
		for(i = 1; i <= n; ++i)
			sol += abs(v[i] - v[(n + 1) / 2]);
	}
	return sol;
}

int main()
{
	int t, i, rez;
	ifstream fin("A.in");
	ofstream fout("A.out");
	fin >> T;
	for(t = 1; t <= T; ++t)
	{
		fin >> n;
		for(i = 1; i <= n; ++i)
		{
			fin >> (s[i] + 1);
			ns[i] = strlen(s[i] + 1);
		}
		rez = Solve();
		if(rez >= 0)
			fout << "Case #" << t << ": " << rez << "\n";
		else
			fout << "Case #" << t << ": Fegla Won" << "\n";
	}
	return 0;
}
