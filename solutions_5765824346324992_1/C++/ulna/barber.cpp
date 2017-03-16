#include <iostream>
#include <iomanip>
#include <sstream>
#include <fstream>
#include <cstdio>
#include <algorithm>
#include <deque>
#include <vector>
#include <map>
#include <cmath>
#include <cstdlib>
#include <set>
#include <queue>
#include <stack>
#include <string>
#include <cstring>
#include <climits>
#include <ctype.h>
#include <utility>
using namespace std;

#define ft first
#define sd second
#define pb push_back
#define endl '\n'
#define cpy(a,e) memcpy(a,e,sizeof(e))
#define clr(a,e) memset(a,e,sizeof(a))
#define rep(i,n) for (int (i)=0;(i)<(n);i++)
#define repd(i,n) for (int (i)=(n)-1;(i)>=0;i--)
#define reps(i,s,e) for (int (i)=(s);(i)<=(e);i++)
#define repds(i,s,e) for (int (i)=(s);(i)>=(e);i--)

int t,m,b;
long long n,barber[1055],ans,cnt,last;

bool C(long long p) {
	long long cnt=(long long)b;
	rep(i,b) cnt+=p/barber[i];
	return cnt>=n;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	ifstream fin;ofstream fout;
	fin.open("in.txt");fout.open("out.txt");
	fin >> t;
	rep(i,t) {
		fin >> b >> n;long long sum=0LL;
		rep(j,b) fin >> barber[j],sum=max(barber[j],sum);
		long long lb=0,ub=n*sum;
		while(ub-lb>1LL) {
			long long mid=(lb+ub)/2;
			if (C(mid)) ub=mid;
			else lb=mid;
		}
		if (n>b) {
			last=b;
			rep(j,b) last+=lb/barber[j];
			cnt=last;
			rep(j,b) {
				if (lb/barber[j]!=ub/barber[j]) {
					cnt++;
					if (cnt==n) {
						ans=j+1;break;
					}
				}
			}
		} else ans=n;
		fout << "Case #" << i+1 << ": " << ans << endl;
	}
	return 0;
}

