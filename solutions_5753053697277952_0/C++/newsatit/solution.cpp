#include <bits/stdc++.h>
using namespace std;
struct Data{
    int groups;
    int num;
    bool operator<(const Data& tmp)const{
        return num < tmp.num;
    }
};
priority_queue<Data> Q;
int main(){

    freopen("A-small-attempt0.in","r",stdin);
    freopen("1out.txt","w",stdout);

    int T;
    scanf("%d",&T);
    for(int t=1;t<=T;t++){
        int N;
        scanf("%d",&N);
        int counter = 0;
        for(int i=0;i<N;i++){
            int groups,nums;
            groups = i;
            scanf("%d",&nums);
            Q.push({groups,nums});
            counter += nums;
        }
        printf("Case #%d:",t);
        while(!Q.empty()){
//            Data top,second;
//            top = Q.top();
//            Q.pop();
//            second = Q.top();
//            Q.pop();
//            if(top.num == second.num){
//                printf(" %c%c",'A'+top.groups,'A'+second.groups);
//                top.num--;
//                second.num--;
//                if(top.num>0){
//                    Q.push(top);
//                    Q.push(second);
//                }
//
//            }else if(top.num == second.num + 1){
//                printf(" %c",'A'+top.groups);
//                top.num--;
//                Q.push(top);
//            }else{
//                printf(" %c%c",'A'+top.groups,'A'+top.groups);
//                top.num-=2;
//                Q.push(top);
//            }
            Data top = Q.top();
            Q.pop();
            printf(" %c",top.groups+'A');
            if(top.num > 1){
                Q.push({top.groups,top.num-1});
            }
            counter--;
            if(!Q.empty()){
                if(Q.top().num > counter/2 ){
                    top = Q.top();
                    Q.pop();
                    printf("%c",'A'+top.groups);
                    if(top.num > 1){
                        Q.push({top.groups,top.num-1});
                    }
                    counter--;
                }
            }
        }
        printf("\n");


    }
    return 0;
}
