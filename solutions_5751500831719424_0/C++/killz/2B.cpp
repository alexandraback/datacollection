#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<string>
#include<cstring>
#include<vector>
#include<cmath>
#include<iostream>

using namespace std;

int i, n, k, N, M, K;

string z[200];
string s[200];
char stp[200];
int avg[200];
int ea[200][200];

int main(){
    freopen("A-small-attempt1.in", "r", stdin);
    freopen("A-sm-1.out", "w", stdout);
double sm = 0;
int a, b, c, d;
int T, R;
string tp;
cin >> T;
R = T;
while(T--){
    c = 0;
    sm = 0;
    cin >> N;
    for(a=0;a<200;a++){
        for(b=0;b<200;b++){
            ea[a][b] = 0;
        }
        avg[a] = 0;
        z[a].clear();
    }
    for(b=0;b<N;b++){
        scanf("%s", stp);
        s[b] = stp;
        k = 0;
        for(a=0;a<s[b].length();a++){
            for(i=a+1;i < s[b].length();i++){
                if(s[b][a]!=s[b][i]) break;
            }
            avg[k] += i-a;
            ea[b][k] = i-a;
            k++;
            a = i-1;
            z[b].push_back(s[b][a]);
        }
        if(b == 0) tp = z[b];
        else {
            if(tp != z[b]){
                c = 1;
                break;
            }
        }
    }
//    printf("%d ", k);
    printf("Case #%d: ", R-T);
    if(c){
        printf("Fegla Won\n");
    }
    else {
        for(a=0;a<k;a++){
//            printf("%d ", avg[a]);
            avg[a] = round(((double)avg[a]*1.0)/(N*1.0));
        }
//        printf("   <\n");
        for(a=0;a<N;a++){
            for(b=0;b<k;b++){
                sm += fabs((double)avg[b]-ea[a][b]);
//                printf("%d ", ea[a][b]);
            }
//            printf("\n");
        }
        printf("%.0lf\n", sm);
    }
}

return 0;
}
