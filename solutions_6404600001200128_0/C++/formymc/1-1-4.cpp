#include<stdio.h>
#include<iostream>

using namespace std;

const int MAX = 10020;

int main(){
	int t;
	int n;
	int number;
	int m[MAX];
	int max;
	int answer1;
	int answer2;

	freopen("A-small-attempt0.in", "r", stdin);
	freopen("out.txt", "w", stdout);

	number = 0;
	scanf("%d", &t);

	while (t--){
		number++;
		scanf("%d", &n);
		for (int i = 0; i < n; i++){
			scanf("%d", m + i);
		}

		answer1 = answer2 = 0;
		max = 0;
		for (int i = 1; i < n; i++){
			if (m[i] < m[i - 1]){
				answer1 += m[i-1] - m[i];
				if (max < m[i - 1] - m[i]){
					max = m[i-1] - m[i];
				}
			}
		}
		for (int i = 1; i < n; i++){
			if (m[i - 1] < max){
				answer2 += m[i - 1];
			}
			else{
				answer2 += max;
			}
		}
		printf("Case #%d: %d %d\n", number, answer1, answer2);
	}


	return 0;

}



