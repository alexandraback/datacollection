#include <bits/stdc++.h>
using namespace std;
int main (){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int z;
	cin >> z;
	for (int i = 0; i < z; ++i){
		int n;
		cin >> n;
		vector <int> A(n);
		for (int j = 0; j < n; ++j){
			cin >> A[j];
		}
		int mas = 0, mas2 = 0;
		for (int j = 0; j < n; ++j){
			if (A[j] > A[mas]){
				mas = j;
			}
		}
		if (mas2 == mas)++mas2;
		for (int j = 0; j < n; ++j){
			if (j == mas)continue;
			if (A[j] > A[mas2]){
				mas2 = j;
			}
		}
		
		cout <<"Case #" << i+1 << ": "; 
		while (A[mas] != A[mas2]){
			cout << (char)('A'+mas)<<' ';
			--A[mas];
		}
		for (int j = 0; j < n; ++j){
			if (j == mas)continue;
			if (j ==mas2)continue;
			for (int x=  0; x <A[j];++x){
				cout << (char)('A'+j)<<' ';
			}
		}
		for (int j = 0; j < A[mas2]; ++j){
			cout << (char)('A'+mas)<<(char)('A'+mas2)<<' ';
		}
		cout<< '\n'; 
	}
}
