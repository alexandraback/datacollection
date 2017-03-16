#include <iostream>
#include <cstdio>
using namespace std;

int n;

int DP(int x)
{
	if(x == n)
		return 0;
	else
	{
		int reverse=0, num = x;
		while(num != 0)
		{
			reverse *= 10;
			reverse += num%10;
			num /= 10;
		}
		if(reverse <= x || reverse > n)
			return 1 + DP(x+1);

		return min(1 + DP(x+1), 1 + DP(reverse));
	}
}

int main(void)
{
	int t;
	scanf("%d", &t);
	for(int rep = 1;rep <= t;rep++)
	{
		scanf("%d", &n);
		printf("Case #%d: %d\n", rep, DP(1)+1);
	}
}