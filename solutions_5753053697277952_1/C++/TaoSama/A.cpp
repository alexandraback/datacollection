//
//  Created by TaoSama on 2016-05-08
//  Copyright (c) 2016 TaoSama. All rights reserved.
//
#pragma comment(linker, "/STACK:102400000,102400000")
#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <string>
#include <set>
#include <vector>

using namespace std;
#define pr(x) cout << #x << " = " << x << "  "
#define prln(x) cout << #x << " = " << x << endl
const int N = 1e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n, p[26];
typedef pair<int, int> P;

int main() {
#ifdef LOCAL
    freopen("A-large.in", "r", stdin);
    freopen("A-large.out", "w", stdout);
#endif
    ios_base::sync_with_stdio(0);
    clock_t _ = clock();

	int t; scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		priority_queue<P> q;
		int sum = 0;
		for(int i = 0; i < n; ++i) {
			scanf("%d", p + i);
			q.push({p[i], i});
			sum += p[i];
		}
		static int kase = 0;
		printf("Case #%d:", ++kase);
		while(q.size()){
            P u = q.top(); q.pop();
            if(q.size() == 2 && sum == 3){
				--sum;
                printf(" %c", char(u.second + 'A'));
            }
            else{
				--sum; --u.first;
				printf(" %c", char(u.second + 'A'));
				if(u.first) q.push(u);
				if(q.size()){
					P u = q.top(); q.pop();
					--sum; --u.first;
					printf("%c", char(u.second + 'A'));
					if(u.first) q.push(u);
				}
            }
		}
		puts("");
	}

#ifdef LOCAL
//    printf("\nTime cost: %.2fs\n", 1.0 * (clock() - _) / CLOCKS_PER_SEC);
#endif
    return 0;
}
