#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

int s[20],a[5][5];

int main()
{
    freopen("A-small-attempt0.in","r",stdin);
    freopen("out.txt","w",stdout);
    
    int T;
	cin >> T;
	for(int t=0,r1,r2;t<T;t++){
		memset(s,0,sizeof(s));
		cin >> r1;
		r1--;
		for(int i=0;i<4;i++)
			for(int j=0;j<4;j++)
				cin >> a[i][j];
		for(int i=0;i<4;i++)
			s[a[r1][i]] = 1;
		int re = 0, ans = 0;
		cin >> r2;
		r2--;
		for(int i=0;i<4;i++)
			for(int j=0;j<4;j++)
				cin >> a[i][j];
		for(int i=0;i<4;i++)
			if(s[a[r2][i]]==1)
				re++, ans = a[r2][i];
		if(re==1)	printf("Case #%d: %d\n",t+1,ans);
		else if(re==0)	printf("Case #%d: Volunteer cheated!\n",t+1);
		else	printf("Case #%d: Bad magician!\n",t+1);
	}
    
    return 0;
}