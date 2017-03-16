#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <fstream>
#include <algorithm>
#include <cassert>
using namespace std;

struct TestCase {
	long long position;
	vector<int> barbers;
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
		fp >> c.position;
		for (int j = 0; j < n; j++) {
			int barber;
			fp >> barber;
			c.barbers.push_back(barber);
		}
		res.push_back(c);
	}
	return res;
}

long long gcd(long long a, long long b) {
	if (b == 0) return a;
	return gcd(b, a % b);
}

long long lcm(long long a, long long b) {
	long long g = gcd(a, b);
	return (a / g) * (b);
}

long long lcm(const vector<int>& numbers) {
	long long res = 1;
	for (int i = 0; i < numbers.size(); i++) {
		res = lcm(res, numbers[i]);
	}
	return res;
}

int solve(TestCase& cs) {
	long long turnaround = lcm(cs.barbers);
	long long throughput = 0;
	for (int i = 0; i < cs.barbers.size(); i++)
		throughput += turnaround / cs.barbers[i];
	long long realPos = cs.position % throughput + throughput;

	vector<long long> queues(cs.barbers.size());
	long long minQueue = 0;
	int lastUsed = 0;
	while (realPos > 0) {
		for (int i = 0; i < queues.size() && realPos > 0; i++) {
			queues[i] -= minQueue;
			if (queues[i] == 0) {
				lastUsed = i;
				queues[i] += cs.barbers[i];
				--realPos;
			}
		}

		minQueue = queues[0];
		for (int i = 1; i < queues.size(); i++) {
			minQueue = min(minQueue, queues[i]);
		}
	}

	return lastUsed + 1;
}

int main(int argc, const char *argv[]) {
	auto cases = load("B-small-attempt1.in");
	std::ofstream fp("B-small-attempt1.out");
	int i = 1;
	for (auto it = cases.begin(); it != cases.end(); ++it, ++i) {
		auto r = solve(*it);
		fp << "Case #" << i << ": " << r << std::endl;
	}

	return 0;
}

