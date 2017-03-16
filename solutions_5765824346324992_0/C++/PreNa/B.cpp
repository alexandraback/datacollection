#include <iostream>
#include <fstream>
using namespace std;

int getlcm(int a, int b){
	int lcm, gcd;
	int z;
	int x = a;
	int y = b;

	while (1){
		z = x % y;
		if (z == 0)
			break;
		x = y;
		y = z;
	}

	gcd = y;
	lcm = a*b / y;
	return lcm;
}

int main(){
	ifstream fin;
	fin.open("B-small-attempt2.in");
	ofstream fout;
	fout.open("B-small-attempt2.out");

	int cnt;
	fin >> cnt;
	for (int T = 1; T <= cnt; T++){
		int b, n;
		fin >> b >> n;
		int m[1000];
		for (int i = 0; i < b; i++){
			fin >> m[i];
		}
		
		int lcm = m[0];
		for (int i = 1; i < b; i++){
			lcm = getlcm(lcm, m[i]);
		}

		int ans = 0;
		for (int i = 0; i < b; i++){
			ans += lcm / m[i];
		}

		n %= ans;
		n += ans;
		
		ans = 0;

		int m2[1000] = { 0, };
		for (int i = 0; i < n; i++){
			int min = 0;
			for (int j = 1; j < b; j++){
				if (m2[min] > m2[j]){
					min = j;
				}
			}
			if (m2[min] > 0){
				int a = m2[min];
				for (int j = 0; j < b; j++){
					m2[j] -= a;
				}
			}
			m2[min] = m[min];
			ans = min;
		}

		fout << "Case #" << T << ": ";
		fout << ans + 1;
		fout << endl;
	}

}