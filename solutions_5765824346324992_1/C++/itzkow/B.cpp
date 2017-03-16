#include <algorithm>
#include <bitset>
#include <cassert>
#include <cctype>
#include <climits>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <fstream>
#include <functional>
#include <iomanip>
#include <iostream>
#include <limits>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>
using namespace std;
typedef long long LL;


ifstream fin ("C:\\CodeJam\\2015\\1A\\B\\B-large.in");
ofstream fout ("C:\\CodeJam\\2015\\1A\\B\\B-large.out");

int testCase = 0;

/*

who are you stop looking i dont like you

for (int i = 0; i < N; i++)
for (int j = 0; j < N; j++)
for (int k = 0; k < N; k++)

std::sort(A, A + N, std::less<int>());

vector.erase(vector.begin()+i);

*/

int M[1001];


void Solve()
{

	LL B,N;
	
	fin>>B>>N;
	for (int i = 0; i < B; i++)
		fin>>M[i];
	
	LL seconds = 0;
	LL mins = 0;
	LL maxs = 200000000000000;
	LL maxssum=200000000000000;
	LL minssum=0;

	while (mins < maxs-1)
	{
		seconds = (mins + maxs) / 2;

		LL sum = 0;
		
		for (int i = 0; i < B; i++)
		{
			sum += ((seconds-1) / M[i])+1;
		}
		if (sum >= N) {
			maxs = seconds;
			maxssum = sum;
		}
		else {
			mins = seconds;
			minssum = sum;
		}
	}
	
	for (int i = 0; i < B; i++)
	{
		if (mins%M[i] == 0)
		{
			minssum++;
			if (minssum == N)
			{
				fout << "Case #" << testCase << ": "<<i+1<<endl;
				return;
			}
		}

	}
	cout<<"ERROR";




}




void main()
{

	fout.precision(15);
	cout.precision(15);
	

	int TestCases = 0;
	fin>>TestCases;

	for (testCase = 1; testCase <= TestCases; testCase++) {
		
		Solve();
		if (testCase == 1+TestCases/20) {
			cout<<"5%"<<endl;
		} else if (testCase == 1+TestCases/4) {
			cout<<"25%"<<endl;
		} else if (testCase == 1+2*TestCases/4) {
			cout<<"50%"<<endl;
		} else if (testCase == 1+3*TestCases/4) {
			cout<<"75%"<<endl;
		}

	}

	cout<<"100%"<<endl;
	cout<<"finished"<<endl;
	getchar();

}



