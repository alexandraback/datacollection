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


ifstream fin ("C:\\CodeJam\\2014\\Qualifications\\A\\A-small-attempt0.in");
ofstream fout ("C:\\CodeJam\\2014\\Qualifications\\A\\A-small-attempt0.out");

int testCase = 0;

int A[4][4] = {0};
int B[4][4] = {0};
int Count[4] = {0};


void Solve()
{
	int i,j,k;
	int solA,solB;
	
	fin>>solA;
	solA--;
	
	for (i = 0; i < 4; i ++) {
		for (j = 0; j < 4; j ++) {
			fin>>A[i][j];
		}
	}

	fin>>solB;
	solB--;
	 
	for (i = 0; i < 4; i ++) {
		for (j = 0; j < 4; j ++) {
			fin>>B[i][j];
		}
	}
	
	for (i = 0; i < 4; i++) {
		Count[i] = 0;
		for (j = 0; j < 4; j ++) {
			if(A[solA][i] == B[solB][j])
				Count[i]=1;
		}		
	}
	
	int sum = 0;
	for (i = 0; i < 4; i++) {
		sum += Count[i];
	}
	if (sum == 0) {
		fout << "Case #" << testCase << ": "<<"Volunteer cheated!"<<endl;
		return;
	} else if(sum >= 2) {
		fout << "Case #" << testCase << ": "<<"Bad magician!"<<endl;
		return;
	} else {
		for (i = 0; i < 4; i++) {
			if (Count[i] == 1) {
				fout << "Case #" << testCase << ": "<<A[solA][i]<<endl;
				return;
			}
		}
	}
	cout<<"Error"<<endl;
	
	




	fout << "Case #" << testCase << ": "<<"Yes"<<endl;

}




void main()
{

	fout.precision(15);
	cout.precision(15);
	

	int TestCases = 0;
	fin>>TestCases;

	for (testCase = 1; testCase <= TestCases; testCase++) {
		
		Solve();

	}

	cout<<"finished"<<endl;
	getchar();

}



