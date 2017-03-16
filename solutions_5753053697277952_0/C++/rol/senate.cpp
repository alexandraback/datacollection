#include<cstdio>
#include<utility>
#include<algorithm>
using namespace std;

int T, N, C=1;

bool lt(pair<int, char>a, pair<int, char>b){
    return a.first < b.first;
}

int main(){

    int np, n;
    pair<int, char> parties[1 << 5];
    scanf("%d", &T);
    while(T--){
        printf("Case #%d: ", C++);
        char p = 'A';
        scanf("%d", &N); np = N;
        for(int i = 0; i < N; ++i){
            scanf("%d", &n);
            parties[i] = make_pair(n, p++);
        }
        make_heap(parties, parties+N, lt);
        while(np){
            if(np == 3){
                bool flag = true;
                for(int i = 0; i < 3; ++i) if(parties[i].first != 1) flag = false;
                if(flag){
                    printf("%c ", parties[2].second);
                    --np;
                    continue;
                }
            }
            for(int i = 0; i < 2; ++i){
                printf("%c", parties[0].second);
                pop_heap(parties, parties+np, lt);
                --parties[np-1].first;
                if(parties[np-1].first == 0) --np;
                make_heap(parties, parties+np, lt);
            }
            if(np) printf(" ");
        }
        printf("\n");
    }
}
