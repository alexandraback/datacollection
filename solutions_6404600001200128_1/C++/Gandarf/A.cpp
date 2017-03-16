#include<iostream>
#include<fstream>
#include<vector>
#include<stack>
#include<queue>
#include<unordered_map>
#include<string>
#include<algorithm>
using namespace std;

int testn, n;
int a[1005];

int main()
{
	ifstream in("A-large.in");
	//ifstream in("input.txt");
	ofstream out("output.txt");

	in >> testn;
	for (int test = 1; test <= testn; ++test) 
	{
		// init

		// input
		in >> n;
		for (int i = 0; i < n; ++i)
			in >> a[i];

		// process
		//A
		int ra = 0, rb = 0;
		for (int i = 1; i < n; ++i)
		{
			if (a[i] < a[i-1])
				ra += (a[i-1] - a[i]);
		}

		//B
		int maxdiff = -1;
		for (int i = 1; i < n; ++i)
			maxdiff = max(maxdiff, a[i-1] - a[i]);

		for (int i = 0; i < n-1; ++i)
		{
			if (a[i] < maxdiff)
				rb += a[i];
			else
				rb += maxdiff;
		}

		// output
		out << "Case #" << test << ": " << ra << " " << rb << endl;
	}

	in.close();
	out.close();
	return 0;
}