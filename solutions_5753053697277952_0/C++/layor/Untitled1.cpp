#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <algorithm>
#include <string.h>
#include <map>
#include <stack>



int t, n, num[26];
int all;

int main(){
    freopen("A-small-attempt0.in", "r", stdin);
    freopen("A0.out", "w", stdout);
    scanf("%d", &t);
    for(int ca=1; ca<=t; ca++){
        scanf("%d", &n); all =0 ;
        for(int i=0; i<n; i++){
            scanf("%d", &num[i]);
            all += num[i];
        }
        printf("Case #%d:", ca);
        while(true){
            if(all <= 2){
                putchar(' ');
                for(int i=0; i<n; i++){
                    while(num[i]){
                        putchar(i+'A');
                        num[i]-- ;
                    }
                }
                putchar('\n');
                break;
            }
            int tag = 0;
            for(int i=0; i<n; i++) if((num[i]-1)*2 > all-2){
                putchar(' ');
                putchar(i+'A');
                putchar(i+'A');
                num[i] -= 2;
                all -= 2;
                tag = 1;
                break;
            }
            if(!tag){
                putchar(' ');
                int cnt = 0;
                for(int i=0; i<n && cnt < 2; i++) if(num[i]*2 > all-2){
                    cnt += 1;
                    putchar(i+'A');
                    num[i] --;
                    if(all - cnt ==2) break;
                }
                if(cnt < 2 && all-cnt > 2){
                    for(int i=0; i<n && cnt<2; i++) if(num[i]){
                        if(num[i] == 1){
                            putchar(i+'A');
                            cnt +=1 ;
                            num[i] -= 1;
                        }else if(num[i] > 1){
                            while(cnt <2){
                                num[i]-=1;
                                cnt += 1;
                                putchar(i+'A');
                            }
                        }
                    }
                }
                all -= cnt;
            }
        }
    }
    return 0;
}
