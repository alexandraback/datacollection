#include <bits/stdc++.h>
#include <cstdio>
using namespace std;
#define MAXM 100000


unsigned long long get_processed(unsigned long long time, vector<unsigned long long> &barbers){
	unsigned long long processed = 0;
	for(vector<unsigned long long>::iterator it = barbers.begin(); it != barbers.end(); ++it){
		processed += ((time)/ (*it)) + 1;
	}
	return processed;
}

int main(){
	std::ios::sync_with_stdio(false);
	int nb_testcases; cin >> nb_testcases;
	for(int current_case = 1; current_case <= nb_testcases; ++current_case){
		unsigned long long N;
		unsigned long long B;
		cin >> B >> N;
		vector<unsigned long long> barbers;
		for(int i = 0; i < B; ++i){
			unsigned long long T;
			cin >> T;
			barbers.push_back(T);
		}


		unsigned long long left = 0;
		unsigned long long right = N*MAXM;
		while(left < right){
			unsigned long long middle = (left+right)/2;
			unsigned long long processed = get_processed(middle, barbers);
			if(processed < N){
				left = middle+1;
			}else{
				right = middle;
			}
		}
		cout << "Case #" << current_case << ": ";
		unsigned long long remaining = N - get_processed(right - 1, barbers);
		for(int i = 0; i < B; ++i){
			if(right%barbers[i]==0){
				--remaining;
				if(remaining == 0){
					cout << i+1;
					break;
				}
			}
		}
		cout << endl;
	}
    return 0;
}
