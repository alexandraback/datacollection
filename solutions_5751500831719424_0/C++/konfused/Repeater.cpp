// Repeater.cpp : Defines the entry point for the console application.
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
		char str1[101], str2[101];
		scanf("%d%s%s", &n, &str1, &str2);

		int itrStr1 = 0;
		int itrStr2 = 0;
		char ch1, ch2;
		int cnt1,cnt2;
		bool flag = true;
		int count = 0;
		
		while(true)
		{
			ch1 = str1[itrStr1];
			ch2 = str2[itrStr2];

			if((0 == ch1)&&(0 == ch2))
				break;

			if(ch1 != ch2)
			{
				flag = false;
				break;
			}
			
			cnt1=cnt2=0;

			while(ch1 == str1[itrStr1])
			{
				itrStr1++;cnt1++;
			}
			while(ch2 == str2[itrStr2])
			{
				itrStr2++;cnt2++;
			}

			if(cnt2>cnt1)
				count += cnt2-cnt1;
			else
				count += cnt1-cnt2;

		}

		if(false == flag)
			printf("Case #%d: Fegla Won\n", i+1);
		else
			printf("Case #%d: %d\n", i+1, count);
	}

	return 0;
}

