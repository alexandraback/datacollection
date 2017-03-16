#include <iostream>
#include <sstream>
#include <cctype>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <set>
using namespace std;

int getans(){
	int n,m;
	int a[20000];
	scanf("%d%d",&n,&m);
	for (int i=0;i<n;i++) scanf("%d",&a[i]);
	if (m<=n) return m;
	long long l=0,r=1000000000000000LL;
	for (;l<r-1;){
		long long cur=(l+r)/2;
		long long num=0;
		for (int i=0;i<n;i++)
			num+=cur/a[i]+1;
		if (num>=m) r=cur;
		else l=cur;
	}
	long long num=0;
	for (int i=0;i<n;i++)
		num+=l/a[i]+1;
	l++;
	for (int i=0;i<n;i++){
		if (l%a[i]==0){
			num++;
			if (num==m) return i+1;
		}
	}
	return -1;
}

int main(){
	int N;
	scanf("%d",&N);
	for (int r=1;r<=N;r++){
		printf("Case #%d: %d\n",r,getans());
	}
	return 0;
}