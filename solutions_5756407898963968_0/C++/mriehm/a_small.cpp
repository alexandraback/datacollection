#include <cstdio>
#include <set>

using namespace std;

int main(void)
{
	unsigned int number_of_tests;
	scanf("%u\n", &number_of_tests);
	for (unsigned int test = 0; test < number_of_tests; ++test)
	{
		unsigned int row1_pick;
		scanf("%u\n", &row1_pick);

		unsigned int row1[16];
		for (unsigned int row = 0; row < 4; ++row)
		{

			scanf("%u %u %u %u\n", row1 + row * 4, row1 + row * 4 + 1, row1 + row * 4 + 2, row1 + row * 4 + 3);
		}

		unsigned int row2_pick;
		scanf("%u\n", &row2_pick);

		unsigned int row2[16];
		for (unsigned int row = 0; row < 4; ++row)
		{
			scanf("%u %u %u %u\n", row2 + row * 4, row2 + row * 4 + 1, row2 + row * 4 + 2, row2 + row * 4 + 3);
		}

		set<unsigned int> numbers(row1 + (row1_pick - 1) * 4, row1 + (row1_pick) * 4);

		unsigned int number_of_matches = 0;
		unsigned int matching_number;
		for (unsigned int number = 0; number < 4; ++number)
		{
			if (numbers.find(row2[(row2_pick - 1) * 4 + number]) != numbers.end())
			{
				++number_of_matches;
				matching_number = row2[(row2_pick - 1) * 4 + number];
				if (number_of_matches > 1)
				{
					break;
				}
			}
		}

		printf("Case #%u: ", test + 1);

		switch (number_of_matches)
		{
			case 0:
				printf("Volunteer cheated!\n");
				break;
			case 1:
				printf("%u\n", matching_number);
				break;
			case 2:
				printf("Bad magician!\n");
				break;
			default:
				printf("I screwed up!\n");
				break;
		}
	}
}
