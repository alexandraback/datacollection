#include <stdlib.h>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>
#include <functional>
#include <map>

using namespace std;

int main()
{
	ifstream ifs("C:/yoshiko/programming/gcj/2014/1b/A/A/A-large.in");
	ofstream ofs("C:/yoshiko/programming/gcj/2014/1b/A/A/A-large.out");
	string line;


	int nCases = 0;
	ifs >> nCases;

	for(int i=0; i<nCases; ++i)
	{
		int N = 0;
		ifs >> N;

		vector<string> vecStrings;
		vector<int> vecCurrentIndex;
		for(int j=0; j<N; ++j)
		{
			string tmp;
			ifs >> tmp;
			vecStrings.push_back(tmp);
			vecCurrentIndex.push_back(0);
		}

		bool isImpossible = false;
		int answer = 0;

		while(true)
		{
			bool isEndFound = false;
			bool isNotEndFound = false;
			for(int j=0; j<N; ++j)
			{
				if(vecCurrentIndex[j] >= vecStrings[j].length() && isEndFound == false)
				{
					isEndFound = true;
				}
				if(vecCurrentIndex[j] < vecStrings[j].length() && isNotEndFound == false)
				{
					isNotEndFound = true;
				}
			}
			if(isEndFound && !isNotEndFound)
			{
				break;
			}
			if(isEndFound && isNotEndFound)
			{
				isImpossible = true;
				break;
			}

			char currentChar = vecStrings[0][vecCurrentIndex[0]];
			map<int, int> mapCount;
			for(int j=0; j<N; ++j)
			{
				int tmpCurrentIndex = vecCurrentIndex[j];
				while(tmpCurrentIndex < vecStrings[j].length() &&
					vecStrings[j][tmpCurrentIndex] == currentChar)
				{
					tmpCurrentIndex++;
				}

				if(mapCount.find(tmpCurrentIndex - vecCurrentIndex[j]) != mapCount.end())
				{
					mapCount[tmpCurrentIndex - vecCurrentIndex[j]]++;
				}
				else
				{
					mapCount[tmpCurrentIndex - vecCurrentIndex[j]] = 1;
				}

				vecCurrentIndex[j] += (tmpCurrentIndex - vecCurrentIndex[j]);
			}

			if(mapCount.find(0) != mapCount.end() && mapCount[0] > 0)
			{
				isImpossible = true;
				break;
			}

			int minCount = -1;
			map<int, int>::iterator it = mapCount.begin();
			for(; it!=mapCount.end(); ++it)
			{
				int count = 0;

				map<int, int>::iterator it2 = mapCount.begin();
				for(; it2!=mapCount.end(); ++it2)
				{
					count += abs(it2->first - it->first) * it2->second;
				}

				if(minCount < 0 || count < minCount)
				{
					minCount = count;
				}
			}

			answer += minCount;
		}

		if(isImpossible)
		{
			ofs << "Case #" << i+1 << ": Fegla Won" << endl;
		}
		else
		{
			ofs << "Case #" << i+1 << ": " << answer << endl;
		}
	}
}