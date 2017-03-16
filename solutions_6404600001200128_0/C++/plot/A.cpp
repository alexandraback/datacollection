#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <cstdlib>
#include <vector>

using namespace std;

vector<int> solve(int* m, int n){
	long a = 0;
	long b = 0;
	long maxdiff = 0;
	vector<int> result;
	
	for(long i = 1; i < n; i++){
		if(m[i-1] > m[i]){
			a += m[i-1] - m[i];
			if(m[i-1] - m[i] > maxdiff)
				maxdiff = m[i-1] - m[i];
		}
	}
	
	for(long i = 0; i < n - 1; i++){
		b += m[i] < maxdiff ? m[i] : maxdiff;
	}
	
	result.push_back(a);
	result.push_back(b);
	
	return result;
}

int main() {
	int t, n;
	int *m;
	vector<int> result;
	
	cin >> t;
	
	for(int i = 0; i < t; i++){
		cin >> n;
		m = (int*)malloc(n * sizeof(int));
		for(int j = 0; j < n; j++)
			cin >> m[j];
		result = solve(m, n);
		cout << "Case #" << (i + 1) << ": " << result.at(0) << " " << result.at(1) << endl;
	}
	
	return EXIT_SUCCESS;
}
