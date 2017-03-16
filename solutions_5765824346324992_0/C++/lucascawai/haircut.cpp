#include <cstdio>

#define MAXN 1005

int mmc(int n1, int n2)
{
	int MMC = 1;
	for(int i = 2; ; i++)
	{
		while(n1 % i == 0 || n2 % i == 0)
		{
			MMC *= i;
			if(n1 % i == 0)
				n1 /= i;
			if(n2 % i == 0)
				n2 /= i;
		}

		if(n1 == 1 && n2 == 1)
			break;
	}

	return MMC;
}

int main()
{
	int T, ind = 0;	scanf("%d", &T);
	while(T--)
	{
		int B, N;	scanf("%d %d", &B, &N);
		int barber[MAXN], barber_aux[MAXN];

		int m = 1;
		for(int i = 0; i < B; i++)
		{
			scanf("%d", &barber[i]);
			barber_aux[i] = 1;
			m = mmc(m, barber[i]);
		}
//		printf("mmc: %d\n", m);
		int total = 0;
		for(int i = 0; i < B; i++)
			total += m/barber[i];
//		printf("total: %d\n", total);
		N = N % total;
		if(N == 0)	N += total;
//		printf("N: %d\n", N);

		int cont = 0, resp = 0;
		while(1)
		{
			for(int j = 0; j < B; j++)
			{
				barber_aux[j]--;
				if(barber_aux[j] == 0){
					cont++, barber_aux[j] += barber[j];
				
				}
				if(cont == N)
				{
					resp = j + 1;
					break;
				}
			//	printf("barber_aux: %d\n", barber_aux[j]);
			}

			if(resp != 0)
				break;
		}

		printf("Case #%d: %d\n", ++ind, resp);
	}

	return 0;
}
