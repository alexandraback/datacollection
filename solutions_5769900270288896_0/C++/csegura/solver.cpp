#include <iostream>
#include <sstream>
#include <numeric>
#include <set>
#include <algorithm>
#include <map>
#include <vector>
#include <queue>
#include <stack>
#include <list>
#include <strings.h>
#include <limits.h>
using namespace std;

int getUnHap(vector< int > &occupation, int R, int C){
	int buildings[R][C];
	for (int i = 0; i < R; i++){
		for (int j = 0; j < C; j++){
			buildings[i][j] = occupation[i * C + j];
		}
	}
	int unHap = 0;
	for (int i = 0; i < R; i++){
		for (int j = 0; j < C; j++){
			if ( (i != R-1) && (buildings[i][j]) && (buildings[i+1][j])){
				unHap++;
			}
			if (( j != C-1) && (buildings[i][j]) && (buildings[i][j+1])){
				unHap++;
			}
		}
	}
	return unHap;
}

int main(){
	int tests;
	cin >> tests;
	for (int t = 0; t < tests; t++){
		int R, C, N;
		cin >> R >> C >> N;
		vector<int> occupation(R * C, 0);
		for (int i = 0; i < N; i++){
			occupation[i] = 1;
		}
		int unhappiness = INT_MAX;
		sort(occupation.begin(), occupation.end());
		do {
			unhappiness = min(unhappiness, getUnHap(occupation, R, C));
		} while(next_permutation(occupation.begin(), occupation.end()));
		cout << "Case #" << (t+1) << ": " << unhappiness << endl;
	}
}
