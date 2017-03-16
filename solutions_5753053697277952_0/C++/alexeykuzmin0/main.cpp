#define _CRT_SECURE_NO_WARNINGS
#include <ios>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <deque>
#include <queue>
#include <set>
#include <map>
#include <cmath>
#include <chrono>
#include <cstdlib>
#include <future>
#include <numeric>
#include <functional>
#include <iterator>

using namespace std;

struct Input
{
	vector<int> q;

	friend istream& operator >> (istream& lhs, Input& rhs)
	{
		int q = 0;
		lhs >> q;
		rhs.q.resize(q);
		for (int i = 0; i < q; ++i)
		{
			lhs >> rhs.q[i];
		}
		return lhs;
	}
};

struct Output
{
	vector<string> ans;

	friend ostream& operator << (ostream& lhs, const Output& rhs)
	{
		static int case_number = 0;
		lhs << "Case #" << ++case_number << ":";
		for (auto s : rhs.ans)
		{
			lhs << ' ' << s;
		}
		return lhs << endl;
	}
};

Output solve(Input input)
{
	vector<string> ans;
	set<pair<int, int>> qs;
	for (size_t i = 0; i < input.q.size(); ++i)
	{
		qs.emplace(-input.q[i], i);
	}
	while (!qs.empty())
	{
		if (qs.size() == 2)
		{
			auto p1 = *qs.begin();
			qs.erase(qs.begin());
			p1.first = -p1.first;
			auto p2 = *qs.begin();
			qs.erase(qs.begin());
			p2.first = -p2.first;
			string cur = "";
			cur += char('A' + p1.second);
			cur += char('A' + p2.second);
			ans.push_back(cur);
			--p1.first;
			--p2.first;
			if (p1.first > 0)
			{
				p1.first = -p1.first;
				qs.insert(p1);
			}
			if (p2.first > 0)
			{
				p2.first = -p2.first;
				qs.insert(p2);
			}
			continue;
		}
		auto p = *qs.begin();
		qs.erase(qs.begin());
		p.first = -p.first;
		string cur = "";
		cur += char('A' + p.second);
		ans.push_back(cur);
		--p.first;
		if (p.first > 0)
		{
			p.first = -p.first;
			qs.insert(p);
		}
	}
	return{ ans };
}

int main(int argc, char* argv[])
{
	auto start = chrono::system_clock::now();
	ios_base::sync_with_stdio(false);
	ifstream fin(argv[1]);
	ofstream fout(argv[2]);
	int t;
	fin >> t;
	int ready = 0;
	vector<future<Output>> tasks;
	mutex cout_mutex;
	for (int i = 0; i < t; ++i)
	{
		Input input;
		fin >> input;
		tasks.push_back(async([&ready, &t, &cout_mutex](Input input)
		{
			auto ans = solve(input);
			cout_mutex.lock();
			system("cls");
			cout << ++ready << "/" << t << endl;
			cout_mutex.unlock();
			return ans;
		}, input));
	}
	for (auto& task : tasks)
	{
		fout << task.get();
	}
	auto finish = chrono::system_clock::now();
	auto elapsed = chrono::duration_cast<chrono::duration<float, std::ratio<1, 1>>>(finish - start);
	cout << "Done!" << endl;
	cout << "Time elapsed: " << elapsed.count() << " s" << endl;
	string s;
	getline(cin, s);
	return 0;
}