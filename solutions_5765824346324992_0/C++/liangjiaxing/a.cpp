#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;

int a[1010];
int B;
int N;
int ans;

int check(int m) {
    int tt = 0;
    vector<int> v;
    for (int i = 0; i < B; i++) {
        tt += m / a[i];
        if (m % a[i] == 0) {
            v.push_back(i);
        } else {
            tt++;
        }
    }
    if (tt <= N-1 && tt+v.size() >= N) {
        ans = v[N - tt - 1];
        return 0;
    }
    if (tt > N-1) return 1;
    if (tt+v.size() < N) return -1;
}

int main() {
	// your code goes here
	int T;
	freopen("a.txt", "r", stdin);
	scanf("%d", &T);
	for (int re = 1; re <= T; re++) {
		scanf("%d%d", &B, &N);
		for (int i = 0; i < B; i++) scanf("%d", a + i);
		int l = 0, r = 100000001;
		while (l <= r) {
		    //printf("%d %d\n", l, r);
		    int m = (l + r) / 2;
		    int val = check(m);
		    if (val == -1) {
		        l = m + 1;
		    } else if (val == 1) {
		        r = m - 1;
		    } else {
		        //printf("%d\n", m);
		        break;
		    }
		}
		printf("Case #%d: %d\n", re, ans + 1);
	}
	return 0;
}