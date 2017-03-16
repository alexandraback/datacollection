#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
using namespace std;
int m[1005], now[1005];
int ans[10000005], num, finish;
int main(){
    int T, n, b;
    scanf("%d", &T);

    for (int _T = 1; _T <= T; _T++){
        scanf("%d %d", &b, &n);

        for (int i = 0; i < b; ++i)
            scanf("%d", &m[i]);

        //
        int Min = m[0], index = 0;
        num = 0;
        for (int i = 0; i < b; ++i){
            ans[num++] = i + 1;
            now[i] = m[i];
            if(m[i] < Min){
                Min = m[i];
                index = i;
            }
        }

        finish = 0;
        while(finish != b && num <= n){
            //printf("MIN:%d\n",Min );
            int temp = Min, temp_i = index;
            Min = 1e9;
            finish = 0;
            ans[num++] = index + 1;

            for (int i = 0; i < b; ++i){
                now[i] -= temp;

                if(now[i] == 0){

                    finish ++;
                    now[i] = m[i];
                    if(temp_i != i)
                        ans[num++] = i + 1;
                }
                
                if(now[i] < Min){
                    Min = now[i];
                    index = i;
                }
            }
        }
        //printf("num:%d\n",num );
        if(finish == b)
            num -= b;
        int a = (n-1)%num;
        //printf("num:%d\n",num );
        //printf("\n");
        printf("Case #%d: %d\n", _T, ans[a]);
        

    }


}