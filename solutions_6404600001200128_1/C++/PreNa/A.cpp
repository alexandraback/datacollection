#include <iostream>
#include <fstream>
using namespace std;

int main(){
	ifstream fin;
	fin.open("A-large.in");
	ofstream fout;
	fout.open("A-large.out");

	int cnt;
	fin >> cnt;
	for (int T = 1; T <= cnt; T++){
		int n;
		fin >> n;
		int m[1001];
		for (int i = 0; i < n; i++){
			fin >> m[i];
		}

		int a1 = 0;
		int t = m[0];
		int max = 0;
		for (int i = 1; i < n; i++){
			int t = m[i-1] - m[i];
			if (t > 0){
				a1 += t;
				if (max < t){
					max = t;
				}
			}
		}

		int a2 = 0;
		for (int i = 0; i < n-1; i++){
			if (m[i] < max){
				a2 += m[i];
			}
			else{
				a2 += max;
			}
		}

		fout << "Case #" << T << ": " << a1 << " " << a2;

		fout << endl;
	}

}