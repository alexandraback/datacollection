#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <algorithm>
#include <bitset>
#include <math.h>
#include <queue>
#include <map>
#include <set>
#include <limits.h>
#include <limits>
#include <stdio.h>
#include <stdlib.h>
#include <sstream>
#include <string.h>
#include <assert.h>
#include <numeric>
using namespace std;

#define MOD 1000000007

int casen;

int tell[17];
int main(){
    freopen("a.in","r",stdin);
    freopen("a.out","w",stdout);
	scanf("%d",&casen);
    for (int casei=1;casei<=casen;casei++){
        memset(tell,0,sizeof(tell));
        int ans=0;
        int t=0;
        int aa=0;
        scanf("%d",&aa);
        for (int i=1;i<=4;i++){
            for (int j=1;j<=4;j++){
                int tmp;scanf("%d",&tmp);
                if (i==aa){
                    tell[tmp]++;
                }
            }
        }
        scanf("%d",&aa);
         for (int i=1;i<=4;i++){
            for (int j=1;j<=4;j++){
                int tmp;scanf("%d",&tmp);
                if (i==aa){
                    tell[tmp]++;
                }
            }
        }
        for (int i=1;i<=16;i++){
           // printf("%d\n",tell[i]);
            if (tell[i]==2){t++;ans=i;}
        }
        printf("Case #%d: ",casei);
        if (t>1){
            printf("Bad magician!");
        }else if (t==0){
             printf("Volunteer cheated!");
        }else{
           printf("%d",ans);
        }
        printf("\n");
    }
}
