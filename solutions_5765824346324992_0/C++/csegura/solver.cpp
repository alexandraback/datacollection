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
		long long B, N;
		cin >> B >> N;
		long long times[B];
		for (int i = 0; i < B; i++){
			cin >> times[i];
		}
		long long timeNot = -1, timeYes = 10e16;
		long long attendingNot = 0;
		long long attendingYes = 0;
		for (int i = 0; i < B; i++){
			attendingYes += ((timeYes / times[i]) + 1);
		}
		while(timeNot + 1 != timeYes){
			long long newTime = (timeYes + timeNot) / 2;
			long long attending = 0;
			for (int i = 0; i < B; i++){
				attending += ((newTime / times[i]) + 1);
			}
			if (attending >= N){
				timeYes = newTime;
				attendingYes = attending;
			} else {
				timeNot = newTime;
				attendingNot = attending;
			}
		}
		long long position = N - attendingNot;
		long long ok = 0;
		for (int i = 0; i < B; i++){
			if ((timeYes % times[i]) == 0){
				ok++;
			}
			if (ok == position){
				cout << "Case #" << (t+1) << ": " << i + 1 << endl;
				break;
			}
		}
	}
}
