#include<iostream>
#include<vector>
#include<cstdio>

using namespace std;

int main(){
	int tests;

	cin >> tests;

	for(int test = 1; test <= tests; ++test){
		int n;
		vector<int> numbers;
		cin >> n;

		for(int i = 0; i < n; ++i){
			int tmp;
			cin >> tmp;
			numbers.push_back(tmp);
		}

		int ans1 = 0;

		for(int i = 1; i < n; ++i){
			if(numbers[i-1] - numbers[i] > 0)
				ans1 += numbers[i-1] - numbers[i];
		}

		int rate = 0;
		for(int i = 1; i < n; ++i){
			if(numbers[i-1] - numbers[i] > rate)
				rate = numbers[i-1] - numbers[i];
		}
		int ans2 = 0;
		for(int i = 1; i < n; ++i){
			if(numbers[i-1] > rate){
				ans2 += rate;
			}else{
				ans2 += numbers[i-1];
			}
		}
			
		printf("Case #%d: %d %d\n", test, ans1, ans2);
	}

	return 0;
}
