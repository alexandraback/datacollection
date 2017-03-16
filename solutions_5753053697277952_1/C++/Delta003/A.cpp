#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair

#define eps 0.0000001
#define pi  3.14159265359
#define inf 2000000000

typedef long long lld;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;

priority_queue<pii> PQ;
int n, t, tt;

int main() {
    scanf("%d", &tt);
    for (int t = 1; t <= tt; t++) {
    	scanf("%d", &n);
    	int a;
    	for (int i = 0; i < n; i++) {
    		scanf("%d", &a);
    		PQ.push(make_pair(a, i));
    	}
    	vector<char> sol;
    	while (PQ.size() > 2) {
    		pii x = PQ.top();
    		PQ.pop();
			sol.push_back('A' + x.second);
			sol.push_back(' ');
			x.first--;
			if (x.first) PQ.push(x);
    	}
    	pii x = PQ.top();
    	PQ.pop();
    	pii y = PQ.top();
    	PQ.pop();
    	for (int i = 0; i < x.first; i++) {
    		sol.push_back('A' + x.second);
    		sol.push_back('A' + y.second);
			sol.push_back(' ');
    	}
    	printf("Case #%d: ", t);
    	for (int i = 0; i < sol.size(); i++) printf("%c", sol[i]);
    	printf("\n");
    }
    return 0;
}
