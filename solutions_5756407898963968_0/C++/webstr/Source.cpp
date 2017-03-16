#include <iostream>
#include <fstream>
#include <string>
using namespace std;

const int N = 4;

string check(int *mas){
	int k = 0;
	int res = -1;
	for (int i = 0; i < N * N; i++){
		if (mas[i] == 2){
			res = i + 1;
			k++;
		}
	}
	
	if (k == 0){
		return "Volunteer cheated!";
	} else if (k == 1){
		return to_string(res);
	} else {
		return "Bad magician!";
	}
}

int main(){
	ifstream fin;
	ofstream fout;
	int T;
	
	fin.open("input.txt");
	fout.open("output.txt");
	fin >> T;
	for (int k = 1; k <= T; k++){
		int ans1, ans2;
		int mas1[N][N], mas2[N][N];
		int mas[N * N];
		memset(mas, 0, sizeof(mas));

		fin >> ans1;
		for (int i = 0; i < N; i++){
			for (int j = 0; j < N; j++){
				fin >> mas1[i][j];
			}
		}

		fin >> ans2;
		for (int i = 0; i < N; i++){
			for (int j = 0; j < N; j++){
				fin >> mas2[i][j];
			}
		}

		for (int i = 0; i < N; i++){
			mas[mas1[ans1 - 1][i] - 1]++;
			mas[mas2[ans2 - 1][i] - 1]++;
		}

		string str = check(mas);
		fout << "Case #" << k << ": " << str << endl;
		

	}
}