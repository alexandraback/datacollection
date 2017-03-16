/*
Author      : Rashedul Hasan Rijul ( Silent_coder ).
Created on  : 2014-09-12
*/

#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<ctype.h>
#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<queue>
#include<stack>
#include<map>
#include<set>
using namespace std;

#define maxm 200100
#define maxn  60
#define inf (1<<30)
#define ii int

#define pi  acos(-1.0)
#define eps 1e-9
#define iseq(a,b) (fabs(a-b)<eps)

#define pii pair<int,int>
#define mp  make_pair
#define uu first
#define vv second

ii on(ii n, ii k){ return (n | (1 << k)); }
ii off(ii n, ii k){ return (n - (n&(1 << k))); }
bool chck(ii n, ii k){ return (n&(1 << k)); }

ii mini(ii a, ii b){ if (a<b) return a;  return b; }
ii maxi(ii a, ii b){ if (a>b) return a;  return b; }

int n;
int cnt[30];

char getChar(int ind){
	return (ind + 'A');
}

void gen(){

	int i;
	for (i = 0; i < n; i++){
		if (cnt[i]) break;
	}
	if (i >= n) return;

	// find first 
	for (i = 0; i < n; i++){
		if (cnt[i]){
			cnt[i]--;
			break;
		}
	}
	char ch1 = getChar(i);

	// find second
	for (i = i+1; i < n; i++){
		if (cnt[i]){
			cnt[i]--;
			break;
		}
	}
	if (i < n){
		char ch2 = getChar(i);
		gen();
		printf(" %c%c", ch1, ch2);
	}
	else{
		gen();
		printf(" %c", ch1);
	}
}

int main(){

	int i, j, k, l, test, t = 1;

	//freopen("in.txt", "r", stdin);
	freopen("a1.in", "r", stdin);
	freopen("outa1.txt", "w", stdout);

	scanf("%d", &test);
	
	while (test--){

		memset(cnt, 0, sizeof(cnt));
		
		scanf("%d", &n);

		for (int i = 0; i < n; i++){
			scanf("%d", &cnt[i]);
		}

		printf("Case #%d:", t++);
		gen();
		puts("");

	}
	

	return 0;
}