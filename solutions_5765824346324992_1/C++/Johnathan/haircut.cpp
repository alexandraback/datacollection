#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <map>
#include <string>
#include <vector>

using namespace std;

int main(){
	freopen("input.in","r",stdin);
	freopen("output.out","w",stdout);
	int n = 0; 
	int t;
	cin >> t;
	while (n++ < t){
		long long int B, N;
		cin >> B>>N;
		long long int b[100000];
		long long int UB = 0;

		for (int i = 0; i <B; i++){
			cin >> b[i];
			if (b[i] > UB)
				UB = b[i];
		}
		UB *= N;

		//readin
		long long int LB = 0;
		
		while (LB < UB){
			long long int mid =(LB +UB)/2;
			long long int done = 0;
			for (int i = 0; i < B; i++){
				done += mid/b[i]; 
			}
			done += B;
			
			if (done >= N){
				UB = mid - 1;
			}
			else //done < N
				LB = mid + 1;
			//cout << mid << " "<<LB << " "<<UB << endl;
			
		}
		
		//LB+1 or LB is the time
		long long int done = 0;
		for (int i = 0; i < B; i++){
			done += LB/b[i];
		}
		done += B;
		long long int t;
		if (done < N)
			t = LB + 1;
		else 
			t = LB;
		//long long int t = LB+1;
		long long int hasdone = 0;
				for (int i = 0; i < B; i++){
			hasdone += (t-1)/b[i];
		}
		hasdone += B;

		long long int rest = N - hasdone;

		//at time t, rest people still being ready to be served
		int index = -1;
		for (int i = 0; i < B; i++){
			if (t % b[i] == 0){
				rest--;
				if (rest == 0){
					index = i;
					break;
				}
			}
		}

		cout << "Case #" << n<< ": " << index + 1  << endl;
	}
	return 0;
}