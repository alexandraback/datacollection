#include <stdio.h>
#include <vector>
using std::vector;

int main()
{
	unsigned int nCases = 0;scanf("%d",&nCases);
	for(unsigned int iCases = 1;iCases <= nCases;++iCases)
	{
		unsigned int n = 0;scanf("%d",&n);
		vector<unsigned int> data(n);
		for(unsigned int i = 0;i < n;++i) scanf("%d",&data[i]);
		unsigned long long ans1 = 0,ans2 = 0;
		unsigned int maxdis = 0;
		for(unsigned int i = 1;i < n;++i)
		{
			if(data[i] >= data[i-1]) continue;
			unsigned int dis = data[i-1] - data[i];
			ans1 += dis;
			if(dis > maxdis) maxdis = dis;
		}
		for(unsigned int i = 1;i < n;++i)
		{
			if(data[i-1] < maxdis) ans2 += data[i-1];
			else ans2 += maxdis;
		}

		printf("Case #%u: %I64u %I64u\n",iCases,ans1,ans2);
	}
	return 0;
}