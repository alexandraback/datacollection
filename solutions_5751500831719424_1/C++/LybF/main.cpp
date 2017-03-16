#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <sstream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <numeric>
using namespace std;

const int N=1e6+10;
char s[200][200];
vector<char>vc[200];
vector<int>vn[200];
int main() {
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    int T;
    scanf("%d",&T);
    for (int cas=1;cas<=T;cas++){
        int n;
        scanf("%d",&n);

        for (int i=1;i<=n;i++){
            vn[i].clear();
            vc[i].clear();
        }
        set<int>se;
        for (int i=1;i<=n;i++){
            scanf("%s",s[i]);
            vc[i].push_back(s[i][0]);
            vn[i].push_back(1);
            int len=strlen(s[i]);
            for (int j=1;j<len;j++){
                if (s[i][j]!=s[i][j-1]){
                    vc[i].push_back(s[i][j]);
                    vn[i].push_back(1);
                }
                else {
                    vn[i][vn[i].size()-1]++;
                }

            }
            se.insert(vc[i].size());
            //cout<<"size"<<vc[i].size()<<endl;
        }
        bool ok=(se.size()==1);
        //cout<<se.size()<<endl;
        printf("Case #%d: ",cas);
        for (int i=2;i<=n;i++)
            if (vc[i]!=vc[i-1])
                ok=false;
        if (!ok) {
            puts("Fegla Won");
            continue;
        }
        int ret=0;
        for (int i=0; i<vc[1].size(); i++) {
            int dp=0x3f3f3f3f;
            for (int k=1;k<=n;k++){
                int enu=vn[k][i];
                int add=0;
                for (int j=1; j<=n; j++) {
                    add+=abs(vn[j][i]-enu);
                }
                dp=min(dp,add);
            }
            ret+=dp;
        }
        printf("%d\n",ret);
    }
    return 0;
}
