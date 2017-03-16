#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;
void solve()
{
	int flag[100] = {};
	int A[9] = {};
	int a;
	scanf("%d", &a);
	a --;
	for(int i = 0; i < 4; i ++)
	{
		for(int j = 0; j < 4; j ++)
		{
			scanf("%d", A + j);
			if(i == a)
				flag[A[j]] ++;
		}
	}
	int b;
	scanf("%d", &b);
	b --;
	for(int i = 0; i < 4; i ++)
		for(int j = 0; j < 4; j ++)
		{
			scanf("%d", A + j);
			if(i == b)
				flag[A[j]] ++;
		}
	int C = 0, R;
	for(int i = 0; i < 32; i ++)
		if(flag[i] == 2)
			C ++, R = i;
	if(C == 0)
		puts("Volunteer cheated!");
	else if(C == 1)
		printf("%d\n", R);
	else
		puts("Bad magician!");
}
int main()
{
	int N;
	scanf("%d", &N);
	for(int i = 0; i < N; i ++)
	{
		printf("Case #%d: ", i + 1);
		solve();
	}
	return 0;
}
