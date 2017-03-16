#include<iostream>
#include<fstream>
#include<vector>
#include<algorithm>
#include<cstring>
#include<string>
#include<math.h>
#include<stdio.h>

using namespace std;

int T;
int N;
vector<int> S;

int main() {
	ifstream fin("input_a.txt");
	ofstream fout("output_a.txt");
	
	fin >> T;
	for(int tc = 1; tc <= T; tc++) {
		fin >> N;
		S.clear();
		S.resize(N);
		for(int i = 0; i < N; i++) {
			fin >> S[i];
		}
		fout << "Case #" << tc << ": ";
		while(true) {
			int cnt = 0;
			int maxi = -1;
			int idx;
			for(int i = 0; i < N; i++) {
				if(S[i] != 0) cnt++;
				if(maxi < S[i]) {
					maxi = S[i];
					idx = i;
				}
			}
			if(cnt > 2) {
				char tmp = 'A' + idx;
				fout << tmp;
				S[idx]--;
				fout << ' ';
			}
			else if(cnt != 0) {
				for(int i = 0; i < N; i++) {
					if(S[i] != 0) {
						char tmp = 'A' + i;
						fout << tmp;
						S[i]--;
					}
				}
				fout << ' ';
			}
			else break;
		}
		fout << endl;
	}
}
