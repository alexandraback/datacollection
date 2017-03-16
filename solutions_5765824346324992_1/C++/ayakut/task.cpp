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

int n,B;
int ar[MAXN];

int main()
{
	int Test , tt;
	scanf(" %d",&Test);
	for(tt=1;tt<=Test;tt++){
		printf("Case #%d: ", tt);
		scanf(" %d %d",&n,&B);
		for(int i = 0 ; i < n; i++)
			scanf(" %d",ar+i);
		Lint lo = 0 , hi = 1e18;
		while(lo < hi){
			Lint k = (lo+hi+1)/2;
			Lint res = 0;
			for(int i = 0 ; i < n; i++){
				Lint p = k / ar[i] + 1;
				if(k % ar[i] == 0) p--;
				res += p;
				if(res >= B) break;
			}
			if(res >= B) hi = k-1;
			else lo = k;
		}
		Lint k = lo;
		Lint res = 0;
		for(int i = 0 ; i < n; i++){
			Lint p = k / ar[i] + 1;
			if(k % ar[i] == 0) p--;
			res += p;
		}
		B-=res;
		for(int i = 0 ; i < n; i++){
			if( k % ar[i] == 0){
				B--;
			}
			if(!B){
				printf("%d\n",i+1);
				break;
			}
		}
	}
	return 0;
}
