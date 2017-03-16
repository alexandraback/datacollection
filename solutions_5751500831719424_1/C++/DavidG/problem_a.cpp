#include <algorithm>
#include <cassert>
#include <deque>
#include <fstream>
#include <functional>
#include <iostream>
#include <limits>
#include <map>
#include <queue>
#include <set>
#include <utility>
#include <vector>

#ifdef DEBUG
#define DBGMSG	std::cerr
#else
#define DBGMSG	if (0) std::cerr
#endif

using namespace std;

int solve(vector<string>& stringList)
{
	// First char should all be the same.
	// For every change in char, everyone should have that change at some index.
	int retval = 0;
	string ref;

	for (char ch : stringList[0]) {
		if (ref.empty() || ref.back() != ch) {
			ref.push_back(ch);
		}
	}

	// Check whether possible:
	for (const string& str : stringList) {
		int index		= -1;

		for (char ch : str) {
			if (index < 0 || ch != ref[index]) {
				++index;
				if (ch != ref[index]) {
					return -1;
				}
			}
		}
		if (index != ref.size() - 1)
			return -1;
	}

	vector<vector<int> >	distances(ref.size(), vector<int>(stringList.size(), 0));

	for (int i = 0; i < stringList.size(); ++i) {
		string s = stringList[i];

		for (int j = 0 ; j < ref.size(); ++j) {
			int count = 0;
			while (!s.empty() && s[0] == ref[j]) {
				count++;
				s = s.substr(1);
			}
			if (count <= 0)
				return -1;

			distances[j][i] = count;
		}
		if (!s.empty())
			return -1;
	}

	for (auto row : distances) {
		int mean = 0;
		for (int n : row)
			mean += n;

		mean = mean / row.size();

		int distance_from_mean = 0;
		for (int n : row)
			distance_from_mean += std::abs(n - mean);

		retval += distance_from_mean;
	}

	return retval;
}

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
			/*
			 * The first line of the input gives the number of test cases, T. T test cases follow.
			 *
			 * Each test case starts with a line containing an integer N which is the number of strings.
			 * Followed by N lines, each line contains a non-empty string (each string will consist of lower
			 * case English characters only, from 'a' to 'z').
			 */
			unsigned N;
			input >> N;

			vector<string>	stringList;

			for (int c = 0; c < N; ++c) {
				string s;
				input >> s;
				stringList.push_back(s);
			}

			int retval = solve(stringList);

			std::cout << "Case #" << i << ": ";
			if (retval < 0)
				std::cout << "Fegla Won" <<std::endl;
			else
				std::cout << retval << std::endl;
		}
	}
	return 0;
}
