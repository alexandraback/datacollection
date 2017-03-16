#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <map>
#include <vector>
#include <string>
#include <queue>
#include <stack>
using namespace std;

#define S second
#define F first
#define mp make_pair
typedef pair<int, int> PII;
#define pb push_back
typedef long long ll;

int pa[30];

int main () {
	int t;
	cin >> t;
	for(int tt = 1; tt <= t; ++tt){
		int n;
		cin >> n;
		int tot = 0;
		for(int i = 0; i < n; ++i) { scanf("%d", pa+i); tot += pa[i]; }
		printf("Case #%d:", tt);
		priority_queue<PII> q;
		for(int i = 0; i < n; ++i) q.push(mp(pa[i], i));
		while(!q.empty()){
			PII a = q.top();
			q.pop();
			if(a.F == 1 && q.top().F == 1 && tot == 2){
				printf(" %c%c", a.S+'A', q.top().S+'A');
				break;
			}
			tot--;
			printf(" %c", a.S+'A');
			a.F--;
			if(a.F > 0) q.push(a);
			if(q.top().F > tot/2){
				printf("%c", q.top().S+'A');
				tot--;
				PII b = q.top();
				q.pop();
				b.F--;
				if(b.F > 0) q.push(b);
			}
		}
		puts("");
	}
}