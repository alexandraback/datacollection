#include<stdlib.h>
#include<stdio.h>
#include<string>
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

string w[100];
int N;
int op;

bool solve(){
	op = 0;
	int a[100], b[100], term;
	for (int i = 0; i < N; i++)	a[i] = 0;
	do{
		vector<int> len;
		for (int i = 0; i < N; i++){
			if (w[i][a[i]] != w[0][a[0]])
				return false;
			b[i] = a[i];
			while (w[i][b[i]] != '!'){
				b[i]++;
				if (w[i][b[i]] != w[i][a[i]]) break;
			}
			len.push_back(b[i] - a[i]);
		}
		sort(len.begin(), len.end());
		int med = len[N / 2];
		term = 0;
		for (int i = 0; i < N; i++){
			op += abs(b[i] - a[i] - med);
			a[i] = b[i];
			term += (w[i][a[i]] == '!');
		}
	} while (term < N);
	return true;
}

int main(){
	int T;
	scanf("%d", &T);
	for (int t = 1; t <= T; t++){
		cin >> N;
		for (int i = 0; i < N; i++){
			cin >> w[i];
			w[i] += '!';
		}
		if (solve())
			printf("Case #%d: %d\n", t, op);
		else
			printf("Case #%d: Fegla Won\n", t);
	}
	return 0;
}