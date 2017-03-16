#include <fstream>
#include <iostream>
#include <string>

using namespace std;

int main()
{ 
	ifstream fin("input.txt");
	ofstream fout("output.txt");
	int numCases;
	fin >> numCases;
	
	for (int caseNumber=1; caseNumber<=numCases; caseNumber++)
	{
		fout << "Case #" << caseNumber << ": ";
		
		// read input
		int N;
		int m[1000];
		
		fin >> N;
		for (int i=0; i<N; i++)
			fin >> m[i];
			
		// first method
		int first = 0;
		int minRate = 0;
		int diff;
		for (int i=0; i<N-1; i++)
		{
			diff = m[i] - m[i+1];
		
			if (diff>0)
				first += diff;
			if (minRate < diff)
				minRate = diff;
		}
		
		// second method
		int second = 0;
		for (int i=0; i<N-1; i++)
		{
			if (m[i] >= minRate)
				second += minRate;
			else
				second += m[i];
		}
		
		// output
		fout << first << " " << second << endl;
	}
 
    return 0;
}