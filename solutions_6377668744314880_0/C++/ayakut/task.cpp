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
#include <cmath>

#define pb push_back

using namespace std;

const int MAXN = 100010;
const int INF  = 1000000010;
const int mod  = 1000003;

typedef long long Lint;
typedef pair <int,int> pii;

struct  point
{
	Lint x,y;
	int id;
}ar[MAXN] , st[MAXN];
int son = 0;
int n,B;
int dp[MAXN];
vector <point> vec;

bool cmp(const point &a, const point &b){
	return atan2(a.y-vec[0].y , a.x - vec[0].x) < atan2(b.y-vec[0].y , b.x - vec[0].x);

}

Lint ccw(point a, point b ,point c){
	return (b.x-a.x) * (c.y - a.y) - (b.y-a.y) * (c.x-a.x);
}
int main()
{
	int Test , tt;
	scanf(" %d",&Test);
	for(tt=1;tt<=Test;tt++){
		printf("Case #%d:\n", tt);
		scanf(" %d",&n);
		for(int i = 0 ;i < n ;i++) dp[i] = n;
		for(int i = 0; i < n ;i++)
		{
			scanf(" %lld %lld",&ar[i].x,&ar[i].y);
			ar[i].id = i;
		}
		for(int k = 0 ; k < (1<<n) ; k++){
			vec.clear();
			for(int i = 0 ; i < n ; i++)
			{
				if((1<<i) & k)
					vec.pb(ar[i]);
			}
			if(vec.size() == 0) continue;
			for(int i = 0 ; i < vec.size();i++)
			{
				if(vec[i].y < vec[0].y) swap(vec[i],vec[0]);
				if(vec[i].y == vec[0].y && vec[i].x < vec[0].x) swap(vec[i],vec[0]);
			}
			sort(vec.begin()+1,vec.end(),cmp);
			son = 0;
			for(int i = 0 ;i < vec.size();i++){
				while(son >= 2 && ccw(st[son-2] , st[son-1] ,vec[i]) <= 0 ){
					son --;
				}
				st[son++] = vec[i];
			}
			st[son++] = st[0];
			for(int i = son-1 ; i >0 ;i--){
				for(int j = 0 ;j < vec.size();j++){
					if(vec[j].id == st[i].id) continue;
					if(vec[j].id == st[i-1].id) continue;
					Lint x1 = st[i].x - vec[j].x;
					Lint y1 = st[i].y - vec[j].y;

					Lint x2 = -st[i-1].x + vec[j].x;
					Lint y2 = -st[i-1].y + vec[j].y;
					if(x1*y2 == x2*y1) st[son++] = vec[j];
						
				}

			}
			
			/*if(vec.size() == n){
				for(int i =0  ;i < son ;i++){
					printf("%d %d\n",st[i].x , st[i].y );
				}
			}*/

			for (int i = 0; i < son; ++i)
			{
				dp[st[i].id] = min( dp[st[i].id] , n-(int)vec.size());
			}
		}
		for(int i = 0 ; i < n ; i++){
			printf("%d\n",dp[i] );
		}
	}

	return 0;
}
