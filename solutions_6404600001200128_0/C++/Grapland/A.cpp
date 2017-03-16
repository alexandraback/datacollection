// B.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;


int main(){
	int T;
	cin >> T;
	for (int tt = 0; tt < T; tt++){
		int N;
		cin >> N;
		vector<int> ipt(N);
		for (int i = 0; i < N; i++){
			cin >> ipt[i];
		}
		int a1 = 0, a2 = 0;
		int maxs = 0;
		for (int i = 1; i < N; i++){
			if (ipt[i] < ipt[i - 1]){
				a1 += ipt[i-1] - ipt[i];
				maxs = max(maxs, ipt[i-1]-ipt[i]);
			}
		}
		for (int i = 1; i < N; i++){
				a2 += min(maxs, ipt[i - 1]);
		}
		cout << "Case #" << tt + 1 << ": " << a1 << " " << a2 << endl;
	}
}