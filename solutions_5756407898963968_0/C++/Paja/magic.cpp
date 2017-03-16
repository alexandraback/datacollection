#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

const int MAXN = 25;

int cnt[MAXN];

int main(){	
	int testcases;
	scanf("%d", &testcases);
	
	for(int test = 0; test < testcases; test++){
		int k, a;
		fill(cnt, cnt + MAXN, 0);
		scanf("%d", &k);
		
		for(int i = 1; i <= 4; i++)
		for(int j = 1; j <= 4; j++){
			scanf("%d", &a);
			if(i == k)
				cnt[a]++;
			}
		scanf("%d", &k);
		for(int i = 1; i <= 4; i++)
		for(int j = 1; j <= 4; j++){
			scanf("%d", &a);
			if(i == k)
				cnt[a]++;
			}
		
		int cnt2 = 0, cnt2f = -1;
		for(int i = 1; i <= 16; i++)
			if(cnt[i] == 2) cnt2++, cnt2f = i;
		
		if(cnt2 == 0)
			printf("Case #%d: Volunteer cheated!\n", test+1);
		if(cnt2 > 1)
			printf("Case #%d: Bad magician!\n", test+1);
		if(cnt2 == 1)
			printf("Case #%d: %d\n", test+1, cnt2f);
		
		}
	
	return 0;
}
