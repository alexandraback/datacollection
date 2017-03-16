#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <utility>
#include <map>
#include <queue>
#include <cmath>
#include <functional>

using namespace std;

const string outPrefix = "Case #";

int main(){
	int T;
	cin >> T;
	
	for (int t=1; t <= T; ++t){
		int N;
		cin >> N;
		
		vector<int> mush(N);
		for (int i=0; i < N; ++i){
			cin >> mush[i];
			//cout << i << " " << mush[i] << endl;
		}
		
		
		int totalDecrease = 0;
		int maxDecrease = 0;
		for (int i=0; i < mush.size()-1; ++i){
			if (mush[i] > mush[i+1]){
				int diff = mush[i] - mush[i+1];
				totalDecrease += diff;
				if (diff > maxDecrease) maxDecrease = diff;
			}
		}
		
		int method1 = totalDecrease;
		int method2 = 0;
		for (int i=0; i < mush.size()-1; ++i){
			if (mush[i] < maxDecrease) method2 += mush[i];
			else method2 += maxDecrease;
		}
		
		cout << "Case #" << t << ": ";
		cout << method1 << " " << method2 << endl;

	}
	
	return 0;
}
