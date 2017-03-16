/* 2015.4.18 Celicath */
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <stdint.h>
#include <iostream>

class barber
{
public:
	int number;
	int time;

	long long wait;

	barber(int number_, int time_)
		: number(number_), time(time_), wait(0) { }
};

bool compare(barber* b1, barber* b2)
{
	return b1->wait == b2->wait ? b1->number > b2->number : b1->wait > b2->wait;
}

int main()
{
	FILE* fin = fopen("input.txt", "r");
	FILE* fout = fopen("output.txt", "w");

	int T;

	fscanf(fin, "%d", &T);

	std::vector<barber*> m;

	for (int c_n = 1; c_n <= T; c_n++)
	{
		int B, N;
		fscanf(fin, "%d%d", &B, &N);

		double tot = 0;
		int max = 0;
		for (int i = 1; i <= B; i++)
		{
			int t;
			fscanf(fin, "%d", &t);
			barber* b = new barber(i, t);
			if (max < t)
				max = t;
			m.push_back(b);
			tot += 1 / (double)t;
		}

		int count = 0;
		double limit = N / tot - 0.00001 - max;
		for (auto a : m)
		{
			int c = std::max(0, (int)(limit / a->time) - 1);
			count += c;
			a->wait = a->time * c;
		}
		if (count >= N)
			printf("???");

		std::make_heap(m.begin(), m.end(), compare);
		for (int i = count + 1; i < N; i++)
		{
			std::pop_heap(m.begin(), m.end(), compare);

			m[B - 1]->wait += m[B - 1]->time;

			std::push_heap(m.begin(), m.end(), compare);
		}
		std::pop_heap(m.begin(), m.end(), compare);

		fprintf(fout, "Case #%d: %d\n", c_n, m[B - 1]->number);
		printf("Case #%d: %d\n", c_n, m[B - 1]->number);

		for (auto a : m)
			delete a;
		m.clear();
	}
	return -0;
}
