#include "stdafx.h"

typedef vector<pair<char, int>> vec;
vec Transform(string a)
{
	vec vA;
	vA.push_back(make_pair(a[0], 1));
	for (int i = 1; i <a.size();i++)
	{
		if (vA.back().first == a[i]) vA.back().second++;
		else vA.push_back(make_pair(a[i], 1));
	}
	return vA;
}
int CalcDis(string a, string b)
{
	vec vA, vB;

	vB.push_back(make_pair(b[0], 1));
	for (int i = 1; i <b.size();i++)
	{
		if (vB.back().first == b[i]) vB.back().second++;
		else vB.push_back(make_pair(b[i], 1));
	}
	if (vA.size() != vB.size()) 
		return -1;

	int res = 0;
	for (int i = 0; i <vA.size();i++)
	{
		if (vA[i].first != vB[i].first)
			return -1;
		res += abs(vA[i].second - vB[i].second);
	}
	return res;
}

void SovleA(char * input)
{
	TRACE("started...");
	Int n; READ(n); NL;
	for (Int i = 0; i < n; i++)
	{
		Int N; READ(N); NL;
		string vals[101];
		for (Int j = 0; j < N; j++)
		{
			READ(vals[j]); NL;
		}
		vec vecs[100];
		Int len = 0;
		bool failed = false;
		for (Int j = 0; j < N && !failed; j++)
		{
			vecs[j] = Transform(vals[j]);
			if (j == 0) 
			{
				len = vecs[j].size();
				continue;
			}
			if (vecs[j].size() != len)
			{
				failed = true;
				continue;
			}
			for (Int j2 = 0; j2 < len; j2++)
			{
				if (vecs[j][j2].first != vecs[j-1][j2].first)
				{
					failed = true;
					break;
				}
			}
		}
		if (failed)
		{
			PRINT("Case #%I64d: Fegla Won\n", i + 1);
			continue;
		}
		vector<multiset<Int>> bests;
		vector<Int> sums;
		for (Int j = 0; j < len; j++)
		{
			bests.push_back(multiset<Int>());
			sums.push_back(0);
			for (Int j2 = 0; j2 < N; j2++)
			{
				bests.back().insert(vecs[j2][j].second);
				sums.back() += (vecs[j2][j].second - 1);
			}
		}
		vector<Int> mins;
		for (Int j = 0; j < len; j++)
		{
			Int m = sums[j];
			mins.push_back(m);
			if (m == 0) {
				continue;
			}
			multiset<Int> & best = bests[j];
			Int l = 0, r = best.size(), mid = 1;
			multiset<Int>::iterator mit = best.begin();
			while (mit != best.end())
			{
				if (*mit == mid)
				{
					mit++;
					l++;
					r--;
					continue;
				}
				if (l >= r)
					break;
				mins.back() += l;
				mins.back() -= r;
				mid++;				
			}
		}
		Int sm = 0;
		for (Int j = 0; j < mins.size(); j++)
		{
			sm += mins[j];
		}
		PRINT("Case #%I64d: %I64d\n", i + 1, sm);
	}
	TRACE("ended.");
}