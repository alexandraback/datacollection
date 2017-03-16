#include <iostream>
#include<stdio.h>
using namespace std;
 
long long int ns[1 << 18];
long long int a, b, N;
 
long long int xx(long long int i)
{
	long long int answer = 0;
	for (long long int r = 0; r < a; r++)
	{
		for (long long int c = 0; c < b; c++)
		{
			if (c > 0 and (i & (1 << (r * b + c))) and (i & (1 << (r * b+ c - 1))))
				answer++;
			if (r > 0 and (i & (1 << (r * b + c))) and (i & (1 << (r * b + c - b))))
				answer++;
		}
	}
	return answer;
}
 
int main() 
{
	freopen("B-large (2).in","r",stdin);
	freopen("raj2.out","w",stdout);
long long	int test;
	cin >> test;
	for (long long int t = 1; t <= test; t++)
	{
		cin >> a >> b >> N;
 
	long long	int best = a * b * N * 100;
		for (long long int i = 1; i < (1 << (a * b)); i++)
		{
			ns[i] = ns[i - (i & -i)] + 1;
			if (ns[i] == N) best = min(best, xx(i));
		}
		printf("Case #%lld: %lld\n", t, best);
	}
}
