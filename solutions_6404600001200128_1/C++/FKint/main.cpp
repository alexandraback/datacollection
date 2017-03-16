#include <bits/stdc++.h>
#include <cstdio>
using namespace std;

int main(){
	std::ios::sync_with_stdio(false);
	unsigned long long nb_testcases; cin >> nb_testcases;
	for(unsigned long long current_case = 1; current_case <= nb_testcases; ++current_case){
		unsigned long long N;
		cin >> N;
		unsigned long long first_method = 0;
		unsigned long long second_method = 0;
		unsigned long long prev;
		cin >> prev;
		vector<unsigned long long> v;
		v.push_back(prev);
		for(unsigned long long i = 1; i < N; ++i){
			unsigned long long t;
			cin >> t;
			if(t < prev){
				first_method += prev-t;
				second_method = max(second_method, prev-t);
			}
			prev = t;
			v.push_back(t);
		}
		cout << "Case #" << current_case << ": ";
		unsigned long long second_result = 0;
		for(unsigned long long i = 1; i < N; ++i){
			second_result += min(v[i-1], second_method);
		}
		cout << first_method << " " << second_result;
		cout << endl;
	}
    return 0;
}
