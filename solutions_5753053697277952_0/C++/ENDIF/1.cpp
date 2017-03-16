#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;


int a[30];
int main(){
    freopen("A-small-attempt3.in", "r", stdin);
    freopen("out.txt", "w", stdout);
    int T, ca = 1;
    cin>>T;
    while(T--){
        int n, sum = 0;
        cin>>n;
        for(int i = 0; i < n; i++){
            cin>>a[i];
//            printf("%d ", a[i]);
            sum += a[i];
        }
//        puts("");
        printf("Case #%d:", ca++);
        for(;sum >= 4;){
            printf(" ");
            int p = 0;
            for(int i = 0; i < n; i++)
                if(a[i] > a[p]) p = i;
            printf("%c", 'A'+p);
            a[p]--, sum--;
//            if(sum < 4) break;

            p = 0;
            for(int i = 0; i < n; i++)
                if(a[i] > a[p]) p = i;
            printf("%c", 'A'+p);
            a[p]--, sum--;
        }

        if(sum == 3){
            int i = 0;
            for(; i < n; i++)
                if(a[i]) {
                        printf(" %c ", 'A'+i);
                        break;
                }
            for(i++; i < n; i++)
                if(a[i])
                        printf("%c", 'A'+i);
        }
        else{
            putchar(' ');
            for(int i = 0; i < n; i++)
                if(a[i])
                    printf("%c", 'A'+i);
        }
        puts("");
    }

    return 0;
}
