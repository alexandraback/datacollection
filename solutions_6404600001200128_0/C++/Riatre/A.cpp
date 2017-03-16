#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <assert.h>

using namespace std;

typedef long long ll;

int mushroom[1111];

int main(void)
{
	int T = 0;
	int TK = 0;
	scanf("%d",&T);
	while(T--)
	{	
		int N = 0;
		scanf("%d",&N);
		for(int i = 0;i < N;i++) scanf("%d",&mushroom[i]);
		int ans1 = 0;
		int ans2 = 0;
		for(int i = 1;i < N;i++)
		{
			if(mushroom[i] < mushroom[i-1]) ans1 += mushroom[i-1]-mushroom[i];
		}
		
		int maxSpeed = 0;
		for(int i = 1;i < N;i++)
		{
			int minEat = max(0, mushroom[i-1]-mushroom[i]);
			maxSpeed = max(maxSpeed, minEat);
		}
		int onPlate = mushroom[0];
		for(int i = 1;i < N;i++)
		{
			int eat =  min(onPlate, maxSpeed);
			onPlate -= eat;
			ans2 += eat;
			assert(onPlate <= mushroom[i]);
			onPlate = mushroom[i];
		}

		printf("Case #%d: ", ++TK);
		printf("%d %d\n",ans1,ans2);
	}
	return 0;
}
