#include <stdio.h>
#include <string>
#include <iostream>
#include <map>
#include <unistd.h>

using namespace std;

int main(void) {
    unsigned short int t;

    cin >> t;

    for(int j=1; j <= t; j++) {
    	int n;
        	cin >> n; // # of parties
        	
        	map<char,int> senators;
        	for (int i = 0; i < n; i++) {
        		char c = 'a' + i;
        		int x;
        		cin >> x;
        		senators[c] = x;
        		//cout << c << ": " << x << "\n";
        	}


	cout << "Case #" << j << ": ";
        	while (true) {
        		char maxIndex = 0;
        		int maxMembers = 0;
        		int membersLeft = 0;

        		char maxIndex2 = 0;
        		int maxMemeberPartiesCount = 0;



        		for (int i = 0; i < n; i++) {
        			char index = 'a' + i;
        			membersLeft += senators[index];
        			if (senators[index] == maxMembers && maxMembers > 0) {
        				maxIndex2 = index;
        				maxMemeberPartiesCount++;
        			}
        			if (senators[index] > maxMembers) {
        				maxIndex = index;
        				maxMembers = senators[index];
        				maxMemeberPartiesCount = 1;
        			}

        		}
        		if (membersLeft <= 2) {
        			break;
        		}
        		char memberOut = maxIndex;
        		senators[maxIndex] = senators[maxIndex] - 1;
        		cout << memberOut;
        		if (maxIndex2 > 0 && !(maxMembers == 1 && maxMemeberPartiesCount ==3)) {
        			char memberOut2 = maxIndex2;
        			senators[maxIndex2] = senators[maxIndex2] - 1;
        			cout << memberOut2;
        		}
        		cout << " ";

        		
        		//usleep(5000);
        	}

        	for (int i = 0; i < n; i++) {
        		char c = 'a' + i;
		if (senators[c] > 0) {
			cout << c;
		}
	}
	cout << "\n";

    }
    return 0;
}
