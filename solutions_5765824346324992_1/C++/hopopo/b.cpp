#include<iostream>
#include<vector>
#include<cstdio>

using namespace std;

bool can_cut(long long v, vector<int>& minutes, int g){
	long long sum = 0;
	for(int i = 0; i < minutes.size(); ++i){
		sum += v / minutes[i] + 1;
	}

	if(sum >= g) return true;
	return false;
}

long long get_when(long long from, long long step, vector<int>& minutes, int g){
	while(step > 0){
		long long mid = from + step/2;
		if(can_cut(mid, minutes, g)){
			step /= 2;
		}else{
			from = mid + 1;
			step = step - step/2 - 1;
		}
	}

	return from;
}

int main(){
	int tests;

	cin >> tests;
	
	for(int test = 1; test <= tests; ++test){
		int n, g;
		vector<int> minutes;
		cin >> n >> g;

		for(int i = 0; i < n ; ++i){
			int tmp;
			cin >> tmp;
			minutes.push_back(tmp);
		}

		long long when = get_when(0LL, 100000000000000LL, minutes, g);
		vector<int> wait;
		int done = 0;
		for(int i = 0; i < n; ++i){
			done += when / minutes[i] + 1;
			if(when % minutes[i] == 0){
				done -= 1;
				wait.push_back(i);
			}
		}
		int ans = wait[g - 1 - done] + 1;

		printf("Case #%d: %d\n", test, ans);
	}

	return 0;
}
