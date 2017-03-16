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
	long tests;
	cin >> tests;
	for (int t = 0; t < tests; t++){
		long firstMethod = 0;
		long N;
		cin >> N;
		long mushrooms[N];
		for (int i = 0; i < N; i++){
			cin >> mushrooms[i];
		}
		for (int i = 1; i < N; i++){
			if (mushrooms[i] < mushrooms[i-1]){
				firstMethod += (mushrooms[i-1] - mushrooms[i]);
			}
		}
		long atLeastSecond = 0;
		for (int i = 1; i < N; i++){
			if (mushrooms[i] < mushrooms[i-1]){
				long atLeast = (mushrooms[i-1] - mushrooms[i]);
				atLeastSecond = max(atLeast, atLeastSecond);
			}
		}
		long solutionSecond = 0;
		for (int i = 0; i < N - 1; i++){
			long current = mushrooms[i];
			solutionSecond += min(mushrooms[i], atLeastSecond);
		}
		cout << "Case #" << (t+1) << ": " << firstMethod << " " << solutionSecond << endl;
	}
}
