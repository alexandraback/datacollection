#include <iostream>
using namespace std;

#define RETURN_TYPE int

RETURN_TYPE parse(int B, long N, int *M){
	double *rates = new double[B+1];
	double sum = 0;
	double total = 0;
	for (int i = 1; i <= B; i++){
		rates[i] = ((double) M[1]) / M[i];
		sum += rates[i];
		if (sum >= N){
			return i;
		}
	}

	total += sum * (int) (N / sum);
	while (total < N){
		for (int i = 1; i <= B; i++){
			total += rates[i];
			if (total >= N){
				return i;
			}
		}
	}
	
	return B;
}

int main(){
	int numberOfCases, i = 0;
	int B;
	long N;
	
	cin >> numberOfCases;
	while (cin >> B >> N){
		int *M = new int[B+1];
		for (int j = 1; j <= B; j++){
			cin >> M[j];
		}
		RETURN_TYPE solution = parse(B, N, M);
		cout << "Case #" << ++i << ": " << solution << endl;
	}
}