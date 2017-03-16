#include<iostream>
#include<vector>
#include<deque>
#include<string>
#include<map>
#include<algorithm>
#include<fstream>
#include<sstream>
#include <cmath>
#include <iomanip>
#include "stdio.h"

using namespace std;
typedef  double ld;

#define DEBUG 1
#define dcout if (DEBUG) cout

int
get_min_count(vector<int> cur_nums)
{
	int min_dist = 100000;
	for (int i = 0; i < cur_nums.size(); ++i) {
		int cur_dist = 0;
		for (int j = 0; j < cur_nums.size(); ++j) {
			if (i == j) {
				continue;
			}
			cur_dist += abs(cur_nums[i] - cur_nums[j]);
		}

		if (cur_dist < min_dist) {
			min_dist = cur_dist;
		}
	}

	return min_dist;
}

string
process_input_small(vector<string> s)
{
	char last_char;
	int last_count = 0;
	string result;
	vector< vector<int> > all_counts;
	vector< vector<char> > all_seq;

	for (int i = 0; i < s.size(); ++i) {
		vector<int> cur_counts;
		vector<char> cur_seq;
		last_char = s[i][0];
		last_count = 1;
		if (s[i].size() == 1) {
			cur_counts.push_back(last_count);
			cur_seq.push_back(last_char);
		}
		else {
			for (int j = 1; j < s[i].size(); ++j) {
				if (s[i][j] == last_char) {
					last_count++;
				}
				else {
					cur_counts.push_back(last_count);
					cur_seq.push_back(last_char);
					last_char = s[i][j];
					last_count = 1;
				}
			}

			cur_counts.push_back(last_count);
			cur_seq.push_back(last_char);
		}

		all_counts.push_back(cur_counts);
		all_seq.push_back(cur_seq);
	}

	// check validity
	bool valid = true;

	for (int i = 1; i < s.size(); ++i) {
		if (all_seq[i].size() != all_seq[0].size()) {
			valid = false;
			break;
		}

		for (int j = 0; j < all_seq[0].size(); ++j) {
			if (all_seq[i][j] != all_seq[0][j]) {
				valid = false;
				break;
			}
		}
		if (!valid) {
			break;
		}
	}

	if (!valid) {
		return "Fegla Won";
	}

	// get_count
	int result_count = 0;
	for (int i = 0; i < all_counts[0].size(); ++i) {
		vector<int> cur_nums;
		for (int j = 0; j < all_counts.size(); ++j) {
			cur_nums.push_back(all_counts[j][i]);
		}

		result_count += get_min_count(cur_nums);
	}
	ostringstream oss;
	oss << result_count;

	return oss.str();
}

int main(int argc, const char *argv[])
{
	int tc = 0;
	ifstream is;
	if (argc == 1)
		is.open("c:\\shiv\\gcj\\input.txt");
	else
		is.open(argv[1]);
	ofstream os;
	os.open("c:\\shiv\\gcj\\output.txt");

	string s;
	getline(is, s);
	istringstream iss(s);
	iss >> tc;

	for (int i = 1; i <= tc; i++)
	{
		os << "Case #" << i << ": ";
		int num_strings;
		getline(is, s);
		istringstream iss(s);
		iss >> num_strings;
		vector<string> ip_strings;

		for (int i = 0; i < num_strings; ++i) {
			getline(is, s);
			ip_strings.push_back(s);
		}

		os << process_input_small(ip_strings) << endl;
	}

	is.close();
	os.close();
	getchar();
	return 0;
}