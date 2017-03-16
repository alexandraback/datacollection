#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <string>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <utility>
#include <bitset>
#include <algorithm>

using namespace std;

#define LL long long
#define pii pair<int,int>

const int INF = 0x3f3f3f3f;

int a[1010];

int main(){
	freopen("A-small-attempt0.in","r",stdin);
	freopen("A.out","w",stdout);
	int T; scanf("%d",&T);
	for(int kase = 1; kase <= T; ++kase){
		int n; scanf("%d",&n);
		int ans1 = 0 , ans2 = 0;
		double m2 = 0;
		for(int i = 0 ; i < n; ++i){
			scanf("%d",&a[i]);
			if(i > 0){
				m2 = max(m2,(double) a[i-1] - a[i]);
				if(a[i] < a[i-1]) ans1 += a[i-1] - a[i];
			}
		}
		m2 = m2 / 10;
		for(int i = 1; i < n; ++i){
			if(a[i-1] < m2 * 10) ans2 += a[i-1];
			else ans2 += m2 * 10;
		}
		printf("Case #%d: %d %d\n",kase,ans1,ans2);
	}
    return 0;
}
