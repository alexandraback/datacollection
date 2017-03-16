/*
* Filename:    A.cpp
* Created:     2016年05月08日 16时58分11秒 星期日
* Author:      JIngwei Xu [mail:xu_jingwei@outlook.com]
*
*/
#include<cstdio>
#include<iostream>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<algorithm>
#include<queue>
#include<stack>
#include<map>
#include<set>
#include<vector>
using namespace std;
typedef pair<int,int> P;
typedef long long ll;
typedef struct po
{
	int num;
	char s;
} POO;
//Init Const
const int INF=1e9;
const int maxn=26+7;
//Global Variables
int n,m,t,ans;
string s;
POO a[maxn];
//Function Declaration
bool cmp(POO p1,POO p2){
	return p1.num<p2.num;
}

//Main Program
int main()
{
#ifdef AC_THIS_PROBLEM
	freopen("data.in","r",stdin);
	freopen("data.out","w",stdout);
#endif
	scanf("%d",&t);
	for (int tcase = 1; tcase<=t; tcase += 1)
	{
		printf("Case #%d:",tcase);
		scanf("%d",&n);
		int tmp=(int)'A';
		for (int i = 0; i < n; i += 1)
		{
			scanf("%d",&a[i].num);
			a[i].s=char(tmp+i);
		}
		if(n==2){
			while (a[0].num--)
			{
				printf(" %c%c",'A','B');
			}
			printf("\n");
		}else{
			sort(a,a+n,cmp);
			int left=a[n-1].num-a[n-2].num;
			while (left!=0)
			{
				printf(" %c",a[n-1].s);
				left-=1;
			}
			for (int i = 0; i < n-2; i += 1)
			{
				for (int j = 0; j < a[i].num; j += 1)
				{
					printf(" %c",a[i].s);
				}
			}
			for (int i = 0; i < a[n-2].num; i += 1)
			{
				printf(" %c%c",a[n-2].s,a[n-1].s);
			}
			printf("\n");
		}
	}
	return 0;
}

