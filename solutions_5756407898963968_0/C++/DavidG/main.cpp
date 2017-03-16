#include <algorithm>
#include <cassert>
#include <cmath>
#include <fstream>
#include <iostream>
#include <limits>
#include <set>
#include <utility>
#include <vector>

using namespace std;

#ifdef DEBUG
#define DBGLOG  std::cerr
#else
#define DBGLOG  if (0) std::cerr
#endif


int main(int argc, char** argv)
{
	if (argc < 2) {
		std::cerr << "Need an input file" << std::endl;
	}
	else {
		std::fstream input;
		input.open(argv[1], std::fstream::in);

		if (!input.is_open())
			return -1;

		unsigned num_testcases;
		input >> num_testcases;
		for (unsigned i = 1; i <= num_testcases; ++i) {


			/* The first line of the input gives the number of test cases, T.
			 * T test cases follow.
			 *
			 * Each test case starts with a line containing an integer: the answer to the first question.
			 * The next 4 lines represent the first arrangement of the cards: each contains 4 integers,
			 * separated by a single space.
			 *
			 * The next line contains the answer to the second question,
			 * and the following four lines contain the second arrangement in the same format.
			 */
			unsigned first_deck;

			input >> first_deck;
			std::set<unsigned> first_candidates;

			for (unsigned r = 0; r < 4; ++r) {
				for (int c = 0; c < 4; ++c) {
					unsigned v;
					input >> v;
					if (r + 1 == first_deck)
						first_candidates.insert(v);
				}
			}

			unsigned second_deck;

			input >> second_deck;
			std::set<unsigned> second_candidates;

			for (unsigned r = 0; r < 4; ++r) {
				for (int c = 0; c < 4; ++c) {
					unsigned v;
					input >> v;
					if (r + 1 == second_deck)
						second_candidates.insert(v);
				}
			}

			std::vector<unsigned> candidates;

			std::set_intersection(first_candidates.cbegin(), first_candidates.cend(),
								  second_candidates.cbegin(), second_candidates.cend(),
								  std::back_inserter(candidates));

			/*
			 * If there is a single card the volunteer could have chosen, y should be the number on the card.
			 * If there are multiple cards the volunteer could have chosen, y should be "Bad magician!",
			 * without the quotes.
			 * If there are no cards consistent with the volunteer's answers, y should be "Volunteer cheated!",
			 * without the quotes.
			 * The text needs to be exactly right, so consider copying/pasting it from here.
			 */

			std::cout << "Case #" << i << ": ";
			if (candidates.size() > 1)
				std::cout << "Bad magician!";
			else if (candidates.empty())
				std::cout << "Volunteer cheated!";
			else
				std::cout << candidates.at(0);
			std::cout << std::endl;
		}
	}
	return 0;
}

