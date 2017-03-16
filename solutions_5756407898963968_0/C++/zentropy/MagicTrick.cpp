#include <stdio.h>

int main()
{
	static const unsigned int card_num = 16;
	static const unsigned int row_num = 4;
	static const unsigned int col_num = 4;

	unsigned int nCases = 0;scanf("%d",&nCases);
	for(unsigned int iCases = 1;iCases <= nCases;++iCases)
	{
		bool possible[card_num+1] = { 0 };
		for(unsigned int i = 0;i <= card_num;++i) possible[i] = true;

		unsigned int u = 0,v = 0;
		for(unsigned int ir = 0;ir < 2;++ir)
		{
			scanf("%d",&u);
			for(unsigned int i = 1;i <= row_num;++i)
			{
				for(unsigned int k = 0;k < col_num;++k)
				{
					scanf("%d",&v);
					if(i == u) possible[v] &= true;
					else possible[v] &= false;
				}
			}
		}

		size_t count = 0,ans = 0;
		for(unsigned int i = 1;i <= card_num;++i)
		{
			if(!possible[i]) continue;
			++ count;ans = i;
		}

		if(1 == count) printf("Case #%u: %u\n",iCases,ans);
		else if(0 == count) printf("Case #%u: Volunteer cheated!\n",iCases);
		else printf("Case #%u: Bad magician!\n",iCases);

	}
	return 0;
}