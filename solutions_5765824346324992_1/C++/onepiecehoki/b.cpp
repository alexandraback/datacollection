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

typedef long long ll;

int findBarberNumber(int N, const vector<pair<int, int> >& M){
	//We will do a binary search on possible time
	//For each time we calculate the number of customer served and number of available barber
	ll maxTime= 1000000000000000LL;
	ll minTime = 0LL;
	ll curTime = (minTime + maxTime) / 2;
	
	while (minTime <= maxTime){
			curTime = (minTime + maxTime) / 2;
			ll numCustomerServed = 0; //from time 0 to time curTime - 1
			int numAvailableBarber = 0;
			for (int i=0; i < M.size(); ++i){
				numCustomerServed += (curTime-1) / M[i].first;
				if (curTime % M[i].first == 0 ) {
					numAvailableBarber++;
				}
			}
			if (curTime > 0) numCustomerServed += M.size();
			if (curTime == 0) numCustomerServed = 0;
			//cout << curTime << " " << numCustomerServed << " " << numAvailableBarber << endl;
			
			if (numCustomerServed < N && numCustomerServed + numAvailableBarber >= N){
				int queueSize = N - numCustomerServed;
				//Get the barber
				int curQueue = queueSize;
				for (int i=0; i < M.size(); ++i){
					if (curTime % M[i].first == 0) curQueue--;
					if (curQueue <= 0) {
						//cout << i << ": " << M[i].first << " " << M[i].second << endl;
						return M[i].second;
					}
				}
			}
			else if (minTime == maxTime){
				break;
			}
			else if (numCustomerServed + numAvailableBarber < N){
				//Go to the right
				minTime = curTime+1;
				continue;
			}
			else if (numCustomerServed >= N){
				//Go to the left
				maxTime = curTime-1;
				continue;
			}
	}
	return -1;
}

int main(){
	int T;
	cin >> T;
	for (int t=1; t <= T; ++t){
		int B, N;
		cin >> B >> N;
		
		vector<pair<int, int> > M(B);
		for (int i=0; i < B; ++i){
			cin >> M[i].first;
			M[i].second = i+1;
		}
		
		int barberNumber = findBarberNumber(N, M);
		
		
		cout << "Case #" << t << ": ";
		cout << barberNumber << endl;

	}
	
	return 0;
}
