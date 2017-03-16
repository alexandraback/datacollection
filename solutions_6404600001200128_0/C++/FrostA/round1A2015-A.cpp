// #include <bits/stdc++.h>
#include "iostream"
#include "cstdio"
#include "algorithm"
#include "math.h"
#include "queue"
#include "map"
#include "set"
#include "stack"
#include "fstream"
#include "cstring"
#include "string"
#define L(x) (x<<1+1)
#define R(x) (x<<1+2)
#define REP(a,b) for(int a=0;a<b;a++)
#define REP1(a,b) for(int a=1;a<=b;a++)
#define RREP(a,b) for(int a=b-1;a>=0;a--)
#define RREP1(a,b) for(int a=b;a>0;a--)
#define ITR(a,b) for(;a!=b;a++)
using namespace std;
#define P 1000000007LL
#define MAXN 100
#define E7 10000000LL
typedef long long ll;

int n;
int a[1010];

int c1(){
	int ans=0;
	REP(i,n-1)
	if(a[i+1]<a[i])ans+=a[i]-a[i+1];
	return ans;
}

int c2(){
	int m = 0;
	REP(i,n-1)m = max(m, a[i]-a[i+1]);
	int ans=0;
	REP(i,n-1)
		ans+=a[i]-max(0,a[i]-m);
	return ans;
}

int main(){
	int T;
	cin>>T;
	REP1(cases,T){
		cin>>n;
		REP(i,n)cin>>a[i];
		cout<<"Case #"<<cases<<": "<<c1()<<' '<<c2()<<endl;
	}
	return 0;
}
