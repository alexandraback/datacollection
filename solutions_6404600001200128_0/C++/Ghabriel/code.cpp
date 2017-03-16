#include <iostream>
#include <math.h>
using namespace std;

#define RETURN_TYPE int

RETURN_TYPE parse1(int N, int *m){
	int total = 0;
	for (int i = 0; i < N - 1; i++){
		if (m[i] > m[i+1]){
			total += m[i] - m[i+1];
		}
	}
	return total;
}

RETURN_TYPE parse2(int N, int *m){
	int maxDelta = 0;
	for (int i = 0; i < N - 1; i++){
		int delta = m[i] - m[i+1];
		if (delta > maxDelta){
			maxDelta = delta;
		}
	}
	
	int total = 0;
	for (int i = 0; i < N - 1; i++){
		total += min(m[i], maxDelta);
	}
	return total;
}

int main(){
	int numberOfCases, i = 0;
	int N;
	int *m;
	
	cin >> numberOfCases;
	while (cin >> N){
		m = new int[N];
		for (int j = 0; j < N; j++){
			cin >> m[j];
		}
		RETURN_TYPE s1 = parse1(N, m);
		RETURN_TYPE s2 = parse2(N, m);
		cout << "Case #" << ++i << ": " << s1 << " " << s2 << endl;
	}
}