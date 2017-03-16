#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <stack>
#include <assert.h>
#include <algorithm>
#include <math.h>
#include <ctime>
#include <functional>

#include <Windows.h>

using namespace std;

int main(int argc, char* argv[]) {
	ifstream inf(argv[1]); 

	int TC = 0; 
	inf >> TC; 
	for (int tc = 1; tc <= TC; tc++) {
		int n; 
		inf >> n; 
		vector<int> mu(n, 0); 
		for (int i = 0; i < n; i++) {
			inf >> mu[i]; 
		}

		int i1 = 0, i2 = 0; 
		for (int i = 1; i < n; i++) {
			if (mu[i] < mu[i - 1])
				i1 += mu[i - 1] - mu[i]; 
		}

		int maxEat = 0; 
		for (int i = 0; i < (n - 1); i++) {
			maxEat = max(maxEat, (mu[i] - mu[i + 1])); 
		}

		for (int i = 0; i < (n - 1); i++) {
			i2 += min(mu[i], maxEat);
		}


		cout << "Case #" << tc << ": " << i1  << " " << i2<< endl;
	}

	return 0; 
}