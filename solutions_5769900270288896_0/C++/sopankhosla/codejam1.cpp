#include <iostream>
#include<cstdio>
#include <cmath>
using namespace std;
 
int arr[270000];
int a, b;
 
int preprocess(int i)
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
	int num,N;
	scanf("%d",&num);
	for (int t = 0; t < num; t++)
	{
		scanf("%d %d %d", &a,&b,&N);
 
		int mini = a * b * N * 100;
		for (int i = 1; i < pow(2,a*b); i++)
		{
			arr[i] = arr[- (i & -i) + i] + 1;
			if (arr[i] == N) 
				mini = min(mini, preprocess(i));
		}
		printf("Case #%d: %d\n", t+1, mini);
	}
}
