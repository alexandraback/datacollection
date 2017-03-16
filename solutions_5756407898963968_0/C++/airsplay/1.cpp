#include<fstream>
#include<iostream>
using namespace std;
int a[5][5], b[5][5];
int n, m;
int cnt;
bool hash[17];
int main(){
	ifstream fin("1.in");
	ofstream fout("1.out");
	int testSum;
	fin >> testSum;
	for (int test = 1; test <= testSum; test++){
		fout << "Case #" << test << ":" << ' ';
		fin >> n;
		for (int i = 1; i <= 4; i++)
			for (int j = 1; j <= 4; j++)
				fin >> a[i][j];
		fin >> m;
		for (int i = 1; i <= 4; i++)
			for (int j = 1; j <= 4; j++)
				fin >> b[i][j];
		for (int i = 1; i <= 16; i++)
			hash[i] = false;
		for (int i = 1; i <= 4; i++)
			hash[a[n][i]] = true;
		cnt = 0;
		int ans = 0;
		for (int i = 1; i <= 4; i++)
			if (hash[b[m][i]]){
				cnt ++;
				ans = b[m][i];
			}
		if (cnt == 1){
			fout << ans << endl;
		}
		else if (cnt > 1){
			fout << "Bad magician!" << endl;
		}
		else {
			fout << "Volunteer cheated!" << endl;
		}
	}

}
