#include <string>
#include <cstdio>
#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <cmath>
#include <stack>
#include <fstream>

using namespace std;

#define PQ priority_queue
typedef long long LL;
typedef pair<LL,LL> pll;

int T,N,num[30];

bool ok(int maxind,int sum) {
	for (int i=0;i<N;i++) {
		if (i==maxind) continue;
		if (num[i]*2>sum) return false;
	}
	return true;
}

int main() {
	ifstream F;
	F.open ("A-large.in");
	ofstream O;
	O.open ("A-large-out.txt");


	F >> T;
	for (int i=1;i<=T;i++) {
		F >> N;
		for (int j=0;j<N;j++) F >> num[j];

		O << "Case #" << i << ":" ;
		int sum,maxn,maxind;
		while (true) {
			sum = 0;
			for (int k=0;k<N;k++) sum += num[k];
			if (sum==0) break;
			maxn = 0;
			O << " ";
			for (int k=0;k<N;k++) {
				if (num[k]>maxn) {
					maxn = num[k];
					maxind = k;
				}
 			}
			O << (char)('A'+maxind);
			num[maxind]--;
			sum--;

			if (sum==0) break;
			maxn = 0;
			for (int k=0;k<N;k++) {
				if (num[k]>maxn) {
					maxn = num[k];
					maxind = k;
				}
 			}
			//cout << "[" << maxind << " " << sum << "]";
			if (ok(maxind,sum-1)) {
				O << (char)('A'+maxind);
				num[maxind]--;
				sum--;
			}
		}
		O << endl;
	}
	return 0;
}
