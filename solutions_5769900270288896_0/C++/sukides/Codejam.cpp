#include "stdafx.h"
#include <string>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <fstream>
#include <sstream>
#include <iomanip>

using namespace std;

typedef unsigned int uint;

int noisy(int R, int C, int N)
{
	if (N <= 1) return 0;
	int L = R*C;
	int ans = INT_MAX;
	uint maxn = 1<<L;
	for (uint i = 1; i < maxn; ++i)
	{
		vector<int> v;
		for (int j = 0; j < L; ++j)
		{
			if (((i>>j) & 1) == 1)
			{
				v.push_back(j);
				if (v.size()>N) break;
			}
		}
		if (v.size() == N)
		{
			int tmp = 0;
			for (int m = 0; m < N; ++m)
			{
				for (int n = m+1; n < N; ++n)
				{
					if ((v[m]+1==v[n] && v[n]%C!=0) || (v[m]+C==v[n]))
						tmp++;
				}
			}
			ans = min(ans, tmp);
		}
	}
	return ans;
}

int main(int argc, char* argv[])
{
	ifstream in("B-small-attempt0.in");
	ofstream out("result.txt");
	int T;
	int R, C, N;
	in >> T;
	for (int i = 0; i < T; ++i)
	{
		in >> R >> C >> N;
		out << "Case #" << i+1 << ": " << noisy(R, C, N) << endl;
		cout << i+1 << endl;
	}

	in.close();
	out.close();
	return 0;
}