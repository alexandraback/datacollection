#include <stdio.h>
#include <vector>
#include <string>
#include <algorithm>

using std::vector;
using std::string;

long long slove_small(const vector<string>& data)
{
	size_t size = data.size();

	string opt = "";
	for(size_t i = 0;i < size;++i)
	{
		string t;t.push_back(data[i][0]);
		for(size_t k = 1,len = data[i].size();k < len;++k)
		{
			if(data[i][k] == data[i][k-1]) continue;
			t.push_back(data[i][k]);
		}
		if(0 == opt.size()) opt = t;
		else if(opt != t) return -1;
	}

	vector<size_t> start(size,0);

	long long ret = 0;
	for(size_t i = 0,len = opt.size();i < len;++i)
	{
		vector<size_t> lens(size,0);
		for(size_t j = 0;j < size;++j)
		{
			size_t k = start[j];
			for(;k < data[j].size() && data[j][k] == opt[i];++k);
			lens[j] = k - start[j];
			start[j] = k;
		}
		std::sort(lens.begin(),lens.end());
		for(size_t j = 0,k = size - 1;j < k;++j,--k)
		{
			ret += lens[k] - lens[0];
		}
	}
	return ret;
}

int main()
{
	static const size_t buff_size = 101;
	unsigned int nCases = 0;scanf("%d",&nCases);					// 1 <= nCases <= 100
	for(unsigned int iCases = 1;iCases <= nCases;++iCases)
	{
		unsigned int n = 0;scanf("%d",&n);
		char buff[buff_size] = { 0 };
		vector<string> data(n);
		for(unsigned int i = 0;i < n;++i)
		{
			scanf("%s",buff);
			data[i] = buff;
		}
		long long ans = slove_small(data);
		if(ans >= 0) printf("Case #%d: %I64d\n",iCases,ans);
		else printf("Case #%d: Fegla Won\n",iCases);
	}
	return 0;
}
