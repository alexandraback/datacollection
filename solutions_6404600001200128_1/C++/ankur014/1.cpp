#include <bits/stdc++.h>

using namespace std;
#define limt 10000

int n;
vector<int> v;

int calc(double rate)
{
	int ret = 0;
	/*for (int i = 1; i < n; ++i) {
	    if (v[i - 1] - v[i] > rate * 10) return -1;
	    else if (v[i - 1] - v[i] == rate * 10) ret += (v[i - 1] - v[i]);
	    else {
	    	ret += (v[i - 1]);
	    }
	}*/

	for(int i=0;i<(n-1);i++){
		int h = rate*10;
		ret+=min(v[i],h);
	}
	return ret;
}

int main()
{
	freopen("in1.in", "r", stdin);
	freopen("out1.txt", "w", stdout);
	int t, x;
	int s, b, l, r, m;
	double rate;
	scanf("%d", &t);

	for (int kase = 1; kase <= t; ++kase) {
		v.clear();
	    scanf("%d", &n);
	    for (int i = 0; i < n; ++i) {
	        scanf("%d", &x);
	        v.push_back(x);
	    }

	    s = 0;
	    b = INT_MAX;
	    for (int i = 1; i < n; ++i) {
	        if (v[i] < v[i - 1]) {
	        	s += (v[i - 1] - v[i]);
	        }
	    }

	    rate = 0;
	    for (int i = 1; i < n; ++i) {
	     	rate = max(rate, (v[i - 1] - v[i]) / 10.0);
	    }

	    printf("Case #%d: %d %d\n", kase, s, calc(rate));
	}

    return 0;
}

/*

*/