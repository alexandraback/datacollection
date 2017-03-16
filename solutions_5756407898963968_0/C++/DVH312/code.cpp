#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <cmath>
#include <string>
#include <cstring>
#include <iostream>
#include <ctime>

using namespace std;

#define F1 "code.inp"
#define F2 "code.out"

const int inf=1000000000;
const int md=1000000007;
const double esp=0.000000000001;
typedef pair<int,int>ii;

int mark[22];
int n;
int init(){
    for (int i=1;i<=16;i++) mark[i]=0;
    return 0;
}

int read(){
    scanf("%d",&n);
    for (int i=1;i<=4;i++){
        for (int j=1;j<=4;j++) {
            int x;
            scanf("%d",&x);
            if (i==n) mark[x]=1;
        }
    }
    int dem=0;
    int last=0;
    scanf("%d",&n);
    for (int i=1;i<=4;i++){
        for (int j=1;j<=4;j++) {
            int x;
            scanf("%d",&x);
            if (i==n && mark[x]) {
                dem++;
                last=x;
            }
        }
    }
    if (dem>1) printf("Bad magician!\n");
    else if (dem==0) printf("Volunteer cheated!\n");
    else printf("%d\n",last);
    return 0;
}

int process(){

    return 0;
}
int main(){
    #ifndef ONLINE_JUDGE
    freopen(F1,"r",stdin);
    freopen(F2,"w",stdout);
    #endif // ONLINE_JUDGE
    int sotest;
    scanf("%d",&sotest);
    //sotest=1;
    for (int test=1;test<=sotest;test++){
        init();
        printf("Case #%d: ",test);
        read();
        process();
    }

    return 0;
}
