#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

string element[100];
int COUNT[100][100];

string base;

int main() {
	int T;
	cin >> T;
	for(int c=1;c<=T;c++) {
		int N;
		cin >> N;
		for(int i=0;i<N;i++) {
			cin >> element[i];
		}
		base = "";
		bool flag = true;
		for(int i=0;i<N;i++) {
			string temp = "";
			int index = -1;
			for(int j=0;j<element[i].size();j++) {
				if(j>0 && temp[temp.size()-1]==element[i][j]) {
					COUNT[index][i]++;
				} else {
					temp += element[i][j];
					COUNT[++index][i] = 1;
				}
			}
			if(base != "" && base != temp) {
				flag = false;
			}
			else {
				base = temp;
			}
		}
		cout << "Case #" << c << ": ";
		if(!flag) {
			cout << "Fegla Won" << endl;
		} else {
			int sum = 0;
			for(int i=0;i<base.size();i++) {
				sort(COUNT[i], COUNT[i] + N);
				int mean = COUNT[i][N/2];
				for(int j=0;j<N;j++) {
					sum += abs(COUNT[i][j] - mean);
				}
			}
			cout << sum << endl;
		}
	}
}