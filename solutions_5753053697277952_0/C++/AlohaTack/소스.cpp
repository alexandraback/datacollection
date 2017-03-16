#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#pragma warning(disable : 4996)


int N;

int Max(int P[]){
	int max= 0;
	for (int i = 1; i <= N; i++)
		if (max < P[i])
			max = P[i];
	return max;
}

int Chk(int P[]){
	int chk = 0;
	int max = Max(P);
	for (int i = 1; i <= N; i++)
		if (P[i] == max)
			chk++;
	return chk;
}
int main(){

	freopen("A-small-attempt2.in", "r", stdin);
	freopen("A-small.out", "w", stdout);

	int T;
	scanf("%d", &T);
	for (int i = 1; i <= T; i++){
		int P[5] = { 0, };
		scanf("%d", &N);
		for (int j = 1; j <= N; j++)
			scanf("%d", &P[j]);
		printf("Case #%d: ", i);
		
		while (P[1] + P[2] + P[3] != 0){
			int max = Max(P);
			int chk = Chk(P);
			for (int j = 1; j <= N; j++){
				int chk = Chk(P);
				if (chk == 2 && P[j] == max){
					printf("%c", 'A' + j - 1);
					P[j]--;
				}
				else if(P[j]==max){
					printf("%c ", 'A' + j - 1);
					P[j]--;
				}
			}
		}
		printf("\n");
	}
	return 0;
}