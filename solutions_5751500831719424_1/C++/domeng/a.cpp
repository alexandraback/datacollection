#include <stdio.h>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;
typedef pair<char,int> pci;
typedef vector<pci> vpci;
int main()
{
	int T;
	scanf("%d",&T);
	for (int kase=1;kase<=T;++kase)
	{
		int n;
		scanf("%d",&n);
		vector<vpci> data(n);
		for (int i=0;i<n;i++)
		{
			char str[105];
			scanf("%s",str);
			for (int j=0;str[j];j++)
			{
				if (data[i].empty() || data[i].back().first != str[j])
					data[i].push_back(make_pair(str[j],1));
				else
					data[i].back().second++;
			}
		}
		int bad = 0;
		for (int i=1;i<n;i++)
		{
			bad |= data[i].size() != data[0].size();
			if (not bad)
			{
				for (int j=0;j<data[i].size();j++)
					if (data[i][j].first != data[0][j].first)
						bad = true;
			}
		}
		if (bad) printf("Case #%d: Fegla Won\n",kase);
		else
		{
			int total = 0;
			for (int i=0;i<data[0].size();i++)
			{
				vector<int> z;
				for (int j=0;j<n;j++) z.push_back(data[j][i].second);
				sort(z.begin(),z.end());
				for (int j=0;j<n;j++)
					total += abs(z[j]-z[n/2]);
			}
			printf("Case #%d: %d\n",kase,total);
		}
	}
	return 0;
}