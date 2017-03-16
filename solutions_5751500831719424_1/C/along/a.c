#include <string>
#include <string.h>
#include <vector>
#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;

vector<pair<int, int> > vs[101];

int main()
{
	int cc,ca;
	int i,j,k;
	cin >> ca;
	for(cc=1; cc<=ca; cc++)
	{
		int N;
		cin >> N;
		for(i=0; i<N; i++) vs[i].clear();
		for(i=0; i<N; i++)
		{
			string s;
			cin >> s;
			for(j=0; j<s.size(); j++)
			{
				char c = s[j];
				int count = 1;
				for(k=j+1; k<s.size(); k++, count++)
					if (s[k] != s[j])
						break;
				vs[i].push_back(make_pair(c, count));
				j = k-1;	
			}
		}
		for(i=1; i<N; i++)
		{
			if (vs[i].size() != vs[0].size())
				break;
			for(j=0; j<vs[0].size(); j++)
				if (vs[0][j].first != vs[i][j].first)
					break;
			if (j < vs[0].size())
				break;
		}
		if (i < N)
		{
			printf("Case #%d: Fegla Won\n", cc);
			continue;
		}
		int r = 0;
		for(i=0; i<vs[0].size(); i++)
		{
			vector<int> d;
			for(j=0; j<N; j++)
				d.push_back(vs[j][i].second);
			sort(d.begin(), d.end());
			int sum = 0;
			for(j=1; j<N; j++)
			{
				sum += d[j] - d[0];
			}
//			printf("%d sum %d\n", i, sum);
			int best = sum;
			for(j=1; j<N; j++)
			{
				int diff = d[j] - d[j-1];
				int nsum = sum + j*diff - (N-j)*diff;
				sum = nsum;
				if (sum < best) best = sum;
			}
			r += best;
		}
		printf("Case #%d: %d\n", cc, r);
	}
}
