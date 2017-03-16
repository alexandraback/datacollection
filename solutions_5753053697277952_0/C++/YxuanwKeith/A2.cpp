#include <cstring>
#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN = 26;

int Num[MAXN], Ord[MAXN];

bool Cmp(int A, int B) {return Num[A] > Num[B];}

int main() {
	freopen("A.in", "r", stdin), freopen("A2.out", "w", stdout);
	
	int Test;
	scanf("%d", &Test);
	for (int i = 1; i <= Test; i ++) {
		int N, All = 0;
		scanf("%d", &N);
		for (int j = 1; j <= N; j ++) {
			scanf("%d", &Num[j]);
			All = All + Num[j];
			Ord[j] = j;
		}
		printf("Case #%d:", i);
		sort(Ord + 1, Ord + N + 1, Cmp);
		while (Num[Ord[1]] != Num[Ord[2]]) {
			printf(" %c", Ord[1] - 1 + 'A');
			Num[Ord[1]] --;
		}
		for (int j = 3; j <= N; j ++) {
			for (int k = 1; k <= Num[Ord[j]]; k ++) printf(" %c", Ord[j] - 1 + 'A');
		}
		for (int j = 1; j <= Num[Ord[1]]; j ++) 
			printf(" %c%c", Ord[1] - 1 + 'A', Ord[2] - 1 + 'A');
		printf("\n");
	}
}