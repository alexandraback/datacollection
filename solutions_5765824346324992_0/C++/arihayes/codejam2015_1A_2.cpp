#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

long gcd(long a, long b) {
    while(true) {
        if (a == 0){
			return b;
		}
        b %= a;
		
        if (b == 0){
			return a;
		}
        a %= b;
    }
}

long lcm(long a, long b) {
	return a / gcd(a, b) * b;
}

long totalLCM(long list[], int start, int end) {
	if(end - start == 1) {
		return list[start];
	} else if(end - start == 2) {
		return lcm(list[start], list[start + 1]);
	} else {
		int pivot = (start + end) / 2;
		return lcm(totalLCM(list, start, pivot), totalLCM(list, pivot, end));
	}
}

int main() {
	int numCases;
	cin >> numCases;
	
	long barbers[1000];
	int busy[1000];
	
	for(int x = 1; x <= numCases; x++) {
		int numBarbers;
		int myPos;
		cin >> numBarbers >> myPos;
		for(int y = 0; y < numBarbers; y++) {
			cin >> barbers[y];
		}		
		
		if(myPos <= numBarbers) {
			cout << "Case #" << x << ": "; 
			cout << myPos;
			cout << "\n";
			continue;
		} else if(numBarbers == 1) {
			cout << "Case #" << x << ": 1\n"; 
			continue;
		}
		
		long multiple = totalLCM(barbers, 0, numBarbers);
		
		int totalPerMult = 0;
		for(int y = 0; y < numBarbers; y++) {
			totalPerMult += multiple / barbers[y];
		}
		
		if(myPos > totalPerMult) {
			myPos = myPos % totalPerMult;
			if(!myPos) {
				myPos = totalPerMult;
			}
		}
		
		int blah = 1;
		int answer = 0;
		int minBusy = 100000;
		for(int b = 0; b < numBarbers; b++) {
			if(blah == myPos) {
				answer = b + 1;
				break;
			}
			blah++;
			busy[b] = barbers[b];
			if(busy[b] < minBusy) {
				minBusy = busy[b];
			}
		}
		while(!answer) {
			for(int b = 0; b < numBarbers; b++) {
				busy[b] -= minBusy;
			}
			minBusy = 100000;
			for(int b = 0; b < numBarbers; b++) {
				if(!busy[b]) {
					if(blah == myPos) {
						answer = b + 1;
						goto printAnswer;
					}
					blah++;
					busy[b] = barbers[b];
				}
				if(busy[b] < minBusy) {
					minBusy = busy[b];
				}
			}
		}
		printAnswer:
		cout << "Case #" << x << ": "; 
		cout << answer;
		cout << "\n";
	}
}
