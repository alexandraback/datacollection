#include<iostream>
#include<stdio.h>
#include<string.h>
#include <algorithm>
#define FR(i,a,b) for(i=a;i<b;++i)
#define FRS(i,a,b,s) for(i=a;i<b;i+=s)
#define FRE(i,a,b) for(i=a;i<=b;++i)
#define FRES(i,a,b,s) for(i=a;i<=b;i+=s)
// 0->tt-1		FR(i, 0, tt) printf(" 1");
// 0,2,4->tt-1	FRS(i, 0, tt, 2) printf(" 2");
// 0->tt		FRE(i, 0, tt) printf(" 3");
// 0,2,4->tt	FRES(i, 0, tt, 2) printf(" 4");
using namespace std;

int i, j, k;
int tt;
	
int x, s, r, t, n;
int w[1005];
int st[1005], en[1005], len[1005];
long double used = 0;
long double available = 0;
void run(){
	int n;
	cin >> n;
	int num[30];
	FR(i,0,n) cin >> num[i];
	// evacuate till 1
   while(true){
		int first = -1;
		FR(i,0,n){
			if(num[i]>1 && (first == -1 || num[first] < num[i])){
				first = i;
			}
		}
		int second = -1;
		FR(i,0,n) if(num[i] > 1 && i!=first && (second == -1 || num[second] < num[i])){ second = i; break;}

		if(first == -1) break;
		printf(" %c", first + 'A'); num[first]--;
		if(second>-1) {printf("%c", second +'A'); num[second]--;}
	}
	int idx =0 ;
	if( n %2 == 1){
		printf(" %c", 'A' + idx);
		idx++;
	}
	for(;idx<n;idx+=2){
		printf(" %c%c", 'A' + idx, 'A' + idx+ 1);
	}
}

int main(){
	int T;
	scanf("%d", &T);
	for(tt =1; tt<=T; tt++){
		printf("Case #%d:",tt); // standard
		run();
		printf("\n"); // endline
	}
	return 0;
}
