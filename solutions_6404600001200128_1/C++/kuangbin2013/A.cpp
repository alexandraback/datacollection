/* ***********************************************
Author        :kuangbin
Created Time  :2015/4/18 9:39:49
File Name     :A.cpp
************************************************ */

#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <math.h>
#include <stdlib.h>
#include <time.h>
using namespace std;
const int MAXN = 10010;
int a[MAXN];

int main()
{
    freopen("A-large.in","r",stdin);
    freopen("out.txt","w",stdout);
    int T;
	int iCase = 0;
	int n;
	scanf("%d",&T);
	while(T--){
		iCase++;
		scanf("%d",&n);
		for(int i = 0;i < n;i++)scanf("%d",&a[i]);
		int ans1 = 0;
		for(int i = 1;i < n;i++)
			if(a[i] < a[i-1])
				ans1 += a[i-1]-a[i];
		int ans2 = 0;
		int Max = 0;
		for(int i = 1;i < n;i++)
			Max = max(Max,a[i-1]-a[i]);
		for(int i = 0;i < n-1;i++)
			ans2 += min(a[i],Max);
		printf("Case #%d: %d %d\n",iCase,ans1,ans2);
	}
    return 0;
}
