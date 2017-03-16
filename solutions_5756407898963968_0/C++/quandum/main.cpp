#include <cstdio>
#include <cstring>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <map>
#include <deque>
#include <cmath>
#define _USE_MATH_DEFINES
#define maxSZ 4
using namespace std;
int a[maxSZ][maxSZ],b[maxSZ][maxSZ],n,m;
int rs[maxSZ*maxSZ],top;
void process(){
    top=0; n--; m--;
    int i,j;
    for (i=0;i<maxSZ;i++)
        for (j=0;j<maxSZ;j++)if (a[n][i]==b[m][j]){
            rs[top]=a[n][i]; top++;
    }
    if (top>1) printf("Bad magician!");
    if (top==1) printf("%d",rs[0]);
    if (1>top) printf("Volunteer cheated!");
}
int main(){
    freopen("A-small-attempt2.in","r",stdin);
    freopen("output.txt","w",stdout);
    int ntest,test,i,j;
    scanf("%d",&ntest);
    for (test=1;test<=ntest;test++){
        scanf("%d",&n);
        for (i=0;i<4;i++) for (j=0;j<4;j++)
            scanf("%d",&a[i][j]);

        scanf("%d",&m);
        for (i=0;i<4;i++) for (j=0;j<4;j++)
            scanf("%d",&b[i][j]);

        if (test>1) printf("\n");
        printf("Case #%d: ",test);
        process();
    }
    fclose(stdin); fclose(stdout);
    return 0;
}
