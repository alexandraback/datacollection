#include <bits/stdc++.h>

using namespace std;

int wsio(int n, int m)
{
	return (n - 1) * m + (m - 1) * n;
}

int jeden(int m, int x)
{
	return wsio(1, m) - 2 * x;
}

int N, M, X;

int napale()
{
	int n = N, m = M, x = X;

	if(n > m)
		swap(n, m);
	
	if((n * m + 1) / 2 >= x)
		return 0;
	
	if(n == 1)
		return jeden(m, n * m - x);
	
	x -= (n * m + 1) / 2;

	if(x <= 0)
		return 0;
	
	int czworek = ((n - 2) * (m - 2)) / 2;

	int trojek = 0;
	if(n % 2 == 0)
		trojek += m - 2;
	else
		trojek += ((m - 1) / 2) * 2;
	if(m % 2 == 0)
		trojek += n - 2;
	else
		trojek += ((n - 1) / 2) * 2;
	
	int dwojek = 2;
	if(n % 2 == 1 && m % 2 == 1)
		dwojek = 0;
	
	int wyn = 0;

	//printf("c = %d, t = %d, d = %d\n", czworek, trojek, dwojek);

	wyn += min(dwojek, x) * 2;
	x -= dwojek;

	if(x <= 0)
		return wyn;
	
	wyn += min(trojek, x) * 3;
	x -= trojek;

	if(x <= 0)
		return wyn;
	
	wyn += min(czworek, x) * 4;
	x -= czworek;

	if(x <= 0)
		return wyn;
	
	assert(false);
	return -1;
}

int przyp()
{
	int n, m, x;
	scanf("%d%d%d", &n, &m, &x);
	N = n;
	M = m;
	X = x;

	if(n > m)
		swap(n, m);

	if((n * m + 1) / 2 >= x)
		return 0;
	
	x = n * m - x;
	
	if(n == 1)
		return jeden(m, x);
	
	int czworek = ((n - 2) * (m - 2) + 1) / 2;
	int trojek = 0;
	if(n % 2 == 0)
		trojek += m - 2;
	else
		trojek += ((m - 2) / 2) * 2;
	if(m % 2 == 0)
		trojek += n - 2;
	else
		trojek += ((n - 2) / 2) * 2;
	int dwojek = 2;
	if(n % 2 == 1 && m % 2 == 1)
		dwojek = 4;
	
	//printf("czworek = %d, trojek = %d, dwojek = %d\n", czworek, trojek, dwojek);
	
	int wyn = wsio(n, m);

	wyn -= min(czworek, x) * 4;
	x -= czworek;

	if(x <= 0)
		return wyn;
	
	wyn -= min(trojek, x) * 3;
	x -= trojek;
	if(x <= 0)
		return wyn;
	
	wyn -= min(dwojek, x) * 2;
	x -= dwojek;
	if(x <= 0)
		return wyn;
	
	assert(false);
	return -1;
}

int main()
{
	int t;
	scanf("%d", &t);
	for(int i = 1; i <= t; i++)
	{
		int a = przyp();
		int b = napale();
		printf("Case #%d: %d\n", i, min(a, b));
	}
	return 0;
}
