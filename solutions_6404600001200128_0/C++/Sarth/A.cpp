#include <cstdio>
#include <vector>


void solve(int caseNo)
{
	int N;
	int a[1024];

	scanf("%d", &N);
	int firstTotal = 0;
	for (int i = 0; i != N; i++){
		scanf("%d", &a[i]);
	}
	int maxRate = 0;
	/*First method*/
	for (int i = 1; i != N; i++){
		if (a[i] < a[i-1]){
			firstTotal += (a[i-1]-a[i]);
			if ((a[i-1]-a[i]) > maxRate)
				maxRate = (a[i-1] - a[i]);
		}
	}

	/*Second method*/
	int secondTotal = 0;
	for (int i = 0; i != (N-1); i++){
		if (a[i] > maxRate) secondTotal += maxRate;
		else secondTotal += a[i];
	}


	if (caseNo > 1)
		printf("\n");
	printf("Case #%d: %d %d", caseNo, firstTotal, secondTotal);
}

int main()
{
	int numOfTestCases, i;
	scanf("%d", &numOfTestCases);
	for (i = 0; i < numOfTestCases; i++){
		solve(i+1);
	}
}
