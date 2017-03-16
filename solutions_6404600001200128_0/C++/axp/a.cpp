/* ***********************************************
Author        :axp
Created Time  :2015/4/18 9:01:13
File Name     :a.cpp
************************************************ */

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <cmath>
#include <cstdlib>
#include <ctime>
using namespace std;

const int maxn = 1010;
int T;
int n,m;
int a1,a2;
int arr[maxn];

int main()
{
    freopen("0.in","r",stdin);
    freopen("out.txt","w",stdout);
    cin>>T;
	for(int kase=1;kase<=T;kase++)
	{
		a1=a2=m=0;
		cin>>n;
		for(int i=0;i<n;i++)
		{
			cin>>arr[i];
			if(i && arr[i-1]>arr[i])
			{
				a1+=arr[i-1]-arr[i];
				m=max(m,arr[i-1]-arr[i]);
			}
		}
		for(int i=0;i<n-1;i++)
			a2+=min(m,arr[i]);
		printf("Case #%d: %d %d\n",kase,a1,a2);
	}
    return 0;
}
