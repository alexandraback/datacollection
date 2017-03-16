#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <queue>
#include <fstream>
#include <cstring>

using namespace std;
typedef long long LL;

bool ok(int m, int p) {
	return (((1<<p)&m)>0);
}

int brute(int n, int m, int k) {
	int ret=-1;
	for (int i=0;i<(1<<(n*m));i++)
		if (__builtin_popcount(i)==k) {
			int c=0;
			for (int x=0;x<n;x++)
				for (int y=1;y<m;y++)
					if (ok(i,x*m+y-1) && ok(i,x*m+y)) c++;
			for (int y=0;y<m;y++)
				for (int x=1;x<n;x++)
					if (ok(i,(x-1)*m+y) && ok(i,x*m+y)) c++;
			if (ret==-1 || ret>c) ret=c;
		}
	return ret;
}

int solve(int n, int m, int k) {
	if (n*m<16) return brute(n, m, k);
	if (m==1 && n==1) return 0;
	if (m==1 && n!=1) return solve(m, n, k);
	if (n==1) {
		int f=(m+3)/2;
		if (k<f) return 0;
		if (m%2==0) return 1+2*(k-f);
		return 2+2*(k-f);
	}
	int mid=(n*m)/2+(n*m)%2;
	if (k<=mid) return 0;
	int f=mid;
	if (n%2==0) f+=m;
	else f+=2*((int)m/2);
	if (m%2==0) f+=n-2;
	else f+=2*((int)(n-1)/2);
	if ((n*m)%2==0) {
		if (k==mid+1) return 2;
		if (k==mid+2) return 4;
		if (k<=f) return 4+3*(k-mid-2);
		return 4+3*(f-mid-2)+4*(k-f);
	} else {
		if (k==mid+1) return 3;
		if (k==mid+2) return 6;
		if (k==mid+3) return 8;
		if (k<f) return 8+3*(k-mid-3);
		return 8+3*(f-1-mid-3)+4*(k-f+1);
	}
}

int main() {
	freopen("noisy_neighbor.in","r",stdin);
	freopen("noisy_neighbor.out","w",stdout);
	int tc, nt=1;
	cin>>tc;
	while (tc--) {
		int n, m, k;
		cin>>n>>m>>k;
		cout<<"Case #"<<nt++<<": "<<solve(n,m,k)<<endl;
	}
}
