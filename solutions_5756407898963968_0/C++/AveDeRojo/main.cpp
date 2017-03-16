#include <algorithm>
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <iterator>
#include <set>

using std::vector;
using std::ostream;
using std::istream;
using std::set;

void getSortedRow(int rowNumber, std::ifstream &in, set<int>& sortedRow)
{
	sortedRow.clear();
	std::string rowStr;
	std::getline(in, rowStr);
	int countRows = 1;
	while (countRows != 5)
	{
		std::string temp;
		std::getline(in, temp);
		if (countRows == rowNumber)
			rowStr = temp;
		++countRows;
	};
	std::istringstream iss(rowStr);
	for (int j = 0; j < 4; ++j)
	{
		int number;
		iss >> number;
		sortedRow.insert(number);
	}
}

int main()
{
	std::ifstream in("A-small-attempt0.in");
	std::ofstream out("textOut.txt");
	int numberOfCases = 0;
	in >> numberOfCases;

	for (int i = 1; i < numberOfCases + 1; ++i)
	{
		int firstNumberOfRow;
		in >> firstNumberOfRow;	
		set<int> firstRow;
		getSortedRow(firstNumberOfRow, in, firstRow);
		int secondNumberOfRow;
		in >> secondNumberOfRow;
		set<int> secondRow;
		getSortedRow(secondNumberOfRow, in, secondRow);

		vector<int> resultIntersect;
		std::set_intersection(firstRow.begin(), firstRow.end(), 
			secondRow.begin(), secondRow.end(), std::back_inserter(resultIntersect));
		
		if (resultIntersect.size() > 1)
			out << "Case #" << i << ": Bad magician!" << std::endl;
		else if (resultIntersect.size() == 1)
			out << "Case #" << i << ": " << resultIntersect[0] << std::endl;
		else
			out << "Case #" << i << ": Volunteer cheated!" << std::endl;
	}

	return 0;
}