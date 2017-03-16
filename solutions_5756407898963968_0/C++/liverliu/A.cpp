#include<iostream>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<algorithm>
using namespace std;
int main() {
    freopen("/Users/liverliu/Documents/codejam/A-small-attempt1.in","r",stdin);
    freopen("/Users/liverliu/Documents/codejam/A-small-attempt1.out","w",stdout);
    int T = 0, cas = 0;
    scanf("%d",&T);
    while(T--) {
    	int a[4][4],b[4][4];
    	int p1,p2;
    	scanf("%d",&p1);
    	for(int i=0;i<4;i++) {
    		for(int j=0;j<4;j++) {
    			scanf("%d", &a[i][j]);
    		}
    	}
    	scanf("%d",&p2);
    	for(int i=0;i<4;i++) {
    		for(int j=0;j<4;j++) {
    			scanf("%d",&b[i][j]);
    		}
    	}
    	p1--,p2--;
    	int find = 0, ans=-1;
    	for(int i=0;i<4;i++) {
    		for(int j=0;j<4;j++) {
    			if(a[p1][i]==b[p2][j]) {
    				ans = a[p1][i];
    				find ++;
    				break;
    			}
    		}
    	}
    	if(find==0) {
    		printf("Case #%d: Volunteer cheated!\n", ++cas);
    	} else if(find==1) {
    		printf("Case #%d: %d\n", ++cas,ans);
    	} else {
    		printf("Case #%d: Bad magician!\n", ++cas);
    	}
    }
    return 0;
}
