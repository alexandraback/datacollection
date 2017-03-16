#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>

#define pb push_back

using namespace std;

const int MAXN = 100010;
const int INF  = 1000000010;
const int mod  = 1000003;

typedef long long Lint;
typedef pair <int,int> pii;

int n,r;
int ar[MAXN];

int main()
{
	int Test , tt;
	scanf(" %d",&Test);
	for(tt=1;tt<=Test;tt++){
		printf("Case #%d: ", tt);
		scanf(" %d",&n);
		int mx = 0 ;
		Lint res1 = 0;
		for(int i = 0 ;i < n; i++){
			scanf(" %d",ar+i);
			if(i > 0)
			{
				mx = max(mx , ar[i-1] - ar[i]);
				res1 += max(0 , ar[i-1] - ar[i]);
			}	
		}
		Lint res = 0;
		for(int i = 0 ; i < n-1; i++){
			res += min(mx, ar[i]);
		}
		cout << res1 <<" " <<res << endl;
	}
	return 0;
}
