
#include <cstdio>

FILE *file_in = fopen("input.txt", "rt"),
	*file_out = fopen("output.txt", "wt");

#include <algorithm>
#include <vector>
#include <set>
#include <stack>
#include <queue>
#include <limits>
#include <functional>
#include <iterator>
using namespace std;

void input(set<int> &a)
{
	int row;
	fscanf(file_in, "%d", &row);
	for (int i = 1; i <= 4; i++)
	{
		for (int j = 1; j <= 4; j++)
		{
			int data;
			fscanf(file_in, "%d", &data);
			
			if (i == row)
			{
				a.insert(data);
			}
		}
	}
}

void testCase()
{
	set<int> a, b;
	
	input(a);
	input(b);

	vector<int> result;
	set_intersection(a.begin(), a.end(), b.begin(), b.end(), back_inserter(result));

	if (result.size() == 1)
	{
		fprintf(file_out, "%d", result.front());
	}
	else if (result.size() == 0)
	{
		fprintf(file_out, "Volunteer cheated!");
	}
	else
	{
		fprintf(file_out, "Bad magician!");
	}
}

int main()
{
	int t;
	fscanf(file_in, "%d", &t);

	for (int i = 1; i <= t; i++)
	{
		fprintf(file_out, "Case #%d: ", i);
		testCase();
		fprintf(file_out, "\n");
	}

	return 0;
}