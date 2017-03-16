#include <cstdio>
#include <fstream>
#include <iostream>

using namespace std;
typedef long long ll;


int main(int argc, char* argv[]){
	ifstream infile(argv[1]);
	ofstream outfile("BOut");

	int numTrials;
	infile >> numTrials;

	for (int trial = 1; trial <= numTrials; trial++){
		outfile << "Case #" << trial << ": ";
		int B, N;
		infile >> B >> N;
		int M[B+1];
		for (int i = 1; i <= B; i++) infile >> M[i];
		
/*		ll prod = 1;
		for (int i = 1; i <= B; i++) prod *= M[i];

		N %= prod;
		if (N == 0) N += prod;*/

		float denom = 0;
		for (int i = 1; i<=B; i++) denom += (1.0/M[i]);
		ll Tlower, Tupper;
		//Tlower = (N-B)/denom - B;
		//Tupper = (N-1)/denom + B;
		//cout << Tlower << " " << Tupper << endl;
		Tlower = 0;
		Tupper = 9223372036854775800 / B; 
		while (Tupper - Tlower > 1){
			ll t = Tupper/2 + Tlower/2 + ((Tupper%2) + (Tlower%2))/2;
			ll tScore = 0;
			for (int i = 1; i <= B; i++){
				tScore += (t-1)/M[i];
				tScore += 1;
			}
			if (tScore >=N) Tupper = t;
			else Tlower = t;
		}

		ll T = Tlower;

		cout << "test "<< trial << " : T is " << T << endl;

		ll tScore = 0;
		for (int i = 1; i <= B; i++){
			tScore += (T-1)/M[i];
			tScore += 1;
		}
		int deficiency = N - tScore;
		for (int i = 1; i <= B; i++){
			if (T % M[i] == 0){
				deficiency --;
				if (deficiency == 0) outfile << i << endl;
			}
		}
		if (deficiency > 0) outfile << "FAIL "<<deficiency << endl;
	}
}
