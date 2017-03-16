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
		cout << "Case #" << caseNumber << ": " << endl;
		
		// read input
		int B, N;
		int M[1000];
		
		fin >> B >> N;
		for (int i=0; i<B; i++)
			fin >> M[i];
			
		// lower bound
		double sumReciprocals = 0;
		for (int i=0; i<B; i++)
			sumReciprocals += 1.0/M[i];
		long x = (N-B)/sumReciprocals;
		if (x<0) x=0;
		
		int numServed = 0;
		for (int i=0; i<B; i++)
		{
			if (x % M[i] == 0)
				numServed += x / M[i];
			else
				numServed += int(x / M[i]) + 1;
		}
		
		if (numServed >= N) 
			cout << "this is bad" << endl;
		
		cout << x << "," << numServed << endl;
				
		// step until I get served
		int b;
		while(true)
		{
			for (b=0; b<B; b++)
			{
				if (x % M[b] == 0)
				{
					if (++numServed == N)
						goto output;
				}
			}
			x++;
		}
		
		output:
		fout << b+1 << endl;
	}
 
    return 0;
}