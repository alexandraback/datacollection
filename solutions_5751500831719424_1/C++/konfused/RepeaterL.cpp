// RepeaterL.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"


int _tmain(int argc, _TCHAR* argv[])
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	freopen("log.txt", "w", stderr);
	
	int nTestCases;
	scanf("%d", &nTestCases);
	
	for(int i = 0; i < nTestCases; i++)
	{
		int n = 0;
		char str[100][101];
		scanf("%d", &n);
		for(int j = 0; j < n; j++)
			scanf("%s",&str[j]);

		int itrStr[100] = {0,};
		char ch[100]  = {0, };
		int cnt[100] = {0,};
		bool flag = true;
		int count = 0;
		
		while(true)
		{
			for(int j = 0; j < n; j++)
				cnt[j] = 0;

			ch[0] = str[0][itrStr[0]];
			for(int j = 0; j < n; j++)
			{
				ch[j] = str[j][itrStr[j]];
				if(ch[j] != ch[0])
				{
					flag = false;
					break;
				}

				/*if(ch[j] == 0)
					break;*/

				while(ch[j] == str[j][itrStr[j]])
				{
					itrStr[j]++;cnt[j]++;
				}
			}

			if(false == flag)
				break;

			int j;
			for(j = 0; j < n; j++)
				if(ch[j] == 0)
					break;
			if(j != n)
				break;


			int index = 0;
			int MIN = 10000, MINIndex = 0;
			for(j = 0; j < n; j++)
			{
				int cnt1 = 0;
				for(int k = 0; k < n; k++)
				{
					if(cnt[k] > cnt[index])
						cnt1 += cnt[k] - cnt[index] ;
					else
						cnt1 += cnt[index] - cnt[k];
				}
				
				if(cnt1 < MIN)
				{
					MIN = cnt1;
					MINIndex = index;
				}
				index++;
			}

			count += MIN;
		}

		if(false == flag)
			printf("Case #%d: Fegla Won\n", i+1);
		else
			printf("Case #%d: %d\n", i+1, count);
	}

	return 0;
}

