#include <cstdio>

typedef struct tag_TestCase
{
	int id;
	int arrangement_1[4][4];
	int arrangement_2[4][4];
	int answer_1;
	int answer_2;
} TestCase;

void solve_test_case(TestCase test_case, FILE *output)
{
	int *possible_cards_1 = test_case.arrangement_1[test_case.answer_1 - 1];
	int *possible_cards_2 = test_case.arrangement_2[test_case.answer_2 - 1];
	int correct_answers_count = 0;
	int correct_answer = -1;
	for (int i = 0; i < 4; ++i)
	{
		for (int j = 0; j < 4; ++j)
			if (possible_cards_1[i] == possible_cards_2[j])
			{
				++correct_answers_count;
				correct_answer = possible_cards_1[i];
			}
	}
	fprintf(output, "Case #%d: ", test_case.id);
	if (correct_answers_count == 0)
		fprintf(output, "Volunteer cheated!");
	else if (correct_answers_count == 1)
		fprintf(output, "%d", correct_answer);
	else
		fprintf(output, "Bad magician!");
	fprintf(output, "\n");
}

void main()
{
	FILE *input = fopen("IO/input.txt", "rt");
	FILE *output = fopen("IO/output.txt", "wt");
	int t = 0;
	fscanf(input, "%d", &t);
	for (int i = 1; i <= t; ++i)
	{
		TestCase test_case;
		test_case.id = i;
		fscanf(input, "%d", &test_case.answer_1);
		for (int y = 0; y < 4; ++y)
		{
			for (int x = 0; x < 4; ++x)
				fscanf(input, "%d", &test_case.arrangement_1[y][x]);
		}
		fscanf(input, "%d", &test_case.answer_2);
		for (int y = 0; y < 4; ++y)
		{
			for (int x = 0; x < 4; ++x)
				fscanf(input, "%d", &test_case.arrangement_2[y][x]);
		}
		solve_test_case(test_case, output);
	}
	fclose(output);
	fclose(input);
}