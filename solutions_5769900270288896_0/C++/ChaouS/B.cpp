#include <bits/stdc++.h>


using namespace std;
const int N = 105;
const int inf = (int)1e8;


int ans[N] , sol[N][N][N];
void solve(int x,int y,int n){


            int len = x * y;
            for(int i = 0; i <= len; ++i ){
                ans[i] = inf;
            }

            for(int mask = 0; mask < 1<<len; mask++){
                int sz = __builtin_popcount(mask);

                    int tmp = 0;
                    for(int i = 0; i < x; ++i){
                        for(int j = 1; j < y; ++j){
                        int p1 = i * y  + j;
                        int p2 = i * y + j - 1;
                            if( (mask & (1<<p1)) != 0 && (mask & (1<<p2)) != 0 ){
                                tmp++;
                            }
                        }
                    }

                    for(int j = 0; j < y; ++j){
                        for(int i = 1; i < x; ++i){
                        int p1 = i * y  + j;
                        int p2 = (i-1) * y + j;
                            if( (mask & (1<<p1)) != 0 && (mask & (1<<p2)) != 0 ){
                                tmp++;
                            }
                        }
                    }
                ans[sz] = min(ans[sz] , tmp);
            }

            for(n = 0; n <= x * y; n++){
             sol[x][y][n] = ans[n];
            }

}

int main(){

   freopen("/home/docente/B-small-attempt0.in","r",stdin);
   freopen("on.c","w",stdout);

  //  freopen("in.c","r",stdin);




    memset(sol,-1,sizeof sol);
    int tc , x ,y , n , nc = 1;

    cin >> tc;

    while(tc--){
        cin >> x >> y >> n;

        if(sol[x][y][n] == -1){
            solve(x,y,n);
        }
        printf("Case #%d: %d\n",nc++,sol[x][y][n]);
    }


	return 0;
}




