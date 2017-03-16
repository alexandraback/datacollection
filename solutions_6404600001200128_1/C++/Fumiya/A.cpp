#include <iostream>
#include <vector>
#include <cstdio>

using namespace std;

int solveA(const vector<int>& v){
	int res = 0;
	for (int i = 0; i + 1 < v.size(); i++){
		res += max(0, v[i] - v[i + 1]);
	}
	return res;
}

int solveB(const vector<int>& v){
	int eat = 0;
	for (int i = 0; i + 1 < v.size(); i++){
		eat = max(eat, v[i] - v[i + 1]);
	}
	int res = 0;
	for (int i = 0; i + 1 < v.size(); i++){
		res += min(eat, v[i]);
	}
	return res;
}

int main(){
	int T; cin >> T;
	for(int t=1;t<=T;t++){
		int N; cin >> N;
		vector<int> m(N);
		for (int i = 0; i < N; i++) cin >> m[i];
		printf("Case #%d: %d %d\n", t, solveA(m), solveB(m));
	}
}
