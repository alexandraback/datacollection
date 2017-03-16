#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;
typedef long long LL;
const int MOD=1000000007;
const double EPS=1e-12;

int n,num[1111];

bool input(){
	scanf("%d",&n);
	for(int i=0; i<n; i++)scanf("%d",&num[i]);
	return 1;
}

void solve(){
	int res1=0,res2=0, v=0;
	for(int i=1; i<n; i++){
		res1+= max(0,num[i-1]-num[i]);
		v=max(num[i-1]-num[i],v);
	}
	for(int i=1; i<n; i++){
        res2+= min(v,num[i-1]);
	}
	static int cas=1;

	printf("Case #%d: %d %d\n",cas++,res1,res2);
}

int main()
{
	int zz;
	scanf("%d",&zz);
	while(zz--){
	    input();
		solve();
	}
    return 0;
}
/*

6 2
ioi
1 3

5 2
ioi
1 2

*/