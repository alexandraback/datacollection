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

int t,n,m[1055];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	ifstream fin;ofstream fout;
	fin.open("in.txt");fout.open("out.txt");
	fin >> t;
	rep(k,t) {
		fin >> n;int ans1=0,ans2=-1,ans3=INT_MAX,great=0,l=0;
		rep(i,n) fin >> m[i],l=max(m[i],l);
		rep(i,n-1) {
			if (m[i]>=m[i+1]) ans1+=m[i]-m[i+1];
		}
		while (ans2<l) {
			ans2++;bool can=1;great=0;
			rep(i,n-1) {
				if (m[i]>=m[i+1]) {
					if (ans2<m[i]-m[i+1]) {
						can=0;break;
					}
					if (ans2>=m[i]) great+=m[i];
					else great+=ans2;
				} else {
					if (m[i]<=ans2) great+=m[i];
					else great+=ans2;
				}
			}
			if (can) ans3=min(ans3,great);
		}
		fout << "Case #" << k+1 << ": " << ans1 << " " << ans3 << endl;
	}
	return 0;
}

