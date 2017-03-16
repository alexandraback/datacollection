#include <iostream>
#include <string>
#include <cstdio>
#include <cstring>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <cmath>
#include <sstream>
#include <algorithm>
#include <numeric>
#define mp(x,y) make_pair(x,y)
#define pb(x) push_back(x)
#define sqr(x) ((x)*(x))
using namespace std;
const int INF = 0x3f3f3f3f;
typedef long long ll;
template<typename X> inline bool minimize(X&p,X q){if(p<=q)return 0;p=q;return 1;}
template<typename X> inline bool maximize(X&p,X q){if(p>=q)return 0;p=q;return 1;}
int A[4][4],B[4][4];
int solve(int a,int b){

}
int main()
{
    int T;
    cin>>T;
    for(int t=1;t<=T;++t){
        int a,b;
        cin>>a;--a;
        for(int i=0;i<4;++i)
            for(int j=0;j<4;++j)
                scanf("%d",&A[i][j]);
        cin>>b;--b;
        for(int i=0;i<4;++i)
            for(int j=0;j<4;++j)
                scanf("%d",&B[i][j]);
        int cnt=0,ans;
        for(int i=0;i<4;++i)
            for(int j=0;j<4;++j)
                if(A[a][i]==B[b][j])
                    ++cnt,ans=A[a][i];
        if(cnt==0)printf("Case #%d: Volunteer cheated!\n",t);
        else if(cnt==1)printf("Case #%d: %d\n",t,ans);
        else printf("Case #%d: Bad magician!\n",t);
    }
    return 0;
}
