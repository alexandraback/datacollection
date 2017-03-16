#include<cstdio>
#include<iostream>
using namespace std;
int p[17], tc, rown;
int main(){
    scanf("%d", &tc);
    for(int TC = 1; TC <= tc; ++TC){
        for(int i = 0; i < 17; ++i) p[i] = 0;
        scanf("%d", &rown);
        for(int i = 0,t; i < 4; ++i){
            for(int j = 0; j < 4; ++j){
                scanf("%d", &t);
                if(rown == i+1){
                    p[t]++;
                }
            }
        }
        scanf("%d", &rown);
        for(int i = 0,t; i < 4; ++i){
            for(int j = 0; j < 4; ++j){
                scanf("%d", &t);
                if(rown == i+1){
                    p[t]++;
                }
            }
        }
        int c = 0, l;
        for(int i = 1; i <= 16; ++i){
            if(p[i] == 2) ++c, l = i;
        }
        if(c == 0) printf("Case #%d: Volunteer cheated!\n", TC);
        if(c == 1) printf("Case #%d: %d\n", TC, l);
        if(c > 1) printf("Case #%d: Bad magician!\n", TC);
    }
    //system("pause");
}
