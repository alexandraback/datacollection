#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
char str[1024];
struct S{
    char c;
    int tms;
};
S rec[101][101];
int rlen[101];
int num[101];
int main(){
    int T, n, ans, L;
    scanf("%d",&T);
    for(int f=1;f<=T;f++){
        scanf("%d",&n);
        for(int i=0;i<n;i++){
            scanf("%s", str);
            L = strlen(str);
            rlen[i] = 0;
            for(int p=0;p<L;p++){
                rec[i][ rlen[i] ].c = str[p];
                rec[i][ rlen[i] ].tms = 1;
                while( str[p] == str[p+1] ){
                    p++;
                    rec[i][ rlen[i] ].tms++;
                }
                rlen[i]++;
            }
        }
        



        int fail = 0;
        for(int i=1;i<n && fail==0;i++){
            if( rlen[i] != rlen[0] ){
                fail = 1;
            }
            for(int j=0;j<rlen[i] && fail==0;j++){
                if( rec[i][j].c != rec[0][j].c ){
                    fail = 1;
                }
            }
        }
        if(fail == 1){
            printf("Case #%d: Fegla Won\n", f);
        }else{
            ans = 0;
            int n2 = n / 2;
            for(int j=0;j<rlen[0];j++){
                for(int i=0;i<n;i++){
                    num[i] = rec[i][j].tms;
                }
                sort(num,num+n);
                for(int i=0;i<n2;i++){
                    ans += num[n-1-i] - num[i];
                }
            }
            printf("Case #%d: %d\n", f, ans);
        }

    }
}
