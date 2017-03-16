#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int method1(vector<int> mushrooms);
int method2(vector<int> mushrooms);
int maxdiff(vector<int> mushrooms);

int main()
{
	ifstream fin("a.in");
	ofstream fout("a.out");

	int cases, current_case, intervals;
	fin >> cases;
	current_case = 1;
	vector<int> mushrooms;
	int temp;
	while (current_case <= cases)
	{
		mushrooms.clear();
		fin >> intervals; // 10 second intervals
		for (int i = 0; i < intervals; i++)
		{
			fin >> temp;
			mushrooms.push_back(temp);
		}

		fout << "Case #" << current_case << ": " << method1(mushrooms) << " " << method2(mushrooms) << endl;
		current_case++;
	}

	fin.close();
	fout.close();
	return 0;
}

int method1(vector<int> mushrooms)
{
	//for this method if mushrooms go down she ate them
	//if they go up they were added
	int eaten = 0;
	for (int i = 0; i < mushrooms.size()-1; i++)
	{
		if (mushrooms[i] > mushrooms[i + 1])
			eaten += mushrooms[i] - mushrooms[i + 1];
		//else no mushrooms were eaten and some were added
	}
	return eaten;
}

int method2(vector<int> mushrooms)
{
	int rate = maxdiff(mushrooms);
	int eaten = 0;
	for (int i = 0; i < mushrooms.size()-1; i++)	//-1 so last intervel doesnt get counted
	{
		eaten += min(rate, mushrooms[i]);
	}
	return eaten;
}

int maxdiff(vector<int> mushrooms)
{
	int maxdiff = 0;
	for (int i = 0; i < mushrooms.size()-1; i++)
	{
		if (mushrooms[i] - mushrooms[i + 1] > maxdiff)
			maxdiff = mushrooms[i] - mushrooms[i + 1];
	}
	return maxdiff;
}