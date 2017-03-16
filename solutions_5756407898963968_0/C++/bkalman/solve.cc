#include <cstdio>

using std::scanf;
using std::printf;

static void load(int& answer, int selected_row[4]) {
	int throwaway;
	scanf("%i", &answer);
	for(int row = 1; row < answer; ++row)
		for(int col = 1; col <= 4; ++col)
			scanf("%i", &throwaway);
	for(int col = 1; col <= 4; ++col)
		scanf("%i", selected_row + col - 1);
	for(int row = answer + 1; row <= 4; ++row)
		for(int col = 1; col <= 4; ++col)
			scanf("%i", &throwaway);
}

static void testcase(int t) {
	int answer1;
	int selected_row1[4];
	load(answer1, selected_row1);
	int answer2;
	int selected_row2[4];
	load(answer2, selected_row2);

	int common_count = 0;
	int solution;
	for(int col1 = 1; col1 <= 4; ++col1) {
		for(int col2 = 1; col2 <= 4; ++col2) {
			if(selected_row1[col1 - 1] == selected_row2[col2 - 1]) {
				common_count++;
				solution = selected_row1[col1 - 1];
			}
		}
	}

	switch(common_count) {
	case 0:
		printf("Case #%d: %s\n", t, "Volunteer cheated!");
		break;
	case 1:
		printf("Case #%d: %d\n", t, solution);
		break;
	default:
		printf("Case #%d: %s\n", t, "Bad magician!");
		break;
	}
}

int main() {
	int T;
	scanf("%i", &T);
	for(int t = 1; t <= T; ++t)
		testcase(t);
}
