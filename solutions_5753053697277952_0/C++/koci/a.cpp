#include <iostream>
#include <iomanip>
#include <climits>
#include <stack>
#include <fstream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <map>
#include <cassert>

#define FOR(i,n) for(int i=0,_n=n;i<_n;i++)
#define FORR(i,s,n) for(int i=s,_n=n;i<_n;i++)
#define mp make_pair
#define pb push_back
#define pii pair<int,int>
#define pli pair<ll,int>
#define vi vector<int>
#define fs first
#define sec second

#define maxn 100000

using namespace std;
typedef long long ll;

const ll MOD = 1000000007LL;

int a[27];

bool konec(int t){
	FOR(i,t)if(a[i]>0)return 0;
	return 1;
}

int naj(int t){
	int tr=0;
	FOR(i,t)if(a[i]>a[tr])tr=i;
	return tr;
}

int sum(int t){
	int rez=0;
	FOR(i,t)rez+=a[i];
	return rez;
}

void solve(int prim){
	printf("Case #%d:",prim);
	int t;
	scanf("%d",&t);
	FOR(i,t)scanf("%d",a+i);
	while(!konec(t)){
		printf(" ");
		int rmv=naj(t);
		printf("%c",'A'+rmv);
		a[rmv]--;
		if(konec(t))break;
		rmv=naj(t);
		a[rmv]--;
		int s=sum(t);
		int mx=naj(t);
		if(s-mx<mx)a[rmv]++;
		else printf("%c",'A'+rmv);
	}
	printf("\n");
}

int main(){
	int n;
	scanf("%d",&n);
	FORR(i,1,n+1)solve(i);
	return 0;
}
