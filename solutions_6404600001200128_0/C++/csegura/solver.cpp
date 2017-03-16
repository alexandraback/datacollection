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

using namespace std;

int main(){
	int tests;
	cin >> tests;
	for (int t = 0; t < tests; t++){
		int firstMethod = 0;
		int N;
		cin >> N;
		int mushrooms[N];
		for (int i = 0; i < N; i++){
			cin >> mushrooms[i];
		}
		for (int i = 1; i < N; i++){
			if (mushrooms[i] < mushrooms[i-1]){
				firstMethod += (mushrooms[i-1] - mushrooms[i]);
			}
		}
		int atLeastSecond = 0;
		for (int i = 1; i < N; i++){
			if (mushrooms[i] < mushrooms[i-1]){
				int atLeast = (mushrooms[i-1] - mushrooms[i]);
				atLeastSecond = max(atLeast, atLeastSecond);
			}
		}
		int solutionSecond = 0;
		for (int i = 0; i < N - 1; i++){
			int current = mushrooms[i];
			solutionSecond += min(mushrooms[i], atLeastSecond);
		}
		cout << "Case #" << (t+1) << ": " << firstMethod << " " << solutionSecond << endl;
	}
}
