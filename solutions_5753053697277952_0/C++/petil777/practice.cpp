#include <cstdio>
#include <algorithm>
#include <vector>
#include <iostream>
#include <string>
#include <cstring>
#include <queue>
#include <math.h>
#include <map>
#include <set>
#include <stdlib.h>
using namespace std;
#define ll long long
#define mp make_pair
int lev, test;
int n, cnt[30];;
struct info{
	int p, num;
	info(int a, int b){ p = a, num = b; }
	bool operator<(const info &i)const{
		if (num == i.num)return p < i.p;
		return num < i.num;
	}
};
int main(){
	freopen("A-small-attempt1.in", "r", stdin);
	freopen("A1.txt", "w", stdout);

	scanf("%d", &test);
	while (test--){
		++lev;
		scanf("%d", &n);
		priority_queue<info> pq;
		for (int i = 0; i < n; i++){
			scanf("%d", &cnt[i]); pq.push(info(i, cnt[i]));
		}
		printf("Case #%d: ", lev);
		while (!pq.empty()){
			info L1 = pq.top(); pq.pop();
			/*
			if (pq.empty()){
				printf("%c", L1.p + 'A'); break;
			}
			*/
			info L2 = pq.top(); pq.pop();
			L1.num--; L2.num--;
			if (pq.size() == 1 && pq.top().num == 1 && L1.num==0 && L2.num==0){
				printf("%c ", L1.p + 'A');
				printf("%c%c", L2.p + 'A', pq.top().p + 'A'); break;
			}
			printf("%c%c ", L1.p + 'A', L2.p + 'A');
			if (L1.num != 0)pq.push(L1);
			if (L2.num != 0)pq.push(L2);
		}
		puts("");
	}
}