#include <bits/stdc++.h>
#include <fstream>
using namespace std;

int main(){
	ifstream in("C-small-attempt2.in");
	ofstream out("C.out");
	int T;
	in >> T;
	for (int z = 1 ; z <= T ; z++)
	{
		int n;
		in >> n;
		long long c[n][2];
		for (int i = 0 ; i < n ; i++)
		{
			in >> c[i][0] >> c[i][1];
		}
		int ans[n];
		memset(ans, 0, sizeof(ans));
		for (int i = 0 ; i < n ; i++)
		{
			int cut = 3000;
			for (int j = 0 ; j < n ; j++)
			{
				int left = 0;
				int right = 0;
				if (i == j)
					continue;
				for (int k = 0 ; k < n ; k++)
				{
					if (k == i || k == j) continue;
					long long y0 = c[k][1] * (c[i][0] - c[j][0]);
					long long y = (c[i][1] - c[j][1]) * (c[k][0] - c[j][0]) + c[j][1] * (c[i][0] - c[j][0]);
					if (y0 < y)
						left++;
					if (y0 > y)
						right++;
				}
				cerr << i << ' ' << left << ' ' << right << endl;
				cut = min(cut, min(left, right));
			}
			ans[i] = cut;
		}
		if (n == 1)
			ans[0] = 0;
		cerr << endl;
		out << "Case #" << z << ": " << endl;
		for (int i = 0 ; i < n ; i++)
			out << ans[i] << endl;
	}
	in.close();
	out.close();
	return 0;
}
