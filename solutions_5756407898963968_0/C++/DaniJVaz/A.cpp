#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

const int N = 4;

int main() {
	int iC=0, nC;
	scanf("%d", &nC);
	for (iC=1; iC<=nC; iC++) {
		int a1, a2;
		int grid1[N*N], grid2[N*N];

		scanf("%d",&a1);
		for (int i=0; i<N*N; i++)
			scanf("%d", grid1+i);

		scanf("%d",&a2);
		for (int i=0; i<N*N; i++)
			scanf("%d", grid2+i);

		a1--; a2--; // Control for lines in (0-3)

		int check[N*N+1];
		fill(check, check+N*N+1, 0);

		// Adds one for each answer a number is in

		for (int j=0; j<N; j++)
			check[grid1[a1*N+j]]++;

		for (int j=0; j<N; j++)
			check[grid2[a2*N+j]]++;

		// Counts the numbers which are in the two answers (check[i] == 2)

		int count = 0;
		int ans;
		for (int i=1; i<=N*N; i++) {
			if (check[i] == 2) {
				count++;
				ans = i;
			}
		}

		printf("Case #%d: ", iC);
		if (count == 0)
			printf("Volunteer cheated!\n");
		else if (count >= 2)
			printf("Bad magician!\n");
		else
			printf("%d\n", ans);

	}
	return 0;
}
