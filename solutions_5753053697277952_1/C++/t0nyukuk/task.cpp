#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <queue>
#include <map>
#include <set>
#include <stack>
#include <vector>
#define MAXN 102000
#define pb push_back
using namespace std;
typedef long long lint;
struct node
{
	char id;
	int per;
}ar[MAXN];
bool cmp(node a,node b){
	return a.per > b.per;
}
int n;
int main(){
	int Test,tt;
	scanf(" %d",&Test);
	for(tt=1;tt<=Test;tt++){
		printf("Case #%d: ", tt);
		scanf(" %d",&n);
		int sum = 0;
		for(int i = 0 ; i < n ; i++){
			scanf(" %d",&ar[i].per);
			ar[i].id = 'A' + i;
			sum = sum + ar[i].per;
		}
		sort(ar,ar+n,cmp);
		while(sum){
			if((ar[0].per-1) * 2 <= sum-1 && ar[1].per*2 <= sum-1){
				ar[0].per--;
				printf("%c ",ar[0].id);
				sum--;
			}
			else if((ar[0].per-2) * 2 <= sum-2 && ar[1].per*2 <= sum-2){
				ar[0].per--;
				printf("%c",ar[0].id);
				ar[0].per--;
				printf("%c ",ar[0].id);
				sum--;
			}
			else{
				ar[0].per--;
				printf("%c",ar[0].id);
				ar[1].per--;
				printf("%c ",ar[1].id);
				sum-=2;
			}

			sort(ar,ar+n,cmp);
		}
		printf("\n");
	}
	return 0;
}