#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

int main() {
	int mushrooms[1000];	
	
	int numCases;
	cin >> numCases;
	
	for(int x = 1; x <= numCases; x++) {
		int numTimes;
		cin >> numTimes;
		int start;
		cin >> start;
		if(numTimes == 1) {
			cout << "Case #" << x << ": 0 0\n";
			continue;
		}
		
		mushrooms[0] = start;
		int maxDecrease = 0;
		int poss1 = 0;
		int prev = start;
		for(int y = 1; y < numTimes; y++) {
			int next;
			cin >> next;
			if(next < prev) {
				poss1 += (prev - next);
				if(prev - next > maxDecrease) {
					maxDecrease = prev - next;
				}
			}
			
			mushrooms[y] = next;
			prev = next;
		}
		
		int poss2 = 0;
		for(int y = 0; y < numTimes - 1; y++) {
			int temp = maxDecrease;
			if(mushrooms[y] < temp) {
				temp = mushrooms[y];
			}
			poss2 += temp;
		}
		
		cout << "Case #" << x << ": "; 
		cout << poss1;
		cout << " ";
		cout << poss2;
		cout << "\n";
	}
}
