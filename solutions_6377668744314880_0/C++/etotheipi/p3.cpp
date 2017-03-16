#include <fstream>
#include <iostream>
#include <string>
#include <cmath>

#define PI 3.14159265

using namespace std;

int N;
int X[15], Y[15];
int best[15];
int first;

// index is the index of the tree where we start wrapping
// angle is the angle of the ray from the tree which we will rotate counterclockwise until we hit a tree
// angle is in radian of course. It ranges from 0 to 2*PI
void wrap(int index, double angle)
{
	if (first<0) first = index;
	else if (first == index) return;

	cout << index << " with angle " << angle << endl;
	
	double angles[15];
	int order[15];
	for (int i=0; i<N; i++)
	{
		// compute angles
		if (i!=index)
		{
			angles[i] = atan2(Y[i] - Y[index], X[i] - X[index]);
			while (angles[i] < angle) angles[i] += 2 * PI;
		}
		else
			angles[i] = 100;
			
		// and sort at the same time
		int j = i-1;
		while(j>=0 && angles[i] < angles[order[j]])
		{
			order[j+1] = order[j];
			j--;
		}
		order[j+1] = i;
	}
	
	// update best kill count
	int rank = 0;
	for (int i=0; i<N-1; i++)
	{
		// don't forget that angles can tie
		// not sure about float point comparison, but let's worry about that later
		if (i>0 && angles[order[i]] > angles[order[i-1]])
			rank = i;
	
		if (best[order[i]] > rank)
		{
			best[order[i]] = rank;
			cout << "\t" << order[i] << " updates to " << rank << endl;
		}
	}
	
	// and backwards too
	rank = 0;
	for (int i=N-2; i>=0; i--)
	{
		if (i<N-2 && angles[order[i]] < angles[order[i+1]])
			rank = N-2 - i;
	
		if (best[order[i]] > rank)
		{
			best[order[i]] = rank;
			cout << "\t" << order[i] << " updates to " << rank << endl;
		}
	}
	
	wrap(order[0], angles[order[0]]);
}
		
int main()
{ 
	ifstream fin("input.txt");
	ofstream fout("output.txt");
	int numCases;
	fin >> numCases;
	
	for (int caseNumber=1; caseNumber<=numCases; caseNumber++)
	{
		fout << "Case #" << caseNumber << ": " << endl;
		cout << endl << "Case #" << caseNumber << ": " << endl;
		
		// read input
		fin >> N;
		for (int i=0; i<N; i++)
		{
			fin >> X[i] >> Y[i];
			best[i] = 100;
		}
		
		// get rid of trivial cases
		switch(N)
		{
			case 3:	fout << 0 << endl;
			case 2: fout << 0 << endl;
			case 1: fout << 0 << endl;
				continue;
		}
		
		// find lowest point
		int min = 0;
		for (int i=1; i<N; i++)
		{
			if (Y[i] < Y[min])
				min = i;
			if (Y[i] == Y[min] && X[i] > X[min])
				min = i;
		}
		
		// now wrap around the forest counterclockwise
		first = -1;
		wrap(min, 0);
		
		// output
		for (int i=0; i<N; i++)
			fout << best[i] << endl;
	}
 
    return 0;
}