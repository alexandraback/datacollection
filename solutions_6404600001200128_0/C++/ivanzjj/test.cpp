#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <queue>
using namespace std;

int a[1010];
int N;

int calc (int x, int y){
	if ((x - y)%10 == 0)	return (x-y)/10;
	else					return (x-y)/10 + 1;
}

int main (){
//	freopen ("F:\\C++\\A-small-attempt0.in","r",stdin);
//	freopen ("F:\\C++\\A-small-attempt0.out","w",stdout);
	int T; scanf ("%d",&T);
	for (int cas=1;cas<=T;cas++){
		scanf ("%d",&N);
		int _max = -1, diff = 0;
		for (int i=0;i<N;i++)	scanf ("%d",a+i), _max = max (_max, a[i]);
		int ans1 = 0 ,ans2 = 0;
		for (int i=0;i<N-1;i++){
			if (a[i] > a[i+1]){
				ans1 += (a[i] - a[i+1]);
				diff = max (diff , a[i] - a[i+1]);
			}
		}
		for (int i=0;i<N-1;i++){
			ans2 += min (a[i], diff);
		}
		printf ("Case #%d: %d %d\n", cas, ans1, ans2);
	}
	return 0;
}