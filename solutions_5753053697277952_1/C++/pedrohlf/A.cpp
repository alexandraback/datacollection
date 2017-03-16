#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
#include <map>
#include <queue>
#include <stdlib.h>
#include <set>
#include <algorithm>
#include <math.h>
#include <stdio.h>
#include <unistd.h>
#include <stack>
#include <sstream>
#include <list>
#include <bitset>
#define ff first
#define ss second
#define mp make_pair

using namespace std;

typedef long long ll;

int v[30];

int main() {
	int t,tc=1,i,n;
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		int sum = 0;
		for(i = 0; i < n; i++){
			scanf("%d", &v[i]);
			sum += v[i];
		}

		vector<pair<char,char>> ans;
		pair<char,char> aux;

		while(sum){
			int ind = 0, big = 0;
			aux = mp(-1,-1);
			for(i = 0; i < n; i++){
				if(v[i] > big){
					big = v[i];
					ind = i;
				}
			}
			aux.ff = ind; v[ind]--;
			sum--;
			ind = 0, big = 0;
			if(sum == 0){ ans.push_back(aux);break;}
			if(sum == 2){ ans.push_back(aux);continue;}
			for(i = 0; i < n; i++){
				if(v[i] > big){
					big = v[i];
					ind = i;
				}
			}
			aux.ss = ind; v[ind]--;
			ans.push_back(aux);
			sum--;
		}

		printf("Case #%d:", tc++);
		for(pair<char,char> x : ans){
			printf(" %c", (x.ff+'A'));
			if(x.ss != -1)
				printf("%c", (x.ss+'A'));
		}
		printf("\n");
	}

	return 0;
}
