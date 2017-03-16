#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <queue>
#include <vector>
#include <algorithm>
#define mm 20
#define clr(A) memset(A,0,sizeof(A))
using namespace std;
typedef long long LL;
int a[mm];
int hash[20];
int main()
{
	//freopen("BUAA.in","r",stdin);
	//freopen("A.out","w",stdout);
	int T,c = 0;
	scanf("%d",&T);
	while(T--){
	    printf("Case #%d: ",++c);
	    clr(hash);
	    int ans;
	    scanf("%d",&ans);
	    for(int i = 1;i<=4;i++)
	    for(int j = 1;j<=4;j++)
	    {
	        int x;
	        scanf("%d",&x);
	        if(i == ans) hash[x]++;
	    }
	    int card = 0,num = 0;
	    scanf("%d",&ans);
	    for(int i = 1;i<=4;i++)
	    for(int j = 1;j<=4;j++)
	    {
	        int x;
	        scanf("%d",&x);
	        if(i == ans) hash[x]++;
	        if(hash[x] >1) num++,card = x;
	    }
	    if(num == 1) printf("%d\n",card);
	    else if(num>1) printf("Bad magician!\n");
	    else printf("Volunteer cheated!\n");
	}
	return 0;
}
