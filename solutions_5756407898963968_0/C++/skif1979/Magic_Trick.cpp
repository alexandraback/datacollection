#include <iostream>
#include <string>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <cmath>       
#include <math.h> 
#include <vector>
#include <algorithm>

using namespace std;

vector <int> getRow(FILE *infile)
{
	char row;
	vector <int> v;

	fscanf_s(infile, "%i\n", &row);

	for (int i = 1; i <= 4; i++)
	{
		char a;
		for (int j = 1; j <= 4; j++)
		{
			fscanf_s(infile, "%i", &a);
			if (i == row)
				v.push_back(a);
		}
	}
	sort(v.begin(), v.end());
	return v;
}


int main()
{
	FILE *infile;
	if (fopen_s(&infile, "A-small-attempt0.in", "r+"))
	{
		cout << "Error opening input file ";
		return getchar();
	}

	ofstream outfile("5.out", std::ios::out);
	if (outfile.bad())
	{
		cout << "Error opening output file ";
		return getchar();
	}

	int tcNumber;
	fscanf_s(infile, "%i\n", &tcNumber);

	for (int tc = 1; tc <= tcNumber; tc++)
	{
		vector <int> row1 = getRow(infile);
		vector <int> row2 = getRow(infile);
		vector <int> res;
		set_intersection(row1.begin(), row1.end(), row2.begin(), row2.end(), inserter(res, res.begin()));
		switch (res.size())
		{
		case 0:		outfile << "Case #" << tc << ": " << "Volunteer cheated!" << endl; break;
		case 1:		outfile << "Case #" << tc << ": " << res[0] << endl; break;
		default:	outfile << "Case #" << tc << ": " << "Bad magician!" << endl; break;
		}
	}

	//outfile
	outfile.close();
	return getchar();
}
