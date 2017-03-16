#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <iostream>
#include <queue>
#include <list>
#include <map>
#include <numeric>
#include <set>
#include <sstream>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

int main(){
	freopen("A-small-attempt0.in", "r", stdin);
	freopen("A-small-attempt0.out", "w+", stdout);
	int t;
    cin >> t;

	int a1;
	int a2;
	int c1[16];
	int c2[16];

	int numberMatched = 0;
	int matchedNum = -1;

	for(int ti = 0; ti < t; ti++){
		numberMatched = 0;
		matchedNum = -1;
		
		cout << "Case #" << (ti+1) << ": ";
		cin >> a1;
		
		for(int i = 0; i < 16; i++){
			cin >> c1[i];
		}

		cin >> a2;

		for(int i = 0; i < 16; i++){
			cin >> c2[i];
		}

		for(int i = 0; i< 4; i++){
			for(int j = 0; j < 4; j++){
				if(c1[(a1-1)*4 + i]  == c2[(a2-1)*4 + j]){
					matchedNum = c1[(a1-1)*4 + i];
					numberMatched++;
				}
			}
		}

		if(numberMatched == 0){
			cout << "Volunteer cheated!";
		}
		else if(numberMatched == 1){
			cout << matchedNum;
		}
		else{
			cout << "Bad magician!";
		}

		cout << endl;
	}

	fclose(stdout);
	fclose(stdin);
	return 0;
}