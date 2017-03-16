#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>

using namespace std;

char str[120][120];
vector<pair<char, int> > ans[200];
vector<int> tmp;

int main(void){
    int T;

    scanf("%d", &T);
    for(int i = 1; i <= T; i++){
        printf("Case #%d: ", i);
        int N;
        scanf("%d", &N);
        for(int j = 0; j < N; j++)
            scanf("%s", str[j]);
        for(int j = 0; j < N; j++) ans[j].clear();
        for(int j = 0; j < N; j++){
            int len = strlen(str[j]);
            ans[j].push_back(make_pair(str[j][0], 1));
            for(int k = 1; k < len; k++){
                if(str[j][k] == str[j][k-1]){
                    ans[j][ans[j].size()-1].second++;
                    continue;
                }
                ans[j].push_back(make_pair(str[j][k], 1));
            }
        }
        int flag = 0;
        for(int j = 1; j < N; j++){
            for(int k = j-1; k < N; k++){
                if(ans[j].size() != ans[k].size()){
                    flag = 1;
                    break;
                }
                for(int l = 0; l < ans[j].size(); l++){
                    if(ans[j][l].first != ans[k][l].first){
                        flag = 1;
                        break;
                    }
                }
            }
        }
        if(flag){
            puts("Fegla Won");
            continue;
        }
        int res = 0;
        int anslen = ans[0].size();
        for(int j = 0; j < anslen; j++){
            tmp.clear();
            for(int k = 0; k < N; k++)
                tmp.push_back(ans[k][j].second);
            //for(int k = 0; k < N; k++) printf("==%d\n", tmp[k]);
            sort(tmp.begin(), tmp.end());
            for(int k = 0; k < N; k++){
                int tmpnum = (ans[k][j].second-tmp[tmp.size()/2]);
                if(tmpnum < 0) tmpnum = -tmpnum;
                res += tmpnum;
            }
        }
        printf("%d\n", res);
    }
    return 0;
}
