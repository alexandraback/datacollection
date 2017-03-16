#include <stdlib.h>
#include <cmath>
#include <vector>
#include <queue>
#include <iostream>
#include <string>
#include <string.h>
#include <stdio.h>
#include <math.h>
#include <sstream>
#include <algorithm>
#include <map>
#include <stack>
#include <set>
#include <list>
#include <complex>
using namespace std;

typedef unsigned long long ui64;
typedef long long i64;

string getBase(string s){
	if(s.size() == 1){ return s; }
	string result = s.substr(0,1);
	
	for(int i = 1; i < s.size(); i++){
		if(s.at(i) != result.at(result.size()-1)){
			result += s.substr(i,1);
		}
	}

	return result;
}

void JeMoeder(int caseNr) {
	cout << "Case #" << caseNr << ": ";
	int n; cin >> n;
	vector<string> input(n);
	
	for(int i = 0; i < n; i++){
		cin >> input[i];
	}
	
	
	// first check if it is feasable
	for(int i = 0; i < n; i++){
		if(getBase(input[i]) != getBase(input[0])){
			cout << "Fegla Won" << endl;
			return;
		}
	}
	
	// no determine the required number of transformations
	int answer = 0;
	string base = getBase(input[0]);
	
	for(int i = 0; i < base.size(); i++){
		vector<int> cur(n);
		int maximum = 0;
		
		for(int j = 0; j < n; j++){
			// check how many we have
			int count = 0;
			while(count < input[j].size() && input[j].at(count) == base[i]){
				count++;
			}
			if(count > maximum){ maximum = count; }
			
			input[j] = input[j].substr(count,input[j].size());
						
			cur[j] = count;
		}
		

		int best = 100000;
		for(int i = 1; i <= maximum; i++){
			int now = 0;
			for(int j = 0; j < n; j++){
				
				now += abs(cur[j] - i);
			}
			
			if(now < best){ best = now; }
		}
		
		answer += best;
	}
	
	
	cout << answer << endl;
	
	
}

int main() {
	int runs; cin >> runs;
	for(int i = 1; i <= runs; i++){
		JeMoeder(i);
	}
	return 0;
}
