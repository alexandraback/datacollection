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
typedef long double LD;


ifstream fin ("C:\\CodeJam\\2015\\1B\\B\\B-large.in");
ofstream fout ("C:\\CodeJam\\2015\\1B\\B\\B-large.out");

int testCase = 0;

/*

who are you stop looking i dont like you

for (int i = 0; i < N; i++)
for (int j = 0; j < N; j++)
for (int k = 0; k < N; k++)

std::sort(A, A + N, std::less<int>());

vector.erase(vector.begin()+i);

*/

char A[10001][101];



void Solve()
{
	int R,C,N;


	
	fin>>R>>C>>N;

	if (R<C)
	{
		int tmp = R;
		R = C;
		C = tmp;
	}

	if (N<=(R*C+1)/2) {
		fout << "Case #" << testCase << ": "<<0<<endl;
		return;
	}
	int empty = R*C-N;
	int unhappy = (R-1)*C+(C-1)*R;


	
	for (int i = 0; i < R; i++)
		for (int j = 0; j < C; j++)
			A[i][j] = 0;
	
	int maxi = -1;
	int maxj = -1;
	while (empty)
	{
		int maxsum = 0;
		for (int i = 0; i < R; i++)
			for (int j = 0; j < C; j++) {
				if(A[i][j])
					continue;
				int sum = 0;
				if(i-1>=0 && !A[i-1][j])
					sum++;
				if(i+1<R && !A[i+1][j])
					sum++;
				if(j-1>=0 && !A[i][j-1])
					sum++;
				if(j+1<C && !A[i][j+1])
					sum++;
				if (sum > maxsum)
				{
					maxi = i;
					maxj = j;
					maxsum = sum;
				}
				if (maxsum == 4)
					break;
			}
		empty--;
		unhappy -= maxsum;
		A[maxi][maxj] = 1;
	}















	int unhappy2 = 0;
	for (int i = 0; i < R; i++)
		for (int j = 0; j < C; j++)
			A[i][j] = 0;
	
	maxi = -1;
	maxj = -1;
	while (N)
	{
		int maxsum = 4;
		for (int i = 0; i < R; i++)
			for (int j = 0; j < C; j++) {
				if(A[i][j])
					continue;
				int sum = 0;
				if(i-1>=0 && A[i-1][j])
					sum++;
				if(i+1<R && A[i+1][j])
					sum++;
				if(j-1>=0 && A[i][j-1])
					sum++;
				if(j+1<C && A[i][j+1])
					sum++;
				if (sum <= maxsum)
				{
					maxi = i;
					maxj = j;
					maxsum = sum;
				}
				if (maxsum == 0)
					break;
			}
		N--;
		unhappy2 += maxsum;
		A[maxi][maxj] = 1;
	}



	fout << "Case #" << testCase << ": "<<min(unhappy, unhappy2)<<endl;

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



