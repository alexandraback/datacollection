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

void getans(){
	int n;
	int a[20000];
	scanf("%d",&n);
	for (int i=0;i<n;i++) scanf("%d",&a[i]);
	int a0=0,a1=0,mi=0;
	for (int i=1;i<n;i++){
		a0+=max(0,a[i-1]-a[i]);
		mi=max(mi,a[i-1]-a[i]);
	}
	for (int i=0;i<n-1;i++)
		a1+=min(a[i],mi);
	
	printf("%d %d\n",a0,a1);
}

int main(){
	int N;
	scanf("%d",&N);
	for (int r=1;r<=N;r++){
		printf("Case #%d: ",r);
		getans();
	}
	return 0;
}