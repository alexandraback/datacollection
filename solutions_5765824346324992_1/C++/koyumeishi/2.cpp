#include <iostream>
#include <vector>
#include <cstdio>
#include <sstream>
#include <map>
#include <string>
#include <algorithm>
#include <queue>
#include <cmath>
#include <set>
using namespace std;

long long solve(){
	int B;
	long long N;
	cin >> B >> N;
	vector<int> M(B);
	for(int i=0; i<B; i++){
		cin >> M[i];
	}

	if(N <= B){
		return N;
	}

	long long lb = 0;
	long long ub = 1LL<<60;

	auto calc = [&](long long t){
		long long ret = 0;
		for(int i=0; i<B; i++){
			ret += t/M[i] + 1;
		}
		return ret;
	};

	while(ub - lb > 1){
		long long med = (lb+ub)/2;
		long long num = calc(med);
		if(N <= num){
			ub = med;
		}else{
			lb = med;
		}
	}
	long long t = ub;
	long long cnt = 0;
	for(int i=0; i<B; i++){
		if(t%M[i] != 0) cnt += t/M[i] + 1;
		else cnt += t/M[i];
	}

	for(int i=0; i<B; i++){
		if(t%M[i] != 0) continue;
		if(cnt + 1 == N){
			return i + 1;
		}
		cnt++;
	}

	return -1;

}

int main(){
	int T;
	cin >> T;
	for(int t=1; t<=T; t++){
		cout << "Case #" << t << ": " << solve() << endl;
	}
	return 0;
}