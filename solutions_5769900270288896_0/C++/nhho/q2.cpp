#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <cmath>
#include <stack>
#include <map>
#include <set>
#include <deque>
#include <cstring>
#include <functional>
#include <climits>
#include <list>

#define F1(x,y,z) for(int x=y;x<z;x++)
#define F2(x,y,z) for(int x=y;x<=z;x++)
#define F3(x,y,z) for(int x=y;x>z;x--)
#define F4(x,y,z) for(int x=y;x>=z;x--)
#define W(x) while(x-->0)
#define SI(x) scanf("%d",&x)
#define pb push_back

using namespace std;

int t,n,m,k;
int cnt;
bool x[20][20];
int y;
int ans;

void go(int a,int b,int left){
	if(a==n+1){
		if(cnt==k){
			ans=min(ans,y);
		}
		return;
	}
	if(b==m+1){
		go(a+1,1,left);
		return;
	}
	go(a,b+1,left);
	if(left==0)return;
	cnt++;
	x[a][b]=1;
	if(x[a][b-1])y++;
	if(x[a-1][b])y++;
	go(a,b+1,left-1);
	if(x[a][b-1])y--;
	if(x[a-1][b])y--;
	x[a][b]=0;
	cnt--;	
}

int main(){
	SI(t);
	F2(tt,1,t){
		SI(n);
		SI(m);
		SI(k);
		ans=INT_MAX;
		go(1,1,k);
		printf("Case #%d: %d\n",tt,ans);
	}
	//system("pause");
    return 0;
}
