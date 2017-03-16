/* ***********************************************
Author        :kuangbin
Created Time  :2015/4/18 10:35:18
File Name     :C.cpp
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
struct Point{
	int x,y;
	Point(int _x = 0,int _y = 0){
		x = _x;
		y = _y;
	}
	Point  operator -(const Point &b)const{
		return Point(x-b.x,y-b.y);
	}
	long long operator ^(const Point &b)const{
		return (long long)x*b.y-(long long)y*b.x;
	}
	long long dis2(const Point &b)const{
		return (long long)(x-b.x)*(x-b.x)+(long long)(y-b.y)*(y-b.y);
	}
};
Point p0;
bool cmp(Point a,Point b){
	return atan2(a.y-p0.y,a.x-p0.x) < atan2(b.y-p0.y,b.x-p0.x);
	long long tmp = (a-p0)^(b-p0);
	if(tmp > 0)return true;
	else return false;
}
int solve(Point p,vector<Point>vec){
	p0 = p;
	sort(vec.begin(),vec.end(),cmp);
	int n = vec.size();
	if(n <= 2)return 0;
	int j = 0;
	int ans = n;
	for(int i = 0;i < n;i++){
		while((j+1)%n != i && ((vec[i]-p0)^(vec[(j+1)%n]-p0)) >= 0)
			j = (j+1)%n;
		int cnt = i;
		if(j >= i)cnt += n-1-j;
		else cnt -= j+1;
		ans = min(ans,cnt);
		if(i == j)j = i+1;
	}
	return ans;
}

Point p[3010];
int main()
{
    freopen("C-small-attempt0.in","r",stdin);
    freopen("out.txt","w",stdout);
    int T;
	int iCase = 0;
	int n;
	scanf("%d",&T);
	while(T--){
		iCase++;
		scanf("%d",&n);
		for(int i = 0;i < n;i++)
			scanf("%d%d",&p[i].x,&p[i].y);
		printf("Case #%d:\n",iCase);
		vector<Point>vec;
		vec.resize(n-1);
		for(int i = 0;i < n;i++){
			int cnt = 0;
			for(int j = 0;j < n;j++)
				if(j != i)
					vec[cnt++] = p[j];
			printf("%d\n",solve(p[i],vec));
		}
	}
    return 0;
}
