#include <cstdio>
#include <algorithm>
#include <set>
#include <cmath>
#include <string>
#include <iostream>

using namespace std;

int main(void)
{
	unsigned int number_of_tests;
	scanf("%u\n", &number_of_tests);

	for (unsigned int test = 0; test < number_of_tests; ++test)
	{
		printf("Case #%u: ", test + 1);

		string words[100];
		unsigned int count[100] = {0};
		unsigned int index[100] = {0};

		unsigned int number_of_words;
		scanf("%u\n", &number_of_words);
		for (unsigned int word = 0; word < number_of_words; ++word)
		{
			cin >> words[word];
		}

		unsigned int total_total = 0;

		int some_end = 0;
		int some_not_end = 0;
		int fail = 0;
		do
		{
		fail = 0;
		char first_letter = words[0][index[0]];

		unsigned int min_val = 999999999;
		unsigned int max_val = 0;

		some_end = 0;
		some_not_end = 0;
		for (unsigned int word = 0; word < number_of_words; ++word)
		{
			count[word] = 0;
			while (words[word].size() > index[word] + count[word] && words[word][index[word] + count[word]] == first_letter)
			{
				++count[word];
			}

			index[word] += count[word];

			if (index[word] == words[word].size())
			{
				some_end = 1;
			}

			if (index[word] != words[word].size())
			{
				some_not_end = 1;
			}

			if (count[word] == 0)
			{
				fail = 1;
				break;
			}

			if (count[word] < min_val)
			{
				min_val = count[word];
			}

			if (count[word] > max_val)
			{
				max_val = count[word];
			}

		}

		if (fail || (some_end && some_not_end))
		{
			fail = 1;
			cout << "Fegla Won" << endl;
			break;
		}

		unsigned int min_total = 999999999;
		for (unsigned int index2 = min_val; index2 <= max_val; ++index2)
		{
			unsigned int total = 0;

			for (unsigned int word = 0; word < number_of_words; ++word)
			{
				total += abs((int)(count[word] - index2));
			}

			if (total < min_total)
			{
				min_total = total;
			}
		}

		total_total += min_total;

		} while (some_end == 0);

		if (fail == 0)
		{
			cout << total_total << endl;
		}
	}
}
