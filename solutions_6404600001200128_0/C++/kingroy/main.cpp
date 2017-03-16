#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
   int cases;
   cin >> cases;
   int num, *mush;
   for (int i = 0;i < cases; i++)
   {
   	cin >> num;
   	mush = new int[num];
   	int maxDiff, sum1, sum2;
   	maxDiff = 0;
   	sum1 = 0;
   	cin >> mush[0];
   	for (int j = 1; j < num; j++)
   	{
   		cin >> mush[j];
   		if (mush[j] < mush[j - 1])
   		{
   			if (mush[j - 1] - mush[j] > maxDiff)
   				maxDiff = mush[j - 1] - mush[j];
   			sum1 += mush[j - 1] - mush[j];
   		}
   	}
   	sum2 = 0;
   	for (int j = 1; j < num; j++)
   	{
   		if (mush[j - 1] >= maxDiff)
   			sum2 += maxDiff;
   		else
   			sum2 += mush[j - 1];
   	}
   	printf("Case #%d: %d %d\n", i + 1, sum1, sum2);
   }
   return 0;
}

