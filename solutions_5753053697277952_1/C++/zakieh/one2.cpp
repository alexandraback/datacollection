#include <iostream>
#include <string>
#include <stdio.h>
#include <cmath>
#include <bitset>
#include <cstdlib>

using namespace std;
int main(int argc, char* argv[]) {

	int t;
	int n;
	int j;
	cin >> t;


	int templ[10] = {0, 2, 4, 6, 8, 7, 5, 9, 1, 3}; 

	for (int e = 1; e <= t; e++) {

		cout << "Case #" << e << ": "; 
		cin >> n;

		int nums[n];

			int max = 0;
			int aftermax = 0;
			int ind = -1;
			int afterind = -1;
			int remaining = n;

		for (int i = 0; i < n; i++) {
			cin >> nums[i];
			if (nums[i]>= max){
				aftermax = max;
				afterind = ind;
				max = nums[i];
				ind = i;
			}
		}
		while (remaining != 0) {
			

			if (remaining == 2 && max == aftermax){
				cout << char(ind + 'A') << char(afterind + 'A') << " ";
				nums[ind] = nums[ind] - 1;
				nums[afterind] = nums[afterind] - 1;
				if (nums[ind] == 0)
					remaining--;
				if (nums[afterind] == 0)
					remaining--;
			}
			else{
				cout << char(ind + 'A') << " ";
				nums[ind] = nums[ind] - 1;
				if (nums[ind] == 0)
					remaining--;

			}

			max = 0;
			aftermax = 0;
			ind = -1;
			afterind = -1;
			
			for (int i = 0; i < n; i++) {
				if (nums[i]>= max){
					aftermax = max;
					afterind = ind;
					max = nums[i];
					ind = i;
				}
			}
		}


   	    
		cout << endl;
		
		
	}


}