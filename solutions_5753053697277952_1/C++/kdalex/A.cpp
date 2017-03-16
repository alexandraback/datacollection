#include <iostream>
#include <vector>
#include <map>
#include <fstream>
#include <sstream>
#include <cassert>
#include <algorithm>
#include <string>

std::vector<std::string> solve(std::vector<int> &pi)
{
	int N = pi.size();
	std::map<char, int> cnt;
	for (int i = 0; i < N; ++i)
		cnt[(char)('A' + i)] = pi[i];
	std::vector<std::pair<std::string, int>> foo;
	for (auto& p: cnt)
		foo.emplace_back(std::string("")+p.first, p.second);
	std::sort(foo.begin(), foo.end(), [](const std::pair<std::string, int> &a, const std::pair<std::string, int> &b) { return a.second > b.second; });


	std::vector<std::string> res;
	while (foo[0].second > foo[1].second)
	{
//		std::cout << "FIRST_REDUCE" << std::endl;
		res.emplace_back(foo[0].second > foo[1].second + 1 ? std::string(foo[0].first) + std::string(foo[0].first) : std::string(foo[0].first));
		foo[0].second -= foo[0].second == foo[1].second + 1 ? 1 : 2;
	}
	for (int i = N - 1; i >= 2; --i)
	{
		for (int j = 0; j < foo[i].second / 2; ++j)
			res.emplace_back(std::string(foo[i].first) + std::string(foo[i].first));
		if (foo[i].second % 2)
			res.emplace_back(std::string(foo[i].first));
		foo.resize(i);
//		std::cout << "REDUCING REM" << std::endl;
	}
	// Either we had 2 equal parties, or we equaled 'em
	assert(foo[0].second == foo[1].second);
	for (int i = 0; i < foo[0].second; ++i)
	{
		res.emplace_back(std::string(foo[0].first) + std::string(foo[1].first));
//		std::cout << "REDUCING PAIR" << std::endl;
	}
	return res;
}

int main(int argc, char **argv)
{
	std::ios_base::sync_with_stdio(false);
	std::ifstream in;
	std::ofstream out;
	in.open(argv[1], std::ios_base::in);
	out.open(argv[2], std::ios_base::out);

	int T;
	in >> T;
	for (int i = 1; i <= T; ++i)
	{
		int N;
		in >> N;
		std::vector<int> pi(N);
		for (int j = 0; j < N; ++j)
			in >> pi[j];
		auto res = solve(pi);
		out << "Case #" << i << ": ";
		for (auto& s: res)
			out << s << " ";
		out << std::endl;
	}
	return 0;
}
