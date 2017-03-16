#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

ofstream fout("out.txt");
ifstream fin("in.txt");

string alpha = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

void function1(const int test_no) {
	int N;
	fin >> N;

	vector<int> P(N, 0);

	

	for (int i = 0; i < N; i++)
		fin >> P[i];

	for (int i = 0; i < N; i++)
		cout << P[i] << endl;

	//identify 2 biggest
	int big=-1, big2=-1;
	int bigv = 0, big2v = 0;

	for (int i = 0; i < N; i++) {
		if (P[i] > big2v) {
			big2v = P[i];
			big2 = i;
			if (P[i] > bigv) {
				int ph = big;
				int ph_v = bigv;
				big = i;
				bigv = P[i];

				big2v = ph_v;
				big2 = ph;
			}
		}
	}

	cout << "Biggest are " << big << " and " << big2 << " with " << bigv << " and " << big2v << endl;
	
	string t = "";

	//reduce 1 till same size
	for(int i=0;i<(bigv - big2v);i++)
		t += string(1, alpha[big]) + " ";
	P[big] = P[big2];


	//get rid of rest
	for (int i = 0; i < N; i++) {
		if (i == big || i == big2)
			continue;
		for(int j=0;j<P[i];j++)
			t+= string(1,alpha[i]) + " ";
	}

	//get rid of 2 biggest 2 at a time
	for (int i = 0; i < big2v; i++) {
		t += string(1, alpha[big]) + string(1, alpha[big2]) + " ";
	}


	fout << "Case #" << test_no << ": " << t << endl;
}

int main() {
	int T;
	fin >> T;
	for (int t = 1; t <= T; t++) {
		function1(t);
	}

	return 0;
}
