/*******************************************************************************
IF YOU ARE LOOKING THIS YOU ARE RIGHT WAY
*******************************************************************************/
#include<stdio.h>
#include<vector>
#include<queue>
#include<stack>
#include<set>
#include<map>
#include<string>
#include<cmath>
#include<cstring>
#include<stdlib.h>
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
#define MAX 100005
typedef pair<int,char> p;
typedef pair<int,p> pii;
#define fi first
#define se second
#define pb push_back
#define s(a) scanf("%d",&a);
#define mem(a) memset(a,0,sizeof(0))
vector<int> v;
priority_queue< p > pq;
int N;
int A[27];

void solve()
{
	int tN=0;
	for(int i = 0 ; i < N ;i++)
	{
		pq.push(p(A[i],'A'+i));
		tN += A[i];
	}
	int cnt = 0;
	
	while(!pq.empty())
	{
//		printf("\ntn : %d\n",tN);
		if(cnt == 0)
		{
			p c = pq.top();
			printf("%c",c.se);
			pq.pop();
			tN--;
			if(c.fi!=1)
				pq.push(p(c.fi-1,c.se));
			cnt = 1;
			continue;
		}
		p c = pq.top();
		pq.pop();
		
//		printf("\n%c %d %d\n",c.se,c.fi,tN/2);
		if(c.fi > tN/2)
		{
			printf("%c",c.se);
		}
		else
			printf(" %c",c.se);
		if(c.fi!=1)
				pq.push(p(c.fi-1,c.se));
		tN--;
	}
	printf("\n");
}


int main()
{
	int T;
	scanf("%d",&T);
//	T = 1;
int tT = T;
	while(T--)
	{
		scanf("%d",&N);
		for(int i = 0 ; i < N ; i++)
			scanf("%d",A+i);
		printf("Case #%d: ",tT-T);
		solve();
	}
	return 0;
}
