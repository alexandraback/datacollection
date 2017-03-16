#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

const int MAXN = 105;
typedef pair<int,int> ii;
vector <ii> V[MAXN];
int N;

char str[MAXN];

void run(){
    scanf("%d",&N);
    for(int i=0;i<MAXN;i++) V[i].clear();


    for(int i=1;i<=N;i++){
        scanf("%s",str);
        char before = 0;
        int cc = 0;
        for(int j=0;str[j];j++){
            if(str[j] == before) cc++;
            else{
                V[i].push_back(ii(before,cc));
                before = str[j];
                cc = 1;
            }
        }
        V[i].push_back(ii(before,cc));
    }

    bool can = true;
    int ss = V[1].size();
    for(int i=2;i<=N;i++) if(ss != V[i].size()) can = false;

    for(int i=1;i<ss;i++){
        for(int j=2;j<=N;j++) if(V[j][i].first != V[1][i].first) can = false;
    }

    if(!can){
        printf("Fegla Won\n");
        return ;
    }

    int ans = 0;
    for(int i=1;i<ss;i++){
        vector <int> vv;
        for(int j=1;j<=N;j++) vv.push_back(V[j][i].second);
        sort(vv.begin(),vv.end());
        int NN = vv.size()/2;

        //for(int j=0;j<vv.size();j++) printf("[%d]",vv[j]); printf("\n");
        for(int j=0;j<vv.size();j++) ans += abs(vv[j] - vv[NN]);
    }
    printf("%d\n",ans);

    /*for(int i=1;i<=N;i++){
        printf("[%d] : ",i);
        for(int j=0;j<V[i].size();j++) printf("[%c,%d]",V[i][j].first,V[i][j].second);
        printf("\n");
    }*/
}

int main(){
    freopen("A-small-attempt0.in","r",stdin);
    freopen("A-small-attempt0.out","w",stdout);

    int T;
    scanf("%d",&T);
    for(int i=1;i<=T;i++){
        printf("Case #%d: ",i);
        run();
    }
    return 0;
}

