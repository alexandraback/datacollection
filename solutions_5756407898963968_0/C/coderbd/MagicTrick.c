#include <stdio.h>
#include <string.h>

int first_answer[32], second_answer[32];

void get_possible_answer(int answer[]) {
	static int grid[8][8];
	int row, r, c;

	scanf("%d", &row);
	for (r = 1; r <= 4; r++)
		for (c = 1; c <= 4; c++)
			scanf("%d", &grid[r][c]);

	memset(answer, 0, 32 * sizeof(int));
	for (c = 1; c <= 4; c++)
		answer[grid[row][c]] = 1;
}

char* check_answer(int a[], int b[]) {
	static char s[64];
	int num, ans, cnt = 0;

	for (num = 1; num <= 16; num++)
		if (a[num] && b[num]) {
			ans = num;
			cnt++;
		}

	if (cnt == 0)
		strcpy(s, "Volunteer cheated!");
	else if (cnt == 1)
		sprintf(s, "%d", ans);
	else
		strcpy(s, "Bad magician!");

	return s;
}

int main(int argc, char* argv[]) {
	int case_no, r, c, t;

	scanf("%d", &t);
	for (case_no = 1; case_no <= t; case_no++) {

		get_possible_answer(first_answer);
		get_possible_answer(second_answer);

		printf("Case #%d: %s\n", case_no, check_answer(first_answer, second_answer));
	}

	return 0;
}