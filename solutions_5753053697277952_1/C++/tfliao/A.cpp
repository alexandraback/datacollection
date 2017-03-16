#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <string>
#include <cstring>
#include <cmath>
using namespace std;

int N, P[26];
int remain = 0;

int largest() 
{
	int mx = 0;
	for (int i=0;i<N;++i) {
		if (P[i] > P[mx]) mx = i;
	}
	return mx;
}


string evacuate()
{
	char ret[3];
	int e1, e2, e3;
	e1 = largest();
	P[e1] --; remain --;
	e2 = largest();
	P[e2] --; remain --;
	e3 = largest();
	
	if (P[e3] > remain / 2) {
		remain ++;
		P[e2] ++;
		ret[0] = 'A' + e1;
		ret[1] = 0;
	} else {
		ret[0] = 'A' + e1;
		ret[1] = 'A' + e2;
		ret[2] = 0;
	}
	return ret;
}

int main()
{
	int T;
	cin >> T;
	for (int nCase = 1; nCase <= T; ++nCase) {
		cin >> N;
		remain = 0;
		for (int i=0;i<N; ++i) {
			cin >> P[i];
			remain += P[i];
		}
		printf("Case #%d:", nCase);
		while (remain) {
			printf(" %s", evacuate().c_str());
		}
		printf("\n");
	}
	return 0;
}