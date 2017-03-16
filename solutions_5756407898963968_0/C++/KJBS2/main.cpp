#include <stdio.h>

int T;

void solve(int k) {
	int first_row, second_row;
	int first[9][9], second[9][9];
	scanf("%d", &first_row);
	for(int i=1; i<=4; i++)
		for(int j=1; j<=4; j++)
			scanf("%d", &first[i][j]);
	scanf("%d", &second_row);
	for(int i=1; i<=4; i++)
		for(int j=1; j<=4; j++)
			scanf("%d", &second[i][j]);

	int check_first, check_second;
	int cnt=0, memo;
	for(int i=1; i<=16; i++) {
		check_first=check_second=0;
		for(int j=1; j<=4; j++)
			if(first[first_row][j]==i) check_first=1;
		for(int j=1; j<=4; j++)
			if(second[second_row][j]==i) check_second=1;

		if(check_first && check_second)
			cnt++, memo=i;
	}
	printf("Case #%d: ", k);
	if(cnt==1) printf("%d", memo);
	if(cnt==0) printf("Volunteer cheated!");
	if(cnt>=2) printf("Bad magician!");
	printf("\n");
	return;
}

int main() {
	freopen("input", "r", stdin);
	freopen("output", "w", stdout);
	scanf("%d", &T);
	for(int i=1; i<=T; i++)
		solve(i);
	return 0;
}
