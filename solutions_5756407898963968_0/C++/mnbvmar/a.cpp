#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

int C, R;
int TC[4][4], TR[4][4];
int numFound[17];

void input(){
	scanf("%d", &C);
	for(int i = 0; i < 4; i++)
		for(int j = 0; j < 4; j++)
			scanf("%d", &TC[i][j]);
	
	scanf("%d", &R);	
	for(int i = 0; i < 4; i++)
		for(int j = 0; j < 4; j++)
			scanf("%d", &TR[i][j]);
	
	C--; R--;
}

void test(){
	input();
	
	fill(numFound, numFound+17, 0);
	
	for(int nr = 0; nr < 4; nr++)
		numFound[TC[C][nr]]++;
	for(int nc = 0; nc < 4; nc++)
		numFound[TR[R][nc]]++;
	
	int res = 0;
	for(int i = 1; i <= 16; i++){
		if(numFound[i] == 2){
			if(!res){
				res = i;
			} else {
				printf("Bad magician!\n");
				return;
			}
		}
	}
	
	if(res){
		printf("%d\n", res);
	} else {
		printf("Volunteer cheated!\n");
	}
}

int main(){
	int t;
	scanf("%d", &t);
	for(int i = 1; i <= t; i++){
		printf("Case #%d: ", i);
		test();
	}
}
