#include<iostream>
#include<cstdio>

#define ll long long
using namespace std;

int main()
{
	freopen("R1Cp1L.in", "r", stdin);
	freopen("R1Cp1L.out", "w", stdout);
	ll T,it,N,i,j,cnt,max,sum,maxit,modd,temp,tempit;
	scanf("%lld", &T);
	for(it = 1; it <= T; it++)
	{
		sum = 0;
		scanf("%lld", &N);
		ll arr[N] = {0};
		for(i = 0; i < N; i++)
		{
			scanf("%lld", &temp);
			arr[i] = temp;
			sum += temp;
		}
		printf("Case #%lld: ", it);
		cnt = N;
		modd = 0;
		while(cnt)
		{
			max = 0;
			//cout << "sum is : " << sum << "\n";
			if(sum == 3 && modd == 0)
			{
				temp = 0;
				for(i = 0; i < N; i++)
				{
					if(arr[i] != 0)
					{
						temp++;
						tempit = i;
					}
				}
				if(temp == 3)
				{
					printf("%c ", tempit + 65);
					arr[tempit]--;
					cnt--;
					modd = 0;
				}
			}
			for(i = 0; i < N; i++)
			{
				if(arr[i] > max)
				{
					max = arr[i];
					maxit = i;
				}
			}
			//cout << 35 << "\n";
			printf("%c",maxit+65);
			arr[maxit]--;
			sum--;
			if(arr[maxit] == 0)
				cnt--;
			modd++;
			if(modd == 2)
			{
				printf(" ");
				modd = 0;
			}
		}
		putchar('\n');
	}
	return 0;
}
