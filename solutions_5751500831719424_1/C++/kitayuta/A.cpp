#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main(){
    int T;
    scanf("%d",&T);
    for(int ix=1;ix<=T;ix++){
        printf("Case #%d: ",ix);
        int N;
        scanf("%d",&N);
        vector<string> ins(N);
        for(int i=0;i<N;i++){
            cin>>ins[i];
        }
        vector<string> uns(ins);
        for(int i=0;i<N;i++){
            uns[i].erase(unique(begin(uns[i]),end(uns[i])),end(uns[i]));
        }
        bool is=true;
        for(int i=1;i<N;i++){
            if(uns[0]!=uns[i]) is=false;
        }
        if(!is){
            printf("Fegla Won\n");
            continue;
        }
        vector<vector<int>> rens(N,vector<int>(uns[0].size()));
        for(int i=0;i<N;i++){
            int sat=0,renat=0;
            for(int j=1;j<ins[i].size();j++){
                if(ins[i][j]!=ins[i][sat]){
                    rens[i][renat++]=j-sat;
                    sat=j;
                }
            }
            rens[i][renat]=ins[i].size()-sat;
        }
        int ans=0;
        for(int i=0;i<rens[0].size();i++){
            int mi=INT_MAX;
            for(int j=1;j<=100;j++){
                int now=0;
                for(int k=0;k<N;k++){
                    now+=abs(rens[k][i]-j);
                }
                mi=min(now,mi);
            }
            ans+=mi;
        }
        printf("%d\n",ans);
    }
}
