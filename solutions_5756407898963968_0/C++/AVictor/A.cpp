#include<iostream>
#include<cstdio>
#include<map>
#include<vector>
#include<set>
#include<queue>
#include<algorithm>
#include<string.h>
#include<memory.h>
#include<iomanip>
#include<cmath>
using namespace std;

int A[4][4], B[4][4];
int a, b;
int main()
{
	int test_cnt;
	cin>>test_cnt;
	for(int test_num=1;test_num<=test_cnt;test_num++)
	{
		cin>>a; a--;
		for(int i=0;i<4;i++)
			for(int j=0;j<4;j++)
				cin>>A[i][j];
		cin>>b; b--;
		for(int i=0;i<4;i++)
			for(int j=0;j<4;j++)
				cin>>B[i][j];
		int ans = -1;				
		for(int i=0;i<4;i++)
			for(int j=0;j<4;j++)
			{
				if (A[a][i] == B[b][j])
				{
					if (ans == -1) ans=A[a][i];
					else if (ans>0) ans=-2;
				}
			}
		switch (ans)
		{
			case -2: printf("Case #%d: Bad magician!\n", test_num); break;
			case -1: printf("Case #%d: Volunteer cheated!\n", test_num); break;
			default: printf("Case #%d: %d\n", test_num, ans); break;
		}
	}
	
	return 0;
}
