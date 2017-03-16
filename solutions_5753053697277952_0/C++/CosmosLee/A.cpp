#include <iostream>
#include <cstdio>
#include <fstream>
#include <map>
#include <set>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool isValid(const vector<int>& N)
{
	int sum = 0;
	for (auto n : N)
		sum += n;
	for (auto n : N)
		if (2 * n > sum)
			return false;
	return true;
}

void evacuation(vector<string>& pairs, vector<int>& N)
{
	int sum = 0;
	for (auto n : N)
		sum += n;
	if (sum == 0) return;

	// just pick one
	for (auto i = 0; i < N.size(); i++)
	{
		if (N[i] > 0)
		{
			N[i]--;
			if (isValid(N))
			{
				string ans;
				ans.push_back('A' + i);
				pairs.push_back(ans);
				evacuation(pairs, N);
				return;
			}
			N[i]++;
		}
	}

	// just pick two
	for (auto i = 0; i < N.size(); i++)
	{
		if (N[i] == 0) continue;
		for (auto j = i + 1; j < N.size(); j++)
		{
			if (N[j] == 0) continue;

			N[i]--;
			N[j]--;
			if (isValid(N))
			{
				string ans;
				ans.push_back('A' + i);
				ans.push_back('A' + j);
				pairs.push_back(ans);
				evacuation(pairs, N);
				return;
			}
			N[i]++;
			N[j]++;
		}
	}
}

void problemA()
{
	ifstream in("input.txt");
	ofstream out("output.txt");

	int T;
	in >> T;
	for (int t = 1; t <= T; t++)
	{
		int P;
		in >> P;
		vector<int> N(P, 0);
		for (int i = 0; i < P; i++)
			in >> N[i];

		vector<string> pairs;
		evacuation(pairs, N);
		out << "Case #" << t << ":";
		for (auto pair : pairs)
			out << " " << pair;
		out << endl;
	}

	in.close();
	out.close();
}

int main(int argc, char**argv)
{
	problemA();
	return 0;
}