//============================================================================
// Name        : Problem.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <fstream>
#include <iostream>
#include <vector>
#include <set>
#include <string>
#include <algorithm>
#include <cmath>
#include <map>

using namespace std;

int main()
{
	// open a file in read mode.
	ifstream infile;
//	infile.open("src/in");
//	infile.open("src/A-small-attempt0.in");
	infile.open("src/A-large.in");

	// open a file in write mode.
	ofstream outfile;
	outfile.open("src/out");

	int T;
	infile>>T;
	for (int i = 1; i <= T; ++i)
	{
		size_t N;
		infile>>N;
		outfile<<"Case #"<<i<<": ";

		vector<pair<int, char> >data(N);
		int senators = 0;
		for (size_t j = 0; j < N; ++j)
			infile>>data[j].first, data[j].second = 'A' + j, senators += data[j].first;

		string answer;


		for (;senators > 0;)
		{
			sort(data.begin(), data.end());
			--senators;
			--data.back().first;
			answer += data.back().second;

			sort(data.begin(), data.end());
			bool check = true;
			for (int h = 0; h < N-1 && check; ++h)
				if (data[h].first == (senators + 1) / 2)
					check = false;

			if (check)
			{
				--senators;
				--data.back().first;
				answer += data.back().second;
			}
			answer += " ";
		}

		answer.resize(answer.size() - 1);
		outfile<<answer<<endl;

	}
	outfile.close();
	return 0;
}
