/* ***********************************************
Author        :kuangbin
Created Time  :2015/4/18 9:48:30
File Name     :B.cpp
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
int a[1100];
long long b[1100];
int c[1100];
bool cmp(int i,int j){

	if(b[i] != b[j])
		return b[i] < b[j];
	return i < j;
}

int main()
{
    freopen("B-large.in","r",stdin);
    freopen("out.txt","w",stdout);
    int T;
	int iCase = 0;
	int n,m;
	scanf("%d",&T);
	while(T--){
		iCase++;
		scanf("%d%d",&n,&m);
		for(int i = 0;i < n;i++)
			scanf("%d",&a[i]);
		long long l = 0;
		long long r = 100000000000000LL;
		int ans = -1;
		while(l <= r){
			if(ans != -1)break;
			long long mid = (l+r)/2;
			long long now = 0 , cnt = 0;
			for(int i = 0;i < n;i++){
				if(mid)now += (mid-1)/a[i]+1;
				cnt += (mid%a[i] == 0);
			}
			if(cnt && now < m && now+cnt >= m){
				m -= now;
				for(int i = 0;i < n;i++)
					if(mid%a[i] == 0){
						m--;
						if(m == 0){
							ans = i;
							break;
						}
					}
				break;
			}
			if(now >= m)r = mid-1;
			else l = mid+1;
		}
		printf("Case #%d: %d\n",iCase,ans+1);
	}
    return 0;
}
