#include <stdio.h>
#include <assert.h>
#include <vector>
#include <deque>

using std::vector;
using std::deque;

unsigned int slove_small(unsigned int r,unsigned int c,unsigned int n)
{
	unsigned int size = r*c,ans = 0xffffffff;
	for(unsigned int imask = 0;imask < (1<<size);++imask)
	{
		vector< vector<bool> > used(r+2,vector<bool>(c+2,false));
		unsigned int count = 0;
		for(unsigned int i = 0;i < size;++i)
		{
			if(imask&(1<<i))
			{
				++count;
				used[i/c+1][i%c+1] = true;
			}
		}
		if(count != n) continue;

		unsigned int value = 0;
		for(unsigned int i = 1;i <= r;++i)
		{
			for(unsigned int k = 1;k <= c;++k)
			{
				if(!used[i][k]) continue;
				if(used[i][k+1]) ++value;
				if(used[i+1][k]) ++value;
			}
		}

		if(value < ans)
		{
			//printf("%d %d %d\n",imask,value,ans);
			ans = value;
		}
	}
	return ans;
}

int main()
{
	static const unsigned int maxr = 16;
	static const unsigned int maxc = 16;
	static const unsigned int maxn = 16;

	unsigned int values[maxr+1][maxc+1][maxn+1] = { 0 };
	for(unsigned int ir = 1;ir <= maxr;++ir)
	{
		for(unsigned int ic = 1;ic <= maxc;++ic)
		{
			unsigned int size = ir*ic;
			if(size > maxn) continue;
			for(unsigned int kn = 0;kn <= size;++kn)
			{
				values[ir][ic][kn] = slove_small(ir,ic,kn);
			}
		}
	}

	unsigned int nCases = 0;scanf("%d",&nCases);
	for(unsigned int iCases = 1;iCases <= nCases;++iCases)
	{
		unsigned int r = 0,c = 0,n = 0;scanf("%d%d%d",&r,&c,&n);
		unsigned int size = r*c,ans = 0;
		ans = values[r][c][n];
		printf("Case #%u: %u\n",iCases,ans);
	}
	return 0;
}