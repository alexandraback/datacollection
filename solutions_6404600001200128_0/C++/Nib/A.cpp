#include <iostream>
#include <cstdio>
using namespace std;

int main(void)
{
	int t, n;
	scanf("%d", &t);
	for(int rep = 1;rep <= t;rep++)
	{
		scanf("%d", &n);
		int A[n];
		for(int i = 0;i < n;i++) scanf("%d", &A[i]);
		int X=0, Y=0;
		int mx = 0;
		for(int i = 1;i < n;i++)
		{
			if(A[i-1]-A[i] > 0)
			{
				X += A[i-1]-A[i];
			}
			if(A[i-1]-A[i] > mx)
				mx = A[i-1]-A[i];
		}
		for(int i = 0;i < n-1;i++)
		{
			if(A[i]<mx)
				Y += A[i];
			else
				Y += mx;
		}
		printf("Case #%d: %d %d\n", rep, X, Y);
	}
}