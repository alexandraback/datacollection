#include <iostream>
#include <fstream>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define fi "A-small-attempt0.in"
#define fo "a.out"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;

int ntest, nParty;
int array[30];

void input();
void output();

void solve(){
	int max1, max2, vt1, vt2;
	
	max1 = 0;
	max2 = 0;
	vt1 = 0;
	vt2 = 0;
	
	for(int i = 0 ; i < nParty; i++){
		if(array[i] >= max1){
			if(max1 >= max2){
				max2 = max1;
				vt2 = vt1;
			}
			
			max1 = array[i];
			vt1 = i;
		} else {
			if(array[i] > max2){
				max2 = array[i];
				vt2 = i;
			}
		}
	}
	
	while(max1 > max2){
		printf(" ");
		
		max1--;
		printf("%c",vt1 + 'A');
		
		if(max1 - max2 > 1){
			max1--;
			printf("%c",vt1 + 'A');
		}
	}
	
	for(int i = 0 ; i < nParty; i++){
		if(i != vt1 && i != vt2){
			while(array[i] > 0){
				printf(" ");
		
				array[i]--;
				printf("%c",i + 'A');
				
				if(array[i] > 0){
					array[i]--;
					printf("%c",i + 'A');
				}
			}
		}
	}
	
	while(max1 > 0){
		printf(" %c%c",vt1 + 'A', vt2 + 'A');
		max1--;
	}
	
	printf("\n");
}

void input()
{
	scanf("%d", &ntest);
	for(int i = 0 ; i < ntest; i++){
		scanf("%d", &nParty);
		for(int j = 0 ; j < nParty; j++){
			scanf("%d", &array[j]);
		}
		
		printf("Case #%d:", i + 1);
		solve();
	}
}

void output()
{
}

int main() {
	
	//freopen(fi,"r",stdin);
	//freopen(fo,"w",stdout);
	
	input();
	
	return 0;
}
