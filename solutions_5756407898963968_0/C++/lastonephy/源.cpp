//#include <vector>
//#include <list>
//#include <map>
//#include <set>
//#include <deque>
//#include <stack>
//#include <bitset>
//#include <algorithm>
//#include <functional>
//#include <numeric>
//#include <utility>
//#include <sstream>
//#include <iostream>
//#include <iomanip>
//#include <cstdio>
//#include <cmath>
//#include <cstdlib>
//#include <ctime>
//#include <cstring>
//#define INF 1<<30
//#define MAXN 10010
//#define MOD 1000000007
//using namespace std;
//
//int  main()
//{
//	int seed;
//	seed = time(NULL);
//	srand(seed);
//	for(int r = 0;r < 100;r++)
//	{
//		int n ,m;
//		do
//		{
//			n = rand();
//		}while(n >5||n<1);
//		do
//		{
//			m = rand();
//		}while(m > 5|| m < 1);
//		printf("%d %d\n",n ,m);
//		int t;
//		for(int i = 0;i < n;i++)
//		{
//			for(int j = 0;j < m;j++)
//			{
//				do
//				{
//					t = rand();
//				}while(t>10000||t<=0);
//				printf("%d ",t);
//			}
//			printf("\n");
//		}
//		printf("\n");
//	}
//	return 0;
//}
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
#define INF 1<<30
#define MAXN 10010
#define MOD 1000000007
using namespace std;

int num[5][5] ,no[5][5];
int flag[20];

int main()
{
	int t ,n ,m;
	scanf("%d",&t);
	for(int r = 1;r<=t;r++)
	{
		memset(flag,0,sizeof(flag));
		scanf("%d",&n);
		for(int i = 1;i <= 4;i++)
		{
			for(int j = 1;j <= 4;j++)
			{
				scanf("%d",&num[i][j]);
				if(i==n)
				{
					flag[num[i][j]]++;
				}
			}
		}
		scanf("%d",&m);
		for(int i = 1;i <= 4;i++)
		{
			for(int j = 1;j <= 4;j++)
			{
				scanf("%d",&no[i][j]);
				if(i==m)
				{
					flag[no[i][j]]++;
				}
			}
		}
		int ans ,cnt = 0;
		for(int i = 1;i <= 16;i++)
		{
			if(flag[i]==2)
			{
				ans = i;
				cnt++;
			}
		}
		printf("Case #%d: ",r);
		if(cnt==1)
		{
			printf("%d\n",ans);
		}
		else if(cnt > 1)
		{
			printf("Bad magician!\n");
		}
		else
		{
			printf("Volunteer cheated!\n");
		}
	}
	return 0;
}