#include <iostream>
#include <fstream>
#include <vector>
//#include <string>
//#include <cstdlib>
#include <unordered_map>
#include <algorithm>
using namespace std;

int method1(vector<int> m)
{
	int N = m.size();
	int i, sum = 0;
	for(i = 1; i < N; i++)
		if(m[i] < m[i-1]) sum += m[i-1]-m[i];
	return sum;
}

int method2(vector<int> m)
{
	int N = m.size();
	int i, maxdiff = 0, sum = 0;
	for(i = 1; i < N; i++)
		if(m[i] < m[i-1] && m[i-1]-m[i] > maxdiff) maxdiff = m[i-1]-m[i];
	for(i = 0; i < N-1; i++)
		sum += min(maxdiff, m[i]);
	return sum;
}

int main()
{
	fstream  infile, outfile;
	infile.open("A-large.in", ios::in);
	
	infile.seekg(0, ios::end);  
	if (infile.tellg() == 0) return 0;
	infile.seekg(0, ios::beg);
	
	outfile.open("output.txt", ios::out | ios::trunc);
	int i, j, nCase, temp, N;
	vector<int> m;
	infile >> nCase;
	//cout << nCase << endl;
	for(i = 0; i < nCase; i++)
	{
		m.clear();
		infile >> N;
		for(j = 0; j < N; j++)
		{
			infile >> temp;
			m.push_back(temp);
		}
		outfile << "Case #" << i+1 << ": " << method1(m) << " " << method2(m) << endl;
	}
	
	infile.close();
	outfile.close();
	
	return 0;
}
