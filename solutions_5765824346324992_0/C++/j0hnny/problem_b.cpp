// problem_b.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <iostream>
#include <fstream>
#include <queue>
#include <vector>
#include <functional>

struct Event
{
	Event(int id_, int time_) { id = id_; time = time_; }
	int id = 0;
	int time = 0;
};

class Compare
{
public:
	bool operator() (const Event& l, const Event& r)
	{
		if (l.time == r.time)
			return l.id > r.id;

		return l.time > r.time;
	}
};

int Case(std::ifstream& in)
{
	int BRB = 0;
	in >> BRB;

	int NUM = 0;
	in >> NUM;
	std::vector<int> brbs;
	for (int i = 0; i < BRB; ++i)
	{
		int b = 0;
		in >> b;
		brbs.push_back(b);
	}

	if (NUM <= BRB)
		return NUM;

	int period = 1;
	for (int i = 0; i < BRB; ++i)
	{
		if ((period % brbs[i]) != 0)
			period *= brbs[i];
	}

	int p = 0;
	for (int i = 0; i < BRB; ++i)
		p += period/brbs[i];

	NUM = (NUM - 1) % p + 1;

	if (NUM <= BRB)
		return NUM;

	std::priority_queue<Event, std::vector<Event>, Compare> queue;

	for (int i = 0; i < BRB; ++i)
	{
		queue.push(Event(i + 1, brbs[i]));
	}

	for (int i = BRB; i != NUM-1; ++i)
	{
		Event e = queue.top();
		queue.pop();
		queue.push(Event(e.id, e.time + brbs[e.id - 1]));
	}

	return queue.top().id;
}

void Run(const char* in, const char* out)
{
	std::ifstream input;
	input.open(in);

	int cases = 0;
	input >> cases;

	std::vector<int> res;
	for (int i = 0; i < cases; ++i)
	{
		res.push_back(Case(input));
		printf("%d\n", i);
	}

	input.close();

	std::ofstream output;
	output.open(out);
	for (int i = 0; i < cases; ++i)
		output << "Case #" << i + 1 << ": " << res[i] << "\n";
	output.close();
}

int _tmain(int argc, _TCHAR* argv[])
{
	Run("B-small-attempt2.in", "output");
	return 0;
}



