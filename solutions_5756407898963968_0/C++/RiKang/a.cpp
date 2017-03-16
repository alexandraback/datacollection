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
#include <queue>

using namespace std;

int a[11][11];
int b[11][11];

int main(){
	int t;
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	scanf("%d",&t);
	for(int i=1;i<=t;i++){
		int ans1,ans2;
		scanf("%d",&ans1);
		for(int j=1;j<=4;j++) for(int k=1;k<=4;k++) scanf("%d",&a[j][k]);
		scanf("%d",&ans2);
		for(int j=1;j<=4;j++) for(int k=1;k<=4;k++) scanf("%d",&b[j][k]);
		int an=0,op=0;
		for(int j=1;j<=4;j++) for(int k=1;k<=4;k++) if(a[ans1][j]==b[ans2][k]){
			an=a[ans1][j],op++;
		}
		printf("Case #%d: ",i);
		if(op==0) printf("Volunteer cheated!\n");
		else if(op==1) printf("%d\n",an);
		else printf("Bad magician!\n");
	}
	return 0;
}