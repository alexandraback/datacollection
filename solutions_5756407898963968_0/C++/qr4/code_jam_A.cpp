// code_jam_practice.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

template<typename T>
ostream& operator<<(ostream& str, const vector<T> &v)
{
	str << "[";
	for (int i = 0; i < v.size(); i++)
	{
		str << v.at(i) << ", ";
	}
	str << "]";
	return str;
}

template<typename T>
ostream& operator<<(ostream& str, const vector<pair<T,T>> &v)
{
	str << "[";
	for (int i = 0; i < v.size(); i++)
	{
		str << v.at(i).first << "-" << v.at(i).second << ", ";
	}
	str << "]";
	return str;
}

int _tmain(int argc, _TCHAR* argv[])
{
	int T;
	ifstream ifs("A-small-0.in", ifstream::in);
	ofstream ofs("A-small-0.out", ifstream::out);
	ifs >> T;
	for (int i = 0; i < T; i++)
	{
		int row1;
		ifs >> row1;
		
		vector<int> r1;
		for (int y = 1; y <= 4; y++)
		{
			for (int x = 1; x <= 4; x++)
			{
				int temp;
				ifs >> temp;
				if (y == row1)
				{
					r1.push_back(temp);
				}
			}
		}

		int row2;
		ifs >> row2;
		
		vector<int> r2;
		for (int y = 1; y <= 4; y++)
		{
			for (int x = 1; x <= 4; x++)
			{
				int temp;
				ifs >> temp;
				if (y == row2)
				{
					r2.push_back(temp);
				}
			}
		}

		sort(r1.begin(), r1.end());
		sort(r2.begin(), r2.end());

		int in_both = 0;
		int last = -1;


		for (int i = 0; i < r1.size(); i++)
		{
			for (int j = 0; j < r2.size(); j++)
			{
				if (r1[i] == r2[j])
				{
					last = r1[i];
					in_both++;
				}
			}
		}

		if (in_both == 0)
		{
			ofs << "Case #" << i+1 << ": Volunteer cheated!" << endl;
		} else if (in_both == 1)
		{
			ofs << "Case #" << i+1 << ": " << last << endl;
		} else {
			
			ofs << "Case #" << i+1 << ": Bad magician!" << endl;
		}
	}
	system("pause");
	return 0;
}

