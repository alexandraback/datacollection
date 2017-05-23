#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <queue>
#include <cstdio>
#include <cmath>
#include <stack>
#define PI acos(-1.0)
#define inf 0x3f3f3f3f
#define E exp(double(1))
#define eps 1e-7
using namespace std;

#ifdef __int64
typedef __int64 LL;
#else
typedef long long LL;
#endif

int s1[10];
int s2[10];
int str[10][10];

int main() {
    int i,j,k,m;
    freopen("out.txt","w",stdout);
    freopen("A-small-attempt1.in","r",stdin);
    int _,n,cas=1;
    cin>>_;
    while(_--) {
        scanf("%d",&n);
        for(i=1; i<=4; i++) {
            for(j=1; j<=4; j++) {
                scanf("%d",&str[i][j]);
                if(i==n)s1[j]=str[i][j];
            }
        }
        scanf("%d",&m);
        for(i=1; i<=4; i++) {
            for(j=1; j<=4; j++) {
                scanf("%d",&str[i][j]);
                if(i==m)s2[j]=str[i][j];
            }
        }
        int cnt = 0,pos;


        for(i=1;i<=4;i++){
            for(j=1;j<=4;j++){
                if(s1[i]==s2[j])cnt++,pos=s1[i];
            }
        }
        if(cnt==0){
            printf("Case #%d: Volunteer cheated!\n",cas++);
        }else if(cnt>1){
            printf("Case #%d: Bad magician!\n",cas++);
        }else{
            printf("Case #%d: %d\n",cas++,pos);
        }
    }
    return 0;
}
