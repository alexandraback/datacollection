#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <cstring>
#include <string>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <ctime>
using namespace std;
long p[111] = {};
long n ;

long maxar() {
    long res = 0;
    for (int i = 0; i < n; i ++)
        if (res < p[i] ) res = p[i];
    return res;
}

long solve() {
    long sum = 0;
    for (int i = 0; i < n; i ++) sum += p[i];
    while (sum > 0) {
        long max = maxar();
        vector <int> pp;
        pp.empty();
        for (int j = 0; j < n; j ++)
            if (p[j] == max) {
                pp.push_back(j);
                sum --; p[j] --;
            }
        for (int j = 2; j < pp.size(); j ++) {
            printf("%c ",'A' + pp[j]);
        }
        if (pp.size() > 1)
            printf("%c%c ",'A' + pp[0], 'A' + pp[1]);
        else printf("%c ",'A' + pp[0]);
    }
}

int main () {
	long t = 0;
	freopen("A-large-c.in","r",stdin);
	freopen("out.out","w",stdout);

	cin >> t;
	for (int i = 0; i < t; i ++) {
		cin >> n;
		for (int j = 0; j < n; j ++ ) cin >> p[j];
		printf("Case #%d: ", i + 1);
		solve();
		printf("\n");
	}
	return 0;
}
