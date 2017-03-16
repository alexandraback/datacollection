#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <fstream>
#include <algorithm>
#include <cassert>
using namespace std;

struct TestCase {
	vector<int> mushrooms;
};

std::vector<TestCase> load(const std::string& fname) {
	std::ifstream fp(fname);
	std::vector<TestCase> res;
	int cases;
	fp >> cases;
	for (int i = 0; i < cases; i++) {
		TestCase c;
		int n;
		fp >> n;
		for (int j = 0; j < n; j++) {
			int mushrooms;
			fp >> mushrooms;
			c.mushrooms.push_back(mushrooms);
		}
		res.push_back(c);
	}
	return res;
}

string solve(TestCase& cs) {
	int method1 = 0;
	for (int i = 1; i < cs.mushrooms.size(); i++) {
		method1 += max(0, cs.mushrooms[i - 1] - cs.mushrooms[i]);
	}

	int method2 = 0;
	int biggestDiff = 0;
	for (int i = 1; i < cs.mushrooms.size(); i++) {
		biggestDiff = max(biggestDiff, (cs.mushrooms[i - 1] - cs.mushrooms[i]));
	}
	for (int i = 0; i < cs.mushrooms.size() - 1; i++) {
		method2 += min(cs.mushrooms[i], biggestDiff);
	}
	return to_string(method1) + " " + to_string(method2);
}

int main(int argc, const char *argv[]) {
	auto cases = load("A-large.in");
	std::ofstream fp("A-large.out");
	int i = 1;
	for (auto it = cases.begin(); it != cases.end(); ++it, ++i) {
		auto r = solve(*it);
		fp << "Case #" << i << ": " << r << std::endl;
	}

	getchar();
	return 0;
}

