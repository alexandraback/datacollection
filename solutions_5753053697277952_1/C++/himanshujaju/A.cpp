#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

#define PII       pair<int,int>
#define all(c)    c.begin(),c.end()
#define sz(c)     (int)c.size()
#define clr(c)    c.clear()
#define pb        push_back
#define mp        make_pair
#define cin(x)    scanf("%d",&x)
#define MOD		1000000007
#define EPS		1E-10

ifstream fin("A.in");
ofstream fout("out.txt");

int main()
{
	int t;
	fin >> t;
	for(int ii = 1; ii <= t; ii++)
	{
		int n;
		fin >> n;
		vector<PII> arr(n);
		for(int i = 0; i < n; i++)
		{
			fin >> arr[i].first;
			arr[i].second = i;
		}
		fout << "Case #" << ii << ": ";
		int SUM = 0;
		for(int i = 0; i < n; i++)
			SUM += arr[i].first;
		while(SUM)
		{
			int nonzero = 0;
			for(int i = 0; i < n; i++)
				if(arr[i].first)
					nonzero += 1;
			PII O = mp(-1,-1);
			for(int i = 0; i < n; i++)
			{
				for(int j = 0; j < n; j++)
				{
					int tot = SUM - 2;
					arr[i].first -= 1;
					arr[j].first -= 1;
					int B = 0;
					for(int a = 0;a < n; a++)
						B = max(B, arr[a].first);
					arr[i].first += 1;
					arr[j].first += 1;
					if(2 * B <= tot)
					{
						O.first = i;
						O.second = j;
					}
				}
				if(O.first >= 0) break;
			}

			if(O.first == -1)
			{
				fout << (char)('A' + arr[n - 1].second) << " ";
				arr[n-1].first -= 1;
				SUM -= 1;
			}
			else
			{
				fout << (char)('A' + arr[O.first].second);
				fout << (char)('A' + arr[O.second].second) << " ";
				arr[O.first].first -= 1;
				arr[O.second].first -= 1;
				SUM -= 2;
			}
			sort(all(arr));
		}
		fout << "\n";
	}
	return 0;
}