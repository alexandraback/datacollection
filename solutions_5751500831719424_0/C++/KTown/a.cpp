#include <iostream>
#include <cstdio>
#include <stdint.h>
#include <set>
#include <string>
#include <cstring>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<pair<char,int> > > ss;
int N;

void input(){
    char buf[101];
    for(int i=0;i<N; i++){
        scanf("%s",buf);
        char curr = 0;
        for(int j=0; j<strlen(buf);j++){
            if(curr != buf[j])
                ss[i].push_back(make_pair(buf[j],1));
            else
                ss[i].back().second++;
            curr = buf[j];
        }
    }
}

int main(){
    int T;
    scanf("%d", &T);
    for(int t=0;t++<T;){
        ss.clear();
        scanf("%d", &N);
        ss.resize(N);
        input();
        int ul = ss[0].size();
        int fw = 0;
        for(int i = 1; i<N;i++){
            if(ss[i].size() != ul){
                fw=1;
                break;
            }
            for(int j=0;j<ul;j++){
                if(ss[i][j].first != ss[0][j].first){
                    fw=1;
                    break;
                }
            }
        }
        if(fw){
            printf("Case #%d: Fegla Won\n", t);
            continue;
        }
        int ret = 0;
        for(int i=0; i <ul;i++){
            vector<int> tmp;
            for(int j=0;j<N;j++){
                tmp.push_back(ss[j][i].second);
            }
            sort(tmp.begin(),tmp.end());
            int mid = tmp[tmp.size()/2];
            for(int j=0;j<N;j++){
                ret += abs(mid - tmp[j]);
            }

        }

        printf("Case #%d: %d\n", t, ret);
    }
}
