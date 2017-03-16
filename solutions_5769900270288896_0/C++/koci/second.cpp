#include <iostream>
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

int r,c;

int bf(int poz, int st, vector <int> f){
	if(st==0)return 0;
	if(poz>=r*c)return 1000000;
	int p1 = bf(poz+1,st,f);
	int dod = 0;
	FOR(i,f.size()){
		if((f[i]==poz-1 && poz%c!=0) || f[i]==poz-c)dod++;
	}
	f.pb(poz);
	int p2 = dod+bf(poz+1,st-1,f);
	return min(p1,p2);
}
	

void solve(int zap){
	int n;
	cin >> r >> c >> n;
	vector <int> p;
	cout << "Case #"<<zap<<": "<<bf(0,n,p)<<"\n";
}

int main(){
	int t;
	cin >> t;
	FORR(i,1,t+1){
		solve(i);
	}
	return 0;
}
