#include <iostream>
#include <vector>
#include <cmath>
#include <string>

using namespace std;


int main() {
	// your code goes here
	int numCases;
	cin >> numCases;
	for(int i=0; i<numCases; i++){
		cout << "Case #" << i+1 << ": ";
		int n;
		cin >> n;
		int ns[26];
		for(int x=0; x<26; x++){
			ns[x] = 0;
		}
		for(int x=0;x<n;x++){
			int temp;
			cin >> temp;
			ns[x]+=temp;
		}

		string out[26] = {"A","B","C","D","E","F","G","H","I","J","K","L","M","N","O","P","Q","R","S","T","U","V","W","X","Y","Z"};

		while(1){
			float avg = 0;
			int numMove[2] = {-1,-1};
			int numMoved = 0;
			int numAlive = 0;
			for(int x=0;x<n;x++){
				avg += (float)ns[x];
				if(ns[x] == 1)
					numAlive++;
			}
			avg = avg / (float)n;

			if(avg <= 0)
				break;

			if(!(numAlive == 3)){
				for(int x=0;x<n;x++){
					if(ns[x] >= avg && numMoved < 2){
						ns[x]--;
						numMove[numMoved] = x;
						numMoved++;
					}
				}
			}else{
				for(int x=0;x<n;x++){
					if(ns[x] >=1 && numMoved < 1){
						ns[x]--;
						numMove[numMoved] = x;
						numMoved++;
					}
				}
			}
			for(int x=0; x<2; x++){
				if(numMove[x] > -1)
					cout << out[numMove[x]];
			}
			cout << " ";
		}
		cout << "\n";
		
	}
	return 0;
}