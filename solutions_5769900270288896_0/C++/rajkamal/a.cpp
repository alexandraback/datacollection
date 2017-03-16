#include <iostream>
#include<stdio.h>
using namespace std;
 
int ns[1 << 18];
int a, b, N;
 
int xx(int i)
{
	int answer = 0;
	for (int r = 0; r < a; r++)
	{
		for (int c = 0; c < b; c++)
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
	int test;
	cin >> test;
	for (int t = 1; t <= test; t++)
	{
		cin >> a >> b >> N;
 
		int best = a * b * N * 100;
		for (int i = 1; i < (1 << (a * b)); i++)
		{
			ns[i] = ns[i - (i & -i)] + 1;
			if (ns[i] == N) best = min(best, xx(i));
		}
		printf("Case #%d: %d\n", t, best);
	}
}
